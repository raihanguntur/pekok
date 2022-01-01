#pragma once
#include "Framework.h"
#include "il2cpp-appdata.h"
#include <chrono>
#include <unordered_map>
#include "kiero/kiero.h"
#include "kiero/minhook/include/MinHook.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_stdlib.h"
#include "imgui/imgui_internal.h"
#include "Globals.h"
#include "Util.h"
#include "Functions.h"
//#include "Il2CppHooks.h"
#define IL2CPP_RUNTIME_CLASS_INIT(klass) if((klass)->has_cctor && !(klass)->cctor_finished && curClass->genericContainerIndex == -1) { il2cpp_runtime_class_init((klass)); }


#define WIDEN2(x) L ## x
#define WIDEN(x) WIDEN2(x)
#define __WFILE__ WIDEN(__FILE__)
#define HRCHECK(__expr) {hr=(__expr);if(FAILED(hr)){wprintf(L"FAILURE 0x%08X (%i)\n\tline: %u file: '%s'\n\texpr: '" WIDEN(#__expr) L"'\n",hr, hr, __LINE__,__WFILE__);goto cleanup;}}
#define RELEASE(__p) {if(__p!=nullptr){__p->Release();__p=nullptr;}}
//typedef void (*ArkAngelCommandCallback)(CmdStr& command, int argCount);
//struct ArkAngelCommand
//{
//	ArkAngelCommandCallback function;
//	std::string alias;
//	std::string description;
//	ArkAngelCommand(std::string alias, ArkAngelCommandCallback function)
//	{
//		this->function = function;
//		this->alias = alias;
//		this->description = "No Description";
//	}
//	ArkAngelCommand(std::string alias, std::string description, ArkAngelCommandCallback function)
//	{
//		this->function = function;
//		this->alias = alias;
//		this->description = description;
//	}
//	ArkAngelCommand()
//	{
//		function = NULL;
//		alias = "";
//		description = "";
//	}
//	void Call(CmdStr command, int argCount)
//	{
//		function(command, argCount);
//	}
//};
struct ArkAngelChatElement
{
	std::string text;
	ImVec4 color;
	int countAbove;
};
struct ArkAngelConsole
{
	std::vector<std::string> history;
	std::vector<ArkAngelChatElement> items;
	std::unordered_map<std::string, ArkAngelCommand> commands;
	std::string input;
	ImFont* MonospaceFont;
	bool ScrollToBottom = false;
	bool AutoScroll = false;
	int historyPos = -1;
	ArkAngelConsole()
	{
		history.clear();
		ScrollToBottom = false;
		AutoScroll = true;
	}
	~ArkAngelConsole()
	{
		history.clear();
		items.clear();
		commands.clear();
	}
	void Draw(bool* pOpen)
	{
		//ImGui::SetNextWindowSize(ImVec2(520, 600), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowBgAlpha(0.9f);
		ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_WindowBg, ImVec4{ 0, 0.2f, 0.45f, 0.9f });
		ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_FrameBg, ImVec4{ 0.1, 0.1f, 0.25f, 0.9f });
		if (!ImGui::Begin("Console", pOpen))
		{
			ImGui::End();
			ImGui::PopStyleColor(2);
			return;
		}

		const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing();
		ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar);

		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1)); // Tighten spacing
		for (int i = 0; i < items.size(); i++)
		{
			ArkAngelChatElement& item = items[i];
			ImGui::PushStyleColor(ImGuiCol_Text, item.color);
			if (item.countAbove > 0)
			{
				const char* c = items[i].text.c_str();
				std::string s = string_printf("%s (%i)", c, item.countAbove);
				c = s.c_str();
				 if (!IsBadMem((void*)c))
					 ImGui::TextUnformatted(c);
			}
			else
			{
				const char* c = item.text.c_str();
				if (!IsBadMem((void*)c))
					ImGui::TextUnformatted(c);
			}
			ImGui::PopStyleColor();
		}
		if (ScrollToBottom || (AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()))
			ImGui::SetScrollHereY(1.0f);
		ScrollToBottom = false;

		ImGui::PopStyleVar();
		ImGui::EndChild();
		//ImGui::Separator();

		// Command-line
		bool reclaim_focus = false;
		ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x - ImGui::GetStyle().ItemSpacing.x);

		if (ImGui::InputText("", &input, ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackHistory | ImGuiInputTextFlags_CallbackAlways, &TextEditCallbackStub, (void*)this))
		{
			if (!input.empty())
			{
				AddLog(">> " + input);
				ExecuteCommand(input);
				input = "";
			}
			reclaim_focus = true;
		}

		ImGui::SetItemDefaultFocus();
		if (reclaim_focus)
			ImGui::SetKeyboardFocusHere(-1);

		ImGui::End();
		ImGui::PopStyleColor(2);
	}
	void AddLog(std::string message, ImVec4 color)
	{
		if (items.size() > 0)
		{
			if (message == items[items.size() - 1].text)
			{
				if (items[items.size() - 1].countAbove == 0)
					items[items.size() - 1].countAbove++;
				items[items.size() - 1].countAbove++;
			}
			else
				items.push_back({ message, color, 0 });
		}
		else
			items.push_back({ message, color, 0 });
	}
	void AddLog(std::string message)
	{
		AddLog(message, ImVec4{1,1,1,1});
	}
	void AddError(std::string error)
	{
		AddLog("[error]" + error, ImVec4{ 1.f, 0, 0, 1.f });
	}
	void printf(const char* format, ...)
	{
		va_list argsToCheckSize;
		int n;
		std::string ret;

		va_start(argsToCheckSize, format);
		// use a temporary buffer as some docs indicate we cannot pass NULL to vsnprintf
		char buf[1];
		n = vsnprintf(buf, 0, format, argsToCheckSize);
		if (n == -1)
			return;

		ret.resize(n + 1, 0);
		va_end(argsToCheckSize);

		va_list argsToFormat;

		va_start(argsToFormat, format);
		n = vsnprintf(&ret[0], ret.size(), format, argsToFormat);
		va_end(argsToFormat);


		if (n == -1)
			return;

		// The v*printf methods might put a trailing NUL character, which should not not be in a
		// std::string, so strip it out.
		if (!ret.empty() && ret[ret.size() - 1] == '\0')
			ret = ret.substr(0, ret.size() - 1);

		AddLog(ret, ImVec4{1,1,1,1});
	}
	void errorf(const char* format, ...)
	{
		va_list argsToCheckSize;
		int n;
		std::string ret;

		va_start(argsToCheckSize, format);
		// use a temporary buffer as some docs indicate we cannot pass NULL to vsnprintf
		char buf[1];
		n = vsnprintf(buf, 0, format, argsToCheckSize);
		if (n == -1)
			return;

		ret.resize(n + 1, 0);
		va_end(argsToCheckSize);

		va_list argsToFormat;

		va_start(argsToFormat, format);
		n = vsnprintf(&ret[0], ret.size(), format, argsToFormat);
		va_end(argsToFormat);


		if (n == -1)
			return;

		// The v*printf methods might put a trailing NUL character, which should not not be in a
		// std::string, so strip it out.
		if (!ret.empty() && ret[ret.size() - 1] == '\0')
			ret = ret.substr(0, ret.size() - 1);

		AddError(ret);
	}
	
	void ExecuteCommand(std::string message)
	{
		historyPos = -1;
		for (int i = history.size() - 1; i >= 0; i--)
		{
			if (history[i] == message)
			{
				history.erase(history.begin() + i);
				break;
			}
		}
		history.push_back(message);

		CmdStr command = CmdStr::Parse(message);
		bool broken = false;
		ArkAngelCommand aacmd = commands[command.command];
		if (aacmd.function != NULL)
		{
			aacmd.Call(command, command.args.size());
		}
		else
		{
			AddLog("Could not find command", { 1, 0, 0, 1 });
		}
		/*for (int i = 0; i < commands.size(); i++)
		{
			if (command.command == commands[i].alias)
			{
				command.command = string_ToLowercase(command.command);
				commands[i].Call(command, command.args.size());
				broken = true;
				break;
			}
		}*/
		if (!broken)
		{
		}
	}
	void AddCommand(std::string name, std::string description, ArkAngelCommandCallback callback)
	{
		commands[name] = ArkAngelCommand(name, description, callback);
	}
	static int TextEditCallbackStub(ImGuiInputTextCallbackData* data)
	{
		ArkAngelConsole* console = (ArkAngelConsole*)data->UserData;
		return console->TextEditCallback(data);
	}
	int TextEditCallback(ImGuiInputTextCallbackData* data)
	{
		static int VisibleSelectedIndex = 0;
		switch (data->EventFlag)
		{
		case ImGuiInputTextFlags_CallbackHistory:
		{
			const int prev_history_pos = historyPos;
			if (data->EventKey == ImGuiKey_UpArrow)
			{
				if (historyPos == -1)
					historyPos = history.size() - 1;
				else if (historyPos > 0)
					historyPos--;
			}
			else if (data->EventKey == ImGuiKey_DownArrow)
			{
				if (historyPos != -1)
					if (++historyPos >= history.size())
						historyPos = -1;
			}

			if (prev_history_pos != historyPos)
			{
				const char* history_str = (historyPos >= 0) ? history[historyPos].c_str() : "";
				data->DeleteChars(0, data->BufTextLen);
				data->InsertChars(0, history_str);
			}
		}
		}
		return 0;
	}
};

static ArkAngelConsole Console;
static void aa_DrawConsole(bool* pOpen)
{
	ImGui::PushFont(Console.MonospaceFont);
	Console.Draw(pOpen);
	ImGui::PopFont();
}
static bool changeFontSize = false;
static float fontSizeToChangeTo = 0.f;
static void aa_SetupConsole()
{

	Console.AddCommand("help", "Displays help",
		[](CmdStr& command, int argCount)
		{
			for (const auto& [key, value] : Console.commands) {
				if (value.alias.empty())
					continue;
				Console.AddLog(value.alias + ": " + value.description);
			}
		});
	Console.AddCommand("v", "v",
		[](CmdStr& command, int argCount)
		{
			//ValidateHWID("no");
		});
	Console.AddCommand("clear", "Clears Console",
		[](CmdStr& command, int argCount)
		{
			Console.items.clear();
		});
	Console.AddCommand("s", "s",
		[](CmdStr& command, int argCount)
		{
			Globals::testState = !Globals::testState;
		});
	Console.AddCommand("ri", "Re-Initializes Stuff",
		[](CmdStr& command, int argCount)
		{
			size_t asmCount = 0;
			const Il2CppAssembly** assemblies = il2cpp_domain_get_assemblies(il2cpp_domain_get(), &asmCount);
			for (int i = 0; i < asmCount; i++)
			{
				Globals::Assemblies[assemblies[i]->aname.name] = assemblies[i];
			}

			Functions::AddIl2CppFunctionCall([]()
				{
					size_t asmCount = 0;
					auto methodSDef = [](Il2CppAssembly* assembly, Il2CppClass* klass, const MethodInfo* meth)
					{
						std::string stubDef = "";
						for (int l = 0; l < meth->parameters_count; l++)
						{
							stubDef += il2cpp_type_get_name(meth->parameters[l].parameter_type);
							stubDef += ",";
						}
						const char* typeName = il2cpp_type_get_name(meth->return_type);
						int len = strlen(typeName) + strlen(assembly->aname.name) + strlen(meth->name) + stubDef.length() + strlen(klass->name) + 64;
						char* frmtCpyStrMethod = frmt(len, "%s %s.%s.%s(%s)", typeName, assembly->aname.name, klass->name, meth->name, stubDef.c_str());
						return frmtCpyStrMethod;
					};
					auto propertySdef = [](Il2CppAssembly* assembly, Il2CppClass* klass, const MethodInfo* meth)
					{
						const char* typeName = il2cpp_type_get_name(meth->return_type);
						int len = strlen(typeName) + strlen(assembly->aname.name) + strlen(meth->name) + strlen(klass->name) + 64;
						char* frmtCpyStrMethod = frmt(len, "%s %s.%s.%s", typeName, assembly->aname.name, klass->name, meth->name);
						return frmtCpyStrMethod;
					};
					Il2CppAssembly** assemblies = (Il2CppAssembly**)il2cpp_domain_get_assemblies(il2cpp_domain_get(), &asmCount);
					for (int i = 0; i < asmCount; i++)
					{
						Il2CppAssembly* curAsm = assemblies[i];
						size_t count = il2cpp_image_get_class_count(curAsm->image);
						for (int j = 0; j < count; j++)
						{
							Il2CppClass* curClass = (Il2CppClass*)il2cpp_image_get_class(curAsm->image, j);
							try
							{
								IL2CPP_RUNTIME_CLASS_INIT(curClass);
							}
#if _DEBUG == 1
							catch (Il2CppExceptionWrapper& e)
							{
								OutputDebugStringA(string_Utf16ToUtf8(e.ex->message).c_str());
								OutputDebugStringA("\n");
							}
							catch (Il2CppException& e)
							{
								OutputDebugStringA(string_Utf16ToUtf8(e.message).c_str());
								OutputDebugStringA("\n");
							}
#endif // DEBUG
							catch (...) {}

							int l = strlen(curAsm->aname.name) + strlen(curClass->name) + 64;
							char* frmtCpyStrCls = frmt(l, "%s.%s", curAsm->aname.name, curClass->name);
							Globals::Classes[frmtCpyStrCls] = curClass;
							free(frmtCpyStrCls);


							for (int k = 0; k < curClass->method_count; k++)
							{
								if (!curClass->initialized)
									continue;
								const MethodInfo* meth = curClass->methods[k];

								char* frmtCpyStrMethod = methodSDef(curAsm, curClass, meth);
								Globals::Methods[frmtCpyStrMethod] = meth;
								free(frmtCpyStrMethod);
							}
							for (int l = 0; l < curClass->property_count; l++)
							{
								if (!curClass->initialized)
									continue;
								const PropertyInfo* prop = &curClass->properties[l];
								const MethodInfo* get = prop->get;
								const MethodInfo* set = prop->set;

								if (get)
								{
									char* getMethodStr = propertySdef(curAsm, curClass, get);
									Globals::Methods[getMethodStr] = get;
									free(getMethodStr);
								}
								if (set)
								{
									char* setMethodStr = propertySdef(curAsm, curClass, set);
									Globals::Methods[setMethodStr] = set;
									free(setMethodStr);
								}
							}
						}
					}
				});

		});
	Console.AddCommand("mainmenu", "Brings you to the main menu",
		[](CmdStr& command, int argCount)
		{
			Functions::AddIl2CppFunctionCall([]()
				{
					const static auto SceneLoader_GoFromWorldToMainMenu0 = reinterpret_cast<void(*)()>(Globals::Methods["System.Void Assembly-CSharp.SceneLoader.GoFromWorldToMainMenu()"]->methodPointer);
					SceneLoader_GoFromWorldToMainMenu0();
				});

		});
	Console.AddCommand("reloadworld", "Reloads the world",
		[](CmdStr& command, int argCount)
		{
			Functions::AddIl2CppFunctionCall([]()
				{
					const static auto SceneLoader_ReloadWorld0 = reinterpret_cast<void(*)()>(Globals::Methods["System.Void Assembly-CSharp.SceneLoader.ReloadWorld()"]->methodPointer);
					SceneLoader_ReloadWorld0();
				});

		});
	Console.AddCommand("reloadgame", "Reloads the game",
		[](CmdStr& command, int argCount)
		{
			Functions::AddIl2CppFunctionCall([]()
				{
					const static auto SceneLoader_ReloadGame0 = reinterpret_cast<void(*)()>(Globals::Methods["System.Void Assembly-CSharp.SceneLoader.ReloadGame()"]->methodPointer);
					SceneLoader_ReloadGame0();
				});

		});
	Console.AddCommand("soundtest", "Gets Current Audio Volume",
		[](CmdStr& command, int argCount)
		{
			audioTest = true;
			CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);
			pEnumerator->GetDefaultAudioEndpoint(EDataFlow::eRender, ERole::eMultimedia, &pDevice);
			pDevice->Activate(__uuidof(IAudioMeterInformation), CLSCTX_ALL, NULL, (void**)&pMeter);
		});

	Console.AddCommand("soundtestoff", "Gets Current Audio Volume",
		[](CmdStr& command, int argCount)
		{
			audioTest = false;
			RELEASE(pMeter);
			RELEASE(pDevice);
			RELEASE(pEnumerator);
		});

	Console.AddCommand("loginup", "Logs in using username and pass",
		[](CmdStr& command, int argCount)
		{
			if (argCount == 2)
			{
				const static auto UserIdent_LoginWithUsernameAndPassword3 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ username, Il2CppString */*System.String*/ password, bool/*System.Boolean*/ loginAfterRegistration)>(Globals::Methods["System.Void Assembly-CSharp.UserIdent.LoginWithUsernameAndPassword(System.String,System.String,System.Boolean,)"]->methodPointer);
				const static auto UserIdent_LogOut0 = reinterpret_cast<void(*)()>(Globals::Methods["System.Void Assembly-CSharp.UserIdent.LogOut()"]->methodPointer);
				const static auto SceneLoader_ReloadGame0 = reinterpret_cast<void(*)()>(Globals::Methods["System.Void Assembly-CSharp.SceneLoader.ReloadGame()"]->methodPointer);

				UserIdent_LogOut0();
				UserIdent_LoginWithUsernameAndPassword3(istr(command.args[0].c_str()), istr(command.args[1].c_str()), false);
				SceneLoader_ReloadGame0();
			}
		});

#ifndef AAPUBLICMODE
	Functions::AddIl2CppTickFunc(5.0, []()
			{
				//if (!Globals::Methods["System.Void Assembly-CSharp.TrapProjectile.OnTriggerEnter2D(UnityEngine.Collider2D,)"]) 
				//{ 
				//	Console.AddError("Not all functions hooked. God mode may not work properly. Type \"ri\" in console to attempt to fix. This will only work when in a world."); 
				//}
			});
#endif
	//Console.AddCommand("ray", "Casts a ray toways mouse",
	//	[](CmdStr& command, int argCount)
	//	{
	//		ImGuiIO& io = ImGui::GetIO();
	//		Vector2i centerScreen = { io.DisplaySize.x / 2, io.DisplaySize.y / 2 };
	//		float a = atan2(centerScreen.y - Globals::MousePos.y, centerScreen.x - Globals::MousePos.x) - 1.57;

	//		Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
	//		Il2CppObject* otherPlayers = Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
	//		Vector2i playerMapPoint = Il2Cpp::Helpers::GetFieldValue<Vector2i>("currentPlayerMapPoint", localPlayer);
	//		Vector2 playerPos = Il2Cpp::Helpers::GetFieldValue<Vector3>("currentPlayerPosition", localPlayer)
	//		Il2CppArray* worldBlocks = (Il2CppArray*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldBlockLayer" });
	//		Il2CppArray* worldItemBase = (Il2CppArray*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldItemsData" });

	//	 	RaycastData castedRay = Raycast::CastRay(playerPos, a, worldBlocks, worldItemBase);
	//		if (castedRay.hit)
	//		{
	//			//Console.AddLog(string_printf("{Dist: %f, Hit Block Type: %i, Hit Position: {x: %i, y: %i}", castedRay.distTraveled, castedRay.hitBlock.blockType, castedRay.hitPosotion.x, castedRay.hitPosotion.y));
	//		}
	//	});
	Console.AddLog("Type \"help\" for a list of commands.");
	Chat.Setup();
}