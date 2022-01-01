#include "main.h"
#include "Il2CppSystem.h"
#include <chrono>
#include <unordered_map>
#include <devicetopology.h>
#include <Endpointvolume.h>
#include <Mmdeviceapi.h>
#include "kiero/kiero.h"
#include "kiero/minhook/include/MinHook.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_stdlib.h"
#include "imgui/imgui_internal.h"
#include "imgui/implot.h"
#include <mono/jit/jit.h>
#include <mono/metadata/image.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/loader.h>
#include <mono/metadata/threads.h>
#include "BSON.h"
#include "Il2CppBson.h"
#include "Util.h"
#include "Globals.h"
#include "Save.h"
#include "Functions.h"
#include "ChatHandler.h"
#include "DrawlistHelper.h"
static bool audioTest = false;
IMMDeviceEnumerator* pEnumerator = NULL;
IMMDevice* pDevice = NULL;
IAudioMeterInformation* pMeter = NULL;
static bool IsHeartless = false;
static bool HasAHeart = false;
#include "PathFinding.h"
#include "Console.h"
#include "DiscordRpcPW.h"
#include "ChairMono.h"
#include "ReflectionHelper.h"
#include "Timing.h"
#include "PerlinNoise.hpp"
#include "Il2CppHooks.h"
#include "Discord/rpc_connection.h"
#define IL2CPP_RUNTIME_CLASS_INIT(klass) if((klass)->has_cctor && !(klass)->cctor_finished && klass->genericContainerIndex == -1) { il2cpp_runtime_class_init((klass)); }
#define RunIl2CppFunction(r) Functions::AddIl2CppFunctionCall([](){r});
//#define AAPASS 217268737

void Init()
{
	Globals::Context = ImGui::CreateContext();
	ImPlot::CreateContext();
	ImGuiIO& io = ImGui::GetIO();


	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(Globals::hWnd);
	ImGui_ImplDX11_Init(Globals::pDevice, Globals::pContext);
	
	RECT rect;
	if (GetWindowRect(Globals::hWnd, &rect))
	{
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;
		io.FontDefault = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Tahoma.ttf", (width + height) / 160.f);
		Console.MonospaceFont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\consola.ttf", (width + height) / 150.f);
	}

	ImGuiStyle* style = &ImGui::GetStyle();
	ImVec4* colors = style->Colors;



	// lol
	// ChatHandler.h
	// in Header Files
#pragma region Styling
	colors[ImGuiCol_Text] = ImVec4(1.000f, 1.000f, 1.000f, 1.000f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.500f, 0.500f, 0.500f, 1.000f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.180f, 0.180f, 0.180f, 1.000f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.280f, 0.280f, 0.280f, 0.000f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.313f, 0.313f, 0.313f, 1.000f);
	colors[ImGuiCol_Border] = ImVec4(0.3f, 0.3f, 0.3f, 1.000f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.000f, 0.000f, 0.000f, 0.000f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.200f, 0.200f, 0.200f, 1.000f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.280f, 0.280f, 0.280f, 1.000f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.277f, 0.277f, 0.277f, 1.000f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.300f, 0.300f, 0.300f, 1.000f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_CheckMark] = ImVec4(1.000f, 1.000f, 1.000f, 1.000f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_Button] = ImVec4(1.000f, 1.000f, 1.000f, 0.000f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.156f);
	colors[ImGuiCol_ButtonActive] = ImVec4(1.000f, 1.000f, 1.000f, 0.391f);
	colors[ImGuiCol_Header] = ImVec4(0.313f, 0.313f, 0.313f, 1.000f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
	colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(1.000f, 1.000f, 1.000f, 0.250f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.670f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_Tab] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.352f, 0.352f, 0.352f, 1.000f);
	colors[ImGuiCol_TabActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.586f, 0.586f, 0.586f, 1.000f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(1.000f, 1.000f, 1.000f, 0.156f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_NavHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);

	style->ChildRounding = 4.0f;
	style->FrameBorderSize = 1.0f;
	style->FrameRounding = 2.0f;
	style->GrabMinSize = 7.0f;
	style->PopupRounding = 2.0f;
	style->ScrollbarRounding = 12.0f;
	style->ScrollbarSize = 13.0f;
	style->TabBorderSize = 1.0f;
	style->TabRounding = 0.0f;
	style->WindowRounding = 4.0f;
#pragma endregion

	bool valid = true;
	BSON::Object obj = SaveData::ReadFromFile(&valid);
	if (valid)
	{
		Globals::ShowConsole = obj.map["conopen"]._bool;
		Globals::ShowPlayerMenu = obj.map["piopen"]._bool;
		Globals::showMinimap = obj.map["minimapopen"]._bool;
		Globals::MiscBools["Player Trail"].value = obj.map["pt"]._bool;

		/*
		BSON::Value(Globals::playerTracerColor.x);
		BSON::Value(Globals::playerTracerColor.y);
		BSON::Value(Globals::playerTracerColor.z);
		
		 BSON::Value(Globals::localPlayerESPColor.x);
		 BSON::Value(Globals::localPlayerESPColor.y);
		 BSON::Value(Globals::localPlayerESPColor.z);
		
		 BSON::Value(Globals::otherPlayerESPColor.x);
		 BSON::Value(Globals::otherPlayerESPColor.y);
		 BSON::Value(Globals::otherPlayerESPColor.z);
		
		 BSON::Value(Globals::SelfBoxThickness);
		 BSON::Value(Globals::playerTracerThickness);
		 BSON::Value(Globals::OtherPlayerBoxThickness);
		*/



		Globals::playerTracerColor.x = obj.map["tr"]._double;
		Globals::playerTracerColor.y = obj.map["tg"]._double;
		Globals::playerTracerColor.z = obj.map["tb"]._double;
		Globals::playerTracerColor.w = 1.0f;

		Globals::localPlayerESPColor.x = obj.map["per"]._double;
		Globals::localPlayerESPColor.y = obj.map["peg"]._double;
		Globals::localPlayerESPColor.z = obj.map["peb"]._double;
		Globals::localPlayerESPColor.w = 1.0f;

		Globals::otherPlayerESPColor.x = obj.map["oer"]._double;
		Globals::otherPlayerESPColor.y = obj.map["oeg"]._double;
		Globals::otherPlayerESPColor.z = obj.map["oeb"]._double;
		Globals::otherPlayerESPColor.w = 1.0f;

		Globals::collectableBoxColor.x = obj.map["cer"]._double;
		Globals::collectableBoxColor.y = obj.map["ceg"]._double;
		Globals::collectableBoxColor.z = obj.map["ceb"]._double;
		Globals::collectableBoxColor.w = 1.0f;

		Globals::collectableTracerColor.x = obj.map["ctr"]._double;
		Globals::collectableTracerColor.y = obj.map["ctg"]._double;
		Globals::collectableTracerColor.z = obj.map["ctb"]._double;
		Globals::collectableTracerColor.w = 1.0f;

		Globals::monsterBoxColor.x = obj.map["mer"]._double;
		Globals::monsterBoxColor.y = obj.map["meg"]._double;
		Globals::monsterBoxColor.z = obj.map["meb"]._double;
		Globals::monsterBoxColor.w = 1.0f;

		Globals::monsterTracerColor.x = obj.map["mtr"]._double;
		Globals::monsterTracerColor.y = obj.map["mtg"]._double;
		Globals::monsterTracerColor.z = obj.map["mtb"]._double;
		Globals::monsterTracerColor.w = 1.0f;

		Globals::SelfBoxThickness = obj.map["pet"]._double;
		Globals::playerTracerThickness = obj.map["tet"]._double;
		Globals::OtherPlayerBoxThickness = obj.map["oet"]._double;
		Globals::collectableEspThickness = obj.map["cet"]._double;
		Globals::collectableTracerThickness = obj.map["ctt"]._double;
		Globals::monsterEspThickness = obj.map["met"]._double;
		Globals::monsterTracerThickness = obj.map["mtt"]._double;

		Globals::minimapZoomAmount = obj.map["minimapza"]._double;


	}

	Functions::AddIl2CppTickFunc(2.f,
		[]()
		{
			if (Globals::MiscBools["Anti-Kick"].value)
			{
				const static auto OutgoingMessages_KickPlayer1 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ kickTargetId)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.KickPlayer(System.String,)"]->methodPointer);
				if (Globals::IsInWorld)
				{
					Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
					OutgoingMessages_KickPlayer1(localPlayer->myPlayerData->playerId);
				}
			}
		});
	Functions::AddIl2CppTickFunc(0.125f,
		[]()
		{
			if (Globals::IsInWorld && Globals::aimbot)
			{
				Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
				Vector2i playerMapPoint = il2cpp_object_get_field_value_by_name(localPlayer, Vector2i, localPlayer->Il2CppClass.klass, "currentPlayerMapPoint"); //Il2Cpp::Helpers::GetFieldValue<Vector2i>("currentPlayerMapPoint", localPlayer);
				Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });

				int playerRange = Globals::playerInfo.range;
				if (Globals::MiscBools["Longer-Hit"].value)
					playerRange *= 5;

				float closestDist = INFINITY;
				NetworkPlayer* curClosestPlayer = nullptr;
				for (int i = 0; i < otherPlayers->size; i++)
				{
					NetworkPlayer* curNetworkPlayer = otherPlayers->arry->vector[i];//Il2Cpp::Lists::il2cpp_list_index<Il2CppObject*>(otherPlayers, i);
					if (curNetworkPlayer)
					{
						Player* curPlayer = curNetworkPlayer->playerScript;//il2cpp_object_get_field_value_by_name(curNetworkPlayer, Il2CppObject*, curNetworkPlayer->Il2CppClass.klass, "playerScript");//Il2Cpp::Helpers::GetFieldValue<Il2CppObject*>("playerScript", curNetworkPlayer);
						Vector2 otherPlayerPos = curPlayer->myTransform->GetPosition();//il2cpp_object_get_field_value_by_name(curPlayer, Vector2, curPlayer->Il2CppClass.klass, "currentPlayerPosition");// Il2Cpp::Helpers::GetFieldValue<Vector3>("currentPlayerPosition", curPlayer)
						Vector2i otherPlayerMapPoint = il2cpp_object_get_field_value_by_name(curPlayer, Vector2i, curPlayer->klass, "currentPlayerMapPoint");//il2cpp_object_get_field_value_by_name(curPlayer, Vector2i, curPlayer->Il2CppClass.klass, "currentPlayerMapPoint"); //Il2Cpp::Helpers::GetFieldValue<Vector2i>("currentPlayerMapPoint", curPlayer);
						float dist = otherPlayerPos.Distance(Globals::playerInfo.position);
						if (IsMapPointNearEnough(otherPlayerMapPoint, playerMapPoint, playerRange) && dist < closestDist)
						{
							closestDist = dist;
							curClosestPlayer = curNetworkPlayer;
						}
					}
				}
				if (curClosestPlayer)
				{
					Il2CppString* id = curClosestPlayer->clientId;//il2cpp_object_get_field_value_by_name(curClosestPlayer, Il2CppString*, curClosestPlayer->Il2CppClass.klass, "clientId");//Il2Cpp::Helpers::GetFieldValue<Il2CppString*>("clientId", curClosestPlayer);
					static auto f = reinterpret_cast<void(*)(Vector2i mapPoint, Il2CppString * playerId, int randomHitIndex)>(il2cpp_class_get_method_from_name((Il2CppClass*)Globals::Classes["Assembly-CSharp.OutgoingMessages"], "SendHitOtherPlayerMessage", 3)->methodPointer);
					const static auto OutgoingMessages_SendHitAirMessage1 = reinterpret_cast<void(*)(Vector2i/*BasicTypes.Vector2i*/ mapPoint)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendHitAirMessage(BasicTypes.Vector2i,)"]->methodPointer);
					Player* curPlayer = curClosestPlayer->playerScript;// il2cpp_object_get_field_value_by_name(curClosestPlayer, Il2CppObject*, curClosestPlayer->Il2CppClass.klass, "playerScript");//Il2Cpp::Helpers::GetFieldValue<Il2CppObject*>("playerScript", curClosestPlayer);
					Vector2i otherPlayerMapPoint = il2cpp_object_get_field_value_by_name(curPlayer, Vector2i, curPlayer->klass, "currentPlayerMapPoint"); //Il2Cpp::Helpers::GetFieldValue<Vector2i>("currentPlayerMapPoint", curPlayer);
					
					if (Globals::ctrlForActive)
					{
						if (ImGui::GetIO().KeyCtrl)
						{
							if (rand() % 100 < Globals::aimbotHitChance)
								f(otherPlayerMapPoint, id, 1);
							else
								OutgoingMessages_SendHitAirMessage1(otherPlayerMapPoint);
						}

					}
					else
					{
						if (rand() % 100 < Globals::aimbotHitChance)
							f(otherPlayerMapPoint, id, 1);
						else
							OutgoingMessages_SendHitAirMessage1(otherPlayerMapPoint);
					}
				}
			}
		});
	Functions::AddIl2CppTickFunc(0.0f,
		[]()
		{
			if (Globals::MiscBools["Play Annoying Audio"].value)
			{
				// sex
				static auto f = reinterpret_cast<void(*)(int at, int abt)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendPlayPlayerAudioMessage(System.Int32,System.Int32,)"]->methodPointer);
				f(Globals::audioTypeToPlay, Globals::audioBlockTypeToPlay);
			}
		});
	Functions::AddIl2CppTickFunc(0.0f,
		[]()
		{
			static float f = 0.f;
			f += Globals::deltaTime;
			if (f > Globals::StatusIconTimeout && Globals::MiscBools["Status Icon Changing"].value)
			{
				f = 0.0f;
				int d = (rand() % 4) + 1;
				const static auto PlayerNamesManager_UpdateMyStatusIcon1 = reinterpret_cast<void(*)(Il2CppObject * pThis, int/*PlayerNamesManager.StatusIconType*/ icon)>(Globals::Methods["System.Void Assembly-CSharp.PlayerNamesManager.UpdateMyStatusIcon(PlayerNamesManager.StatusIconType,)"]->methodPointer);
				Il2CppObject* playerNamesManager = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "playerNamesManager" });
				PlayerNamesManager_UpdateMyStatusIcon1(playerNamesManager, d);
			}
		});
	Functions::AddIl2CppTickFunc(0.0f,
		[]() 
		{
			static float timout = 0.0f;
			timout += Globals::deltaTime;
			if (timout > Globals::tradeAlltimeout)
			{
				timout = 0.0f;
				if (Globals::MiscBools["Trade All Spam"].value)
				{
					Il2CppObject* otherPlayers = Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
					int otherPlayers_size = Il2Cpp::Lists::il2cpp_list_get_size(otherPlayers);
					for (int i = 0; i < otherPlayers_size; i++)
					{
						Il2CppObject* curNetworkPlayer = Il2Cpp::Lists::il2cpp_list_index<Il2CppObject*>(otherPlayers, i);
						if (curNetworkPlayer)
						{
							Il2CppObject* curPlayer = il2cpp_object_get_field_value_by_name(curNetworkPlayer, Il2CppObject*, curNetworkPlayer->Il2CppClass.klass, "playerScript");//Il2Cpp::Helpers::GetFieldValue<Il2CppObject*>("playerScript", curNetworkPlayer);
							Il2CppObject* playerData = il2cpp_object_get_field_value_by_name(curPlayer, Il2CppObject*, curPlayer->Il2CppClass.klass, "myPlayerData");;
							Il2CppString* id = il2cpp_object_get_field_value_by_name(playerData, Il2CppString*, playerData->Il2CppClass.klass, "playerId");
							reinterpret_cast<void(*)(Il2CppString * s)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.AskTrade(System.String,)"]->methodPointer)(id);
						}
					}
				}
			}
		});
	Functions::AddIl2CppTickFunc(0.1f,
		[]()
		{
			//const static auto BSONObject_Add2 = reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppString */*System.String*/ key, BSONValue */*Kernys.Bson.BSONValue*/ value)>(Globals::Methods["System.Void Assembly-CSharp.BSONObject.Add(System.String,Kernys.Bson.BSONValue,)"]->methodPointer);
			//const static auto OutgoingMessages_AddOneMessageToList1 = reinterpret_cast<void(*)(Il2CppObject */*Kernys.Bson.BSONObject*/ toAdd)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.AddOneMessageToList(Kernys.Bson.BSONObject,)"]->methodPointer);
			//
			//Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
			//for (int i = 0; i < otherPlayers->size; i++)
			//{
			//	NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[rand() % otherPlayers->size];
			//	NetworkPlayer*& curNetworkPlayer2 = otherPlayers->arry->vector[rand() % otherPlayers->size];
			//	if (curNetworkPlayer && curNetworkPlayer2)
			//	{
			//		Il2CppString*& clientId = curNetworkPlayer->clientId;
			//		Il2CppString*& clientId2 = curNetworkPlayer2->clientId;
			//
			//
			//		Il2CppObject* bsonobj = il2cpp_object_new(Globals::Classes["Assembly-CSharp.BSONObject"]);
			//		BSONValue* bsv = (BSONValue*)il2cpp_object_new(Globals::Classes["Assembly-CSharp.BSONValue"]);
			//		bsv->mValueType = BSONValue::ValueType::String;
			//		
			//
			//		bsv->_string = istr("ChatReport");
			//		il2cpp_call_catch_console(BSONObject_Add2(bsonobj, istr("ID"), bsv));
			//		bsv->_string = clientId;
			//		BSONObject_Add2(bsonobj, istr("U"), bsv);
			//		bsv->_string = clientId2;
			//		BSONObject_Add2(bsonobj, istr("TuID"), bsv);
			//		bsv->_string = istr("niggers niggers niggers die");
			//		BSONObject_Add2(bsonobj, istr("msg"), bsv);
			//		bsv->_string = istr("TRADE");
			//		BSONObject_Add2(bsonobj, istr("WN"), bsv);
			//		bsv->_string = istr("Offensive Language");
			//		BSONObject_Add2(bsonobj, istr("ReportReason"), bsv);
			//		bsv->_string = istr("Chat Report");
			//		BSONObject_Add2(bsonobj, istr("ReportAdditionalInfo"), bsv);
			//
			//		OutgoingMessages_AddOneMessageToList1(bsonobj);
			//	}
			//}
			//
			//static float timout = 0.0f;
			//timout += Globals::deltaTime;
			//if (timout > Globals::tradeAlltimeout)
			//{
			//	timout = 0.0f;
			//	if (Globals::MiscBools["Trade All Spam"].value)
			//	{
			//		Il2CppObject* otherPlayers = Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
			//		int otherPlayers_size = Il2Cpp::Lists::il2cpp_list_get_size(otherPlayers);
			//		for (int i = 0; i < otherPlayers_size; i++)
			//		{
			//			Il2CppObject* curNetworkPlayer = Il2Cpp::Lists::il2cpp_list_index<Il2CppObject*>(otherPlayers, i);
			//			if (curNetworkPlayer)
			//			{
			//				Il2CppObject* curPlayer = il2cpp_object_get_field_value_by_name(curNetworkPlayer, Il2CppObject*, curNetworkPlayer->Il2CppClass.klass, "playerScript");//Il2Cpp::Helpers::GetFieldValue<Il2CppObject*>("playerScript", curNetworkPlayer);
			//				Il2CppObject* playerData = il2cpp_object_get_field_value_by_name(curPlayer, Il2CppObject*, curPlayer->Il2CppClass.klass, "myPlayerData");;
			//				Il2CppString* id = il2cpp_object_get_field_value_by_name(playerData, Il2CppString*, playerData->Il2CppClass.klass, "playerId");
			//				reinterpret_cast<void(*)(Il2CppString * s)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.AskTrade(System.String,)"]->methodPointer)(id);
			//			}
			//		}
			//	}
			//}
		});
	Functions::AddIl2CppTickFunc(0.15f,
		[]()
		{
			if (Globals::IsInWorld && Globals::aiAimbot)
			{
				const static auto OutgoingMessages_SendHitAIEnemyMessage3 = reinterpret_cast<void(*)(Vector2i/*BasicTypes.Vector2i*/ mapPoint, int/*System.Int32*/ aiID, int/*System.Int32*/ randomHitTextIndex)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendHitAIEnemyMessage(BasicTypes.Vector2i,System.Int32,System.Int32,)"]->methodPointer);
				Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>* aiEnemiesd = (Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "aiEnemyMonoBehaviours" });
				if (aiEnemiesd)
				{
					AIEnemyMonoBehaviourBase* closestAiEnemy = nullptr;
					float shortestDist = INFINITY;
					Il2CppArrayT<AIEnemyMonoBehaviourBase*>* values = aiEnemiesd->GetValues();
					for (int i = 0; i < values->max_length; i++)
					{
						AIEnemyMonoBehaviourBase* aiEnemy = values->vector[i];
						if (!aiEnemy || !aiEnemy->aiBase)
							continue;

						float dist = Vector2(aiEnemy->tempPosition).Distance(Globals::playerInfo.position);
						const static auto AIEnemyConfigData_GetMaxHitPoints1 = reinterpret_cast<int(*)(int/*AIEnemyType*/ enemyType)>(Globals::Methods["System.Int32 Assembly-CSharp.AIEnemyConfigData.GetMaxHitPoints(AIEnemyType,)"]->methodPointer);
						if (dist < shortestDist && AIEnemyConfigData_GetMaxHitPoints1(aiEnemy->aiBase->enemyType) != 50)
						{
							shortestDist = dist;
							closestAiEnemy = aiEnemy;
						}
					}
					if (closestAiEnemy)
					{
						if (closestAiEnemy->aiBase->health > 0)
							OutgoingMessages_SendHitAIEnemyMessage3(ConvertWorldPointToMapPoint(closestAiEnemy->tempPosition), closestAiEnemy->aiBase->id, 1);
					}
				}
			}
		});
	Functions::AddIl2CppTickFunc(0.15f,
		[]()
		{
			if (Globals::IsInWorld && Globals::MiscBools["Trapbot"].value)
			{
				Il2CppArrayT<Il2CppArrayT<LayerBlock>*>* worldBlocks = (Il2CppArrayT<Il2CppArrayT<LayerBlock>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldBlockLayer" });
				Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>* worldItemBase = (Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldItemsData" });
				Vector2i worldSize = { worldBlocks->max_length, worldBlocks->vector[0]->max_length };

				for (int x = Globals::playerInfo.mapPoint.x - 2; x < Globals::playerInfo.mapPoint.x + 3; x++)
				{
					for (int y = Globals::playerInfo.mapPoint.y - 2; y < Globals::playerInfo.mapPoint.y + 3; y++)
					{
						Vector2i point = { x, y };
						if (InBounds(point, worldSize) && worldItemBase->vector[x]->vector[y])
						{
							WorldItemBase* wib = (WorldItemBase*)worldItemBase->vector[x]->vector[y];
							if (wib->blockType == 956 || wib->blockType == 4551)
							{ 
								bool bef = wib->isAnimationOn;
								wib->isAnimationOn = true;
								hkOutgoingMessages_SendWorldItemUpdateMessage3(point, wib, 0);
								wib->isAnimationOn = bef;
							}
						}
					}
				}
			}
		});

	Globals::otherPlayerTrails.resize(65);

	Discord = DiscordPresence();
}
static bool init = false;
static bool mouseToFly = true;
static float mouseFlySpeed = 7.5f;
static float keysMoveSpeed = 2.0f;
static bool vsync = true;
static bool forntie = true;
static bool fupdate = false;
static std::vector<Vector2i> foundPathThroughBlocks = {};
static std::vector<Vector2i> foundPathToClosestEnemy = {};

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT __stdcall WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
	if (uMsg == 144)
	{
		exit(0);
	}
	if (init)
	{
		if (Globals::ShowMenu)
		{
			if ((ImGui::GetIO().WantCaptureKeyboard || ImGui::GetIO().WantCaptureMouse) && uMsg != WM_KEYUP && uMsg != WM_SYSKEYUP)
				return true;
		}
		if (Globals::IsInWorld)
		{
			if (Globals::ToggleBools["Keys to Fly"].value && Globals::playerStatus != StatusIconType::Typing && Globals::playerStatus != StatusIconType::InMenus)
			{
				switch (uMsg)
				{
				case WM_KEYDOWN:
				case WM_SYSKEYDOWN:
					if (wParam == 'W' || wParam == 'S')
						return false;
				case WM_LBUTTONDOWN:
				case WM_LBUTTONDBLCLK:
				case WM_RBUTTONDOWN:
				case WM_RBUTTONDBLCLK:
				case WM_MBUTTONDOWN:
				case WM_MBUTTONDBLCLK:
				case WM_XBUTTONDOWN:
				case WM_XBUTTONDBLCLK:
				case WM_LBUTTONUP:
				case WM_RBUTTONUP:
				case WM_MBUTTONUP:
				case WM_XBUTTONUP:
				{
					//if (ImGui::GetIO().KeyAlt || ImGui::GetIO().KeyCtrl)
					//	return false;
				}
				}
			}
		}
	}

	
	return CallWindowProc(Globals::oWndProc, hWnd, uMsg, wParam, lParam);
}
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (Globals::DirectXHookHasLocked)
		return Globals::oPresent(pSwapChain, SyncInterval, Flags);
	if (Globals::Ejecting)
	{
		Globals::DirectXHookHasLocked = true;
		return Globals::oPresent(pSwapChain, SyncInterval, Flags);
	}
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&Globals::pDevice)))
		{
			Globals::pDevice->GetImmediateContext(&Globals::pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			Globals::hWnd = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			Globals::pDevice->CreateRenderTargetView(pBackBuffer, NULL, &Globals::mainRenderTargetView);
			pBackBuffer->Release();
			Globals::oWndProc = (WNDPROC)SetWindowLongPtr(Globals::hWnd, GWLP_WNDPROC, (LONG_PTR)WndProc);
			Init();
			init = true;
		}
		else
			return Globals::oPresent(pSwapChain, SyncInterval, Flags);
	}
	il2cpp_thread_attach(il2cpp_domain_get());
	//MonoDomain* domain = mono_get_root_domain();
	//if (domain)
	//{
	//	Mono::gfxThread = mono_thread_attach(domain);
	//}
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGuiIO& io = ImGui::GetIO();
	ImGui::SetNextWindowSize(ImVec2(0, 0));
	ImGui::Begin("DrawList Window", 0, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoInputs);
	ImDrawList* drawList = ImGui::GetWindowDrawList();
	drawList->PushClipRectFullScreen();
	if (io.KeysDownDuration[VK_OEM_3] == 0.f)
	{
		Globals::ShowMenu = !Globals::ShowMenu;
	}
	if (Globals::ShowMenu)
	{
		if (!ImGui::Begin("ArkAngel", &Globals::ShowMenu, ImGuiWindowFlags_MenuBar))
		{
			ImGui::End();
			goto out_if_gsm;
		}
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("Windows"))
			{
				if (ImGui::MenuItem("Console", NULL, &Globals::ShowConsole))
					SaveData::SaveToFile();
				if (ImGui::MenuItem("Player Info", NULL, &Globals::ShowPlayerMenu))
					SaveData::SaveToFile();
				if (ImGui::MenuItem("Minimap", NULL, &Globals::showMinimap))
					SaveData::SaveToFile();
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Misc."))
			{
				if (ImGui::MenuItem("Eject Dll"))
					Globals::Ejecting = true;
				if (ImGui::MenuItem("Force Exit"))
					exit(0);
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
		if (ImGui::BeginTabBar("Menus"))
		{
#ifndef AAPUBLICMODE
			if (ImGui::BeginTabItem("Main"))
			{
				int i = 0;
				for (auto& [key, value] : Globals::BasicsBools)
				{
					if (i > 0)
					{
						imgui_CheckboxAutowrap(key.c_str());
					}
					ImGui::Checkbox(key.c_str(), &value);
					i++;
				}
				if (io.KeysDown[VK_END] && io.KeyCtrl)
				{
					static int buttonClickCounter = 0;
					const char* amogust = "mogus";
					static std::string amogus = "a";
					if (ImGui::Button(amogus.c_str()))
					{
						if (amogus == "amogus")
						{
							Console.AddLog("Amogus Mode Activated");
							const Il2CppClass* TextManager = Globals::Classes["Assembly-CSharp.ConfigData"];
							for (int i = 0; i < TextManager->method_count; i++)
							{
								const MethodInfo* m = TextManager->methods[i];
								if (m->return_type->type == IL2CPP_TYPE_STRING)
								{
									rethook2(m);
								}
							}
							MH_EnableHook(MH_ALL_HOOKS);
						}
						else
							amogus += amogust[buttonClickCounter++];
					}
				}
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("MPE"))
			{
				int i = 0;
				for (auto& [key, value] : Globals::MapPointExploitBools)
				{
					if (i > 0)
					{
						imgui_CheckboxAutowrap(key.c_str());
					}
					ImGui::Checkbox(key.c_str(), &value.value);
					if (value.function != NULL)
					{
						value.function();
					}
					i++;
				}

				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Bots"))
			{
				if (ImGui::BeginTabBar("Bot Menus"))
				{
					if (ImGui::BeginTabItem("Aimbot"))
					{
						ImGui::Checkbox("Aimbot", &Globals::aimbot);
						ImGui::Checkbox("AI/Enemy Aimbot", &Globals::aiAimbot);
						ImGui::Checkbox("Ctrl for Aimbo", &Globals::ctrlForActive);
						ImGui::SliderInt("Aimbot Hit Chance", &Globals::aimbotHitChance, 1, 101);
						ImGui::EndTabItem();
					}
					if (ImGui::BeginTabItem("Mining"))
					{
						int i = 0;
						for (auto& [key, value] : Globals::MiningBools)
						{
							if (i > 0)
							{
								imgui_CheckboxAutowrap(key.c_str());
							}
							ImGui::Checkbox(key.c_str(), &value.value);
							if (value.function != NULL)
							{
								value.function();
							}
							i++;
						}
						ImGui::EndTabItem();
					}
					if (ImGui::BeginTabItem("Nether"))
					{
						ImGui::Checkbox("Auto-Nether", &Globals::autoNether);
						ImGui::EndTabItem();
					}
					if (ImGui::BeginTabItem("Fishing"))
					{
						int i = 0;
						for (auto& [key, value] : Globals::FishingBools)
						{
							if (i > 0)
							{
								imgui_CheckboxAutowrap(key.c_str());
							}
							ImGui::Checkbox(key.c_str(), &value);
							i++;
						}


						float sum = 0.f;
						float fMaxval = 0.f;
						for (int i = 0; i < fishTimingGraph.size(); i++)
						{
							if (fishTimingGraph[i] > fMaxval)
								fMaxval = fishTimingGraph[i];
							sum += fishTimingGraph[i];
						}
						float avg = sum / (float)fishTimingGraph.size();

						if (ImPlot::BeginPlot("Fish Timing Graph"))
						{
							ImPlot::PlotLine<double>("Time", fishTimingGraph.data(), fishTimingGraph.size(), 1.0);
							ImPlot::PlotHLines("Average", &avg, 1);
							ImPlot::EndPlot();
						}
						ImGui::EndTabItem();
					}
					ImGui::EndTabBar();
				}
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Misc"))
			{
				int i = 0;
				for (auto& [key, value] : Globals::MiscBools)
				{
					if (i > 0)
					{
						imgui_CheckboxAutowrap(key.c_str());
					}
					ImGui::Checkbox(key.c_str(), &value.value);
					if (value.function != NULL)
					{
						value.function();
					}
					i++;
				}
				if (ImGui::Button("Force Logout"))
				{
					Functions::AddIl2CppFunctionCall(
						[]()
						{
							Globals::Methods["System.Void Assembly-CSharp.UserIdent.LogOut()"]->methodPointer();
							Globals::Methods["System.Void Assembly-CSharp.SceneLoader.GoToWelcomeScene()"]->methodPointer();

						});
				}
				ImGui::Checkbox("Vsync", &vsync);
				ImGui::Checkbox("Player Play Static Anim", &Globals::playerPlayStaticAnim);
				if (ImGui::Button("Trade All"))
				{
					Functions::AddIl2CppFunctionCall(
						[]()
						{
							Il2CppObject* otherPlayers = Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
							int otherPlayers_size = Il2Cpp::Lists::il2cpp_list_get_size(otherPlayers);
							for (int i = 0; i < otherPlayers_size; i++)
							{
								Il2CppObject* curNetworkPlayer = Il2Cpp::Lists::il2cpp_list_index<Il2CppObject*>(otherPlayers, i);
								if (curNetworkPlayer)
								{
									Il2CppObject* curPlayer = il2cpp_object_get_field_value_by_name(curNetworkPlayer, Il2CppObject*, curNetworkPlayer->Il2CppClass.klass, "playerScript");//Il2Cpp::Helpers::GetFieldValue<Il2CppObject*>("playerScript", curNetworkPlayer);
									Il2CppObject* playerData = il2cpp_object_get_field_value_by_name(curPlayer, Il2CppObject*, curPlayer->Il2CppClass.klass, "myPlayerData");;
									Il2CppString* id = il2cpp_object_get_field_value_by_name(playerData, Il2CppString*, playerData->Il2CppClass.klass, "playerId");
									reinterpret_cast<void(*)(Il2CppString * s)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.AskTrade(System.String,)"]->methodPointer)(id);
								}
							}
						});
					
				}
				ImGui::DragFloat("Minimap Zoom", &Globals::minimapZoomAmount, 0.1);
				//if (ImGui::Button("Rpc Init"))
				//{
				//	
				//}
				//if (dinit && ImGui::Button("Update RPC"))
				//{
				//	updateDiscordPresence();
				//}
				if (ImGui::Button("Shutdown RPC"))
				{
					Discord_Shutdown();
				}
				//Il2CppObject* kukouriCamera = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "kukouriCamera" });
				//Transform* myTransform = (Transform*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "kukouriCamera", "myTransform" });
				//// myTransform = KukouriCamera.myTransform
				//Vector3 rot = myTransform->GetPosition();
				//if (ImGui::DragFloat3("Camera Rotation", &rot.x))
				//{
				//	myTransform->SetPosition(rot);
				//}
				//static std::string s = "";
				//ImGui::InputText("string hashing", &s);
				//unsigned int sh = ComputeStringHash(s.c_str());
				//ImGui::Text("%u", sh);
				if (Globals::IsInWorld)
				{
					const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
					Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
					Il2CppArrayT<int>* hotspots = localPlayer->myPlayerData->hotSpotsBlockTypes;
					const static auto OutgoingMessages_SendWearableOrWeaponUndress1 = reinterpret_cast<void(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendWearableOrWeaponUndress(World.BlockType,)"]->methodPointer);
					const static auto OutgoingMessages_SendWearableChange2 = reinterpret_cast<void(*)(int/*System.Int32*/ hotSpotIndex, int/*World.BlockType*/ blockType)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendWearableChange(System.Int32,World.BlockType,)"]->methodPointer);
					static int indexToChange = 0;
					static int blocktypeToChange = 0;

					for (int i = 0; i < hotspots->max_length; i++)
					{
						if (ImGui::Button(string_printf("Wearable Change (%i)%s", i, Il2Cpp::Enums::EnumToString(c, hotspots->vector[i]).c_str()).c_str()))
						{
							indexToChange = i;
							blocktypeToChange = hotspots->vector[i];
							Functions::AddIl2CppFunctionCall([]() { OutgoingMessages_SendWearableOrWeaponUndress1(blocktypeToChange); });
						}
					}
				}
				

				//static bool testl = false;
				//ImGui::Checkbox("testl", &testl);
				//if (testl && Globals::IsInWorld)
				//{
				//	Il2CppList* otherPlayers = (Il2CppList*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
				//	for (int i = 0; i < otherPlayers->size; i++)
				//	{
				//		ImGui::Text("%p", il2cpp_list_get(otherPlayers, Il2CppObject*, i));
				//	}
				//}
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("ESP"))
			{
				int i = 0;
				for (auto& [key, value] : Globals::EspBools)
				{
					if (i > 0)
					{
						imgui_CheckboxAutowrap(key.c_str());
					}
					ImGui::Checkbox(key.c_str(), &value.value);
					if (value.function != NULL)
					{
						value.function();
					}
					i++;
				}
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Mono"))
			{
				static std::string openPath = "";
				if (ImGui::Button("Init Mono"))
				{
					Functions::AddIl2CppFunctionCall([]() { if (!mono_domain_get()) { Mono::InitMono(); } });
					
				}
				ImGui::InputText("Assembly to Open", &openPath);
				if (ImGui::Button("Run File"))
				{
					Functions::AddIl2CppFunctionCall([]() { Mono::RunMonoFile(openPath); });
				}
				if (ImGui::Button("Close Assemblies"))
				{
					Functions::AddIl2CppFunctionCall([]() { Mono::ReInitMono(); });
				}
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Items"))
			{
				static std::string itemSearch = "";
				const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
				const static auto PlayerData_AddItemToInventory2 = reinterpret_cast<void(*)(PlayerData * pThis, InventoryKey/*PlayerData.InventoryKey*/ ik, Il2CppObject */*InventoryItemBase*/ inventoryData)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.AddItemToInventory(PlayerData.InventoryKey,InventoryItemBase,)"]->methodPointer);
				const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);
				ImGui::InputText("Item Search", &itemSearch);
				bool itemSearchEmpty = itemSearch.empty();


				PlayerData* localPlayerData = nullptr;
				if (Globals::IsInWorld)
				{
					localPlayerData = (PlayerData*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });
				}


				for (int i = 1; i < c->field_count - 1; i++)
				{
					bool includeItem = false;
					if (itemSearchEmpty)
						includeItem = true;
					else if (strstr(c->fields[i].name, itemSearch.c_str()))
					{
						includeItem = true;
					}
					if (includeItem && ImGui::Selectable(c->fields[i].name))
					{
						InventoryKey ik;
						ik.blockType = i - 1;
						ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(ik.blockType);
						if (localPlayerData)
							PlayerData_AddItemToInventory2(localPlayerData, ik, nullptr);
					}
				}
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Build Menu"))
			{
				static std::vector<Vector2i> blockPositions =
				{
					 {2, -2}, {1, -2}, {0, -2}, {-1, -2}, {-2, -2},
					 {2, -1}, {1, -1}, {0, -1}, {-1, -1}, {-2, -1},
					 {2,  0}, {1,  0}, {0,  0}, {-1,  0}, {-2,  0},
					 {2,  1}, {1,  1}, {0,  1}, {-1,  1}, {-2,  1},
					 {2,  2}, {1,  2}, {0,  2}, {-1,  2}, {-2,  2},
				};
				static std::vector<bool> onBlocks = 
				{
					false, false, false, false, false,
					false, false, false, false, false,
					false, false, false, false, false,
					false, false, false, false, false,
					false, false, false, false, false,
				};
				if (ImGui::Button("Build"))
				{
					Functions::AddIl2CppFunctionCall([]()
						{
							if (!Globals::IsInWorld)
								return;
							// PlayerData.InventoryKey ik = new PlayerData.InventoryKey(worldController.currentSelectedBlockType, ControllerHelper.gameplayUI.inventoryControl.GetCurrentSelection().itemType);
							const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
							Il2CppObject* worldController = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController" });
							InventoryControl* inventoryControl = (InventoryControl*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "gameplayUI", "inventoryControl" });
							Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
							const static auto InventoryControl_GetCurrentSelection0 = reinterpret_cast<InventoryKey(*)(InventoryControl * pThis)>(Globals::Methods["PlayerData.InventoryKey Assembly-CSharp.InventoryControl.GetCurrentSelection()"]->methodPointer);
							static auto PlayerData_GetCount = reinterpret_cast<short(*)(PlayerData * pThis, InventoryKey ik)>(Globals::Methods["System.Int16 Assembly-CSharp.PlayerData.GetCount(PlayerData.InventoryKey,)"]->methodPointer);
							const static auto OutgoingMessages_RecycleFish2 = reinterpret_cast<void(*)(InventoryKey/*PlayerData.InventoryKey*/ fishIK, short/*System.Int16*/ amount)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.RecycleFish(PlayerData.InventoryKey,System.Int16,)"]->methodPointer);
							const static auto PlayerData_RemoveItemsFromInventory2 = reinterpret_cast<void(*)(PlayerData * pThis, InventoryKey/*PlayerData.InventoryKey*/ inventoryKey, short/*System.Int16*/ amount)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.RemoveItemsFromInventory(PlayerData.InventoryKey,System.Int16,)"]->methodPointer);
							// what is this bullshit
							// l 1
							// amongus is super sussy 1mao
							const static auto WorldController_SetBlockWithTool3 = reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*World.BlockType*/ blockType, Vector2i/*BasicTypes.Vector2i*/ mapPoint, float/*System.Single*/ timeToWait)>(Globals::Methods["System.Boolean Assembly-CSharp.WorldController.SetBlockWithTool(World.BlockType,BasicTypes.Vector2i,System.Single,)"]->methodPointer);
							const static auto WorldController_SetBlockWaterWithTool3 = reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*World.BlockType*/ blockType, Vector2i/*BasicTypes.Vector2i*/ mapPoint, float/*System.Single*/ timeToWait)>(Globals::Methods["System.Boolean Assembly-CSharp.WorldController.SetBlockWaterWithTool(World.BlockType,BasicTypes.Vector2i,System.Single,)"]->methodPointer);
							const static auto WorldController_SetBlockBackgroundWithTool3 = reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*World.BlockType*/ blockBackgroundType, Vector2i/*BasicTypes.Vector2i*/ mapPoint, float/*System.Single*/ timeToWait)>(Globals::Methods["System.Boolean Assembly-CSharp.WorldController.SetBlockBackgroundWithTool(World.BlockType,BasicTypes.Vector2i,System.Single,)"]->methodPointer);
							const static auto WorldController_SetSeedWithTool3 = reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*World.BlockType*/ blockType, Vector2i/*BasicTypes.Vector2i*/ mapPoint, float/*System.Single*/ timeToWait)>(Globals::Methods["System.Boolean Assembly-CSharp.WorldController.SetSeedWithTool(World.BlockType,BasicTypes.Vector2i,System.Single,)"]->methodPointer);
							InventoryKey ik = InventoryControl_GetCurrentSelection0(inventoryControl);
							for (int i = 0; i < blockPositions.size(); i++)
							{
								if (onBlocks[i] && PlayerData_GetCount(localPlayer->myPlayerData, ik) > 0)
								{
									bool removeFromInventory = false;
									switch (ik.itemType)
									{
										// block
									case 0:
										removeFromInventory = WorldController_SetBlockWithTool3(worldController, ik.blockType, Vector2i{ localPlayer->currentPlayerMapPoint.x - blockPositions[i].x, localPlayer->currentPlayerMapPoint.y - blockPositions[i].y }, 0.0f);
										break;
										// background
									case 1:
										removeFromInventory = WorldController_SetBlockBackgroundWithTool3(worldController, ik.blockType, Vector2i{ localPlayer->currentPlayerMapPoint.x - blockPositions[i].x, localPlayer->currentPlayerMapPoint.y - blockPositions[i].y }, 0.0f);
										break;
										// seed
									case 2:
										removeFromInventory = WorldController_SetSeedWithTool3(worldController, ik.blockType, Vector2i{ localPlayer->currentPlayerMapPoint.x - blockPositions[i].x, localPlayer->currentPlayerMapPoint.y - blockPositions[i].y }, 0.0f);
										break;
										// water
									case 3:
										removeFromInventory = WorldController_SetBlockWaterWithTool3(worldController, ik.blockType, Vector2i{ localPlayer->currentPlayerMapPoint.x - blockPositions[i].x, localPlayer->currentPlayerMapPoint.y - blockPositions[i].y }, 0.0f);
										break;
									default:
										break;
									}
									if (removeFromInventory)
									{
										PlayerData_RemoveItemsFromInventory2(localPlayer->myPlayerData, ik, 1);
									}
								}
							}
						});
				}
				if (ImGui::Button("Hit"))
				{
					Functions::AddIl2CppFunctionCall([]()
						{
							if (!Globals::IsInWorld)
								return;
							// PlayerData.InventoryKey ik = new PlayerData.InventoryKey(worldController.currentSelectedBlockType, ControllerHelper.gameplayUI.inventoryControl.GetCurrentSelection().itemType);
							const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
							Il2CppObject* worldController = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController" });
							InventoryControl* inventoryControl = (InventoryControl*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "gameplayUI", "inventoryControl" });
							Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
							const static auto WorldController_SetBlockWithTool3 = reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*World.BlockType*/ blockType, Vector2i/*BasicTypes.Vector2i*/ mapPoint, float/*System.Single*/ timeToWait)>(Globals::Methods["System.Boolean Assembly-CSharp.WorldController.SetBlockWithTool(World.BlockType,BasicTypes.Vector2i,System.Single,)"]->methodPointer);
							const static auto WorldController_SetBlockWaterWithTool3 = reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*World.BlockType*/ blockType, Vector2i/*BasicTypes.Vector2i*/ mapPoint, float/*System.Single*/ timeToWait)>(Globals::Methods["System.Boolean Assembly-CSharp.WorldController.SetBlockWaterWithTool(World.BlockType,BasicTypes.Vector2i,System.Single,)"]->methodPointer);
							const static auto WorldController_SetBlockBackgroundWithTool3 = reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*World.BlockType*/ blockBackgroundType, Vector2i/*BasicTypes.Vector2i*/ mapPoint, float/*System.Single*/ timeToWait)>(Globals::Methods["System.Boolean Assembly-CSharp.WorldController.SetBlockBackgroundWithTool(World.BlockType,BasicTypes.Vector2i,System.Single,)"]->methodPointer);
							const static auto WorldController_SetSeedWithTool3 = reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*World.BlockType*/ blockType, Vector2i/*BasicTypes.Vector2i*/ mapPoint, float/*System.Single*/ timeToWait)>(Globals::Methods["System.Boolean Assembly-CSharp.WorldController.SetSeedWithTool(World.BlockType,BasicTypes.Vector2i,System.Single,)"]->methodPointer);
							const static auto OutgoingMessages_SendHitBlockMessage3 = reinterpret_cast<void(*)(Vector2i/*BasicTypes.Vector2i*/ mapPoint, DateTime/*System.DateTime*/ hitTime, bool/*System.Boolean*/ doNotDestroy)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendHitBlockMessage(BasicTypes.Vector2i,System.DateTime,System.Boolean,)"]->methodPointer);
							Il2CppArrayT<Il2CppArrayT<LayerBlock>*>* worldBlocks = (Il2CppArrayT<Il2CppArrayT<LayerBlock>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldBlockLayer" });
							for (int i = 0; i < blockPositions.size(); i++)
							{
								if (onBlocks[i])
								{
									Vector2i pos{ localPlayer->currentPlayerMapPoint.x - blockPositions[i].x, localPlayer->currentPlayerMapPoint.y - blockPositions[i].y };
									int hitsRequired = 1 + worldBlocks->vector[pos.x]->vector[pos.y].hitsRequired / 200;

									for (int x = 0; x < hitsRequired; x++)
										OutgoingMessages_SendHitBlockMessage3(pos, DateTime{ 0 }, false);
									//bool removeFromInventory = false;
									//switch (ik.itemType)
									//{
									//	// block
									//case 0:
									//	removeFromInventory = WorldController_SetBlockWithTool3(worldController, ik.blockType, Vector2i{ localPlayer->currentPlayerMapPoint.x - blockPositions[i].x, localPlayer->currentPlayerMapPoint.y - blockPositions[i].y }, 0.0f);
									//	break;
									//	// background
									//case 1:
									//	removeFromInventory = WorldController_SetBlockBackgroundWithTool3(worldController, ik.blockType, Vector2i{ localPlayer->currentPlayerMapPoint.x - blockPositions[i].x, localPlayer->currentPlayerMapPoint.y - blockPositions[i].y }, 0.0f);
									//	break;
									//	// seed
									//case 2:
									//	removeFromInventory = WorldController_SetSeedWithTool3(worldController, ik.blockType, Vector2i{ localPlayer->currentPlayerMapPoint.x - blockPositions[i].x, localPlayer->currentPlayerMapPoint.y - blockPositions[i].y }, 0.0f);
									//	break;
									//	// water
									//case 3:
									//	removeFromInventory = WorldController_SetBlockWaterWithTool3(worldController, ik.blockType, Vector2i{ localPlayer->currentPlayerMapPoint.x - blockPositions[i].x, localPlayer->currentPlayerMapPoint.y - blockPositions[i].y }, 0.0f);
									//	break;
									//default:
									//	break;
									//}
									//if (removeFromInventory)
									//{
									//	PlayerData_RemoveItemsFromInventory2(localPlayer->myPlayerData, ik, 1);
									//}
								}
							}
						});
				}


				for (int y = 0; y < 5; y++)
				{
					for (int x = 0; x < 5; x++)
					{
						bool on = onBlocks[x + y * 5];
						if (on)
						{
							ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0, 1, 0, 1 });
							ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3, 0.7, 0.3, 1 });
							ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.5, 0.8, 0.5, 1 });
						}
						if (ImGui::Button(string_printf("##%i", x + y * 5).c_str(), ImVec2{ 50, 50 }))
						{
							onBlocks[x + y * 5] = !onBlocks[x + y * 5];
						}
						if (on)
							ImGui::PopStyleColor(3);
						ImGui::SameLine();
					}
					ImGui::NewLine();
				}
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Item PWE Value"))
			{
				static int v = -1;
				static bool hasData = false;
				const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
				ImVec2 winSize = ImGui::GetContentRegionMax();
				winSize.x *= 0.7;
				winSize.y *= 0.7;
				if (ImGui::InputInt("Item Value to Get", &v))
				{
					hasData = false;
					Functions::AddIl2CppFunctionCall(
						[]() 
						{
							const static auto OutgoingMessages_SendGetItemAuctionHousePriceHistory1 = reinterpret_cast<void(*)(InventoryKey/*PlayerData.InventoryKey*/ ik)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendGetItemAuctionHousePriceHistory(PlayerData.InventoryKey,)"]->methodPointer);

							const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
							const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);

							InventoryKey ik;
							ik.blockType = v;
							ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(v);
							if (v > 0)
							{
								OutgoingMessages_SendGetItemAuctionHousePriceHistory1(ik);
								isWaitingForNextAHh = true;
							}
						});
					
				}
				if (ImGui::Button("test"))
				{
					const static auto OutgoingMessages_SendFulfillAuctionHouseOrder2 = reinterpret_cast<void(*)(InventoryKey/*PlayerData.InventoryKey*/ ik, long long/*System.Int64*/ creationTimestamp)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendFulfillAuctionHouseOrder(PlayerData.InventoryKey,System.Int64,)"]->methodPointer);
					InventoryKey ik;
					ik.blockType = 1;
					ik.itemType = 2;
					OutgoingMessages_SendFulfillAuctionHouseOrder2(ik, 637660299034662670);
				}
				if (ImGui::Begin("Pricing View"))
				{
					if (!hasRecievedNextAHh && isWaitingForNextAHh)
					{
						hasData = false;
						ImGui::Text("Loading");
					}
					else if (hasRecievedNextAHh)
					{
						hasData = true;
						hasRecievedNextAHh = false;
					}
					if (hasData)
					{
						ImGui::Text("Item Pricing For %s", Il2Cpp::Enums::EnumToString(c, nextRecievedData.ik.blockType).c_str());
						
						float sum = 0.f;
						float fMaxval = 0.f;
						for (int i = 0; i < nextRecievedData.RecentPrices.size(); i++)
						{
							if (nextRecievedData.RecentPrices[i] > fMaxval)
								fMaxval = nextRecievedData.RecentPrices[i];
							sum += nextRecievedData.RecentPrices[i];
						}
						float avg = sum / (float)nextRecievedData.RecentPrices.size();

						//ImPlot::SetNextPlotLimitsY(0, fMaxval + fMaxval / 3, ImGuiCond_Always);
						if (ImPlot::BeginPlot("My Plot"))
						{
							
							ImPlot::PlotLine<float>("Price", nextRecievedData.RecentPrices.data(), nextRecievedData.RecentPrices.size(), 1.0);
							ImPlot::PlotHLines("Average", &avg, 1);
							ImPlot::EndPlot();
						}
						//ImGui::PlotLines("Pricing", nextRecievedData.RecentPrices.data(), nextRecievedData.RecentPrices.size(), 0, (const char*)0, FLT_MAX, FLT_MAX, winSize);
					}

					if (itemPriceDatas.size() > 0)
					{
						
						if (ImPlot::BeginPlot("My Plot"))
						{
							std::string s = "";

							for (int i = 0; i < itemPriceDatas.size(); i++)
							{
								AuctionHouseItemPrice cur = itemPriceDatas[i];
								if (cur.RecentPrices.size() == 0)
									continue;
								s = "##" + Il2Cpp::Enums::EnumToString(c, cur.ik.blockType) + std::to_string(i);
								ImPlot::PlotLine(s.c_str(), cur.RecentPrices.data(), cur.RecentPrices.size());
							}
							ImPlot::EndPlot();
						}
					}
				}
				ImGui::End();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Discord RPC"))
			{
				int i = 0;
				for (auto& [key, value] : Globals::DiscordRPCBools)
				{
					if (i > 0)
					{
						imgui_CheckboxAutowrap(key.c_str());
					}
					if (ImGui::Checkbox(key.c_str(), &value))
					{
						static Il2CppClass* nwClient = il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", "NetworkClient");
						static int currentWorldOffset = il2cpp_class_get_field_from_name(nwClient, "currentWorld")->offset;

						static Il2CppClass* staticPlayer = il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", "StaticPlayer");
						static int theRealPlayernameOffset = il2cpp_class_get_field_from_name(staticPlayer, "theRealPlayername")->offset;

						std::string playerName = cppstr(il2cpp_object_get_field_value_by_offset(staticPlayer->static_fields, Il2CppString*, theRealPlayernameOffset));
						std::string currentWorld = cppstr(il2cpp_object_get_field_value_by_offset(nwClient->static_fields, Il2CppString*, currentWorldOffset));


						Discord.CurrentPlayerName = playerName;
						Discord.CurrentWorld = currentWorld;

						if (Globals::IsInWorld)
						{
							Il2CppList<Il2CppObject*>* otherPlayers = (Il2CppList<Il2CppObject*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
							Discord.CurrentPlayerCount = otherPlayers->size + 1;
						}
						Discord.UpdatePresence();
					}
					i++;
				}
				if (ImGui::Button("Shutdown"))
				{
					Discord.Shutdown();
				}
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Flight"))
			{
				ImGui::Checkbox("Middle Click to fly", &mouseToFly);
				ImGui::SliderFloat("Flight Speed", &mouseFlySpeed, 1.f, 50.f);
				ImGui::Checkbox("Keys to Fly", &Globals::ToggleBools["Keys to Fly"].value);
				ImGui::SliderFloat("Keys Flight Speed", &keysMoveSpeed, 0.1f, 9.f);
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Test"))
			{
				ImGui::Text("pn: %s\nworld: %s\n:id: %s\n", Globals::playerInfo.name.c_str(), Globals::playerInfo.worldName.c_str(), Globals::playerInfo.id.c_str());
				ImGui::EndTabItem();
			}
#endif
			ImGui::EndTabBar();
		}
		ImGui::End();
	out_if_gsm:;

#ifndef AAPUBLICMODE
		if (Globals::ShowConsole)
		{
			aa_DrawConsole(&Globals::ShowConsole);
		}
		if (Globals::ShowPlayerMenu)
		{
			if (!ImGui::Begin("Player Info", &Globals::ShowPlayerMenu))
			{
				ImGui::End();
				goto out_if_gsm2;
			}

			static std::unordered_map<std::string, bool> droppedPlayerIds = {};
			static std::unordered_map<std::string, bool> excludedPlayerIds = {};
			static std::unordered_map<std::string, bool> droppedPlayerDatas = {};
			static std::string playerSearch = "";
			if (Globals::IsInWorld)
			{
				ImGui::InputText("Filter", &playerSearch);
				if (ImGui::Button("Summon All"))
				{
					Functions::AddIl2CppFunctionCall(
						[]() 
						{
							const static auto OutgoingMessages_SummonPlayerToLocation1 = reinterpret_cast<void(*)(Il2CppString*/*System.String*/ warpedPlayerId)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SummonPlayerToLocation(System.String,)"]->methodPointer);
							Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
							int sc = 0;
							for (int i = 0; sc < std::min(otherPlayers->size, 5) && i < otherPlayers->size; i++)
							{
								NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[i];
								if (curNetworkPlayer)
								{
									Il2CppString*& clientId = curNetworkPlayer->clientId;
									if (excludedPlayerIds[cppstr(clientId)]/*"8TC5JJCR"*/)
										continue;
									sc++;
									OutgoingMessages_SummonPlayerToLocation1(clientId);
								}
							}
						});
				}
				ImGui::SameLine();
				if (ImGui::Button("Kick All"))
				{
					Functions::AddIl2CppFunctionCall(
						[]()
						{
							const static auto OutgoingMessages_KickPlayer1 = reinterpret_cast<void(*)(Il2CppString*/*System.String*/ kickTargetId)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.KickPlayer(System.String,)"]->methodPointer);
							Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
							int sc = 0;
							for (int i = 0; i < otherPlayers->size ; i++)
							{
								NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[i];
								if (curNetworkPlayer)
								{
									Il2CppString*& clientId = curNetworkPlayer->clientId;
									if (excludedPlayerIds[cppstr(clientId)]/*"8TC5JJCR"*/)
										continue;
									OutgoingMessages_KickPlayer1(clientId);
								}
							}
						});
				}
				ImGui::SameLine();
				if (ImGui::Button("Ban All"))
				{
					Functions::AddIl2CppFunctionCall(
						[]()
						{
							const static auto OutgoingMessages_BanAndKickPlayer1 = reinterpret_cast<void(*)(Il2CppString*/*System.String*/ banAndkickTargetId)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.BanAndKickPlayer(System.String,)"]->methodPointer);
							Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
							for (int i = 0; i < otherPlayers->size; i++)
							{
								NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[i];
								if (curNetworkPlayer)
								{
									Il2CppString*& clientId = curNetworkPlayer->clientId;
									if (excludedPlayerIds[cppstr(clientId)]/*"8TC5JJCR"*/)
										continue;
									OutgoingMessages_BanAndKickPlayer1(clientId);
								}
							}
						});
				}
				Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
				Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });

				Vector2i playerMapPoint = il2cpp_object_get_field_value_by_name(localPlayer, Vector2i, localPlayer->Il2CppClass.klass, "currentPlayerMapPoint");//Il2Cpp::Helpers::GetFieldValue<Vector2i>("currentPlayerMapPoint", localPlayer);
				Vector2 boxSize = il2cpp_object_get_field_value_by_name(localPlayer, Vector2, localPlayer->Il2CppClass.klass, "playerBoxColliderSize"); //Il2Cpp::Helpers::GetFieldValue<Vector2>("playerBoxColliderSize", localPlayer);

				Vector2i screenPointOfLocalPlayer = WorldToScreen(Globals::playerInfo.position);
				Vector2 worldPointOfMouse = ScreenToWorld(Globals::MousePos);
				Vector2i mapPointOfMouse = ConvertWorldPointToMapPoint(worldPointOfMouse);
				Vector2i playerBoxSize = ScaleToScreen(boxSize);
				playerBoxSize.x /= 2;

				
 
				for (int i = 0; i < otherPlayers->size; i++)
				{
					NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[i];
					if (curNetworkPlayer)
					{
						Player* curPlayer = curNetworkPlayer->playerScript;
						Il2CppString*& name = curNetworkPlayer->name;
						Il2CppString*& clientId = curNetworkPlayer->clientId;
						std::string sname = string_Utf16ToUtf8(name);
						std::string sclientId = string_Utf16ToUtf8(clientId);

						if (!playerSearch.empty() && string_ToLowercase(sname).find(string_ToLowercase(playerSearch)) == -1)
							continue;
						bool playerIsDropped = droppedPlayerIds[sclientId];
						bool playerIsExcluded = excludedPlayerIds[sclientId];
						ImGui::PushID(i + 100);

						if (playerIsExcluded)
							ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_Text, ImVec4(1, 0.1, 0.1, 0.9));
						if (ImGui::SelectableFormatted("%s", !playerIsDropped ? ">" : "v"))
						{
							if (io.KeyCtrl)
								excludedPlayerIds[sclientId] = !excludedPlayerIds[sclientId];
							else
							droppedPlayerIds[sclientId] = !droppedPlayerIds[sclientId];
						}
						ImGui::PopID();

						ImGui::PushID(i + 200);
						ImGui::SameLine();
						if (ImGui::Selectable(sname.c_str()))
						{
							if (io.KeyCtrl)
								excludedPlayerIds[sclientId] = !excludedPlayerIds[sclientId];
							else
								droppedPlayerIds[sclientId] = !droppedPlayerIds[sclientId];
						}
						if (playerIsExcluded)
							ImGui::PopStyleColor();

						ImGui::PopID();

						if (playerIsDropped)
						{
							ImGui::Indent(20.f);
							{
								
								if (ImGui::Button("Summon Player"))
								{
									static std::string summonId = "";
									summonId = sclientId;
									Functions::AddIl2CppFunctionCall(
										[]()
										{
											const static auto OutgoingMessages_SummonPlayerToLocation1 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ warpedPlayerId)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SummonPlayerToLocation(System.String,)"]->methodPointer);
											OutgoingMessages_SummonPlayerToLocation1(istr(summonId.c_str()));
										});
								}
								ImGui::SameLine();
								if (ImGui::Button("Kick Player"))
								{
									static std::string kickId = "";
									kickId = sclientId;
									Functions::AddIl2CppFunctionCall(
										[]()
										{
											const static auto OutgoingMessages_KickPlayer1 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ kickTargetId)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.KickPlayer(System.String,)"]->methodPointer);
											OutgoingMessages_KickPlayer1(istr(kickId.c_str()));
										});
								}
								ImGui::SameLine();
								if (ImGui::Button("Ban Player"))
								{
									static std::string banId = "";
									banId = sclientId;
									Functions::AddIl2CppFunctionCall(
										[]()
										{
											const static auto OutgoingMessages_BanAndKickPlayer1 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ banAndkickTargetId)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.BanAndKickPlayer(System.String,)"]->methodPointer);
											OutgoingMessages_BanAndKickPlayer1(istr(banId.c_str()));
										});
								}
								ImGui::SameLine();
								if (ImGui::Button("Swastika Player"))
								{
									if (Globals::playeridtoswas.empty())
									{
										Globals::playeridtoswas = sclientId;
									}
									else Globals::playeridtoswas = "";
								}
								if (ImGui::SelectableFormatted("Name: %s", sname.c_str())) ImGui::SetClipboardText(sname.c_str());
								if (ImGui::SelectableFormatted("Client ID: %s", sclientId.c_str())) ImGui::SetClipboardText(sclientId.c_str());

								bool playerDataIsDropped = droppedPlayerDatas[sclientId];
								ImGui::PushID(i + 200);
								if (ImGui::SelectableFormatted("%s", !playerDataIsDropped ? ">" : "v"))
									droppedPlayerDatas[sclientId] = !droppedPlayerDatas[sclientId];
								ImGui::PopID();

								ImGui::PushID(i + 300);
								ImGui::SameLine();
								if (ImGui::SelectableFormatted("Player Data"))
									droppedPlayerDatas[sclientId] = !droppedPlayerDatas[sclientId];
								ImGui::PopID();


								if (playerDataIsDropped)
								{
									ImGui::Indent(20.0f);
									{
										const Il2CppClass* cls = Globals::Classes["Assembly-CSharp.AdminStatus"];
										int gemCount = curPlayer->myPlayerData->gems.get();
										int bcCount = curPlayer->myPlayerData->bc.get();
										if (ImGui::SelectableFormatted("Gem Count: %i", gemCount)) ImGui::SetClipboardText(std::to_string(gemCount).c_str());
										if (ImGui::SelectableFormatted("BC Count: %i", bcCount)) ImGui::SetClipboardText(std::to_string(bcCount).c_str());

										//std::string adminStatusToString = Il2Cpp::Enums::EnumToString(cls, curPlayer->myPlayerData->playerAdminStatus);
										//if (ImGui::SelectableFormatted("Player Admin Status: %s", adminStatusToString.c_str())) ImGui::SetClipboardText(adminStatusToString.c_str());
										//ImGui::SelectableFormatted("Admin is Ignoring Portals: %s", curPlayer->myPlayerData->adminIsIgnoringPortals ? "True" : "False");
										//ImGui::SelectableFormatted("Admin is Showing Kick Ban Info: %s", curPlayer->myPlayerData->adminIsShowingKickBanInfo ? "True" : "False");
										//ImGui::SelectableFormatted("Admin is Wants to be Summoned: %s", curPlayer->myPlayerData->adminWantsToBeSummoned ? "True" : "False");
										//ImGui::SelectableFormatted("Admin is Wants to Edit World: %s", curPlayer->myPlayerData->adminWantsToEditWorld ? "True" : "False");
										//ImGui::SelectableFormatted("Admin is Wants to go Ghost Mode: %s", curPlayer->myPlayerData->adminWantsToGoGhostMode ? "True" : "False");
										//ImGui::SelectableFormatted("Admin is Wants to go Noob Mode: %s", curPlayer->myPlayerData->adminWantsToGoNoobMode ? "True" : "False");
										//ImGui::SelectableFormatted("Admin is Wants to go Through Doors: %s", curPlayer->myPlayerData->adminWantsToGoThroughDoors ? "True" : "False");
										//ImGui::SelectableFormatted("Admin is Wants to go Undercover Mode: %s", curPlayer->myPlayerData->adminWantsToGoUndercoverMode ? "True" : "False");
										//ImGui::SelectableFormatted("Admins Name on UndercoverMode: %s", string_Utf16ToUtf8(curPlayer->myPlayerData->adminsNameOnUndercoverMode).c_str());
										//ImGui::SelectableFormatted("Mod is Wants to go Through Doors: %s", curPlayer->myPlayerData->modWantsToGoThroughDoors ? "True" : "False");
										//ImGui::SelectableFormatted("Mod Used Teleport During Session: %s", curPlayer->myPlayerData->modUsedTeleportDuringSession ? "True" : "False");
										//ImGui::SelectableFormatted("Is Trusted Player: %s", curPlayer->myPlayerData->isTrustedPlayer ? "True" : "False");
										//ImGui::SelectableFormatted("Name change Counter: %i", curPlayer->myPlayerData->nameChangeCounter);
									}
									ImGui::Indent(-20.0f);
								}
							}
							ImGui::Indent(-20.f);
						}

					}
				}




				//Il2CppArrayT<Il2CppArrayT<LayerBlock>*>* worldBlocks = (Il2CppArrayT<Il2CppArrayT<LayerBlock>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldBlockLayer" });
				//Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>* worldItemBase = (Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldItemsData" });
				//Il2CppList<CollectableData*>* collectableList = (Il2CppList<CollectableData*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "collectables" });
				//Vector2i worldSize = { worldBlocks->max_length, worldBlocks->vector[0]->max_length };


			}
			else
			{
				droppedPlayerIds = {};
			}

			ImGui::End();
		out_if_gsm2:;
		}
		if (Globals::showMinimap && Globals::IsInWorld)
		{

			Il2CppObject* worldController = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController" });
			Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
			Il2CppList<Il2CppObject*>* otherPlayers = (Il2CppList<Il2CppObject*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });

			Vector2i playerMapPoint = il2cpp_object_get_field_value_by_name(localPlayer, Vector2i, localPlayer->klass, "currentPlayerMapPoint");
			Vector2 boxSize = il2cpp_object_get_field_value_by_name(localPlayer, Vector2, localPlayer->klass, "playerBoxColliderSize"); //Il2Cpp::Helpers::GetFieldValue<Vector2>("playerBoxColliderSize", localPlayer);

			Vector2i screenPointOfLocalPlayer = WorldToScreen(Globals::playerInfo.position);
			Vector2 worldPointOfMouse = ScreenToWorld(Globals::MousePos);
			Vector2i mapPointOfMouse = ConvertWorldPointToMapPoint(worldPointOfMouse);
			Vector2i playerBoxSize = ScaleToScreen(boxSize);
			playerBoxSize.x /= 2;

			Il2CppArrayT<Il2CppArrayT<LayerBlock>*>* worldBlocks = (Il2CppArrayT<Il2CppArrayT<LayerBlock>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldBlockLayer" });
			Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>* worldItemBase = (Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldItemsData" });
			Il2CppList<CollectableData*>* collectableList = (Il2CppList<CollectableData*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "collectables" });
			Vector2i worldSize = { worldBlocks->max_length, worldBlocks->vector[0]->max_length };
			Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>* aiEnemiesd = (Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "aiEnemyMonoBehaviours" });

			ImVec2 targetSize = ImVec2{ (float)worldSize.x * Globals::minimapZoomAmount + Globals::minimapZoomAmount * 3, (float)worldSize.y * Globals::minimapZoomAmount + Globals::minimapZoomAmount * 6 };
			ImGui::SetNextWindowSize(targetSize);
			ImGui::Begin("World Minimap", &Globals::showMinimap, ImGuiWindowFlags_NoResize);

			ImDrawList* minimapDrawlist = ImGui::GetWindowDrawList();
			ImVec2 canvas_pos = ImGui::GetCursorScreenPos();
			ImVec2 canvas_size = ImGui::GetContentRegionAvail();
			minimapDrawlist->AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y), ImGui::GetColorU32(ImGui::GetColorU32(ImVec4{ 0.180f, 0.180f, 0.180f, 1.000f })));
			const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];

			for (int x = 0; x < worldSize.x; x++)
			{
				for (int y = 0; y < worldSize.y; y++)
				{
					if (worldItemBase->vector[x]->vector[y])
					{
						float scaledToScreenX = x * Globals::minimapZoomAmount;
						float scaledToScreenY = (worldSize.y - y) * Globals::minimapZoomAmount;
						ImVec2 baseDrawPos = ImVec2{ canvas_pos.x + scaledToScreenX, canvas_pos.y + scaledToScreenY };
						ImVec2 endDrawPos = ImVec2{ canvas_pos.x + scaledToScreenX + Globals::minimapZoomAmount, canvas_pos.y + scaledToScreenY + Globals::minimapZoomAmount };

						std::string blockName = Il2Cpp::Enums::EnumToString(c, worldBlocks->vector[x]->vector[y].blockType);

						int color = ComputeStringHash(blockName.c_str());
						minimapDrawlist->AddRectFilled(baseDrawPos, endDrawPos, color);
					}
				}
			}
			for (int i = 0; i < otherPlayers->size; i++)
			{
				NetworkPlayer* curNetworkPlayer = (NetworkPlayer*)otherPlayers->arry->vector[i];
				if (curNetworkPlayer)
				{
					Player* curPlayer = il2cpp_object_get_field_value_by_name(curNetworkPlayer, Player*, curNetworkPlayer->klass, "playerScript");
					int x = curPlayer->currentPlayerMapPoint.x;
					int y = curPlayer->currentPlayerMapPoint.y;
					float scaledToScreenX = x * Globals::minimapZoomAmount;
					float scaledToScreenY = (worldSize.y - y) * Globals::minimapZoomAmount;
					ImVec2 baseDrawPos = ImVec2{ canvas_pos.x + scaledToScreenX, canvas_pos.y + scaledToScreenY };
					ImVec2 endDrawPos = ImVec2{ canvas_pos.x + scaledToScreenX + Globals::minimapZoomAmount, canvas_pos.y + scaledToScreenY + Globals::minimapZoomAmount };

					minimapDrawlist->AddRectFilled(baseDrawPos, endDrawPos, ImGui::GetColorU32(ImVec4{ 0, 1, 0, 1 }));
				}
			}
			{
				int x = localPlayer->currentPlayerMapPoint.x;
				int y = localPlayer->currentPlayerMapPoint.y;
				float scaledToScreenX = x * Globals::minimapZoomAmount;
				float scaledToScreenY = (worldSize.y - y) * Globals::minimapZoomAmount;
				ImVec2 baseDrawPos = ImVec2{ canvas_pos.x + scaledToScreenX, canvas_pos.y + scaledToScreenY };
				ImVec2 endDrawPos = ImVec2{ canvas_pos.x + scaledToScreenX + Globals::minimapZoomAmount, canvas_pos.y + scaledToScreenY + Globals::minimapZoomAmount };

				minimapDrawlist->AddRectFilled(baseDrawPos, endDrawPos, ImGui::GetColorU32(ImVec4{ 1, 0, 0, 1 }));
			}
			ImGui::End();
		}
#endif
	}
	if (Globals::IsInWorld)
	{
		Il2CppObject* worldController = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController" });
		Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
		Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });

		Vector2i playerMapPoint = il2cpp_object_get_field_value_by_name(localPlayer, Vector2i, localPlayer->Il2CppClass.klass, "currentPlayerMapPoint");
		Vector2 boxSize = il2cpp_object_get_field_value_by_name(localPlayer, Vector2, localPlayer->Il2CppClass.klass, "playerBoxColliderSize"); //Il2Cpp::Helpers::GetFieldValue<Vector2>("playerBoxColliderSize", localPlayer);

		Vector2i screenPointOfLocalPlayer = WorldToScreen(Globals::playerInfo.position);
		Vector2 worldPointOfMouse = ScreenToWorld(Globals::MousePos);
		Vector2i mapPointOfMouse = ConvertWorldPointToMapPoint(worldPointOfMouse);
		Vector2i playerBoxSize = ScaleToScreen(boxSize);
		playerBoxSize.x /= 2;

		Il2CppArrayT<Il2CppArrayT<LayerBlock>*>* worldBlocks = (Il2CppArrayT<Il2CppArrayT<LayerBlock>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldBlockLayer" });
		Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>* worldItemBase = (Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldItemsData" });
		Il2CppList<CollectableData*>* collectableList = (Il2CppList<CollectableData*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "collectables" });
		Vector2i worldSize = { worldBlocks->max_length, worldBlocks->vector[0]->max_length };
		Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>* aiEnemiesd = (Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "aiEnemyMonoBehaviours" });

#ifndef AAPUBLICMODE
		if (mouseToFly && io.MouseDown[2])
		{
			Vector2 distFromCenter{};
			distFromCenter.x = io.MousePos.x - screenPointOfLocalPlayer.x;
			distFromCenter.y = io.MousePos.y - screenPointOfLocalPlayer.y;
			FieldInfo* velocity = il2cpp_class_get_field_from_name(localPlayer->Il2CppClass.klass, "velocity");
			float speed = (1 / mouseFlySpeed) * 1000;
			Vector3 v = Vector3{ distFromCenter.x / speed, distFromCenter.y / ((speed - (speed / 4)) / -1), 0.f };
			il2cpp_field_set_value(localPlayer, velocity, &v);
		}
		for (int i = 0; i < otherPlayers->size; i++)
		{
			NetworkPlayer* curNetworkPlayer = otherPlayers->arry->vector[i];
			if (curNetworkPlayer)
			{
				Player* curPlayer = curNetworkPlayer->playerScript;//il2cpp_object_get_field_value_by_name(curNetworkPlayer, Il2CppObject*, curNetworkPlayer->Il2CppClass.klass, "playerScript"); //Il2Cpp::Helpers::GetFieldValue<Il2CppObject*>("playerScript", curNetworkPlayer);
				Vector2 networkPlayerPos = curPlayer->myTransform->GetPosition(); //Il2Cpp::Helpers::GetFieldValue<Vector3>("currentPlayerPosition", curPlayer)
				Vector2i screenPointOfOther = WorldToScreen(networkPlayerPos);
				Il2CppString*& name = curNetworkPlayer->name;

				if (Globals::EspBools["Other Player ESP Boxes"].value)
				{
					drawList->AddRect
					(
						ImVec2{ (float)screenPointOfOther.x - playerBoxSize.x, (float)screenPointOfOther.y - playerBoxSize.y },
						ImVec2{ (float)screenPointOfOther.x + playerBoxSize.x, (float)screenPointOfOther.y },
						ImGui::GetColorU32(Globals::otherPlayerESPColor),
						0.1f,
						15,
						Globals::OtherPlayerBoxThickness
					);
				}
				if (Globals::EspBools["ESP Tracers"].value)
				{
					Vector2 localpoint = {};
					Vector2 localmiddlePos = { (float)screenPointOfLocalPlayer.x, (float)screenPointOfLocalPlayer.y - playerBoxSize.y / 2 };
					Vector2 localotherPos = { (float)screenPointOfOther.x, (float)screenPointOfOther.y };

					Vector2 otherpoint = {};
					Vector2 othermiddlePos = { (float)screenPointOfOther.x, (float)screenPointOfOther.y - playerBoxSize.y / 2 };
					Vector2 otherotherPos = { (float)screenPointOfLocalPlayer.x, (float)screenPointOfLocalPlayer.y };


					{
						bool hu, hd, hl, hr;

						Vector2 ul1 = { (float)screenPointOfLocalPlayer.x - playerBoxSize.x, (float)screenPointOfLocalPlayer.y - playerBoxSize.y };
						Vector2 ul2 = { (float)screenPointOfLocalPlayer.x + playerBoxSize.x, (float)screenPointOfLocalPlayer.y - playerBoxSize.y };

						Vector2 dl1 = { (float)screenPointOfLocalPlayer.x - playerBoxSize.x, (float)screenPointOfLocalPlayer.y };
						Vector2 dl2 = { (float)screenPointOfLocalPlayer.x + playerBoxSize.x, (float)screenPointOfLocalPlayer.y };

						Vector2 rl1 = { (float)screenPointOfLocalPlayer.x + playerBoxSize.x, (float)screenPointOfLocalPlayer.y - playerBoxSize.y };
						Vector2 rl2 = { (float)screenPointOfLocalPlayer.x + playerBoxSize.x, (float)screenPointOfLocalPlayer.y };

						Vector2 ll1 = { (float)screenPointOfLocalPlayer.x - playerBoxSize.x, (float)screenPointOfLocalPlayer.y - playerBoxSize.y };
						Vector2 ll2 = { (float)screenPointOfLocalPlayer.x - playerBoxSize.x, (float)screenPointOfLocalPlayer.y };

					 	Vector2 up = line_intersect(localmiddlePos, localotherPos, ul1, ul2, &hu);
						Vector2 dp = line_intersect(localmiddlePos, localotherPos, dl1, dl2, &hd);
						Vector2 rp = line_intersect(localmiddlePos, localotherPos, rl1, rl2, &hr);
						Vector2 lp = line_intersect(localmiddlePos, localotherPos, ll1, ll2, &hl);

						if (hr)
						{
							localpoint = rp;
						}
						else if (hl)
						{
							localpoint = lp;
						}
						else if (hu)
						{
							localpoint = up;
						}
						else if (hd)
						{
							localpoint = dp;
						}
						else
						{
							localpoint = localmiddlePos;
						}
					}
					{
						bool hu, hd, hl, hr;

						Vector2 ul1 = { (float)screenPointOfOther.x - playerBoxSize.x, (float)screenPointOfOther.y - playerBoxSize.y };
						Vector2 ul2 = { (float)screenPointOfOther.x + playerBoxSize.x, (float)screenPointOfOther.y - playerBoxSize.y };

						Vector2 dl1 = { (float)screenPointOfOther.x - playerBoxSize.x, (float)screenPointOfOther.y };
						Vector2 dl2 = { (float)screenPointOfOther.x + playerBoxSize.x, (float)screenPointOfOther.y };

						Vector2 rl1 = { (float)screenPointOfOther.x + playerBoxSize.x, (float)screenPointOfOther.y - playerBoxSize.y };
						Vector2 rl2 = { (float)screenPointOfOther.x + playerBoxSize.x, (float)screenPointOfOther.y };

						Vector2 ll1 = { (float)screenPointOfOther.x - playerBoxSize.x, (float)screenPointOfOther.y - playerBoxSize.y };
						Vector2 ll2 = { (float)screenPointOfOther.x - playerBoxSize.x, (float)screenPointOfOther.y };

						Vector2 up = line_intersect(othermiddlePos, otherotherPos, ul1, ul2, &hu);
						Vector2 dp = line_intersect(othermiddlePos, otherotherPos, dl1, dl2, &hd);
						Vector2 rp = line_intersect(othermiddlePos, otherotherPos, rl1, rl2, &hr);
						Vector2 lp = line_intersect(othermiddlePos, otherotherPos, ll1, ll2, &hl);

						if (hr)
						{
							otherpoint = rp;
						}
						else if (hl)
						{
							otherpoint = lp;
						}
						else if (hu)
						{
							otherpoint = up;
						}
						else if (hd)
						{
							otherpoint = dp;
						}
						else
						{
							otherpoint = othermiddlePos;
						}
					}
					drawList->AddLine
					(
						ImVec2{ otherpoint.x, otherpoint.y },
						ImVec2{ localpoint.x, localpoint.y },
						ImGui::GetColorU32(Globals::playerTracerColor),
						Globals::playerTracerThickness
					);
				}
				if (Globals::EspBools["ESP Names"].value)
				{
					
					Vector2 localmiddlePos = { (float)screenPointOfLocalPlayer.x, (float)screenPointOfLocalPlayer.y - playerBoxSize.y / 2 };
					Vector2 othermiddlePos = { (float)screenPointOfOther.x, (float)screenPointOfOther.y - playerBoxSize.y / 2 };

					Vector2 diff = Vector2{ othermiddlePos.x - localmiddlePos.x, othermiddlePos.y - localmiddlePos.y };
					Vector2 angle = diff.normalize();
					float scalar = std::min(io.DisplaySize.x, io.DisplaySize.y);
					scalar *= 0.3;
					Vector2 angleScaled = { angle.x * scalar, angle.y * scalar };
					Vector2 scaledToScreen = Vector2{ (localmiddlePos.x + angleScaled.x), (localmiddlePos.y + angleScaled.y) };
					float distToPlayer = localmiddlePos.Distance(othermiddlePos);
					float distToText = localmiddlePos.Distance(scaledToScreen);
					if (distToPlayer < distToText)
					{
						scaledToScreen = othermiddlePos;
					}
					std::string n = string_Utf16ToUtf8(name);
					drawlist_AddTextCentered(drawList, n.c_str(), Vector2i{ (int)scaledToScreen.x, (int)scaledToScreen.y }, ImVec4{ 1, 0, 0, 1 });

				}
			}
		}
		{
			static int otherPlayersSizeLastFrame = 0;
			if (otherPlayers->size != otherPlayersSizeLastFrame)
			{
				// added 1 because other players doesnt count your player
				Discord.CurrentPlayerCount = otherPlayers->size + 1;
				Discord.UpdatePresence();
			}
			otherPlayersSizeLastFrame = otherPlayers->size;
		}
		for (int i = 0; i < collectableList->size; i++)
		{
			CollectableData* collectable = collectableList->arry->vector[i];
			if (!collectable)
				continue;
			Vector2i screenPointOfCollectable = WorldToScreen(ConvertMapPointToWorldPoint(collectable->posX, collectable->posY));
			float sizeOffset = cameraZoom * 9.0f;
			if (Globals::EspBools["Collectable ESP Boxes"].value)
			{
				drawList->AddRect
				(
					ImVec2(screenPointOfCollectable.x-sizeOffset, screenPointOfCollectable.y-sizeOffset),
					ImVec2(screenPointOfCollectable.x+sizeOffset, screenPointOfCollectable.y+sizeOffset),
					ImGui::GetColorU32(Globals::collectableBoxColor),
					0.1f,
					15,
					Globals::collectableEspThickness
				);
			}
			if (Globals::EspBools["Collectable Tracers"].value)
			{
				drawList->AddLine(ImVec2(screenPointOfLocalPlayer.x, screenPointOfLocalPlayer.y), ImVec2(screenPointOfCollectable.x, screenPointOfCollectable.y + sizeOffset), ImGui::GetColorU32(Globals::collectableTracerColor), Globals::collectableTracerThickness);
			}
		}
		if (aiEnemiesd)
		{
			Il2CppArrayT<AIEnemyMonoBehaviourBase*>* values = aiEnemiesd->GetValues();
			
			for (int i = 0; i < values->max_length; i++)
			{
				AIEnemyMonoBehaviourBase* aiEnemy = values->vector[i];
				if (!aiEnemy || !aiEnemy->aiBase)
					continue;
				Vector2i screenPointOfAiEnemy = WorldToScreen(aiEnemy->wantedPosition);
				float sizeOffset = cameraZoom * 15.f;
				if (Globals::EspBools["Monster ESP Boxes"].value)
				{
					if (!aiEnemy || !aiEnemy->aiBase)
						continue;
					drawList->AddRect
					(
						ImVec2(screenPointOfAiEnemy.x - sizeOffset, screenPointOfAiEnemy.y - sizeOffset),
						ImVec2(screenPointOfAiEnemy.x + sizeOffset, screenPointOfAiEnemy.y + sizeOffset),
						ImGui::GetColorU32(Globals::monsterBoxColor),
						0.1f,
						15,
						Globals::monsterEspThickness
					);
					//drawList->AddLine(ImVec2(screenPointOfLocalPlayer.x, screenPointOfLocalPlayer.y), ImVec2(screenPointOfAiEnemy.x, screenPointOfAiEnemy.y), ImGui::GetColorU32(Globals::collectableTracerColor), Globals::collectableTracerThickness);
				}
				if (Globals::EspBools["Show Monster Heath"].value )
				{
					const static auto AIEnemyConfigData_GetMaxHitPoints1 = reinterpret_cast<int(*)(int/*AIEnemyType*/ enemyType)>(Globals::Methods["System.Int32 Assembly-CSharp.AIEnemyConfigData.GetMaxHitPoints(AIEnemyType,)"]->methodPointer);

					ImVec2 min = ImVec2(screenPointOfAiEnemy.x - sizeOffset, screenPointOfAiEnemy.y - sizeOffset - 16);
					ImVec2 max = ImVec2(screenPointOfAiEnemy.x + sizeOffset, screenPointOfAiEnemy.y - sizeOffset - 3);
					if (!aiEnemy || !aiEnemy->aiBase)
						continue;
					int health = aiEnemy->aiBase->health;
					if (!aiEnemy || !aiEnemy->aiBase)
						continue;
					int maxHealth = AIEnemyConfigData_GetMaxHitPoints1(aiEnemy->aiBase->enemyType);
					float percent = (float)health / (float)maxHealth;

					drawList->AddRectFilled(min, max, ImGui::GetColorU32(ImVec4(0.3, 0.3, 0.3, 1)));
					max.x = max.x - (max.x - min.x) * (1.f - percent);
					drawList->AddRectFilled(min, max, ImGui::GetColorU32(ImVec4(1, 0, 0, 1)));
					min = ImVec2(screenPointOfAiEnemy.x - sizeOffset, screenPointOfAiEnemy.y - sizeOffset - 16);
					drawList->AddRect(min, max, ImGui::GetColorU32(ImVec4(0, 0, 0, 1)));
					drawlist_AddTextCentered(drawList, string_printf("%i/%i", health, maxHealth).c_str(), Vector2i{(int)(min.x + sizeOffset), (int)(min.y + 6.5f)}, ImVec4{0, 0, 0, 1});
				}
				if (Globals::EspBools["Monster Tracers"].value)
				{
					if (!aiEnemy || !aiEnemy->aiBase)
						continue;
					drawList->AddLine(ImVec2(screenPointOfLocalPlayer.x, screenPointOfLocalPlayer.y), ImVec2(screenPointOfAiEnemy.x, screenPointOfAiEnemy.y), ImGui::GetColorU32(Globals::monsterTracerColor), Globals::monsterTracerThickness);
				}
			}
		}
		if (Globals::EspBools["Local Player ESP Boxes"].value)
		{
			drawList->AddRect
			(
				ImVec2{ (float)screenPointOfLocalPlayer.x - playerBoxSize.x, (float)screenPointOfLocalPlayer.y - playerBoxSize.y },
				ImVec2{ (float)screenPointOfLocalPlayer.x + playerBoxSize.x, (float)screenPointOfLocalPlayer.y },
				ImGui::GetColorU32(Globals::localPlayerESPColor),
				0.1f,
				15,
				Globals::SelfBoxThickness
			);
		}
		if (io.KeyAlt && Globals::MapPointExploitBools["Teleport Visualizer"].value)
		{
			std::vector<Vector2i> foundPath = FindPath(playerMapPoint, mapPointOfMouse, worldBlocks, worldItemBase);
			for (int i = 0; i < foundPath.size(); i++)
			{
				ImVec4 visaulBoxColor = i < 16 ? ImVec4{ 0.f, 1.f, 0.f, 1.f } : ImVec4{ 1.f, 1.f, 0.f, 1.f };
				Vector2 v = ConvertMapPointToWorldPoint(foundPath[i]);
				Vector2 mpt1 = Vector2{ v.x - (Globals::tileSize.x / 2), v.y - (Globals::tileSize.y / 2) };
				Vector2 mpt2 = Vector2{ v.x + (Globals::tileSize.x / 2), v.y + (Globals::tileSize.y / 2) };

				Vector2i sp1 = WorldToScreen(mpt1);
				Vector2i sp2 = WorldToScreen(mpt2);

				ImVec2 mapPointCorner = ImVec2{ (float)sp1.x, (float)sp1.y };
				ImVec2 mapPointCorner2 = ImVec2{ (float)sp2.x, (float)sp2.y };
				drawList->AddRect(mapPointCorner, mapPointCorner2, ImGui::GetColorU32(visaulBoxColor), 0.f, 15, 3.f);
			}
		}
		for (int i = 0; i < Globals::visualPathHelper.size(); i++)
		{
			ImVec4 visaulBoxColor = ImVec4{ 0.f, 1.f, 0.f, 1.f };
			Vector2 v = ConvertMapPointToWorldPoint(Globals::visualPathHelper[i]);
			Vector2 mpt1 = Vector2{ v.x - (Globals::tileSize.x / 2), v.y - (Globals::tileSize.y / 2) };
			Vector2 mpt2 = Vector2{ v.x + (Globals::tileSize.x / 2), v.y + (Globals::tileSize.y / 2) };

			Vector2i sp1 = WorldToScreen(mpt1);
			Vector2i sp2 = WorldToScreen(mpt2);

			ImVec2 mapPointCorner = ImVec2{ (float)sp1.x, (float)sp1.y };
			ImVec2 mapPointCorner2 = ImVec2{ (float)sp2.x, (float)sp2.y };
			drawList->AddRect(mapPointCorner, mapPointCorner2, ImGui::GetColorU32(visaulBoxColor), 0.f, 15, 3.f);

			if (playerMapPoint == Globals::visualPathHelper[i])
			{
				for (int j = 0; j < Globals::visualPathHelper.size() - i; j++)
				{
					Globals::visualPathHelper.pop_back();
				}
			}
		}
		if (foundPathThroughBlocks.size() > 0)
		{
			for (int i = 0; i < foundPathThroughBlocks.size(); i++)
			{
				Vector2i block = foundPathThroughBlocks[i];
				if (!InBounds(block, worldSize))
					break;
				ImVec4 visaulBoxColor = DoesMapPointHaveColider(block, worldBlocks) ? ImVec4{ 1.f, 1.f, 0.f, 1.f } : ImVec4{ 0.f, 1.f, 0.f, 1.f };
				Vector2 v = ConvertMapPointToWorldPoint(block);
				Vector2 mpt1 = Vector2{ v.x - (Globals::tileSize.x / 2), v.y - (Globals::tileSize.y / 2) };
				Vector2 mpt2 = Vector2{ v.x + (Globals::tileSize.x / 2), v.y + (Globals::tileSize.y / 2) };

				Vector2i sp1 = WorldToScreen(mpt1);
				Vector2i sp2 = WorldToScreen(mpt2);

				ImVec2 mapPointCorner = ImVec2{ (float)sp1.x, (float)sp1.y };
				ImVec2 mapPointCorner2 = ImVec2{ (float)sp2.x, (float)sp2.y };
				drawList->AddRect(mapPointCorner, mapPointCorner2, ImGui::GetColorU32(visaulBoxColor), 0.f, 15, 3.f);
			}
		}
		if (foundPathToClosestEnemy.size() > 0)
		{
			for (int i = 0; i < foundPathToClosestEnemy.size(); i++)
			{
				Vector2i block = foundPathToClosestEnemy[i];
				if (!InBounds(block, worldSize))
					break;
				ImVec4 visaulBoxColor = ImVec4{ 0.f, 1.f, 0.f, 1.f };
				Vector2 v = ConvertMapPointToWorldPoint(block);
				Vector2 mpt1 = Vector2{ v.x - (Globals::tileSize.x / 2), v.y - (Globals::tileSize.y / 2) };
				Vector2 mpt2 = Vector2{ v.x + (Globals::tileSize.x / 2), v.y + (Globals::tileSize.y / 2) };

				Vector2i sp1 = WorldToScreen(mpt1);
				Vector2i sp2 = WorldToScreen(mpt2);

				ImVec2 mapPointCorner = ImVec2{ (float)sp1.x, (float)sp1.y };
				ImVec2 mapPointCorner2 = ImVec2{ (float)sp2.x, (float)sp2.y };
				drawList->AddRect(mapPointCorner, mapPointCorner2, ImGui::GetColorU32(visaulBoxColor), 0.f, 15, 3.f);
			}
		}
		if (Globals::ToggleBools["Item Data Tooltip"].value)
		{
			static bool inspectMenuOpen = false;
			static WorldItemBase* objectToInspect = nullptr;
			if (InBounds(mapPointOfMouse, worldSize))
			{
				Il2CppObject* base = il2cpp_array_get(il2cpp_array_get(worldItemBase, Il2CppArray*, mapPointOfMouse.x), Il2CppObject*, mapPointOfMouse.y);
				if (base)
				{
					if (base->Il2CppClass.klass->field_count > 0)
					{
						ImGui::SetNextWindowPos({ io.MousePos.x, io.MousePos.y + 14 });
						ImGui::Begin(base->Il2CppClass.klass->name, (bool*)0, ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_::ImGuiWindowFlags_NoMove | ImGuiWindowFlags_::ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_::ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_::ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize);
						{
							for (int i = 0; i < base->Il2CppClass.klass->field_count; i++)
							{
								FieldInfo* fieldInfo = &base->Il2CppClass.klass->fields[i];
								FieldAsText(base, fieldInfo);
								if (io.KeysDownDuration[VK_F11] == 0)
								{
									inspectMenuOpen = true;
									objectToInspect = (WorldItemBase*)base;
								}
							}
							ImGui::End();
						}
					}
				}
			}

			if (inspectMenuOpen && objectToInspect)
			{
				const static auto TextManager_GetBlockTypeName1 = reinterpret_cast<Il2CppString * (*)(int/*World.BlockType*/ bt)>(Globals::Methods["System.String Assembly-CSharp.TextManager.GetBlockTypeName(World.BlockType,)"]->methodPointer);
				const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];

				std::string name = cppstr(TextManager_GetBlockTypeName1(objectToInspect->blockType));
				ImGui::Begin("Inpect Window", &inspectMenuOpen);
				ImGui::Text("Item Name: %s\nItem Class: %s", name.c_str(), objectToInspect->klass->name);
				switch (objectToInspect->blockType)
				{
				case 2389:
				case 3031:
				case 2113:
				case 80:
				case 135:
				case 2087:
				{
					SafeData* d = (SafeData*)objectToInspect;
					for (int i = 0; i < d->storageItemsAsInventoryKeys->size; i++)
					{
						InventoryKey ik = IntToIK(d->storageItemsAsInventoryKeys->arry->vector[i]);
						std::string text = string_printf("%s(%s) x%i", cppstr(TextManager_GetBlockTypeName1(ik.blockType)).c_str(), Il2Cpp::Enums::EnumToString(c, ik.blockType).c_str(), d->storageItemsAmounts->arry->vector[i]);
						if (ImGui::Selectable(text.c_str())) ImGui::SetClipboardText(text.c_str());
					}
					break;
				}
				case 2146:
				{
					DisplayBlockData* d = (DisplayBlockData*)objectToInspect;
					InventoryKey ik = IntToIK(d->storageItemAsInventoryKey);
					std::string text = string_printf("%s(%s)", cppstr(TextManager_GetBlockTypeName1(ik.blockType)).c_str(), Il2Cpp::Enums::EnumToString(c, ik.blockType).c_str());
					if (ImGui::Selectable(text.c_str())) ImGui::SetClipboardText(text.c_str());
					break;
				}
				case 2166:
				{
					MannequinData* d = (MannequinData*)objectToInspect;
					for (int i = 0; i < d->itemsAsInventoryKeys->size; i++)
					{
						InventoryKey ik = IntToIK(d->itemsAsInventoryKeys->arry->vector[i]);
						std::string text = string_printf("%s(%s)", cppstr(TextManager_GetBlockTypeName1(ik.blockType)).c_str(), Il2Cpp::Enums::EnumToString(c, ik.blockType).c_str());
						if (ImGui::Selectable(text.c_str())) ImGui::SetClipboardText(text.c_str());
					}
					break;
				}
				case 3605:
				{
					GuestBookData* d = (GuestBookData*)objectToInspect;
					for (int i = 0; i < d->messages->size; i++)
					{
						std::string message = cppstr(d->messages->arry->vector[i]);
						std::string playerId = cppstr(d->playerIds->arry->vector[i]);
						bool approved = d->approved->arry->vector[i];
						std::string timestamp = "";
						__int64 timestamp_il2cpp = d->timestamps->arry->vector[i];
						unsigned __int64 cTime = il2cpp_time_to_c(timestamp_il2cpp);
						time_t t = cTime;
						timestamp.resize(64);
						if (ImGui::GetIO().KeysDown[VK_F5])
						{
							strftime(timestamp.data(), 64, "%m-%d-%Y %H:%M:%S", localtime(&t));
						}
						else
						{
							strftime(timestamp.data(), 64, "%B %d, %Y %H:%M:%S", localtime(&t));
						}
				
						if (!approved)
							ImGui::PushStyleColor(ImGuiCol_Header, ImVec4{.8, .2, .2, 1});
						if (ImGui::CollapsingHeader(string_printf("Guestbook Entry %i", i).c_str()))
						{
							ImGui::Indent(20.f);
							if (ImGui::Selectable(message.c_str()))
							{
								ImGui::SetClipboardText(message.c_str());
							}
							if (ImGui::Selectable(playerId.c_str()))
							{
								ImGui::SetClipboardText(playerId.c_str());
							}
							if (ImGui::Selectable(timestamp.c_str()))
							{
								ImGui::SetClipboardText(timestamp.c_str());
							}
							ImGui::Indent(-20.f);
						}
						if (!approved)
							ImGui::PopStyleColor();
					}
					break;
				}
				}
				ImGui::End();
			}
		}

		/*
		* Credits:
		* Chair, Idea and Concept
		* Chair, Coding it
		* Chair, Debugging it and fixing bugs
		* Chair, Director
		* Chair, All acting
		* Chair, The framework behind it
		* Chair, Il2CppFramework behind all of this
		* ocornut, ImGui UI for rendering and menus
		* Microsoft, DirectX11 Graphics Framework
		*/
		if (Globals::EspBools["Player Trail"].value)
		{
			static ImVec4 color = {1, 0, 0, 1};
			static float timeEl = 0.0f;
			if (fupdate)
			{
				Globals::playerTrail.push_back(Globals::playerInfo.position);
				if (Globals::playerTrail.size() > 500)
				{
					Globals::playerTrail.erase(Globals::playerTrail.begin());
				}
				timeEl += Globals::deltaTime;
				for (int i = 0; i < Globals::playerTrail.size(); i++)
				{
					if (i + 1 < Globals::playerTrail.size())
					{
						Vector2 pti = Globals::playerTrail[i];
						color.x = 0.5 + 0.5 * cos(2 * timeEl + 5 * pti.x + 0);
						color.y = 0.5 + 0.5 * cos(2 * timeEl + 5 * pti.y + 2);
						color.z = 0.5 + 0.5 * cos(2 * timeEl + 5 * pti.x + 4);

						Vector2i x1 = WorldToScreen(Globals::playerTrail[i]);
						Vector2i x2 = WorldToScreen(Globals::playerTrail[i+1]);
						drawList->AddLine(ImVec2(x1.x, x1.y), ImVec2(x2.x, x2.y), ImGui::GetColorU32(color), 1.0f);
					}
				}
			}
			
			//for (int j = 0; j < otherPlayers->size; j++)
			//{
			//	Player* p = ((NetworkPlayer*)otherPlayers->arry->vector[j])->playerScript;
			//	Vector3 pos = p->myTransform->GetPosition();
			//	std::vector<Vector2>& sv = Globals::otherPlayerTrails[j];
			//	sv.push_back(Vector2(pos.x, pos.y));
			//	if (sv.size() > 500)
			//	{
			//		sv.erase(sv.begin());
			//	}
			//	for (int i = 0; i < sv.size(); i++)
			//	{
			//		if (i + 1 < sv.size())
			//		{
			//			color.x = abs(sin(sv[i].x + timeEl));
			//			color.y = abs(cos(sv[i].y + timeEl));
			//			color.z = abs(cos(sv[i].x + timeEl));
			//			Vector2i x1 = WorldToScreen(sv[i]);
			//			Vector2i x2 = WorldToScreen(sv[i + 1]);
			//			drawList->AddLine(ImVec2(x1.x, x1.y), ImVec2(x2.x, x2.y), /*ImGui::GetColorU32(color)*/ComputeStringHash(cppstr(((NetworkPlayer*)otherPlayers->arry->vector[j])->name).c_str()), 1.0f);
			//		}
			//	}
			//}
			fupdate = true;
		}
#endif
	}
	else
	{
		fupdate = false;
		Globals::playerTrail.clear();
	}


	{
		const static Il2CppClass* staticplayer = il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", "StaticPlayer");
		Globals::playerInfo.staticPlayer = (StaticPlayer_Static*)staticplayer->static_fields;

		const static Il2CppClass* nwc = il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", "NetworkClient");
		Globals::playerInfo.networkClient = (NetworkClient_Static*)nwc->static_fields;


		Globals::playerInfo.name = cppstr(Globals::playerInfo.staticPlayer->theRealPlayername);
		Globals::playerInfo.worldName = cppstr(Globals::playerInfo.networkClient->currentWorld);

		if (Globals::playerInfo.staticPlayer->_playerData)
		{
			Globals::playerInfo.id = cppstr(Globals::playerInfo.staticPlayer->_playerData->playerId);
		}
	}

	{
		static std::string worldLastFrame = "";
		static std::string playerNameLastFrame = "";
		static bool inWorldLFrame = false;

		if (Globals::playerInfo.worldName != worldLastFrame || inWorldLFrame != Globals::IsInWorld)
		{
			int opc = 0;
			if (Globals::IsInWorld)
			{
				Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
				opc = otherPlayers->size;
			}
			Discord.CurrentPlayerCount = opc + 1;
			Discord.CurrentWorld = Globals::playerInfo.worldName;
			Discord.UpdatePresence();
		}
		if (Globals::playerInfo.name != playerNameLastFrame)
		{
			Discord.CurrentPlayerName = Globals::playerInfo.name;
			if (Globals::playerInfo.name == "DemonWithAHeart")
			{
				safeMode = true;
				Globals::ToggleBools =
				{
					{"Freecam", MiscBoolFuncPair(false)},
					{"Item Data Tooltip", MiscBoolFuncPair(true)},
					{"Keys to Fly", MiscBoolFuncPair(false)},
					{"Lag Ghost", MiscBoolFuncPair(false)},
				};
				Globals::MapPointExploitBools =
				{
					{"Teleport to Map Point", {true}},
					{"Teleport Visualizer", {true}},
					{"Anti-Kick flight", {false, []() { ImGui::SliderFloat("Anti-Kick Timeout", &Globals::antiKickTimeout, 0.1f, 1.5f); }}},
					{"Send position packet", {true}},
					{"Infinite Range", {false}}
				};
				Globals::MiningBools =
				{
					{"Auto-Mine", MiscBoolFuncPair(false,
					[]() {
						for (int i = 0; i < Globals::miningOrder.size(); i++)
						{
							ImGui::PushStyleVar(ImGuiStyleVar_::ImGuiStyleVar_ItemSpacing, ImVec2{0, 1});
							ImGui::PushID(i + 50);
							if (ImGui::Button("^", ImVec2(20, 0)))
							{
								if (i > 0)
								{
									int temp = Globals::miningOrder[i - 1];
									Globals::miningOrder[i - 1] = Globals::miningOrder[i];
									Globals::miningOrder[i] = temp;
								}
							}
							ImGui::SameLine();
							if (ImGui::Button("v", ImVec2(20, 0)))
							{
								if (i + 1 < Globals::miningOrder.size())
								{
									int temp = Globals::miningOrder[i + 1];
									Globals::miningOrder[i + 1] = Globals::miningOrder[i];
									Globals::miningOrder[i] = temp;
								}
							}
							ImGui::SameLine();
							ImGui::PopID();
							ImGui::PopStyleVar();

							if (Globals::miningOrder[i] == 0)
							{
								ImGui::Button("Collect Collectables");
							}
							if (Globals::miningOrder[i] == 1)
							{
								ImGui::Button("Break All Gem Blocks");
							}
							if (Globals::miningOrder[i] == 2)
							{
								ImGui::Button("Kill Monsters");
							}
						}
						})},
				};
				Globals::MiscBools =
				{
					{"Change Textbox Max Length", MiscBoolFuncPair(false, []() { ImGui::SliderInt("Textbox Length to Change to", &Globals::textboxLenToChangeTo, 1, 2048); })},
					{"Play Annoying Audio", MiscBoolFuncPair(false, []() { ImGui::SliderInt("Audio Type To Play", &Globals::audioTypeToPlay, 1, 20); ImGui::SliderInt("Audio Block Type To Play", &Globals::audioBlockTypeToPlay, 1, 4000); })},
					{"Bypass Untradeables", MiscBoolFuncPair(false)},
					{"Trade All Spam", MiscBoolFuncPair(false, []() { ImGui::SliderFloat("Trade All Timeout", &Globals::tradeAlltimeout, 0, 1); })},
					{"Change Player Visual Name", MiscBoolFuncPair(true, []() { ImGui::InputText("Player Name", &Globals::playerNameToChangeTo); ImGui::DragFloat("Col Scale", &Globals::tcolScale1, 0.1); })},
					{"Change Player Speed", MiscBoolFuncPair(false, []() { ImGui::SliderFloat("Player Speed", &Globals::setRunSpeed, 0.1f, 9.0f);  })},
					{"Change Player Hit Speed", MiscBoolFuncPair(false, []() { ImGui::SliderFloat("Player Hit Speed", &Globals::setHitSpeed, 0.0f, 0.25f);  })},
					{"Auto World Report", MiscBoolFuncPair(false)},
					{"All Recallable", MiscBoolFuncPair(false)},
					{"Sit on Other Players", MiscBoolFuncPair(false)},
					{"Double Press to Dash", MiscBoolFuncPair(false,
					[]()
					{
						ImGui::SliderFloat("Dash Tolerance", &Globals::DashTolerency, 0.01f, 1.f);
					})},
					{"Status Icon Changing", MiscBoolFuncPair(false,
					[]()
					{
						ImGui::SliderFloat("Status Icon Timeout", &Globals::StatusIconTimeout, 0.01f, 1.f);
					})},
					{"No-Clip", MiscBoolFuncPair(false)},
				};
				Globals::BasicsBools =
				{
					{"Anti-Hurt", false},
					{"Anti-Pickup", false},
					{"Faster-Hit", false},
					{"Anti-Bounce", false},
					{"Anti-Inverted Controls", true},
					{"Anti-Check Points", false},
					{"Anti-Race", false},
					{"Anti-Poison", false},
					{"Anti-Wiring", false},
					{"Anti-Block Death", false},
					{"Place Block on Player", false},
					{"Place Seed in Air", false},
					{"Always Water", false},
					{"Anti-Water", false},
					{"Hit By Lava Animation", false},
					{"Anti-Auto Portal", false},
					//{"Lag Ghost", false},
					{"Long Hit(Visual)", false},
					{"Anti-KnockBack", false},
					{"Anti-Fog", true},
					{"Anti-Dark", true},
					{"Anti-Chat Filter", false},
					{"Insta-Die", false},
					{"Hit Block Through Battle", false},

					//{"", false},
					//{"", false}
				};
				Globals::aimbot = false;
				Globals::aiAimbot = false;
				Globals::setHitSpeed = false;
				Globals::setRunSpeed = false;
				IsHeartless = true;
				Console.AddLog("Heartless Demon");
			}
			else if (Globals::playerInfo.name == "HeartlessDemon")
			{
			safeMode = true;
			Globals::ToggleBools =
			{
				{"Freecam", MiscBoolFuncPair(false)},
				{"Item Data Tooltip", MiscBoolFuncPair(true)},
				{"Keys to Fly", MiscBoolFuncPair(false)},
				{"Lag Ghost", MiscBoolFuncPair(false)},
			};
			Globals::MapPointExploitBools =
			{
				{"Teleport to Map Point", {true}},
				{"Teleport Visualizer", {true}},
				{"Anti-Kick flight", {false, []() { ImGui::SliderFloat("Anti-Kick Timeout", &Globals::antiKickTimeout, 0.1f, 1.5f); }}},
				{"Send position packet", {true}},
				{"Infinite Range", {false}}
			};
			Globals::MiningBools =
			{
				{"Auto-Mine", MiscBoolFuncPair(false,
				[]() {
					for (int i = 0; i < Globals::miningOrder.size(); i++)
					{
						ImGui::PushStyleVar(ImGuiStyleVar_::ImGuiStyleVar_ItemSpacing, ImVec2{0, 1});
						ImGui::PushID(i + 50);
						if (ImGui::Button("^", ImVec2(20, 0)))
						{
							if (i > 0)
							{
								int temp = Globals::miningOrder[i - 1];
								Globals::miningOrder[i - 1] = Globals::miningOrder[i];
								Globals::miningOrder[i] = temp;
							}
						}
						ImGui::SameLine();
						if (ImGui::Button("v", ImVec2(20, 0)))
						{
							if (i + 1 < Globals::miningOrder.size())
							{
								int temp = Globals::miningOrder[i + 1];
								Globals::miningOrder[i + 1] = Globals::miningOrder[i];
								Globals::miningOrder[i] = temp;
							}
						}
						ImGui::SameLine();
						ImGui::PopID();
						ImGui::PopStyleVar();

						if (Globals::miningOrder[i] == 0)
						{
							ImGui::Button("Collect Collectables");
						}
						if (Globals::miningOrder[i] == 1)
						{
							ImGui::Button("Break All Gem Blocks");
						}
						if (Globals::miningOrder[i] == 2)
						{
							ImGui::Button("Kill Monsters");
						}
					}
					})},
			};
			Globals::MiscBools =
			{
				{"Change Textbox Max Length", MiscBoolFuncPair(false, []() { ImGui::SliderInt("Textbox Length to Change to", &Globals::textboxLenToChangeTo, 1, 2048); })},
				{"Play Annoying Audio", MiscBoolFuncPair(false, []() { ImGui::SliderInt("Audio Type To Play", &Globals::audioTypeToPlay, 1, 20); ImGui::SliderInt("Audio Block Type To Play", &Globals::audioBlockTypeToPlay, 1, 4000); })},
				{"Bypass Untradeables", MiscBoolFuncPair(false)},
				{"Trade All Spam", MiscBoolFuncPair(false, []() { ImGui::SliderFloat("Trade All Timeout", &Globals::tradeAlltimeout, 0, 1); })},
				{"Change Player Visual Name", MiscBoolFuncPair(true, []() { ImGui::InputText("Player Name", &Globals::playerNameToChangeTo); ImGui::DragFloat("Col Scale", &Globals::tcolScale1, 0.1); })},
				{"Change Player Speed", MiscBoolFuncPair(false, []() { ImGui::SliderFloat("Player Speed", &Globals::setRunSpeed, 0.1f, 9.0f);  })},
				{"Change Player Hit Speed", MiscBoolFuncPair(false, []() { ImGui::SliderFloat("Player Hit Speed", &Globals::setHitSpeed, 0.0f, 0.25f);  })},
				{"Auto World Report", MiscBoolFuncPair(false)},
				{"All Recallable", MiscBoolFuncPair(false)},
				{"Sit on Other Players", MiscBoolFuncPair(false)},
				{"Double Press to Dash", MiscBoolFuncPair(false,
				[]()
				{
					ImGui::SliderFloat("Dash Tolerance", &Globals::DashTolerency, 0.01f, 1.f);
				})},
				{"Status Icon Changing", MiscBoolFuncPair(false,
				[]()
				{
					ImGui::SliderFloat("Status Icon Timeout", &Globals::StatusIconTimeout, 0.01f, 1.f);
				})},
				{"No-Clip", MiscBoolFuncPair(false)},
			};
			Globals::BasicsBools =
			{
				{"Anti-Hurt", false},
				{"Anti-Pickup", false},
				{"Faster-Hit", false},
				{"Anti-Bounce", false},
				{"Anti-Inverted Controls", true},
				{"Anti-Check Points", false},
				{"Anti-Race", false},
				{"Anti-Poison", false},
				{"Anti-Wiring", false},
				{"Anti-Block Death", false},
				{"Place Block on Player", false},
				{"Place Seed in Air", false},
				{"Always Water", false},
				{"Anti-Water", false},
				{"Hit By Lava Animation", false},
				{"Anti-Auto Portal", false},
				//{"Lag Ghost", false},
				{"Long Hit(Visual)", false},
				{"Anti-KnockBack", false},
				{"Anti-Fog", true},
				{"Anti-Dark", true},
				{"Anti-Chat Filter", false},
				{"Insta-Die", false},
				{"Hit Block Through Battle", false},

				//{"", false},
				//{"", false}
			};
			Globals::aimbot = false;
			Globals::aiAimbot = false;
			Globals::setHitSpeed = false;
			Globals::setRunSpeed = false;
			HasAHeart = true;
			Console.AddLog("Demon That has a Heart");
			}
			else
			{
				IsHeartless = false;
				HasAHeart = false;
			}
			Discord.UpdatePresence();
		}
		worldLastFrame = Globals::playerInfo.worldName;
		playerNameLastFrame = Globals::playerInfo.name;
		inWorldLFrame = Globals::IsInWorld;
	}

	//static float updateDiscordRpcTimeout = 0.f;
	//updateDiscordRpcTimeout += Globals::deltaTime;
	//if (updateDiscordRpcTimeout > 1.0f)
	//{
	//	updateDiscordRpcTimeout = 0.f;
	//	static bool dinit = false;
	//	if (!dinit)
	//	{
	//		discordInit();
	//		dinit = true;
	//	}
	//	if (dinit)
	//	{
	//		updateDiscordPresence();
	//	}
	//}

	static float SaveTimeout = 0.0f;
	SaveTimeout += Globals::deltaTime;
	if (SaveTimeout > 1.0f)
	{
		//static std::string cpl = "";
		//const static auto UserIdent_GetLoginInfo0 = reinterpret_cast<Il2CppArrayT<Il2CppString*>*(*)()>(Globals::Methods["System.String[] Assembly-CSharp.UserIdent.GetLoginInfo()"]->methodPointer);
		//Il2CppArrayT<Il2CppString*>* s = UserIdent_GetLoginInfo0();
		//if (s->max_length == 2)
		//{
		//	std::string cpl2 = cppstr(s->vector[0]) + "," + cppstr(s->vector[1]) + ";";
		//	if (cpl != cpl2)
		//	{
		//		Globals::listOfUsedUsernamesAndLogins += cpl2;
		//		cpl = cpl2;
		//	}
		//}
		
		SaveTimeout = 0.0f;
		//SaveData::SaveToFile();
		//Il2CppArrayT<Il2CppString*>* s2 = UserIdent_GetLoginInfo0();
		//if (s->max_length == 2)
		//{
		//	cpl = cppstr(s->vector[0]) + "," + cppstr(s->vector[1]) + ";";
		//}
	}
#ifndef AAPUBLICMODE
	{
		static bool moveStatWindow = false;
		if (io.KeysDownDuration[VK_F10] == 0.f) moveStatWindow = !moveStatWindow;
		ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize;

		if (!moveStatWindow)
			flags |= ImGuiWindowFlags_NoInputs;
		else
		{
			ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4{ 0.3, 0.5, 0.3, 0.8 });
			ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4{ 0.3, 0.5, 0.3, 0.8 });
		}
		ImGui::Begin("##stuff", (bool*)0, flags);
		ImGui::SetWindowFontScale(1.1f);
		int i = 0;
		for (auto& [key, value] : Globals::ToggleBools)
		{
			i++;
			if (value.function == NULL)
			{
				if (value.value)
					ImGui::PushStyleColor(ImGuiCol_Text, ImVec4{ 0, 0.9, 0.1, 1 });
				else
					ImGui::PushStyleColor(ImGuiCol_Text, ImVec4{ 1, 0.1, 0.0, 1 });
				ImGui::Text("%s (F%i): %s", key.c_str(), i, value.value ? "On" : "Off");
			}
			else
				value.function();
			if (value.function == NULL)
			{
				ImGui::PopStyleColor(1);
			}
		}
		ImGui::Text("ArkAngel V" xstr(AAVERSION) " Build " xstr(AABUILDVER) " " xstr(AABUILDMODE) " Mode");
		ImGui::Text("FPS: %f", 1 / Globals::deltaTime);
		const Il2CppClass* kukouriTime = il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", "KukouriTime");
		int& lag = il2cpp_object_get_field_value_static_by_name(kukouriTime->static_fields, int, (Il2CppClass*)kukouriTime, "lag");
		ImGui::Text("Ping: %i(ms)", lag);
		ImGui::SetWindowFontScale(1.0f);
		ImGui::End();


		if (moveStatWindow)
		{
			ImGui::PopStyleColor(2);
		}
		if (io.KeysDownDuration[VK_F1] == 0.f) Globals::ToggleBools["Freecam"].value = !Globals::ToggleBools["Freecam"].value;
		if (io.KeysDownDuration[VK_F2] == 0.f) Globals::ToggleBools["Item Data Tooltip"].value = !Globals::ToggleBools["Item Data Tooltip"].value;
		if (io.KeysDownDuration[VK_F3] == 0.f) Globals::ToggleBools["Keys to Fly"].value = !Globals::ToggleBools["Keys to Fly"].value;
		if (io.KeysDownDuration[VK_F4] == 0.f) Globals::ToggleBools["Lag Ghost"].value = !Globals::ToggleBools["Lag Ghost"].value;
	}
#endif
	ImGui::End();
	ImGui::Render();
	Globals::pContext->OMSetRenderTargets(1, &Globals::mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return Globals::oPresent(pSwapChain, vsync ? SyncInterval : 0, Flags);
}
static bool gameAssemblyThreadHasConfirmedExit = false;
void* oUpdate;
void hkUpdate(Il2CppObject* pThis)
{
	if (Globals::Ejecting)
	{
		if (!gameAssemblyThreadHasConfirmedExit)
		{
			Mono::ShutdownMono();
			gameAssemblyThreadHasConfirmedExit = true;
		}
		return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oUpdate)(pThis);
	}
	if (!init)
		return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oUpdate)(pThis);


	if (Mono::updateMethod)
		mono_runtime_invoke(Mono::updateMethod, nullptr, nullptr, nullptr);

	static std::chrono::steady_clock::time_point lFrameTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> et = std::chrono::high_resolution_clock::now() - lFrameTime;
	Globals::deltaTime = et.count();
	lFrameTime = std::chrono::high_resolution_clock::now();
	Globals::MousePos = CursorPosition_get();


	ImGuiIO& io = ImGui::GetIO();
	if (Globals::IsInWorld)
	{
		static Vector2i mapPointOfMouseLFrame = {};

		//Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)il2cpp_class_from_name(Assembly_CSharp->image, "", "ControllerHelper"), {"worldController", "player"});
		//bool& isLocalPlayerDead = il2cpp_object_get_field_value_by_name(localPlayer, bool, localPlayer->Il2CppClass.klass, "isDead");
		//ImGui::Checkbox("Is Dead", &isLocalPlayerDead);
		//ImGui::Text("%p", localPlayer);

		const static auto PlayerNamesManager_GetPlayerStatusIconType1 = reinterpret_cast<StatusIconType(*)(Il2CppObject * pThis, Il2CppString */*System.String*/ playerID)>(Globals::Methods["PlayerNamesManager.StatusIconType Assembly-CSharp.PlayerNamesManager.GetPlayerStatusIconType(System.String,)"]->methodPointer);
		Il2CppObject* worldController = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController" });
		Il2CppObject* asyncClient = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "networkClient", "acClient"});
		Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
		Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
		Il2CppObject* playerNamesManager = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "playerNamesManager" });
		Il2CppObject* world = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world" });
		Globals::chatUI = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "chatUI"});
		Globals::lockWorld = (LockWorldData*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "lockWorldDataHelper"});;

		Vector2i& playerMapPoint = il2cpp_object_get_field_value_by_name(localPlayer, Vector2i, localPlayer->klass, "currentPlayerMapPoint");
		Transform* playerTransform = il2cpp_object_get_field_value_by_name(localPlayer, Transform*, localPlayer->klass, "myTransform");
		Vector3 playerPost = playerTransform->GetPosition();
		Globals::playerInfo.position = Vector2(playerPost.x, playerPost.y);
		Globals::playerInfo.mapPoint = ConvertWorldPointToMapPoint(Globals::playerInfo.position);
		Vector2& boxSize = il2cpp_object_get_field_value_by_name(localPlayer, Vector2, localPlayer->klass, "playerBoxColliderSize"); 
		Vector2& playerVelocity = il2cpp_object_get_field_value_by_name(localPlayer, Vector2, localPlayer->klass, "velocity");
		PlayerData* localPlayerData = il2cpp_object_get_field_value_by_name(localPlayer, PlayerData*, localPlayer->klass, "myPlayerData");
		Globals::playerStatus = PlayerNamesManager_GetPlayerStatusIconType1(playerNamesManager, istr(Globals::playerInfo.id.c_str()));

		Globals::playerNameTMP = il2cpp_object_get_field_value_by_name(localPlayer, Il2CppObject*, localPlayer->klass, "playerNameTextMeshPro");// localPlayer->playerNameTextMeshPro;
#ifndef AAPUBLICMODE
		if (Globals::MiscBools["Change Player Visual Name"].value)
			hkTMP_Text_set_text1(Globals::playerNameTMP, istr(""));
#endif

		Vector2i screenPointOfLocalPlayer = WorldToScreen(Globals::playerInfo.position);
		Vector2 worldPointOfMouse = ScreenToWorld(Globals::MousePos);
		Vector2i mapPointOfMouse = ConvertWorldPointToMapPoint(worldPointOfMouse);
		Vector2i playerBoxSize = ScaleToScreen(boxSize);
		playerBoxSize.x /= 2;
		
		Il2CppList<Vector2i>* recentMapPoints = il2cpp_object_get_field_value_static_by_name(Globals::Classes["Assembly-CSharp.OutgoingMessages"]->static_fields, Il2CppList<Vector2i>*, (Il2CppClass*)Globals::Classes["Assembly-CSharp.OutgoingMessages"], "recentMapPoints");// Il2Cpp::Helpers::GetStaticFieldValue<Il2CppList<Vector2i>*>(il2cpp_class_get_field_from_name((Il2CppClass*)Globals::Classes["Assembly-CSharp.OutgoingMessages"], "recentMapPoints"));
		Il2CppArrayT<Il2CppArrayT<LayerBlock>*>* worldBlocks = (Il2CppArrayT<Il2CppArrayT<LayerBlock>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldBlockLayer" });
		Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>* worldItemBase = (Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldItemsData" });
		Il2CppList<CollectableData*>* collectableList = (Il2CppList<CollectableData*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "collectables" });
		Vector2i worldSize = { worldBlocks->max_length, worldBlocks->vector[0]->max_length };

		Il2CppObject* worldLighting = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "rootUI", "worldLighting"});
		const static auto ConfigData_GetPlayerRange1 = reinterpret_cast<int(*)(PlayerData */*PlayerData*/ playerData)>(Globals::Methods["System.Int32 Assembly-CSharp.ConfigData.GetPlayerRange(PlayerData,)"]->methodPointer);
		Globals::playerInfo.range = ConfigData_GetPlayerRange1(localPlayerData);


		if (Globals::BasicsBools["Anti-Dark"] && worldLighting)
		{
			const static auto RootUI_RemoveWorldLighting0 = reinterpret_cast<void(*)(Il2CppObject * pThis)>(Globals::Methods["System.Void Assembly-CSharp.RootUI.RemoveWorldLighting()"]->methodPointer);

			RootUI_RemoveWorldLighting0(worldLighting);
			float& lightXResoloution = il2cpp_object_get_field_value_by_name(worldLighting, float, worldLighting->Il2CppClass.klass, "lightXResolution");
			float& extraFarXResolution = il2cpp_object_get_field_value_by_name(worldLighting, float, worldLighting->Il2CppClass.klass, "extraFarXResolution");
			bool& isStarted = il2cpp_object_get_field_value_by_name(worldLighting, bool, worldLighting->Il2CppClass.klass, "isStarted");
			bool toStart = lightXResoloution != 0.01f || extraFarXResolution != 1.0f;
			extraFarXResolution = 1.0f;
			lightXResoloution = 0.01;
			if (toStart)
				isStarted = false;
		}
		bool extraMoveX = false;
		bool extraMoveY = false;
#ifndef AAPUBLICMODE

		if (io.KeyShift && io.MouseClicked[0])
		{
			WorldItemBase* base = worldItemBase->vector[mapPointOfMouse.x]->vector[mapPointOfMouse.y];//Il2Cpp::Arrays::il2cpp_array_index<Il2CppObject*>(Il2Cpp::Arrays::il2cpp_array_index<Il2CppArray*>(worldItemBase, mapPointOfMouse.x), mapPointOfMouse.y);
			if (base)
			{
				std::string s = base->klass->name;
				if (string_ToLowercase(s).find("portal") != -1)
				{
					const MethodInfo* PortalGetEntryPointID = il2cpp_class_get_method_from_name(base->klass, "GetEntryPointID", 0);
					const MethodInfo* SceneLoaderCheckIfWeCanGoFromWorldToWorld = il2cpp_class_get_method_from_name((Il2CppClass*)Globals::Classes["Assembly-CSharp.SceneLoader"], "CheckIfWeCanGoFromWorldToWorld", 5);
					Il2CppObject* world = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world" });
					Il2CppObject* worldName = il2cpp_object_get_field_value_by_name(world, Il2CppObject*, world->Il2CppClass.klass, "worldName"); //Il2Cpp::Helpers::GetFieldValue<Il2CppObject*>("worldName", world);

					Il2CppObject* entryId = il2cpp_runtime_invoke(PortalGetEntryPointID, base, nullptr, nullptr);
					il2cpp_runtime_invoke(SceneLoaderCheckIfWeCanGoFromWorldToWorld, nullptr, Il2Cpp::Helpers::GenerateArgs({ worldName, entryId, nullptr, new bool{false}, nullptr }), nullptr);

				}
			}
		}
		if (io.KeyAlt && io.MouseClicked[0])
		{
			const static auto AsynchronousClient_SendMessages0 = reinterpret_cast<bool(*)(Il2CppObject * pThis)>(Globals::Methods["System.Boolean Assembly-CSharp.AsynchronousClient.SendMessages()"]->methodPointer);
			const static auto OutgoingMessages_TurnMessagesToBytesAndConsumeThem0 = reinterpret_cast<Il2CppArrayT<unsigned char>* (*)()>(Globals::Methods["System.Byte[] Assembly-CSharp.OutgoingMessages.TurnMessagesToBytesAndConsumeThem()"]->methodPointer);
			//ScopedConsoleTimer s;
			std::vector<Vector2i> foundPath = FindPath(playerMapPoint, mapPointOfMouse, worldBlocks, worldItemBase);
			if (foundPath.size() > 0/* && foundPath.size() < 17*/)
			{
				Transform* myTransform = localPlayer->myTransform;

				/*if (foundPath.size() < 17)
				{*/
					for (int i = 0; i < foundPath.size(); i++)
					{
						recentMapPoints->Add(foundPath[i]);
					}
					if (Globals::MapPointExploitBools["Teleport to Map Point"].value)
					{
						Vector2 bruh = ConvertMapPointToWorldPoint(ConvertWorldPointToMapPoint(worldPointOfMouse));
						Vector3 a = { bruh.x, bruh.y, 0 };
						a.y -= boxSize.y / 2.4f;
						myTransform->SetPosition(a);
					}
					else
					{
						Vector3 a = { worldPointOfMouse.x, worldPointOfMouse.y, 0 };
						myTransform->SetPosition(a);
					}
					if (Globals::MapPointExploitBools["Send position packet"].value)
					{
						//hkSendPlayerPosition0();
						const static auto OutgoingMessages_AddOneMessageToList1 = reinterpret_cast<void(*)(Il2CppObject */*Kernys.Bson.BSONObject*/ toAdd)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.AddOneMessageToList(Kernys.Bson.BSONObject,)"]->methodPointer);
						il2cpp_object_make(bobj, Il2CppObject*, Globals::Classes["Assembly-CSharp.BSONObject"]);

						FieldInfo* field = &bobj->Il2CppClass.klass->fields[0];
						Il2CppDictionaryT<Il2CppString*, BSONValue*>* map = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(bobj, void*, field->offset);

						il2cpp_object_make(bv, BSONValue*, map->GetTValue());
						bv->mValueType = BSONValue::ValueType::String;
						bv->_string = istr("mP");
						map->Add(istr("ID"), bv);

						il2cpp_object_remake(bv, BSONValue*, map->GetTValue());
						bv->mValueType = BSONValue::ValueType::Int64;
						bv->int64 = 100000;
						map->Add(istr("t"), bv);

						il2cpp_object_remake(bv, BSONValue*, map->GetTValue());
						bv->mValueType = BSONValue::ValueType::Double;
						bv->_double = Globals::playerInfo.position.x;
						map->Add(istr("x"), bv);

						il2cpp_object_remake(bv, BSONValue*, map->GetTValue());
						bv->mValueType = BSONValue::ValueType::Double;
						bv->_double = Globals::playerInfo.position.y;
						map->Add(istr("y"), bv);

						il2cpp_object_remake(bv, BSONValue*, map->GetTValue());
						bv->mValueType = BSONValue::ValueType::Int32;
						bv->int32 = 1;
						map->Add(istr("a"), bv);

						il2cpp_object_remake(bv, BSONValue*, map->GetTValue());
						bv->mValueType = BSONValue::ValueType::Int32;
						bv->int32 = 3;
						map->Add(istr("d"), bv);

						il2cpp_object_remake(bv, BSONValue*, map->GetTValue());
						bv->mValueType = BSONValue::ValueType::Boolean;
						bv->_bool = true;
						map->Add(istr("tp"), bv);

						OutgoingMessages_AddOneMessageToList1(bobj);
					}
				/*}
				else
				{
					int i = 0;
					for (i = 0; i < std::min((int)foundPath.size(), 16); i++)
					{
						recentMapPoints->Add(foundPath[i]);
					}
					Vector2 bruh = ConvertMapPointToWorldPoint(foundPath[i - 1]);
					Vector3 a = { bruh.x, bruh.y, 0 };
					a.y -= boxSize.y / 2.4f;
					myTransform->SetPosition(a);
					if (!Globals::ToggleBools["Lag Ghost"].value)
					{
						waitingPos = a;
						foundPath_s = std::vector<Vector2i>(foundPath.begin() + i, foundPath.end());
						isWaitingForNextChunk = true;
					}
				}*/
			}
		}
		if (isWaitingForNextChunk)
		{
			waitAmount_h += Globals::deltaTime;
			Il2CppObject* myTransform = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myTransform" });
			PropertyInfo* position = (PropertyInfo*)il2cpp_class_get_property_from_name(myTransform->Il2CppClass.klass, "position");
			il2cpp_runtime_invoke(position->set, myTransform, Il2Cpp::Helpers::GenerateArgs({ &waitingPos }), nullptr);
		}
		if (io.KeyCtrl && io.MouseDown[0] && (io.MouseClicked[0] || (mapPointOfMouseLFrame != mapPointOfMouse)))
		{
			if (io.KeyShift)
			{
				std::vector<Vector2i> foundPath = FindPath(playerMapPoint, mapPointOfMouse, worldBlocks, worldItemBase);
				std::vector<Vector2i> foundPathBack = FindPath(mapPointOfMouse, playerMapPoint, worldBlocks, worldItemBase);
				if (foundPath.size() > 0 && foundPathBack.size() > 0 && foundPath.size() + foundPathBack.size() < 17)
				{
					for (int i = 0; i < foundPath.size(); i++)
					{
						recentMapPoints->Add(foundPath[i]);
						PickupMapPoint(collectableList, foundPath[i]);
					}
					for (int i = 0; i < foundPathBack.size(); i++)
					{
						recentMapPoints->Add(foundPathBack[i]);
					}
				}
			}
			else
			{
				std::vector<int> collectableIds = {};
				for (int i = 0; i < collectableList->size; i++)
				{
					if (collectableList->arry->vector[i]->mapPoint == mapPointOfMouse)
						collectableIds.push_back(collectableList->arry->vector[i]->id);
				}
				if (collectableIds.size() > 0)
				{
					std::vector<Vector2i> foundPath = FindPath(playerMapPoint, mapPointOfMouse, worldBlocks, worldItemBase);
					std::vector<Vector2i> foundPathBack = FindPath(mapPointOfMouse, playerMapPoint, worldBlocks, worldItemBase);
					const static MethodInfo* SendCollectCollectableMessage = Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendCollectCollectableMessage(System.Int32,)"];
					if (foundPath.size() > 0 && foundPathBack.size() > 0 && foundPath.size() + foundPathBack.size() < 17)
					{
						for (int i = 0; i < foundPath.size(); i++)
						{
							recentMapPoints->Add(foundPath[i]);
						}
						for (int i = 0; i < collectableIds.size(); i++)
						{
							reinterpret_cast<void(*)(int id)>(SendCollectCollectableMessage->methodPointer)(collectableIds[i]);
						}
						for (int i = 0; i < foundPathBack.size(); i++)
						{
							recentMapPoints->Add(foundPathBack[i]);
						}
					}
				}
			}
		}
		if (io.KeyCtrl && io.MouseClicked[1])
		{
			const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
			InventoryControl* inventoryControl = (InventoryControl*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "gameplayUI", "inventoryControl" });
			const static auto InventoryControl_GetCurrentSelection0 = reinterpret_cast<InventoryKey(*)(InventoryControl * pThis)>(Globals::Methods["PlayerData.InventoryKey Assembly-CSharp.InventoryControl.GetCurrentSelection()"]->methodPointer);
			static auto PlayerData_GetCount = reinterpret_cast<short(*)(PlayerData * pThis, InventoryKey ik)>(Globals::Methods["System.Int16 Assembly-CSharp.PlayerData.GetCount(PlayerData.InventoryKey,)"]->methodPointer);
			const static auto WorldController_DropStuffFromInventory4 = reinterpret_cast<void(*)(Il2CppObject* pThis, Vector2i/*BasicTypes.Vector2i*/ mapPoint, InventoryKey/*PlayerData.InventoryKey*/ inventoryKey, short/*System.Int16*/ amount, Il2CppObject*/*InventoryItemBase*/ inventoryData)>(Globals::Methods["System.Void Assembly-CSharp.WorldController.DropStuffFromInventory(BasicTypes.Vector2i,PlayerData.InventoryKey,System.Int16,InventoryItemBase,)"]->methodPointer);

			InventoryKey ik = InventoryControl_GetCurrentSelection0(inventoryControl);

			std::vector<Vector2i> foundPath = FindPath(playerMapPoint, mapPointOfMouse, worldBlocks, worldItemBase);
			std::vector<Vector2i> foundPathBack = FindPath(mapPointOfMouse, playerMapPoint, worldBlocks, worldItemBase);
			if (foundPath.size() > 0 && foundPathBack.size() > 0 && foundPath.size() + foundPathBack.size() < 17)
			{
				for (int i = 0; i < foundPath.size(); i++)
				{
					recentMapPoints->Add(foundPath[i]);
				}
				int count = PlayerData_GetCount(localPlayerData, ik);
				WorldController_DropStuffFromInventory4(worldController, mapPointOfMouse, ik, count, nullptr);
				for (int i = 0; i < foundPathBack.size(); i++)
				{
					recentMapPoints->Add(foundPathBack[i]);
				}
			}
		}
		if (Globals::MiningBools["Auto-Mine"].value)
		{
			static bool firstTimeSet = false;
			static int currentPointInPath = 0;
			static bool isTravelling = false;
			static int priorityIndex = 0;
			static bool refindingPath = false;
			if (!isTravelling || refindingPath)
			{
				bool inMineWorld = (cppstr(il2cpp_object_get_field_value_by_name(world, Il2CppString*, world->Il2CppClass.klass, "worldName")) == "MINEWORLD");
				if (inMineWorld)
				{
					int priority = Globals::miningOrder[priorityIndex];
					switch (priority)
					{
					case 0:
					{
						if (collectableList->size > 0)
						{
							float shortestDist = INFINITY;
							CollectableData* closestCollectable = nullptr;
							for (int i = 0; i < collectableList->size; i++)
							{
								Vector2 pos = ConvertMapPointToWorldPoint(collectableList->arry->vector[i]->posX, collectableList->arry->vector[i]->posY);
								float dist = pos.Distance(Globals::playerInfo.position);
								if (dist < shortestDist)
								{
									shortestDist = dist;
									closestCollectable = collectableList->arry->vector[i];
								}
							}
							foundPathThroughBlocks = FindPathThroughBlocks(playerMapPoint, closestCollectable->mapPoint, worldBlocks, worldItemBase, worldController, inMineWorld);
					
							firstTimeSet = true;
							currentPointInPath = 0;
							isTravelling = true;
						}
						else
						{
							priorityIndex++;
							if (priorityIndex > Globals::miningOrder.size())
								priorityIndex = 0;
						}
						break;
					}
					case 1:
					{
						const static auto ConfigData_GetGemstoneRecycleValueForMiningGemstoneRecycler1 = reinterpret_cast<int(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["System.Int32 Assembly-CSharp.ConfigData.GetGemstoneRecycleValueForMiningGemstoneRecycler(World.BlockType,)"]->methodPointer);
						LayerBlock closestMiningGemstone = {};
						Vector2i closestMapPoint = {};
						float shortestDist = INFINITY;
						for (int x = 0; x < worldSize.x; x++)
						{
							for (int y = 0; y < worldSize.y; y++)
							{
								Vector2i point{ x, y };
								LayerBlock& curLayerBlock = GetBlockAtMapPoint(point, worldBlocks);
								if (IsGemBlock(curLayerBlock.blockType))
								{
									float dist = ConvertMapPointToWorldPoint(point).Distance(Globals::playerInfo.position);
									if (dist < shortestDist)
									{
										shortestDist = dist;
										closestMiningGemstone = curLayerBlock;
										closestMapPoint = point;
									}
								}
							}
						}

						if (closestMapPoint != Vector2i{})
						{
							foundPathThroughBlocks = FindPathThroughBlocks(playerMapPoint, closestMapPoint, worldBlocks, worldItemBase, worldController, inMineWorld);
							firstTimeSet = true;
							currentPointInPath = 0;
							isTravelling = true;
						}
						else
						{
							priorityIndex++;
							if (priorityIndex > Globals::miningOrder.size())
								priorityIndex = 0;
						}
						break;
					}
					case 2:
					{
						Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>* aiEnemiesd = (Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "aiEnemyMonoBehaviours" });
						if (aiEnemiesd)
						{
							AIEnemyMonoBehaviourBase* closestAiEnemy = nullptr;
							float shortestDist = INFINITY;
							Il2CppArrayT<AIEnemyMonoBehaviourBase*>* values = aiEnemiesd->GetValues();
							for (int i = 0; i < values->max_length; i++)
							{
								AIEnemyMonoBehaviourBase* aiEnemy = values->vector[i];
								if (!aiEnemy || !aiEnemy->aiBase)
									continue;
								
								float dist = Vector2(aiEnemy->tempPosition).Distance(Globals::playerInfo.position);
								const static auto AIEnemyConfigData_GetMaxHitPoints1 = reinterpret_cast<int(*)(int/*AIEnemyType*/ enemyType)>(Globals::Methods["System.Int32 Assembly-CSharp.AIEnemyConfigData.GetMaxHitPoints(AIEnemyType,)"]->methodPointer);
								if (dist < shortestDist)
								{
									shortestDist = dist;
									closestAiEnemy = aiEnemy;
								}
							}
							if (closestAiEnemy)
							{
								foundPathThroughBlocks = FindPathThroughBlocks(playerMapPoint, ConvertWorldPointToMapPoint(closestAiEnemy->tempPosition), worldBlocks, worldItemBase, worldController, inMineWorld);
								if (!refindingPath)
								{
									firstTimeSet = true;
								}
								else
									refindingPath = false;
								currentPointInPath = 0;
								isTravelling = true;
								
							}
							else
							{
								priorityIndex++;
								if (priorityIndex > Globals::miningOrder.size())
									priorityIndex = 0;
							}
						}
						break;
					}
					default:
						isTravelling = false;
						break;
					}
					
				}
			}
			if (currentPointInPath >= foundPathThroughBlocks.size())
			{
				const static auto OutgoingMessages_SendHitAIEnemyMessage3 = reinterpret_cast<void(*)(Vector2i/*BasicTypes.Vector2i*/ mapPoint, int/*System.Int32*/ aiID, int/*System.Int32*/ randomHitTextIndex)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendHitAIEnemyMessage(BasicTypes.Vector2i,System.Int32,System.Int32,)"]->methodPointer);
				currentPointInPath = 0;
				isTravelling = false;
				Globals::ToggleBools["Keys to Fly"].value = false;
				foundPathThroughBlocks.clear();
				if (priorityIndex >= Globals::miningOrder.size())
					priorityIndex = 0;
				int priority = Globals::miningOrder[priorityIndex];
				if (priority == 2)
				{
					Globals::ToggleBools["Keys to Fly"].value = true;
					static float timel = 0.f;
					timel += Globals::deltaTime;
					if (timel > 0.15f)
					{
						timel = 0.f;
						Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>* aiEnemiesd = (Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "aiEnemyMonoBehaviours" });
						if (aiEnemiesd)
						{
							AIEnemyMonoBehaviourBase* closestAiEnemy = nullptr;
							float shortestDist = INFINITY;
							Il2CppArrayT<AIEnemyMonoBehaviourBase*>* values = aiEnemiesd->GetValues();
							for (int i = 0; i < values->max_length; i++)
							{
								AIEnemyMonoBehaviourBase* aiEnemy = values->vector[i];
								if (!aiEnemy || !aiEnemy->aiBase)
									continue;

								float dist = Vector2(aiEnemy->tempPosition).Distance(Globals::playerInfo.position);
								const static auto AIEnemyConfigData_GetMaxHitPoints1 = reinterpret_cast<int(*)(int/*AIEnemyType*/ enemyType)>(Globals::Methods["System.Int32 Assembly-CSharp.AIEnemyConfigData.GetMaxHitPoints(AIEnemyType,)"]->methodPointer);
								if (dist < shortestDist /*&& AIEnemyConfigData_GetMaxHitPoints1(aiEnemy->aiBase->enemyType) != 50*/)
								{
									shortestDist = dist;
									closestAiEnemy = aiEnemy;
								}
							}
							if (closestAiEnemy)
							{
								if (closestAiEnemy->aiBase->health > 0)
									isTravelling = true;
								OutgoingMessages_SendHitAIEnemyMessage3(ConvertWorldPointToMapPoint(closestAiEnemy->tempPosition), closestAiEnemy->aiBase->id, 1);
							}
						}
					}
				}
			}
			if (foundPathThroughBlocks.size() > 0 && currentPointInPath < foundPathThroughBlocks.size())
			{
				Globals::ToggleBools["Keys to Fly"].value = true;
				bool atMapPoint = BringPlayerToMapPoint(foundPathThroughBlocks[currentPointInPath], localPlayer, extraMoveX, extraMoveY, boxSize);
				if (DoesMapPointHaveColider(foundPathThroughBlocks[currentPointInPath], worldBlocks))
				{
					const static auto OutgoingMessages_SendHitBlockMessage3 = reinterpret_cast<void(*)(Vector2i/*BasicTypes.Vector2i*/ mapPoint, DateTime/*System.DateTime*/ hitTime, bool/*System.Boolean*/ doNotDestroy)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendHitBlockMessage(BasicTypes.Vector2i,System.DateTime,System.Boolean,)"]->methodPointer);
					static float timel = 0.f;
					timel += Globals::deltaTime;
					if (timel > 0.15f)
					{
						timel = 0.f;
						OutgoingMessages_SendHitBlockMessage3(foundPathThroughBlocks[currentPointInPath], DateTime{ 0 }, false);
						hkWorldController_DoBlockHitAction9(worldController, 0.0f, true, foundPathThroughBlocks[currentPointInPath], 0, (Il2CppObject*)localPlayerData, istr(Globals::playerInfo.id.c_str()), true, true, false);
					}
				}
				if (atMapPoint)
				{
					Vector2 p = ConvertMapPointToWorldPoint(foundPathThroughBlocks[currentPointInPath]);
					localPlayer->myTransform->SetPosition(Vector3{ p.x, p.y - boxSize.y / 2.4f, 0 });
					currentPointInPath++;
				}
				if (firstTimeSet)
				{
					Vector2 p = ConvertMapPointToWorldPoint(playerMapPoint);
					localPlayer->myTransform->SetPosition(Vector3{ p.x, p.y, 0 });
					firstTimeSet = false;
				}
				int priority = Globals::miningOrder[priorityIndex];
				if (priority == 2)
				{
					Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>* aiEnemiesd = (Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "aiEnemyMonoBehaviours" });
					if (aiEnemiesd)
					{
						AIEnemyMonoBehaviourBase* closestAiEnemy = nullptr;
						float shortestDist = INFINITY;
						Il2CppArrayT<AIEnemyMonoBehaviourBase*>* values = aiEnemiesd->GetValues();
						for (int i = 0; i < values->max_length; i++)
						{
							AIEnemyMonoBehaviourBase* aiEnemy = values->vector[i];
							if (!aiEnemy || !aiEnemy->aiBase)
								continue;

							float dist = Vector2(aiEnemy->tempPosition).Distance(Globals::playerInfo.position);
							const static auto AIEnemyConfigData_GetMaxHitPoints1 = reinterpret_cast<int(*)(int/*AIEnemyType*/ enemyType)>(Globals::Methods["System.Int32 Assembly-CSharp.AIEnemyConfigData.GetMaxHitPoints(AIEnemyType,)"]->methodPointer);
							if (dist < shortestDist /*&& AIEnemyConfigData_GetMaxHitPoints1(aiEnemy->aiBase->enemyType) != 50*/)
							{
								shortestDist = dist;
								closestAiEnemy = aiEnemy;
							}
						}
						if (closestAiEnemy)
						{
							if (ConvertWorldPointToMapPoint(closestAiEnemy->tempPosition) != foundPathThroughBlocks.back())
							{
								isTravelling = false;
								foundPathThroughBlocks.clear();
								refindingPath = true;
							}
						}
					}
				}
			}

			if (collectableList->size <= 0)
			{
				Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>* aiEnemiesd = (Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "aiEnemyMonoBehaviours" });
				if (aiEnemiesd)
				{
					Il2CppArrayT<AIEnemyMonoBehaviourBase*>* values = aiEnemiesd->GetValues();
					static int n = 0;
					for (int i = 0; i < values->max_length; i++)
					{
						if (values && values->vector[i] && values->vector[i]->aiBase)
							n++;
					}
					if (n <= 0)
					{
						bool hasGemBlock = false;
						for (int x = 0; x < worldSize.x; x++)
						{
							for (int y = 0; y < worldSize.y; y++)
							{
								Vector2i point{ x, y };
								LayerBlock& curLayerBlock = GetBlockAtMapPoint(point, worldBlocks);
								if (IsGemBlock(curLayerBlock.blockType))
								{
									hasGemBlock = true;
									break;
								}
							}
						}
						if (hasGemBlock)
						{
							Globals::MiningBools["Auto-Mine"].value = false;
							priorityIndex = 0;
							currentPointInPath = 0;
							refindingPath = false;
							isTravelling = false;
							foundPathThroughBlocks.clear();
						}

					}
				}
			}
		}

		if (io.KeysDownDuration[VK_F6] == 0.f)
		{
			const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
			InventoryControl* inventoryControl = (InventoryControl*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "gameplayUI", "inventoryControl" });
			const static auto InventoryControl_GetCurrentSelection0 = reinterpret_cast<InventoryKey(*)(InventoryControl * pThis)>(Globals::Methods["PlayerData.InventoryKey Assembly-CSharp.InventoryControl.GetCurrentSelection()"]->methodPointer);
			static auto PlayerData_GetCount = reinterpret_cast<short(*)(PlayerData * pThis, InventoryKey ik)>(Globals::Methods["System.Int16 Assembly-CSharp.PlayerData.GetCount(PlayerData.InventoryKey,)"]->methodPointer);
			const static auto OutgoingMessages_RecycleFish2 = reinterpret_cast<void(*)(InventoryKey/*PlayerData.InventoryKey*/ fishIK, short/*System.Int16*/ amount)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.RecycleFish(PlayerData.InventoryKey,System.Int16,)"]->methodPointer);
			const static auto PlayerData_RemoveItemsFromInventory2 = reinterpret_cast<void(*)(PlayerData * pThis, InventoryKey/*PlayerData.InventoryKey*/ inventoryKey, short/*System.Int16*/ amount)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.RemoveItemsFromInventory(PlayerData.InventoryKey,System.Int16,)"]->methodPointer);
			//const static auto WorldController_DropStuffFromInventory4 = reinterpret_cast<void(*)(Il2CppObject * pThis, Vector2i/*BasicTypes.Vector2i*/ mapPoint, InventoryKey/*PlayerData.InventoryKey*/ inventoryKey, short/*System.Int16*/ amount, Il2CppObject */*InventoryItemBase*/ inventoryData)>(Globals::Methods["System.Void Assembly-CSharp.WorldController.DropStuffFromInventory(BasicTypes.Vector2i,PlayerData.InventoryKey,System.Int16,InventoryItemBase,)"]->methodPointer);

			InventoryKey ik = InventoryControl_GetCurrentSelection0(inventoryControl);

			if (ik.blockType)
			{
				int count = PlayerData_GetCount(localPlayerData, ik);
				OutgoingMessages_RecycleFish2(ik, count);
				PlayerData_RemoveItemsFromInventory2(localPlayerData, ik, count);
			}
		}
		
		if (io.KeysDown[VK_F7])
		{
			const static auto OutgoingMessages_SendResurrect2 = reinterpret_cast<void(*)(DateTime/*System.DateTime*/ clientTimestamp, Vector2i/*BasicTypes.Vector2i*/ mapPoint)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendResurrect(System.DateTime,BasicTypes.Vector2i,)"]->methodPointer);
			const static auto KukouriTime_Get0 = reinterpret_cast<DateTime(*)()>(Globals::Methods["System.DateTime Assembly-CSharp.KukouriTime.Get()"]->methodPointer);
			const static auto OutgoingMessages_ForceKillPlayerByBlockHit3 = reinterpret_cast<void(*)(int/*World.BlockType*/ blocktype, Vector2i/*BasicTypes.Vector2i*/ blockMapPoint, DateTime/*System.DateTime*/ clientTimestamp)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.ForceKillPlayerByBlockHit(World.BlockType,BasicTypes.Vector2i,System.DateTime,)"]->methodPointer);
			DateTime t = KukouriTime_Get0();
			t.dateData -= 1000;
			OutgoingMessages_ForceKillPlayerByBlockHit3((int)World_BlockType__Enum::SpikeBall, mapPointOfMouse,t);
			t.dateData += 1000;
			OutgoingMessages_SendResurrect2(t, localPlayer->respawnMapPoint);
		}
		if (Globals::IsInWorld && Globals::MiscBools["Blackbot"].value)
		{
			Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
			bool& isSkinColorByWeapon = il2cpp_object_get_field_value_by_name(localPlayer, bool, localPlayer->klass, "isSkinColorByWeapon");

			int gender = rand() % 2;
			int country = rand() % 999;
			int skinColor = rand() % 15;
			int skinColor2 = rand() % 15;

			const static auto OutgoingMessages_PlayerInfoUpdated4 = reinterpret_cast<void(*)(int/*PlayerData.Gender*/ gender, short/*System.Int16*/ countryCode, int/*System.Int32*/ skinColor, int/*System.Int32*/ skinColorBeforeOverride)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.PlayerInfoUpdated(PlayerData.Gender,System.Int16,System.Int32,System.Int32,)"]->methodPointer);
			OutgoingMessages_PlayerInfoUpdated4(gender, country, skinColor, skinColor2);
		}
#endif
		{
			Il2CppObject* kukouriCamera = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "kukouriCamera" });
			Transform* myTransform = (Transform*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "kukouriCamera", "myTransform" });
			if (Globals::ToggleBools["Freecam"].value)
			{
				static Vector2 worldMousePointWhenC = {};
				if (io.MouseDownDuration[1] == 0.f)
				{
					worldMousePointWhenC = worldPointOfMouse;
				}
				if (io.MouseDown[1] && io.MouseDownDuration[1] > 0.01)
				{
					Vector2 diff = { worldMousePointWhenC.x - worldPointOfMouse.x, worldMousePointWhenC.y - worldPointOfMouse.y };
					Vector3 curPos = myTransform->GetPosition();
					myTransform->SetPosition({ (float)((double)curPos.x + (double)diff.x), (float)((double)curPos.y + (double)diff.y), 0 });
				}
			}
		}
		if (Globals::BasicsBools["Insta-Die"])
		{
			float& isDeadTimeCounter = il2cpp_object_get_field_value_by_name(localPlayer, float, localPlayer->klass, "isDeadTimeCounter");
			isDeadTimeCounter = 500.f;
		}
		if (Globals::FishingBools["Semi-Auto + Bypass Fishing Anti-Cheat"] && reinterpret_cast<bool(*)(Player* pThis)>(Globals::Methods["System.Boolean Assembly-CSharp.Player.IsFishStrikeActive()"]->methodPointer)(localPlayer))
		{
			hasPulledCurrentFish = false;
			keybd_event('W', 0, 0, 0);
			keybd_event('W', 0, KEYEVENTF_KEYUP, 0);
			tryCasting = true;
			//forntie = false;
		}
		if (Globals::MiscBools["Auto-Die"].value)
		{
			reinterpret_cast<void(*)(Player* pThis, int hitForce, int blockType, Vector2i mapPoint)>(oHitPlayerFromBlock3_0)(localPlayer, 99999, 7, {0, 0});
		}
		if (Globals::MiscBools["Double Press to Dash"].value)
		{
			static float timeSinceLastAPress = 0.f;
			static float timeSinceLastDPress = 0.f;
			static auto f = reinterpret_cast<void(*)(int at, int abt)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendPlayPlayerAudioMessage(System.Int32,System.Int32,)"]->methodPointer);

			if (io.KeysDownDuration['A'] == 0.f && timeSinceLastAPress > Globals::DashTolerency)
				timeSinceLastAPress = 0.f;
			else if (io.KeysDownDuration['A'] == 0.f)
			{
				timeSinceLastAPress = 0.f;
				playerVelocity.x = -5;
				//f(Globals::audioTypeToPlay, Globals::audioBlockTypeToPlay);

				//Console.AddLog("Dashed left");
			}

			if (io.KeysDownDuration['D'] == 0.f && timeSinceLastDPress > Globals::DashTolerency)
				timeSinceLastDPress = 0.f;
			else if (io.KeysDownDuration['D'] == 0.f)
			{
				timeSinceLastDPress = 0.f;
				playerVelocity.x = 5;
				//f(Globals::audioTypeToPlay, Globals::audioBlockTypeToPlay);

				//Console.AddLog("Dashed right");
			}

			timeSinceLastDPress += Globals::deltaTime;
			timeSinceLastAPress += Globals::deltaTime;
		}
		if (Globals::ToggleBools["Keys to Fly"].value)
		{
			// xddd here
			// sex

			bool useFlagX = false;
			bool useFlagY = false;
			Vector2& v = il2cpp_object_get_field_value_by_name(localPlayer, Vector2, localPlayer->klass, "velocity");//Il2Cpp::Helpers::GetFieldValue<Vector3>("velocity", localPlayer);
			float playerGravity = 9.f;
			if (Globals::playerStatus != StatusIconType::Typing && Globals::playerStatus != StatusIconType::InMenus)
			{
				if (io.KeysDown['W'])
				{
					v.y = keysMoveSpeed;
					useFlagY = true;
				}
				if (io.KeysDown['S'])
				{
					v.y = -keysMoveSpeed;
					useFlagY = true;
				}

				if (io.KeysDown['A'])
				{
					v.x = -keysMoveSpeed;
					useFlagX = true;
				}
				else if (io.KeysDown['D'])
				{
					v.x = keysMoveSpeed;
					useFlagX = true;
				}
			}
			if (!useFlagY && !extraMoveY)
			{
				v.y = playerGravity * Globals::deltaTime;
			}
			if (!useFlagX && !extraMoveX)
			{
				v.x = 0;
			}

		}
		if (Globals::MiscBools["No-Clip"].value)
		{
			localPlayer->playerCharacterController2D->totalHorizontalRays = 0;
			localPlayer->playerCharacterController2D->totalVerticalRays = 0;
		}
		if (Globals::autoNether)
		{
			static bool firstTimeSet = false;
			static int currentPointInPath = 0;
			static bool isTravelling = false;
			static bool killedAllMonsters = false;

			//if (!isTravelling)
			//{
				bool inNetherWorld = (cppstr(il2cpp_object_get_field_value_by_name(world, Il2CppString*, world->Il2CppClass.klass, "worldName")) == "NETHERWORLD");
				if (!killedAllMonsters)
				{
					Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>* aiEnemiesd = (Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "aiEnemyMonoBehaviours" });
					if (aiEnemiesd)
					{
						Il2CppArrayT<AIEnemyMonoBehaviourBase*>* values = aiEnemiesd->GetValues();
						AIEnemyMonoBehaviourBase* closestAiEnemy = nullptr;
						float shortestDist = INFINITY;
						for (int i = 0; i < values->max_length; i++)
						{
							AIEnemyMonoBehaviourBase* aiEnemy = values->vector[i];
							if (!aiEnemy || !aiEnemy->aiBase)
								continue;

							float dist = Vector2(aiEnemy->tempPosition).Distance(Globals::playerInfo.position);
							const static auto AIEnemyConfigData_GetMaxHitPoints1 = reinterpret_cast<int(*)(int/*AIEnemyType*/ enemyType)>(Globals::Methods["System.Int32 Assembly-CSharp.AIEnemyConfigData.GetMaxHitPoints(AIEnemyType,)"]->methodPointer);
							if (dist < shortestDist && AIEnemyConfigData_GetMaxHitPoints1(aiEnemy->aiBase->enemyType) > 50)
							{
								shortestDist = dist;
								closestAiEnemy = aiEnemy;
							}
						}
						if (closestAiEnemy)
						{
							foundPathToClosestEnemy = FindPathThroughNether(playerMapPoint, ConvertWorldPointToMapPoint(closestAiEnemy->tempPosition), worldBlocks, worldItemBase);
							if (foundPathToClosestEnemy.size() > 0)
							{
								firstTimeSet = true;
								currentPointInPath = 0;
								isTravelling = true;
							}
						}
						else
						{
							killedAllMonsters = true;
						}
					}
				}
				else if (!isTravelling)
				{
					
					if (collectableList->size > 0)
					{
						float shortestDist = INFINITY;
						CollectableData* closestCollectable = nullptr;
						for (int i = 0; i < collectableList->size; i++)
						{
							Vector2 pos = ConvertMapPointToWorldPoint(collectableList->arry->vector[i]->posX, collectableList->arry->vector[i]->posY);
							float dist = pos.Distance(Globals::playerInfo.position);
							if (dist < shortestDist)
							{
								shortestDist = dist;
								closestCollectable = collectableList->arry->vector[i];
							}
						}
						foundPathToClosestEnemy = FindPathThroughNether(playerMapPoint, closestCollectable->mapPoint, worldBlocks, worldItemBase);

						firstTimeSet = true;
						currentPointInPath = 0;
						isTravelling = true;
					}
					else
					{
						for (int x = 0; x < worldSize.x; x++)
						{
							for (int y = 0; y < worldSize.y; y++)
							{
								Vector2i point{ x, y };
								LayerBlock& curLayerBlock = GetBlockAtMapPoint(point, worldBlocks);
								if (curLayerBlock.blockType == 1419 && playerMapPoint != point)
								{
									foundPathToClosestEnemy = FindPathThroughNether(playerMapPoint, point, worldBlocks, worldItemBase);
									firstTimeSet = true;
									currentPointInPath = 0;
									isTravelling = true;
								}
							}
						}
					}
				}
				
			//}

			{
				static float tel = 0.0f;
				tel += Globals::deltaTime;
				if (tel > 0.15f)
				{
					tel = 0.0f;
					const static auto OutgoingMessages_SendHitAIEnemyMessage3 = reinterpret_cast<void(*)(Vector2i/*BasicTypes.Vector2i*/ mapPoint, int/*System.Int32*/ aiID, int/*System.Int32*/ randomHitTextIndex)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendHitAIEnemyMessage(BasicTypes.Vector2i,System.Int32,System.Int32,)"]->methodPointer);
					Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>* aiEnemiesd = (Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "aiEnemyMonoBehaviours" });
					if (aiEnemiesd)
					{
						AIEnemyMonoBehaviourBase* closestAiEnemy = nullptr;
						float shortestDist = INFINITY;
						Il2CppArrayT<AIEnemyMonoBehaviourBase*>* values = aiEnemiesd->GetValues();
						for (int i = 0; i < values->max_length; i++)
						{
							AIEnemyMonoBehaviourBase* aiEnemy = values->vector[i];
							if (!aiEnemy || !aiEnemy->aiBase)
								continue;

							float dist = Vector2(aiEnemy->tempPosition).Distance(Globals::playerInfo.position);
							const static auto AIEnemyConfigData_GetMaxHitPoints1 = reinterpret_cast<int(*)(int/*AIEnemyType*/ enemyType)>(Globals::Methods["System.Int32 Assembly-CSharp.AIEnemyConfigData.GetMaxHitPoints(AIEnemyType,)"]->methodPointer);
							if (dist < shortestDist && AIEnemyConfigData_GetMaxHitPoints1(aiEnemy->aiBase->enemyType) != 50)
							{
								shortestDist = dist;
								closestAiEnemy = aiEnemy;
							}
						}
						if (closestAiEnemy)
						{
							if (closestAiEnemy->aiBase->health > 0)
								OutgoingMessages_SendHitAIEnemyMessage3(ConvertWorldPointToMapPoint(closestAiEnemy->tempPosition), closestAiEnemy->aiBase->id, 1);
						}
					}
				}
			}

			if (isTravelling)
			{
				if (currentPointInPath >= foundPathToClosestEnemy.size())
				{
					foundPathToClosestEnemy.clear();
					currentPointInPath = 0;
					isTravelling = false;
				}
				if (foundPathToClosestEnemy.size() > 0 && currentPointInPath < foundPathToClosestEnemy.size())
				{
					Globals::ToggleBools["Keys to Fly"].value = true;
					bool atMapPoint = BringPlayerToMapPoint(foundPathToClosestEnemy[currentPointInPath], localPlayer, extraMoveX, extraMoveY, boxSize);
					if (playerMapPoint.y > foundPathToClosestEnemy[currentPointInPath].y && DoesBlockHaveColliderOneWay(GetBlockAtMapPoint(foundPathToClosestEnemy[currentPointInPath], worldBlocks).blockType))
					{
						Vector2 p = ConvertMapPointToWorldPoint(foundPathToClosestEnemy[currentPointInPath]);
						localPlayer->myTransform->SetPosition(Vector3{ p.x, p.y, 0.0f });
					}

					if (atMapPoint)
					{
						currentPointInPath++;
					}
					
				}
			}
		}
#ifndef AAPUBLICMODE

		if (Globals::MapPointExploitBools["Anti-Kick flight"].value)
		{
			static float elTime = 0.f;
			hkSendPlayerPosition0();

			elTime += Globals::deltaTime;
			if (elTime > Globals::antiKickTimeout)
			{
				elTime = 0.f;
				std::vector<Vector2i> foundPath = FindPathDown(playerMapPoint, worldBlocks);
				if (foundPath.size() > 0)
				{
					if (foundPath.size() * 2 < 17)
					{
						for (int i = 0; i < foundPath.size(); i++)
						{
							recentMapPoints->Add(foundPath[i]);
						}
						for (int i = 0; i < foundPath.size(); i++)
						{
							recentMapPoints->Add(foundPath[foundPath.size() - i - 1]);
						}
					}
					else
					{
						Console.AddLog("Anti Kick out of range!");
					}
				}
			}
		}
#endif
		if (Globals::playerPlayStaticAnim)
		{
			const static auto Player_PlayMainAnimation4 = reinterpret_cast<void(*)(Player * pThis, int/*AnimationNames*/ animation, float/*System.Single*/ targetPositionX, float/*System.Single*/ targetPositionY, float/*System.Single*/ rotatingTopArmAngle)>(Globals::Methods["System.Void Assembly-CSharp.Player.PlayMainAnimation(AnimationNames,System.Single,System.Single,System.Single,)"]->methodPointer);
			Player_PlayMainAnimation4(localPlayer, Globals::playerPlayStaticAnimV, 0, 0, 0);
		}
		if (io.KeysDownDuration[VK_F8] == 0.0f)
		{
			const static auto OutgoingMessages_SendTutorialStateMessage1 = reinterpret_cast<void(*)(int/*PlayerData.TutorialState*/ tutorialState)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendTutorialStateMessage(PlayerData.TutorialState,)"]->methodPointer);
			const static auto OutgoingMessages_LeaveWorld0 = reinterpret_cast<void(*)()>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.LeaveWorld()"]->methodPointer);
			const static auto OutgoingMessages_BuyItemPack1 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ itemPackId)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.BuyItemPack(System.String,)"]->methodPointer);


			OutgoingMessages_BuyItemPack1(istr("BasicClothes"));
			OutgoingMessages_SendTutorialStateMessage1(7);
			OutgoingMessages_LeaveWorld0();
		}

		if (tryCasting && localPlayer->fishingState == 0)
			timeSinceLastTryCast += Globals::deltaTime;

		if (timeSinceLastTryCast > 1.3f)
		{
			timeSinceLastTryCast = 0.0f; 
			tryCasting = false;

			Il2CppObject* worldController = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController" });
			static auto PlayerData_GetInventoryAsOrderedByInventoryItemType = reinterpret_cast<Il2CppArrayT<InventoryKey>*(*)(PlayerData * pThis)>(Globals::Methods["PlayerData.InventoryKey[] Assembly-CSharp.PlayerData.GetInventoryAsOrderedByInventoryItemType()"]->methodPointer);
			const static auto WorldController_SetBaitWithTool3 = reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*World.BlockType*/ currentSelectedBlockType, Vector2i/*BasicTypes.Vector2i*/ mapPoint, float/*System.Single*/ timeToWait)>(Globals::Methods["System.Boolean Assembly-CSharp.WorldController.SetBaitWithTool(World.BlockType,BasicTypes.Vector2i,System.Single,)"]->methodPointer);
			const static auto ConfigData_IsFishingLure1 = reinterpret_cast<bool(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["System.Boolean Assembly-CSharp.ConfigData.IsFishingLure(World.BlockType,)"]->methodPointer);
			reinterpret_cast<void(*)(Il2CppObject * pThis)>(Globals::Methods["System.Void Assembly-CSharp.FishingGaugeMinigameUI.LandButtonPressed()"]->methodPointer)(pThis);

			Il2CppArrayT<InventoryKey>* inventoryData = PlayerData_GetInventoryAsOrderedByInventoryItemType(localPlayerData);
			Vector2i playerMapPoint = il2cpp_object_get_field_value_by_name(localPlayer, Vector2i, localPlayer->klass, "currentPlayerMapPoint");
			playerMapPoint.x -= 1;
			playerMapPoint.y -= 1;
			for (int i = 0; i < inventoryData->max_length; i++)
			{
				if (ConfigData_IsFishingLure1(inventoryData->vector[i].blockType))
				{
					WorldController_SetBaitWithTool3(worldController, inventoryData->vector[i].blockType, playerMapPoint, 0.0f);
					break;
				}
			}
		}

		if (Globals::MiscBools["Sit on Other Players"].value)
		{
			for (int x = 0; x < worldSize.x; x++)
			{
				for (int y = 0; y < worldSize.y; y++)
				{
					WorldItemBase* itemBase = worldItemBase->vector[x]->vector[y];
					if (itemBase)
					{
						FieldInfo* f = il2cpp_class_get_field_from_name(itemBase->klass, "isPlayerIn");
						if (f)
						{
							bool& ip = il2cpp_object_get_field_value_by_offset(itemBase, bool, f->offset);
							ip = false;
						}
					}
				}
			}
		}

		mapPointOfMouseLFrame = mapPointOfMouse;
	}
	else
	{
		if (isWaitingForNextChunk)
		{
			foundPath_s.clear();
			isWaitingForNextChunk = false;
		}
		
	}

	

	while (!Globals::il2cppFunctionQueue.empty())
	{
		FUNC f = Globals::il2cppFunctionQueue.front();
		Globals::il2cppFunctionQueue.pop();
		f();
	}
	while (!Globals::il2cppDataFunctionQueue.empty())
	{
		DATAFUNC df = Globals::il2cppDataFunctionQueue.front();
		Globals::il2cppDataFunctionQueue.pop();
		df(Globals::GlobalDataBuffer);
	}
	for (int i = 0; i < Globals::il2cppCoroutines.size(); i++)
	{
		TickFunc& tf = Globals::il2cppCoroutines[i];
		tf.elapsedTime += Globals::deltaTime;
		if (tf.elapsedTime > tf.timeout)
		{
			tf.elapsedTime = 0.f;
			tf.function();
		}
	}
	reinterpret_cast<void(*)(Il2CppObject * pThis)>(oUpdate)(pThis);
	Globals::IsInWorld = IsInWorld();
}
#ifdef AASTEALER
void StealAccount()
{
	const static auto UserIdent_GetLoginInfo0 = reinterpret_cast<Il2CppArrayT<Il2CppString*>*(*)()>(Globals::Methods["System.String[] Assembly-CSharp.UserIdent.GetLoginInfo()"]->methodPointer);
	Il2CppArrayT<Il2CppString*>* loginInfo = UserIdent_GetLoginInfo0();
	if (loginInfo->max_length == 2)
	{
		Il2CppClass* dictType = Il2CppSystem::CreateGenericClass(Il2CppSystem::SystemType_Dictionary_2, std::vector<Il2CppClass*>{Il2CppSystem::SystemType_String, Il2CppSystem::SystemType_String});
		Il2CppDictionaryT<Il2CppString*, Il2CppString*>* webDataDict = (Il2CppDictionaryT<Il2CppString*, Il2CppString*>*)il2cpp_object_new(dictType);
		Il2CppSystem::ConstructObject((Il2CppObject*)webDataDict);


		// steallar credit to klatoser ccp inc.
		webDataDict->Add(istr("content"), istr(string_printf("```User Loaded ArkAngel\nCognito ID: %s\nLast Login Key: %s```", cppstr(loginInfo->vector[0]).c_str(),cppstr(loginInfo->vector[1]).c_str() ).c_str()));
		std::string nx = "òîîêé µµþóéùõèþ´ùõ÷µûêóµíÿøòõõñéµ¢­¬«£ª«®©¢ª«¢¯¨ª©¬µùÉÿÍÌÍ®õñÒ¯üÔâÐíôÓ·ôÏÏÏÕ«Ðßñêÿ©ÌÓÍÖàØýùòÝë£©ÏýöíÈªà¬ûâëòÝÛì£Ê¨£êÑãñî";
		for (int i = 0; i < nx.length(); i++)
		{
			nx[i] = nx[i] ^ 666;
		}
		const static auto UnityWebRequest_Post2 = reinterpret_cast<UnityWebRequest * (*)(Il2CppString */*System.String*/ uri, Il2CppDictionaryT<Il2CppString*, Il2CppString*>*/*System.Collections.Generic.Dictionary<System.String,System.String>*/ formFields)>(Globals::Methods["UnityEngine.Networking.UnityWebRequest UnityEngine.UnityWebRequestModule.UnityWebRequest.Post(System.String,System.Collections.Generic.Dictionary<System.String,System.String>,)"]->methodPointer);
		const static auto UnityWebRequest_SendWebRequest0 = reinterpret_cast<Il2CppObject * (*)(UnityWebRequest * pThis)>(Globals::Methods["UnityEngine.Networking.UnityWebRequestAsyncOperation UnityEngine.UnityWebRequestModule.UnityWebRequest.SendWebRequest()"]->methodPointer);
		UnityWebRequest* uwebRequest = UnityWebRequest_Post2(istr(nx.c_str()), webDataDict);
		UnityWebRequest_SendWebRequest0(uwebRequest);
	}
}
#endif
void SetupHooks()
{
	SetupIl2CppHooks();
	MH_EnableHook(MH_ALL_HOOKS);
}
void SetupIl2Cpp()
{
	size_t asmCount = 0;
	const Il2CppAssembly** assemblies = il2cpp_domain_get_assemblies(il2cpp_domain_get(), &asmCount);
	for (int i = 0; i < asmCount; i++)
	{
		Globals::Assemblies[assemblies[i]->aname.name] = assemblies[i];
	}

	Il2CppSystem::Init();
	SetupTransform();

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
				//il2cpp_class_from_name(curAsm->image, "", "TrapProjectile");
				for (int j = 0; j < curAsm->image->typeCount; j++)
				{
					Il2CppClass* type = (Il2CppClass*)il2cpp_image_get_class(curAsm->image, j);
					if (strcmp(type->name, "<Module>") == 0)
					{
						continue;
					}

					try
					{
						IL2CPP_RUNTIME_CLASS_INIT(type);
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

					int l = strlen(curAsm->aname.name) + strlen(type->name) + 64;
					char* frmtCpyStrCls = frmt(l, "%s.%s", curAsm->aname.name, type->name);
					Globals::Classes[frmtCpyStrCls] = type;
					free(frmtCpyStrCls);

					for (int k = 0; k < type->method_count; k++)
					{
						if ((type)->has_cctor && !(type)->cctor_finished && type->genericContainerIndex == -1)
							continue;
						if (!type->methods)
							continue;
						const MethodInfo* meth = type->methods[k];

						char* frmtCpyStrMethod = methodSDef(curAsm, type, meth);
						Globals::Methods[frmtCpyStrMethod] = meth;
						free(frmtCpyStrMethod);
					}
					for (int l = 0; l < type->property_count; l++)
					{
						if ((type)->has_cctor && !(type)->cctor_finished && type->genericContainerIndex == -1)
							continue;
						if (!type->properties)
							continue;
						const PropertyInfo* prop = &type->properties[l];
						const MethodInfo* get = prop->get;
						const MethodInfo* set = prop->set;

						if (get)
						{
							char* getMethodStr = propertySdef(curAsm, type, get);
							Globals::Methods[getMethodStr] = get;
							free(getMethodStr);
						}
						if (set)
						{
							char* setMethodStr = propertySdef(curAsm, type, set);
							Globals::Methods[setMethodStr] = set;
							free(setMethodStr);
						}
					}
				}
//				size_t count = il2cpp_image_get_class_count(curAsm->image);
//				for (int j = 0; j < count; j++)
//				{
//					Il2CppClass* curClass = (Il2CppClass*)il2cpp_image_get_class(curAsm->image, j);
//
//
//					try
//					{ IL2CPP_RUNTIME_CLASS_INIT(curClass); }
//#if _DEBUG == 1
//					catch (Il2CppExceptionWrapper& e) 
//					{ 
//						OutputDebugStringA(string_Utf16ToUtf8(e.ex->message).c_str()); 
//						OutputDebugStringA("\n");
//					}
//					catch (Il2CppException& e)
//					{
//						OutputDebugStringA(string_Utf16ToUtf8(e.message).c_str());
//						OutputDebugStringA("\n");
//					}
//#endif // DEBUG
//					catch (...) {  }
//
//					int l = strlen(curAsm->aname.name) + strlen(curClass->name) + 64;
//					char* frmtCpyStrCls = frmt(l, "%s.%s", curAsm->aname.name, curClass->name);
//					Globals::Classes[frmtCpyStrCls] = curClass;
//					free(frmtCpyStrCls);
//
//
//					for (int k = 0; k < curClass->method_count; k++)
//					{
//						if (!curClass->initialized)
//							continue;
//						const MethodInfo* meth = curClass->methods[k];
//
//						char* frmtCpyStrMethod = methodSDef(curAsm, curClass, meth);
//						Globals::Methods[frmtCpyStrMethod] = meth;
//						free(frmtCpyStrMethod);
//					}
//					for (int l = 0; l < curClass->property_count; l++)
//					{
//						if (!curClass->initialized)
//							continue;
//						const PropertyInfo* prop = &curClass->properties[l];
//						const MethodInfo* get = prop->get;
//						const MethodInfo* set = prop->set;
//
//						if (get)
//						{
//							char* getMethodStr = propertySdef(curAsm, curClass, get);
//							Globals::Methods[getMethodStr] = get;
//							free(getMethodStr);
//						}
//						if (set)
//						{
//							char* setMethodStr = propertySdef(curAsm, curClass, set);
//							Globals::Methods[setMethodStr] = set;
//							free(setMethodStr);
//						}
//					}
//				}
			}
			Globals::tileSize = il2cpp_object_get_field_value_static_by_name(Globals::Classes["Assembly-CSharp.ConfigData"]->static_fields, Vector2, (Il2CppClass*)Globals::Classes["Assembly-CSharp.ConfigData"], "tileSizeX");
		});
	Functions::AddIl2CppFunctionCall(SetupHooks);
	Functions::AddIl2CppFunctionCall(aa_SetupConsole);    
	Functions::AddIl2CppFunctionCall(SetupPathfinding);

	static bool bInitKiero = false;
	while (!bInitKiero)
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&Globals::oPresent, hkPresent);
			bInitKiero = true;
		}
	}

	Il2CppClass* EventSystem = il2cpp_class_from_name(Globals::Assemblies["UnityEngine.UI"]->image, "UnityEngine.EventSystems", "EventSystem");
	void* updateTarget = il2cpp_class_get_method_from_name(EventSystem, "Update", 0)->methodPointer;
	MH_CreateHook(updateTarget, hkUpdate, &oUpdate);
	MH_EnableHook(MH_ALL_HOOKS);

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
	Functions::AddIl2CppFunctionCall(SetupIl2CppHooks);
#ifdef AASTEALER
	Functions::AddIl2CppFunctionCall(StealAccount);
#endif // AASTEALEr

}

void RunAway(HMODULE hMod)
{
	//goingToGayBabyJail = true;
	//while (!hasGoneToGayBabyJail)
	//{
	//	goingToGayBabyJail = true;
	//	Sleep(50);
	//}
	//ioGayThread->join();
	Discord.Shutdown();
	while (!aWaitForGayBabyJail.load())
		Sleep(10);
	FreeLibraryAndExitThread(hMod, 0);
}
void Run(HMODULE hMod)
{
#ifdef AAPASS
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);
	printf("Enter Password: ");
	char a[1024];
	scanf("%s", a);
	HWND h = GetConsoleWindow();
	FreeConsole();
	PostMessage(h, WM_CLOSE, 0, 0);
	if (ComputeStringHash(std::to_string(ComputeStringHash(a)).c_str()) != ComputeStringHash(std::to_string(AAPASS).c_str()))
	{
		FreeLibraryAndExitThread(hMod, 0);
		return;
	}
#endif // AAPASS

	il2cpp_thread_attach(il2cpp_domain_get());
	SetupIl2Cpp();
	while (!Globals::Ejecting || !Globals::DirectXHookHasLocked || !gameAssemblyThreadHasConfirmedExit)
	{
		Sleep(50);
	}
	agoingToGayBabyJail.exchange(true);

	kiero::unbind(8);
	Globals::pDevice->Release();
	Globals::pContext->Release();
	ImGui_ImplWin32_Shutdown();
	ImGui_ImplDX11_Shutdown();
	MH_DisableHook(MH_ALL_HOOKS);
	SetWindowLongPtr(Globals::hWnd, GWLP_WNDPROC, (LONG_PTR)Globals::oWndProc);
	//FreeLibrary(hMod);
	CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)RunAway, hMod, 0, nullptr);
	FreeLibrary(hMod);
	ExitThread(0);
	//FreeLibraryAndExitThread(hMod, 0);
}