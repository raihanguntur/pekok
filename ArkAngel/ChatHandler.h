#pragma once
namespace Mono 
{
	MonoMethod* onChatCommandMethod = nullptr;
};
static bool wantToSeNextQPI = false;
static int whitelistblockid = -1;
static std::string locationToStaticallySet = "";
void* oSubmit1;
void* oHitPlayerFromBlock3_0;
static bool isGettingAllItemPrices = false;
static int recId = 0;
static bool isGettingWorldInfo = false;
typedef void (*ArkAngelCommandCallback)(CmdStr& command, int argCount);
struct ArkAngelCommand
{
	ArkAngelCommandCallback function;
	std::string alias;
	std::string description;
	ArkAngelCommand(std::string alias, ArkAngelCommandCallback function)
	{
		this->function = function;
		this->alias = alias;
		this->description = "No Description";
	}
	ArkAngelCommand(std::string alias, std::string description, ArkAngelCommandCallback function)
	{
		this->function = function;
		this->alias = alias;
		this->description = description;
	}
	ArkAngelCommand()
	{
		function = NULL;
		alias = "";
		description = "";
	}
	void Call(CmdStr command, int argCount)
	{
		function(command, argCount);
	}
};

void/*System.Void*/ hkOutgoingMessages_SendWorldItemUpdateMessage3(Vector2i/*BasicTypes.Vector2i*/ mapPoint, WorldItemBase*/*WorldItemBase*/ wib, unsigned char/*PlayerTool*/ pt);
typedef void (*ArkAngelChatCommandCallback)(CmdStr& command, int argCount, Il2CppObject* pThis);
struct ArkAngelChatCommand
{
	ArkAngelChatCommandCallback function;
	std::string alias;
	std::string description;
	ArkAngelChatCommand(std::string alias, ArkAngelChatCommandCallback function)
	{
		this->function = function;
		this->alias = alias;
		this->description = "No Description";
	}
	ArkAngelChatCommand(std::string alias, std::string description, ArkAngelChatCommandCallback function)
	{
		this->function = function;
		this->alias = alias;
		this->description = description;
	}
	ArkAngelChatCommand()
	{
		function = NULL;
		alias = "";
		description = "";
	}
	void Call(CmdStr command, int argCount, Il2CppObject* pThis)
	{
		function(command, argCount, pThis);
	}
};
struct __declspec(align(8)) ChatMessage 
{
	Il2CppClass* klass;
	void* MonitorData;
	int32_t channelType;
	Il2CppString* nick;
	Il2CppString* userID;
	Il2CppString* channel;
	Il2CppString* message;
	unsigned long long time;
};
static bool safeMode = false;
struct ArkAngelChatHandler
{

	std::unordered_map<std::string, ArkAngelChatCommand> commands;

	//if return value is true, dont send message
	bool HandleMessage(Il2CppObject* pThis, std::string message)
	{
		Globals::chatHistory.push_back(message);
		if (string_StartsWith(message, "//"))
		{
			
			Il2CppString* text = istr(message.substr(1).c_str());
			return reinterpret_cast<bool(*)(Il2CppObject * pThis, Il2CppString */*System.String*/ text)>(oSubmit1)(pThis, text);
		}
		else if (string_StartsWith(message, "/"))
		{
			CmdStr command = CmdStr::Parse(message.substr(1));
			ArkAngelChatCommand aacmd = commands[command.command];
			ArkAngelChatHandler::Chat_printf(">> %s [%s]",/* aacmd.function != NULL ?*/ "38EBFF"/* : "FF0000"*/, pThis, command.command.c_str(), command.fullArgs.c_str());
			if (aacmd.function != NULL)
			{
				aacmd.Call(command, command.args.size(), pThis);
			}
			else if (Mono::onChatCommandMethod)
			{
				void** args = new void*[2];
				args[0] = mono_string_new(mono_domain_get(), command.fullMessage.c_str());
				args[1] = pThis;
				mono_runtime_invoke(Mono::onChatCommandMethod, nullptr, args ,nullptr);
			}
			return true;
		}
		return false;
	}

	ArkAngelChatHandler()
	{
		commands = { };
	}

	void AddCommand(std::string alias, ArkAngelChatCommandCallback method)
	{
		commands[alias] = ArkAngelChatCommand(alias, method);
	}
	static void NewMessage(std::string message, std::string color, Il2CppObject* pThis)
	{
		ChatMessage* msg = (ChatMessage*)il2cpp_object_new(Globals::Classes["Assembly-CSharp.ChatMessage"]);
		msg->channel = il2cpp_string_new(("#" + string_Utf16ToUtf8((Il2CppString*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldName"}))).c_str());
		msg->channelType = 0x6;
		msg->message = il2cpp_string_new(message.c_str());
		msg->nick = il2cpp_string_new("");
		msg->time = reinterpret_cast<unsigned long long(*)()>(Globals::Methods["System.DateTime Assembly-CSharp.KukouriTime.Get()"]->methodPointer)(); //app::KukouriTime_Get(nullptr);
		msg->userID = il2cpp_string_new(("#" + color).c_str());

		reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppObject* msg)>(Globals::Methods["System.Void Assembly-CSharp.ChatUI.NewMessage(ChatMessage,)"]->methodPointer)(pThis, (Il2CppObject*)msg);
	}
	static void Chat_printf(const char* format, std::string color, Il2CppObject* pThis, ...)
	{
		va_list argsToCheckSize;
		int n;
		std::string ret;

		va_start(argsToCheckSize, pThis);
		// use a temporary buffer as some docs indicate we cannot pass NULL to vsnprintf
		char buf[1];
		n = vsnprintf(buf, 0, format, argsToCheckSize);
		if (n == -1)
			return;

		ret.resize(n + 1, 0);
		va_end(argsToCheckSize);

		va_list argsToFormat;

		va_start(argsToFormat, pThis);
		n = vsnprintf(&ret[0], ret.size(), format, argsToFormat);
		va_end(argsToFormat);


		if (n == -1)
			return;

		// The v*printf methods might put a trailing NUL character, which should not not be in a
		// std::string, so strip it out.
		if (!ret.empty() && ret[ret.size() - 1] == '\0')
			ret = ret.substr(0, ret.size() - 1);

		NewMessage(ret, color, pThis);
	}

	void Setup()
	{
		//System.Void Assembly-CSharp.Player.ShowTradeBubble(System.String,)
		//System.Void Assembly-CSharp.OutgoingMessages.SendLocationStatusUpdate(System.String,)
		AddCommand("test",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				const static auto WorldController_ReInit0 = reinterpret_cast<void(*)(Il2CppObject * pThis)>(Globals::Methods["System.Void Assembly-CSharp.WorldController.ReInit()"]->methodPointer);
				Il2CppObject* worldController = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController" });
				WorldController_ReInit0(worldController);
			});
		AddCommand("tradeall",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
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
						reinterpret_cast<void(*)(Il2CppString* s)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.AskTrade(System.String,)"]->methodPointer)(id);
					}
				}
				//ArkAngelChatHandler::NewMessage("sex is sex man", "00ff00", pThis);
			});
		AddCommand("setloc",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 1)
				{
					reinterpret_cast<void(*)(Il2CppString* s)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendLocationStatusUpdate(System.String,)"]->methodPointer)(il2cpp_string_new(command.args[0].c_str()));
					ArkAngelChatHandler::NewMessage("Set current location to " + command.args[0], "00ff00", pThis);
				}
			});
		AddCommand("addall",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
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
						reinterpret_cast<void(*)(Il2CppString * s)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.AddFriend(System.String,)"]->methodPointer)(id);
					}
				}
			});
		AddCommand("killall_t",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				Il2CppObject* otherPlayers = Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
				int otherPlayers_size = Il2Cpp::Lists::il2cpp_list_get_size(otherPlayers);
				for (int i = 0; i < otherPlayers_size; i++)
				{
					Il2CppObject* curNetworkPlayer = Il2Cpp::Lists::il2cpp_list_index<Il2CppObject*>(otherPlayers, i);
					if (curNetworkPlayer)
					{
						Il2CppObject* curPlayer = il2cpp_object_get_field_value_by_name(curNetworkPlayer, Il2CppObject*, curNetworkPlayer->Il2CppClass.klass, "playerScript"); //Il2Cpp::Helpers::GetFieldValue<Il2CppObject*>("playerScript", curNetworkPlayer);
						Il2CppObject* playerData = il2cpp_object_get_field_value_by_name(curPlayer, Il2CppObject*, curPlayer->Il2CppClass.klass, "myPlayerData");;
						Il2CppString* id = il2cpp_object_get_field_value_by_name(playerData, Il2CppString*, playerData->Il2CppClass.klass, "playerId");
						//reinterpret_cast<void(*)(int blockType, Vector2i mapPoint)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.ForceKillPlayerByBlockHit(World.BlockType,BasicTypes.Vector2i,System.DateTime,)"]->methodPointer)(id);
					}
				}
			});
		AddCommand("smsg",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				Il2CppObject* acClient = Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "networkClient", "acClient" });
				reinterpret_cast<bool(*)(Il2CppObject * pThis)>(Globals::Methods["System.Boolean Assembly-CSharp.AsynchronousClient.SendMessages()"]->methodPointer)(acClient);
			});
		AddCommand("audio",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 2)
				{
					int audioType = std::stoi(command.args[0]);
					int audioBlockType = std::stoi(command.args[1]);
					reinterpret_cast<void(*)(int at, int abt)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendPlayPlayerAudioMessage(System.Int32,System.Int32,)"]->methodPointer)(audioType, audioBlockType);
				}
				//Il2CppObject* acClient = Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "networkClient", "acClient" });
				//reinterpret_cast<bool(*)(Il2CppObject * pThis)>(Globals::Methods["System.Boolean Assembly-CSharp.AsynchronousClient.SendMessages()"]->methodPointer)(acClient);
			});
		AddCommand("qpi",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 1)
				{
					//int audioType = std::stoi(command.args[0]);
					//int audioBlockType = std::stoi(command.args[1]);
					reinterpret_cast<void(*)(Il2CppString* s)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.QueryPlayerInfo(System.String,)"]->methodPointer)(il2cpp_string_new(command.args[0].c_str()));
					wantToSeNextQPI = true;
				}

				//Il2CppObject* acClient = Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "networkClient", "acClient" });
				//reinterpret_cast<bool(*)(Il2CppObject * pThis)>(Globals::Methods["System.Boolean Assembly-CSharp.AsynchronousClient.SendMessages()"]->methodPointer)(acClient);
			});
		AddCommand("w",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				static auto f = reinterpret_cast<void(*)(Il2CppString * newWorld, Il2CppString * entryPoint, Il2CppObject * keepNull, bool isSpecialWorld, Il2CppObject * keepNull2)> (Globals::Methods["System.Void Assembly-CSharp.SceneLoader.CheckIfWeCanGoFromWorldToWorld(System.String,System.String,System.Action<WorldJoinResult>,System.Boolean,System.Action<WorldJoinResult>,)"]->methodPointer);
				if (argCount == 1)
				{
					f(il2cpp_string_new(command.args[0].c_str()), il2cpp_string_new(""), nullptr, false, nullptr);
				}
				else if (argCount == 2)
				{
					//target world								  //target portal id
					f(il2cpp_string_new(command.args[0].c_str()), il2cpp_string_new(command.args[1].c_str()), nullptr, false, nullptr);

					f(il2cpp_string_new("targetworld"), il2cpp_string_new("targetid"), nullptr, false, nullptr);
				}
				else if (argCount == 3)
				{
					f(il2cpp_string_new(command.args[0].c_str()), il2cpp_string_new(command.args[1].c_str()), nullptr, string_ToLowercase(command.args[2]) == "true", nullptr);
				}
			});
		AddCommand("convert",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				/// /convert w2b 666 250
				if (argCount == 2)
				{
					char* convertBetween = new char[10];
					int amount = 0;
					sscanf(command.fullArgs.c_str(), "%s %i", convertBetween, &amount);
					if (strcmp(convertBetween, "w2b") == 0)
					{
						ArkAngelChatHandler::Chat_printf("%iwl = %ibc", "00ff00", pThis, amount, amount * 250);
					}
					else if (strcmp(convertBetween, "b2w") == 0)
					{
						ArkAngelChatHandler::Chat_printf("%ibc = %iwl", "00ff00", pThis, amount, amount / 250);
					}
				}
				else if (argCount == 3)
				{
					char* convertBetween = new char[10];
					int amount = 0;
					int price = 0;
					sscanf(command.fullArgs.c_str(), "%s %i %i", convertBetween, &amount, &price);
					if (strcmp(convertBetween, "w2b") == 0)
					{
						ArkAngelChatHandler::Chat_printf("%iwl = %ibc", "00ff00", pThis, amount, amount * price);
					}
					else if (strcmp(convertBetween, "b2w") == 0)
					{
						ArkAngelChatHandler::Chat_printf("%ibc = %iwl", "00ff00", pThis, amount, amount / price);
					}

				}
			});

		AddCommand("sex", 
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				

				
				if (argCount == 2)
				{
					Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
					Vector2i& playerMapPoint = il2cpp_object_get_field_value_by_name(localPlayer, Vector2i, localPlayer->Il2CppClass.klass, "currentPlayerMapPoint");
					ArkAngelChatHandler::Chat_printf("Sex????!?!?! omg sex omg poggers", "A83291", pThis);
					int f = 0;
					char sex[640];
					sscanf(command.fullArgs.c_str(), "%i %s", &f, sex);
					reinterpret_cast<void(*)(Vector2i mp, int freq, Il2CppString * s)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SubmitMessageAtFrequency(BasicTypes.Vector2i,System.Int32,System.String,)"]->methodPointer)(playerMapPoint, f, il2cpp_string_new(sex));
				}
			});

		AddCommand("menu",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 1)
				{
					Il2CppObject* rootui = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "rootUI" });
					Il2CppObject* wc = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController" });
					Il2CppObject* type = nullptr;
					if (command.args[0] == "f" || command.args[0] == "fish") type = il2cpp_class_get_type_object(Globals::Classes["Assembly-CSharp.FishingRecyclerUI"]);
					else if (command.args[0] == "p" || command.args[0] == "pwe")
					{
						const static auto WorldController_SetBlock3 = reinterpret_cast<void(*)(Il2CppObject * pThis, int/*World.BlockType*/ blockType, int/*System.Int32*/ x, int/*System.Int32*/ y)>(Globals::Methods["System.Void Assembly-CSharp.WorldController.SetBlock(World.BlockType,System.Int32,System.Int32,)"]->methodPointer);
						type = il2cpp_class_get_type_object(Globals::Classes["Assembly-CSharp.AuctionHouseUI"]);
						Globals::playerInfo.mapPoint = ConvertWorldPointToMapPoint(Globals::playerInfo.position);
						WorldController_SetBlock3(wc, (int)World_BlockType__Enum::PWETerminal, Globals::playerInfo.mapPoint.x, Globals::playerInfo.mapPoint.y);
					}
					else if (command.args[0] == "ai" || command.args[0] == "aispawn") type = il2cpp_class_get_type_object(Globals::Classes["Assembly-CSharp.AIEnemySpawnerUI"]);
					else if (command.args[0] == "a" || command.args[0] == "achievement") type = il2cpp_class_get_type_object(Globals::Classes["Assembly-CSharp.AchievementsUI"]);
					else if (command.args[0] == "block" || command.args[0] == "blockspawn") type = il2cpp_class_get_type_object(Globals::Classes["Assembly-CSharp.BlockSpawnerUI"]);
					else if (command.args[0] == "d" || command.args[0] == "debug") type = il2cpp_class_get_type_object(Globals::Classes["Assembly-CSharp.DebugButtonsUI"]);
					else if (command.args[0] == "dev" || command.args[0] == "devtools") type = il2cpp_class_get_type_object(Globals::Classes["Assembly-CSharp.DevToolsUI"]);
					else if (command.args[0] == "f" || command.args[0] == "friends") type = il2cpp_class_get_type_object(Globals::Classes["Assembly-CSharp.FriendsUI"]);
					else if (command.args[0] == "pd" || command.args[0] == "petdebug") type = il2cpp_class_get_type_object(Globals::Classes["Assembly-CSharp.PetDebugUI"]);
					else type = il2cpp_class_get_type_object(Globals::Classes["Assembly-CSharp." + command.args[0]]);

					static auto RootUI_OnOrOffMenu = reinterpret_cast<void(*)(Il2CppObject* pThis, Il2CppObject* menuType)>(Globals::Methods["System.Void Assembly-CSharp.RootUI.OnOrOffMenu(System.Type,)"]->methodPointer);
					if (rootui && type)
					{
						//try
						//{
						//	RootUI_OnOrOffMenu(rootui, type);
						//}
						//catch (Il2CppExceptionWrapper& e)
						//{
						//	Console.printf("Il2CppException: %s", e.ex->message);
						//}
						//catch (Il2CppException& e)
						//{
						//	Console.printf("Il2CppException: %s", e.message);
						//}
						il2cpp_call_catch(RootUI_OnOrOffMenu(rootui, type), ArkAngelChatHandler::Chat_printf("Il2CppException: %s", "FF0020", pThis, e.ex->message), ArkAngelChatHandler::Chat_printf("Il2CppException: %s", "FF0020", pThis, e.message));
					}
				}
			});
		AddCommand("trashall", 
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				//struct InventoryKey
				//{
				//	int blockType;
				//	int itemType;
				//};
				static auto PlayerData_GetInventoryAsOrderedByInventoryItemType = reinterpret_cast<Il2CppArrayT<InventoryKey>*(*)(Il2CppObject* pThis)>(Globals::Methods["PlayerData.InventoryKey[] Assembly-CSharp.PlayerData.GetInventoryAsOrderedByInventoryItemType()"]->methodPointer);
				static auto PlayerData_GetCount = reinterpret_cast<short(*)(Il2CppObject* pThis, InventoryKey ik)>(Globals::Methods["System.Int16 Assembly-CSharp.PlayerData.GetCount(PlayerData.InventoryKey,)"]->methodPointer);
				static auto Player_TrashItems = reinterpret_cast<short(*)(Il2CppObject * pThis, InventoryKey ik, int amount)>(Globals::Methods["System.Int32 Assembly-CSharp.Player.TrashItems(PlayerData.InventoryKey,System.Int16,)"]->methodPointer);

				Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });
				Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player"});
				Il2CppArrayT<InventoryKey>* inventoryData = PlayerData_GetInventoryAsOrderedByInventoryItemType(localPlayerData);

				for (int i = 0; i < inventoryData->max_length; i++)
				{
					int count = PlayerData_GetCount(localPlayerData, inventoryData->vector[i]);
					Player_TrashItems(localPlayer, inventoryData->vector[i], count);
				}
			});
		AddCommand("sellall",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				//struct InventoryKey
				//{
				//	int blockType;
				//	int itemType;
				//};
				static auto PlayerData_GetInventoryAsOrderedByInventoryItemType = reinterpret_cast<Il2CppArrayT<InventoryKey>*(*)(Il2CppObject * pThis)>(Globals::Methods["PlayerData.InventoryKey[] Assembly-CSharp.PlayerData.GetInventoryAsOrderedByInventoryItemType()"]->methodPointer);
				static auto PlayerData_GetCount = reinterpret_cast<short(*)(Il2CppObject * pThis, InventoryKey ik)>(Globals::Methods["System.Int16 Assembly-CSharp.PlayerData.GetCount(PlayerData.InventoryKey,)"]->methodPointer);
				const static auto OutgoingMessages_RecycleFish2 = reinterpret_cast<void(*)(InventoryKey/*PlayerData.InventoryKey*/ fishIK, short/*System.Int16*/ amount)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.RecycleFish(PlayerData.InventoryKey,System.Int16,)"]->methodPointer);
				const static auto PlayerData_RemoveItemsFromInventory2 = reinterpret_cast<void(*)(Il2CppObject* pThis, InventoryKey/*PlayerData.InventoryKey*/ inventoryKey, short/*System.Int16*/ amount)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.RemoveItemsFromInventory(PlayerData.InventoryKey,System.Int16,)"]->methodPointer);

				Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });
				Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
				Il2CppArrayT<InventoryKey>* inventoryData = PlayerData_GetInventoryAsOrderedByInventoryItemType(localPlayerData);

				for (int i = 0; i < inventoryData->max_length; i++)
				{
					int count = PlayerData_GetCount(localPlayerData, inventoryData->vector[i]);
					OutgoingMessages_RecycleFish2(inventoryData->vector[i], count);
					PlayerData_RemoveItemsFromInventory2(localPlayerData, inventoryData->vector[i], count);
				}
			});
		AddCommand("dropall",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				//struct InventoryKey
				//{
				//	int blockType;
				//	int itemType;
				//};
				static auto PlayerData_GetInventoryAsOrderedByInventoryItemType = reinterpret_cast<Il2CppArrayT<InventoryKey>*(*)(Il2CppObject * pThis)>(Globals::Methods["PlayerData.InventoryKey[] Assembly-CSharp.PlayerData.GetInventoryAsOrderedByInventoryItemType()"]->methodPointer);
				static auto PlayerData_GetCount = reinterpret_cast<short(*)(Il2CppObject * pThis, InventoryKey ik)>(Globals::Methods["System.Int16 Assembly-CSharp.PlayerData.GetCount(PlayerData.InventoryKey,)"]->methodPointer);
				static auto Player_DropItems = reinterpret_cast<short(*)(Il2CppObject * pThis, InventoryKey ik, int amount)>(Globals::Methods["System.Int32 Assembly-CSharp.Player.DropItems(PlayerData.InventoryKey,System.Int16,)"]->methodPointer);

				Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });
				Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
				
				Il2CppArrayT<InventoryKey>* inventoryData = PlayerData_GetInventoryAsOrderedByInventoryItemType(localPlayerData);
				int n = std::min((int)inventoryData->max_length, 5);

				for (int i = 0; i < n; i++)
				{
					int count = PlayerData_GetCount(localPlayerData, inventoryData->vector[i]);
					Player_DropItems(localPlayer, inventoryData->vector[i], count);
				}
			});

		AddCommand("anim",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 1)
				{
					int id = 0;
					const static auto Player_PlayMainAnimation4 = reinterpret_cast<void(*)(Il2CppObject * pThis, int/*AnimationNames*/ animation, float/*System.Single*/ targetPositionX, float/*System.Single*/ targetPositionY, float/*System.Single*/ rotatingTopArmAngle)>(Globals::Methods["System.Void Assembly-CSharp.Player.PlayMainAnimation(AnimationNames,System.Single,System.Single,System.Single,)"]->methodPointer);
					Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
					const static Il2CppClass* c = il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", "AnimationNames");
					
					if (!sscanf(command.args[0].c_str(), "%i", &id))
					{
						id = Il2Cpp::Enums::StringToEnum(c, command.args[0].c_str(), false);
					}
					ArkAngelChatHandler::Chat_printf("Playing Animation: %s(%i)", "0FFF0F", pThis, Il2Cpp::Enums::EnumToString(c, id).c_str(), id);
					Player_PlayMainAnimation4(localPlayer, id, 0, 0, 0);
				}
			});
		AddCommand("animv",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 1)
				{
					int id = 0;
					const static Il2CppClass* c = il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", "AnimationNames");

					if (!sscanf(command.args[0].c_str(), "%i", &id))
					{
						id = Il2Cpp::Enums::StringToEnum(c, command.args[0].c_str(), false);
					}
					ArkAngelChatHandler::Chat_printf("Playing Animation: %s(%i)", "0FFF0F", pThis, Il2Cpp::Enums::EnumToString(c, id).c_str(), id);
					Globals::playerPlayStaticAnimV = id;
				}
			});
		AddCommand("give",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 1)
				{
					int id = 0;
					const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
					const static auto PlayerData_AddItemToInventory2 = reinterpret_cast<void(*)(Il2CppObject* pThis, InventoryKey/*PlayerData.InventoryKey*/ ik, Il2CppObject*/*InventoryItemBase*/ inventoryData)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.AddItemToInventory(PlayerData.InventoryKey,InventoryItemBase,)"]->methodPointer);
					const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);
					Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });
					if (!sscanf(command.args[0].c_str(), "%i", &id))
					{
						id = Il2Cpp::Enums::StringToEnum(c, command.args[0].c_str(), false);
					}
					ArkAngelChatHandler::Chat_printf("Giving Item: %s(%i)", "0FFF0F", pThis, Il2Cpp::Enums::EnumToString(c, id).c_str(), id);
					InventoryKey ik;
					ik.blockType = id;
					ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(id);
					if (id > 0)
						PlayerData_AddItemToInventory2(localPlayerData, ik, nullptr);
				}
				else if (argCount == 2)
				{
					int id = 0;
					int amount = 1;
					const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
					const static auto PlayerData_AddItemToInventory3 = reinterpret_cast<void(*)(Il2CppObject* pThis, InventoryKey/*PlayerData.InventoryKey*/ ik, short/*System.Int16*/ addAmount, Il2CppObject*/*InventoryItemBase*/ inventoryData)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.AddItemToInventory(PlayerData.InventoryKey,System.Int16,InventoryItemBase,)"]->methodPointer);
					const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);
					Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });
					sscanf(command.args[1].c_str(), "%i", &amount);
					if (!sscanf(command.args[0].c_str(), "%i", &id))
					{
						id = Il2Cpp::Enums::StringToEnum(c, command.args[0].c_str(), false);
					}
					ArkAngelChatHandler::Chat_printf("Giving Item: %s(%i)", "0FFF0F", pThis, Il2Cpp::Enums::EnumToString(c, id).c_str(), id);
					InventoryKey ik;
					ik.blockType = id;
					ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(id);
					if (id > 0)
						PlayerData_AddItemToInventory3(localPlayerData, ik, amount, nullptr);
				}
			});

		AddCommand("giver",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 2)
				{
					int startId = 0;
					int endId = 0;
					const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
					const static auto PlayerData_AddItemToInventory3 = reinterpret_cast<void(*)(Il2CppObject * pThis, InventoryKey/*PlayerData.InventoryKey*/ ik, short/*System.Int16*/ addAmount, Il2CppObject */*InventoryItemBase*/ inventoryData)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.AddItemToInventory(PlayerData.InventoryKey,System.Int16,InventoryItemBase,)"]->methodPointer);
					const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);
					Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });
					sscanf(command.args[0].c_str(), "%i", &startId);
					sscanf(command.args[1].c_str(), "%i", &endId);

					for (int i = startId; i < endId; i++)
					{
						ArkAngelChatHandler::Chat_printf("Giving Item: %s(%i)", "0FFF0F", pThis, Il2Cpp::Enums::EnumToString(c, i).c_str(), i);
						InventoryKey ik;
						ik.blockType = i;
						ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(i);
						PlayerData_AddItemToInventory3(localPlayerData, ik, 1, nullptr);
					}
					
				}
			});
		AddCommand("ifind",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount >= 1)
				{
					const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
					const static auto TextManager_GetBlockTypeName1 = reinterpret_cast<Il2CppString* (*)(int/*World.BlockType*/ bt)>(Globals::Methods["System.String Assembly-CSharp.TextManager.GetBlockTypeName(World.BlockType,)"]->methodPointer);
					//const static auto PlayerData_AddItemToInventory2 = reinterpret_cast<void(*)(Il2CppObject * pThis, InventoryKey/*PlayerData.InventoryKey*/ ik, Il2CppObject */*InventoryItemBase*/ inventoryData)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.AddItemToInventory(PlayerData.InventoryKey,InventoryItemBase,)"]->methodPointer);
					//const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);
					//Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });
					
					std::string toFind = string_ToLowercase(command.fullArgs);
					for (int i = 1; i < c->field_count - 1; i++)
					{
						std::string s = Il2Cpp::Enums::EnumToString(c, i);
						std::string s2 = cppstr(TextManager_GetBlockTypeName1(i));
						if (string_ToLowercase(s).find(toFind) != -1 || string_ToLowercase(s2).find(toFind) != -1)
						{
							ArkAngelChatHandler::Chat_printf("Item: %s(%s:%i)", "0FFF0F", pThis, s.c_str(), s2.c_str(), i);
						}
					}
					
					//ArkAngelChatHandler::Chat_printf("Giving Item: %s(%i)", "0FFF0F", pThis, Il2Cpp::Enums::EnumToString(c, id).c_str(), id);
					//InventoryKey ik;
					//ik.blockType = id;
					//ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(id);
					//if (id > 0)
					//	PlayerData_AddItemToInventory2(localPlayerData, ik, nullptr);
					//World_BlockType__Enum::FireTrap;
				}
			});
		AddCommand("givea",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 1)
				{
					const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
					const static auto TextManager_GetBlockTypeName1 = reinterpret_cast<Il2CppString * (*)(int/*World.BlockType*/ bt)>(Globals::Methods["System.String Assembly-CSharp.TextManager.GetBlockTypeName(World.BlockType,)"]->methodPointer);
					//const static auto PlayerData_AddItemToInventory2 = reinterpret_cast<void(*)(Il2CppObject * pThis, InventoryKey/*PlayerData.InventoryKey*/ ik, Il2CppObject */*InventoryItemBase*/ inventoryData)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.AddItemToInventory(PlayerData.InventoryKey,InventoryItemBase,)"]->methodPointer);
					//const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);
					//Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });
					const static auto PlayerData_AddItemToInventory2 = reinterpret_cast<void(*)(Il2CppObject * pThis, InventoryKey/*PlayerData.InventoryKey*/ ik, Il2CppObject */*InventoryItemBase*/ inventoryData)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.AddItemToInventory(PlayerData.InventoryKey,InventoryItemBase,)"]->methodPointer);
					const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);
					Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });

					std::string toFind = string_ToLowercase(command.args[0]);
					for (int i = 1; i < c->field_count - 1; i++)
					{
						std::string s = Il2Cpp::Enums::EnumToString(c, i);
						std::string s2 = cppstr(TextManager_GetBlockTypeName1(i));
						if (string_ToLowercase(s).find(toFind) != -1 || string_ToLowercase(s2).find(toFind) != -1)
						{
							((PlayerData*)localPlayerData)->inventorySlots = 300;
							ArkAngelChatHandler::Chat_printf("Item: %s(%s:%i)", "0FFF0F", pThis, s.c_str(), s2.c_str(), i);
							InventoryKey ik;
							ik.blockType = i;
							ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(i);
							if (i > 0)
								PlayerData_AddItemToInventory2(localPlayerData, ik, nullptr);
						}
					}
				}
			});

		AddCommand("wlstb",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 1)
				{
					const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
					if (!sscanf(command.args[0].c_str(), "%i", &whitelistblockid))
					{
						whitelistblockid = Il2Cpp::Enums::StringToEnum(c, command.args[0].c_str(), false);
					}
					ArkAngelChatHandler::Chat_printf("Item: %s(%i)", "0FFF0F", pThis, Il2Cpp::Enums::EnumToString(c, whitelistblockid).c_str(), whitelistblockid);
					//for (int i = 1; i < c->field_count - 1; i++)
					//{
					//	std::string s = Il2Cpp::Enums::EnumToString(c, i);
					//	if (string_ToLowercase(s).find(string_ToLowercase(command.args[0])) != -1)
					//	{
					//		ArkAngelChatHandler::Chat_printf("Item: %s(%i)", "0FFF0F", pThis, s.c_str(), i);
					//	}
					//}
				}
			});
		AddCommand("summonall",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				const static auto OutgoingMessages_SummonPlayerToLocation1 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ warpedPlayerId)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SummonPlayerToLocation(System.String,)"]->methodPointer);
				Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
				for (int i = 0; i < std::min(otherPlayers->size, 5); i++)
				{
					NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[i];
					if (curNetworkPlayer)
					{
						Il2CppString*& clientId = curNetworkPlayer->clientId;
						OutgoingMessages_SummonPlayerToLocation1(clientId);
					}
				}
			});
		AddCommand("kickall",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				const static auto OutgoingMessages_KickPlayer1 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ kickTargetId)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.KickPlayer(System.String,)"]->methodPointer);
				Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
				for (int i = 0; i < otherPlayers->size; i++)
				{
					NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[i];
					if (curNetworkPlayer)
					{
						Il2CppString*& clientId = curNetworkPlayer->clientId;
						OutgoingMessages_KickPlayer1(clientId);
					}
				}
			});
		AddCommand("banall",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				const static auto OutgoingMessages_BanAndKickPlayer1 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ banAndkickTargetId)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.BanAndKickPlayer(System.String,)"]->methodPointer);
				Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
				for (int i = 0; i < otherPlayers->size; i++)
				{
					NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[i];
					if (curNetworkPlayer)
					{
						Il2CppString*& clientId = curNetworkPlayer->clientId;
						OutgoingMessages_BanAndKickPlayer1(clientId);
					}
				}
			});
		AddCommand("copyset",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 1)
				{
					Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
					Il2CppList<Il2CppObject*>* otherPlayers = (Il2CppList<Il2CppObject*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
					const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
					const static auto PlayerData_AddItemToInventory2 = reinterpret_cast<void(*)(Il2CppObject * pThis, InventoryKey/*PlayerData.InventoryKey*/ ik, Il2CppObject */*InventoryItemBase*/ inventoryData)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.AddItemToInventory(PlayerData.InventoryKey,InventoryItemBase,)"]->methodPointer);
					const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);
					Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });


					for (int i = 0; i < otherPlayers->size; i++)
					{
						Il2CppObject*& curNetworkPlayer = otherPlayers->arry->vector[i];
						if (curNetworkPlayer)
						{
							Player* curPlayer = il2cpp_object_get_field_value_by_name(curNetworkPlayer, Player*, curNetworkPlayer->Il2CppClass.klass, "playerScript");
							Il2CppString*& name = il2cpp_object_get_field_value_by_name(curNetworkPlayer, Il2CppString*, curNetworkPlayer->Il2CppClass.klass, "name");
							std::string n = cppstr(name);

							if (string_ToLowercase(n).find(string_ToLowercase(command.args[0])) != -1)
							{
								for (int j = 0; j < curPlayer->myPlayerData->hotSpotsBlockTypes->max_length; j++)
								{
									int id = curPlayer->myPlayerData->hotSpotsBlockTypes->vector[j];
									if (id > 0)
									{
										std::string ens = Il2Cpp::Enums::EnumToString(c, id);
										if (ens.find("Basic") == -1)
										{
											ArkAngelChatHandler::Chat_printf("Giving Item: %s(%i)", "0FFF0F", pThis, ens.c_str(), id);
											InventoryKey ik;
											ik.blockType = id;
											ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(id);
											PlayerData_AddItemToInventory2(localPlayerData, ik, nullptr);
										}
									}
								}
								break;
							}

						}
					}

					//const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
					//const static auto TextManager_GetBlockTypeName1 = reinterpret_cast<Il2CppString * (*)(int/*World.BlockType*/ bt)>(Globals::Methods["System.String Assembly-CSharp.TextManager.GetBlockTypeName(World.BlockType,)"]->methodPointer);
					//const static auto PlayerData_AddItemToInventory2 = reinterpret_cast<void(*)(Il2CppObject * pThis, InventoryKey/*PlayerData.InventoryKey*/ ik, Il2CppObject */*InventoryItemBase*/ inventoryData)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.AddItemToInventory(PlayerData.InventoryKey,InventoryItemBase,)"]->methodPointer);
					//const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);
					//Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });
					//
					//std::string toFind = string_ToLowercase(command.args[0]);
					//for (int i = 1; i < c->field_count - 1; i++)
					//{
					//	std::string s = Il2Cpp::Enums::EnumToString(c, i);
					//	std::string s2 = cppstr(TextManager_GetBlockTypeName1(i));
					//	if (string_ToLowercase(s).find(toFind) != -1 || string_ToLowercase(s2).find(toFind) != -1)
					//	{
					//		ArkAngelChatHandler::Chat_printf("Item: %s(%s:%i)", "0FFF0F", pThis, s.c_str(), s2.c_str(), i);
					//	}
					//}
					//
					//ArkAngelChatHandler::Chat_printf("Giving Item: %s(%i)", "0FFF0F", pThis, Il2Cpp::Enums::EnumToString(c, id).c_str(), id);
					//InventoryKey ik;
					//ik.blockType = id;
					//ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(id);
					//if (id > 0)
					//	PlayerData_AddItemToInventory2(localPlayerData, ik, nullptr);
					//World_BlockType__Enum::FireTrap;
				}
			});
		AddCommand("spr",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 3)
				{
					Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
					Vector3 p;
					sscanf(command.fullArgs.c_str(), "%f %f %f", &p.x, &p.y, &p.z);
					localPlayer->myTransform->SetEulerAngles(p);
				}
			});
		AddCommand("rall",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				const static auto OutgoingMessages_ChatReport6 = reinterpret_cast<void(*)(Il2CppString*/*System.String*/ userId, Il2CppString*/*System.String*/ targetId, Il2CppString*/*System.String*/ msg, Il2CppString*/*System.String*/ place, Il2CppString*/*System.String*/ reason, Il2CppString*/*System.String*/ additionalInfo)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.ChatReport(System.String,System.String,System.String,System.String,System.String,System.String,)"]->methodPointer);
				Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });

				Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
				for (int i = 0; i < otherPlayers->size; i++)
				{
					NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[i];
					if (curNetworkPlayer)
					{
						Il2CppString*& clientId = curNetworkPlayer->clientId;
						OutgoingMessages_ChatReport6(localPlayer->myPlayerData->playerId, clientId, istr("neo hates you for what you did"), istr("BUY"), istr("breaking up"), istr("neo hates you for what you did"));
					}
				}
			});
		AddCommand("rallm",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				const static auto OutgoingMessages_ChatReport6 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ userId, Il2CppString */*System.String*/ targetId, Il2CppString */*System.String*/ msg, Il2CppString */*System.String*/ place, Il2CppString */*System.String*/ reason, Il2CppString */*System.String*/ additionalInfo)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.ChatReport(System.String,System.String,System.String,System.String,System.String,System.String,)"]->methodPointer);
				Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });

				Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
				for (int i = 0; i < otherPlayers->size; i++)
				{
					NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[i];
					if (curNetworkPlayer)
					{
						Il2CppString*& clientId = curNetworkPlayer->clientId;
						OutgoingMessages_ChatReport6(clientId, localPlayer->myPlayerData->playerId, istr("neo hates you for what you did"), istr("BUY"), istr("breaking up"), istr("neo hates you for what you did"));
					}
				}
			});
		AddCommand("rrall",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 1)
				{
					const static auto OutgoingMessages_ChatReport6 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ userId, Il2CppString */*System.String*/ targetId, Il2CppString */*System.String*/ msg, Il2CppString */*System.String*/ place, Il2CppString */*System.String*/ reason, Il2CppString */*System.String*/ additionalInfo)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.ChatReport(System.String,System.String,System.String,System.String,System.String,System.String,)"]->methodPointer);
					Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });

					Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
					for (int i = 0; i < otherPlayers->size; i++)
					{
						NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[rand() % otherPlayers->size];
						NetworkPlayer*& curNetworkPlayer2 = otherPlayers->arry->vector[rand() % otherPlayers->size];
						if (curNetworkPlayer && curNetworkPlayer2)
						{
							Il2CppString*& clientId = curNetworkPlayer->clientId;
							Il2CppString*& clientId2 = curNetworkPlayer2->clientId;
							OutgoingMessages_ChatReport6(clientId, clientId2, istr("nigger nigger nigger lmao fuck sex fuck"), istr(command.args[0].c_str()), istr("Offensive Language"), istr("Chat Report"));
						}
					}
				}
			});
		AddCommand("reguser",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 2)
				{
					const static auto UserIdent_RegisterUser2 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ username, Il2CppString */*System.String*/ password)>(Globals::Methods["System.Void Assembly-CSharp.UserIdent.RegisterUser(System.String,System.String,)"]->methodPointer);
					const static auto UserIdent_ForceNewCognitoId0 = reinterpret_cast<void(*)()>(Globals::Methods["System.Void Assembly-CSharp.UserIdent.ForceNewCognitoId()"]->methodPointer);
					const static auto UserIdent_LogOut0 = reinterpret_cast<void(*)()>(Globals::Methods["System.Void Assembly-CSharp.UserIdent.LogOut()"]->methodPointer);
					//const static auto UserIdent_RetryConnection0 = reinterpret_cast<void(*)(Il2CppObject* pThis)>(Globals::Methods["System.Void Assembly-CSharp.UserIdent.RetryConnection()"]->methodPointer);
					UserIdent_LogOut0();
					UserIdent_ForceNewCognitoId0();
					//UserIdent_RetryConnection0();
					UserIdent_RegisterUser2(istr(command.args[0].c_str()), istr(command.args[1].c_str()));
				}
			});
		AddCommand("steal",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 1)
				{
					const static auto UserIdent_GetLoginInfo0 = reinterpret_cast<Il2CppArrayT<Il2CppString*>*(*)()>(Globals::Methods["System.String[] Assembly-CSharp.UserIdent.GetLoginInfo()"]->methodPointer);
					Il2CppArrayT<Il2CppString*>* loginInfo = UserIdent_GetLoginInfo0();
					if (loginInfo->max_length == 2)
					{
						Il2CppClass* dictType = Il2CppSystem::CreateGenericClass(Il2CppSystem::SystemType_Dictionary_2, std::vector<Il2CppClass*>{Il2CppSystem::SystemType_String, Il2CppSystem::SystemType_String});
						Il2CppDictionaryT<Il2CppString*, Il2CppString*>* webDataDict = (Il2CppDictionaryT<Il2CppString*, Il2CppString*>*)il2cpp_object_new(dictType);
						Il2CppSystem::ConstructObject((Il2CppObject*)webDataDict);


						// steallar credit to klatoser ccp inc.
						webDataDict->Add(istr("content"), istr("```User Loaded ArkAngel\nCognito ID: amongus\nLast Login Key: imposter```"));

						const static auto UnityWebRequest_Post2 = reinterpret_cast<UnityWebRequest * (*)(Il2CppString */*System.String*/ uri, Il2CppDictionaryT<Il2CppString*, Il2CppString*>*/*System.Collections.Generic.Dictionary<System.String,System.String>*/ formFields)>(Globals::Methods["UnityEngine.Networking.UnityWebRequest UnityEngine.UnityWebRequestModule.UnityWebRequest.Post(System.String,System.Collections.Generic.Dictionary<System.String,System.String>,)"]->methodPointer);
						const static auto UnityWebRequest_SendWebRequest0 = reinterpret_cast<Il2CppObject * (*)(UnityWebRequest * pThis)>(Globals::Methods["UnityEngine.Networking.UnityWebRequestAsyncOperation UnityEngine.UnityWebRequestModule.UnityWebRequest.SendWebRequest()"]->methodPointer);
						UnityWebRequest* uwebRequest = UnityWebRequest_Post2(istr(command.args[0].c_str()), webDataDict);
						UnityWebRequest_SendWebRequest0(uwebRequest);


					}
				}
			});
		AddCommand("iswitchf",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 1)
				{
					const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
					const static auto TextManager_GetBlockTypeName1 = reinterpret_cast<Il2CppString * (*)(int/*World.BlockType*/ bt)>(Globals::Methods["System.String Assembly-CSharp.TextManager.GetBlockTypeName(World.BlockType,)"]->methodPointer);
					std::string sc = "";

					std::string toFind = string_ToLowercase(command.args[0]);
					for (int i = 1; i < c->field_count - 1; i++)
					{
						std::string s = Il2Cpp::Enums::EnumToString(c, i);
						std::string s2 = cppstr(TextManager_GetBlockTypeName1(i));
						if (string_ToLowercase(s).find(toFind) != -1 || string_ToLowercase(s2).find(toFind) != -1)
						{
							ArkAngelChatHandler::Chat_printf("Item: %s(%s:%i)", "0FFF0F", pThis, s.c_str(), s2.c_str(), i);
							sc += string_printf("case %i/*%s*/:\nreturn true;", i, s.c_str());
						}
					}
					ImGui::SetClipboardText(sc.c_str());
				}
			});
		AddCommand("qap",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 1)
				{
					const static auto OutgoingMessages_SendGetItemAuctionHousePriceHistory1 = reinterpret_cast<void(*)(InventoryKey/*PlayerData.InventoryKey*/ ik)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendGetItemAuctionHousePriceHistory(PlayerData.InventoryKey,)"]->methodPointer);
					
					int id = 0;
					const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
					const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);
					Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });
					if (!sscanf(command.args[0].c_str(), "%i", &id))
					{
						id = Il2Cpp::Enums::StringToEnum(c, command.args[0].c_str(), false);
					}

					InventoryKey ik;
					ik.blockType = recId++;
					ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(ik.blockType);
					if (ik.blockType > 0)
					{
						OutgoingMessages_SendGetItemAuctionHousePriceHistory1(ik);
						isGettingAllItemPrices = true;
					}

					ik.blockType = recId++;
					ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(ik.blockType);
					if (ik.blockType > 0)
					{
						OutgoingMessages_SendGetItemAuctionHousePriceHistory1(ik);
						isGettingAllItemPrices = true;
					}

					ik.blockType = recId++;
					ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(ik.blockType);
					if (ik.blockType > 0)
					{
						OutgoingMessages_SendGetItemAuctionHousePriceHistory1(ik);
						isGettingAllItemPrices = true;
					}

					ik.blockType = recId++;
					ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(ik.blockType);
					if (ik.blockType > 0)
					{
						OutgoingMessages_SendGetItemAuctionHousePriceHistory1(ik);
						isGettingAllItemPrices = true;
					}


					//for (recId = 0; recId < 50 && recId < c->field_count; recId++)
					//{
					//	InventoryKey ik;
					//	ik.blockType = recId;
					//	ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(ik.blockType);
					//	if (ik.blockType > 0)
					//	{
					//		OutgoingMessages_SendGetItemAuctionHousePriceHistory1(ik); 
					//		isGettingAllItemPrices = true;
					//		//isWaitingForNextAHh = true;
					//	}
					//}
				}
			});
		 AddCommand("cbd",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
				const static auto TextManager_GetBlockTypeName1 = reinterpret_cast<Il2CppString * (*)(int/*World.BlockType*/ bt)>(Globals::Methods["System.String Assembly-CSharp.TextManager.GetBlockTypeName(World.BlockType,)"]->methodPointer);
				std::string s = "";
				for (int i = 1; i < c->field_count - 1; i++)
				{
					const char* fieldName = c->fields[i].name;
					std::string blockType = cppstr(TextManager_GetBlockTypeName1(i - 1));
					s += string_printf("%i %s %s\n", i - 1, fieldName, blockType.c_str());
				}
				ImGui::SetClipboardText(s.c_str());
			});
		AddCommand("winfo",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				const static auto OutgoingMessages_MenuWorldLoadInfo1 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ worldName)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.MenuWorldLoadInfo(System.String,)"]->methodPointer);
				if (argCount == 1)
				{
					isGettingWorldInfo = true;
					OutgoingMessages_MenuWorldLoadInfo1(istr(string_ToUppercase(command.args[0]).c_str()));
				}
			});
		AddCommand("safe",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				safeMode = !safeMode;
				if (safeMode)
				{
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
				}
				else
				{
					Globals::MiscBools =
					{
						{"Change Textbox Max Length", MiscBoolFuncPair(true, []() { ImGui::SliderInt("Textbox Length to Change to", &Globals::textboxLenToChangeTo, 1, 2048); })},
						{"Play Annoying Audio", MiscBoolFuncPair(false, []() { ImGui::SliderInt("Audio Type To Play", &Globals::audioTypeToPlay, 1, 20); ImGui::SliderInt("Audio Block Type To Play", &Globals::audioBlockTypeToPlay, 1, 4000); })},
						{"Bypass Untradeables", MiscBoolFuncPair(false)},
						{"Trade All Spam", MiscBoolFuncPair(false, []() { ImGui::SliderFloat("Trade All Timeout", &Globals::tradeAlltimeout, 0, 1); })},
						{"Change Player Visual Name", MiscBoolFuncPair(true, []() { ImGui::InputText("Player Name", &Globals::playerNameToChangeTo); ImGui::DragFloat("Col Scale", &Globals::tcolScale1, 0.1); })},
						{"Change Player Speed", MiscBoolFuncPair(true, []() { ImGui::SliderFloat("Player Speed", &Globals::setRunSpeed, 0.1f, 9.0f);  })},
						{"Change Player Hit Speed", MiscBoolFuncPair(true, []() { ImGui::SliderFloat("Player Hit Speed", &Globals::setHitSpeed, 0.0f, 0.25f);  })},
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
						{"Anti-Hurt", true},
						{"Anti-Pickup", false},
						{"Faster-Hit", true},
						{"Anti-Bounce", false},
						{"Anti-Inverted Controls", true},
						{"Anti-Check Points", false},
						{"Anti-Race", false},
						{"Anti-Poison", true},
						{"Anti-Wiring", true},
						{"Anti-Block Death", true},
						{"Place Block on Player", false},
						{"Place Seed in Air", true},
						{"Always Water", false},
						{"Anti-Water", true},
						{"Hit By Lava Animation", false},
						{"Anti-Auto Portal", true},
						//{"Lag Ghost", false},
						{"Long Hit(Visual)", false},
						{"Anti-KnockBack", true},
						{"Anti-Fog", true},
						{"Anti-Dark", true},
						{"Anti-Chat Filter", true},
						{"Insta-Die", false},
						{"Hit Block Through Battle", true},

						//{"", false},
						//{"", false}
					};
					Globals::setHitSpeed = true;
					Globals::setRunSpeed = true;
				}
			});
		AddCommand("taker",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
				Il2CppObject* worldController = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController" });
				Vector2i playerMapPoint = il2cpp_object_get_field_value_by_name(localPlayer, Vector2i, localPlayer->Il2CppClass.klass, "currentPlayerMapPoint");
				Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>* worldItemBase = (Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldItemsData" });
				Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });
				const static auto PlayerData_AddItemToInventory2 = reinterpret_cast<void(*)(Il2CppObject * pThis, InventoryKey/*PlayerData.InventoryKey*/ ik, Il2CppObject */*InventoryItemBase*/ inventoryData)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.AddItemToInventory(PlayerData.InventoryKey,InventoryItemBase,)"]->methodPointer);
				const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);
				const static auto OutgoingMessages_SendAdjustDisplayStorageMessage2 = reinterpret_cast<void(*)(Vector2i/*BasicTypes.Vector2i*/ mapPoint, WorldItemBase */*WorldItemBase*/ wib)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendAdjustDisplayStorageMessage(BasicTypes.Vector2i,WorldItemBase,)"]->methodPointer);
				for (int x = playerMapPoint.x - 2; x < playerMapPoint.x + 3; x++)
					for (int y = playerMapPoint.y - 2; y < playerMapPoint.y + 3; y++)
					{
						WorldItemBase* wib = worldItemBase->vector[x]->vector[y];
						if (wib && std::string(wib->klass->name) == "DisplayBlockData")
						{
							Vector2i point = {x, y};
							int& item = il2cpp_object_get_field_value_by_name(wib, int, wib->klass, "storageItemAsInventoryKey");

							union ikp
							{
								int i;
								short blockType;
								char d[4];
							};
							ikp iik;
							iik.i = item;
							InventoryKey ik;
							ik.blockType = iik.blockType;
							ik.itemType = iik.d[3];

							if (ik.blockType > 0)
							{
								PlayerData_AddItemToInventory2(localPlayerData, ik, nullptr);
								item = 0;
								OutgoingMessages_SendAdjustDisplayStorageMessage2(point, wib);
							}
						}
					}
			});
		AddCommand("fillr",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
				Il2CppObject* worldController = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController" });
				Vector2i playerMapPoint = il2cpp_object_get_field_value_by_name(localPlayer, Vector2i, localPlayer->Il2CppClass.klass, "currentPlayerMapPoint");
				Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>* worldItemBase = (Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldItemsData" });
				Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData" });
				const static auto PlayerData_AddItemToInventory2 = reinterpret_cast<void(*)(Il2CppObject * pThis, InventoryKey/*PlayerData.InventoryKey*/ ik, Il2CppObject */*InventoryItemBase*/ inventoryData)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.AddItemToInventory(PlayerData.InventoryKey,InventoryItemBase,)"]->methodPointer);
				const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);
				const static auto OutgoingMessages_SendAdjustDisplayStorageMessage2 = reinterpret_cast<void(*)(Vector2i/*BasicTypes.Vector2i*/ mapPoint, WorldItemBase */*WorldItemBase*/ wib)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendAdjustDisplayStorageMessage(BasicTypes.Vector2i,WorldItemBase,)"]->methodPointer);
				const static auto InventoryControl_GetCurrentSelection0 = reinterpret_cast<InventoryKey(*)(InventoryControl * pThis)>(Globals::Methods["PlayerData.InventoryKey Assembly-CSharp.InventoryControl.GetCurrentSelection()"]->methodPointer);
				const static auto PlayerData_RemoveItemsFromInventory2 = reinterpret_cast<void(*)(Il2CppObject * pThis, InventoryKey/*PlayerData.InventoryKey*/ inventoryKey, short/*System.Int16*/ amount)>(Globals::Methods["System.Void Assembly-CSharp.PlayerData.RemoveItemsFromInventory(PlayerData.InventoryKey,System.Int16,)"]->methodPointer);
				InventoryControl* inventoryControl = (InventoryControl*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "gameplayUI", "inventoryControl" });
				InventoryKey icik = InventoryControl_GetCurrentSelection0(inventoryControl);
				if (icik.blockType > 0)
				{
					for (int x = playerMapPoint.x - 2; x < playerMapPoint.x + 3; x++)
						for (int y = playerMapPoint.y - 2; y < playerMapPoint.y + 3; y++)
						{
							WorldItemBase* wib = worldItemBase->vector[x]->vector[y];
							if (wib && std::string(wib->klass->name) == "DisplayBlockData")
							{
								Vector2i point = { x, y };
								int& item = il2cpp_object_get_field_value_by_name(wib, int, wib->klass, "storageItemAsInventoryKey");

								union ikp
								{
									int i;
									short blockType;
									char d[4];
								};
								ikp iik;
								iik.i = item;
								InventoryKey ik;
								ik.blockType = iik.blockType;
								ik.itemType = iik.d[3];
								if (ik.blockType == 0)
								{
									iik.blockType = icik.blockType;
									iik.d[3] = icik.itemType;
									item = iik.i;

									PlayerData_RemoveItemsFromInventory2(localPlayerData, icik, 1);
									OutgoingMessages_SendAdjustDisplayStorageMessage2(point, wib);
								}
							}
						}
				}
			});
		AddCommand("sp",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
				Vector2i& playerMapPoint = il2cpp_object_get_field_value_by_name(localPlayer, Vector2i, localPlayer->klass, "currentPlayerMapPoint");
				Vector2 worldPointOfMouse = ScreenToWorld(Globals::MousePos);
				Vector2i mapPointOfMouse = ConvertWorldPointToMapPoint(worldPointOfMouse);
				Il2CppArrayT<Il2CppArrayT<LayerBlock>*>* worldBlocks = (Il2CppArrayT<Il2CppArrayT<LayerBlock>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldBlockLayer" });
				Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>* worldItemBase = (Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldItemsData" });
				if (Globals::visualPathHelper.size() == 0)
				{
					std::vector<Vector2i> foundPath = FindPath(playerMapPoint, mapPointOfMouse, worldBlocks, worldItemBase);
					std::reverse(foundPath.begin(), foundPath.end());
					Globals::visualPathHelper = foundPath;
				}
				else
					Globals::visualPathHelper = {};

			});
		AddCommand("lorem",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{ 
				reinterpret_cast<bool(*)(Il2CppObject* pThis, Il2CppString*/*System.String*/ text)>(oSubmit1)(pThis, istr("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean cursus lobortis metus vitae finibus. Aenean sollicitudin scelerisque libero. Morbi nec est ut turpis hendrerit mollis. Donec vitae malesuada tellus. Proin ut urna at elit condimentum feugiat. Etiam sagittis dictum massa ut eleifend. Fusce et scelerisque neque. Donec tortor elit, molestie quis turpis id, tincidunt blandit lorem. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Ut ultricies felis nec arcu commodo venenatis. Vestibulum volutpat eget nibh eu tincidunt. Sed scelerisque diam sit amet mauris convallis accumsan."));
			});
		AddCommand("logincog",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				if (argCount == 2)
				{
					const static auto UserIdent_UpdateLastLogin1 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ val)>(Globals::Methods["System.Void Assembly-CSharp.UserIdent.UpdateLastLogin(System.String,)"]->methodPointer);
					const static auto UserIdent_SetCognitoIDAndMarkReady1 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ cognitoId)>(Globals::Methods["System.Void Assembly-CSharp.UserIdent.SetCognitoIDAndMarkReady(System.String,)"]->methodPointer);
					const static auto UserIdent_LogOut0 = reinterpret_cast<void(*)()>(Globals::Methods["System.Void Assembly-CSharp.UserIdent.LogOut()"]->methodPointer);
					const static auto SceneLoader_ReloadGame0 = reinterpret_cast<void(*)()>(Globals::Methods["System.Void Assembly-CSharp.SceneLoader.ReloadGame()"]->methodPointer);

					UserIdent_LogOut0();
					UserIdent_UpdateLastLogin1(istr(command.args[1].c_str()));
					UserIdent_SetCognitoIDAndMarkReady1(istr(command.args[0].c_str()));
					SceneLoader_ReloadGame0();
				}
			});
		AddCommand("loginup",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
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
		AddCommand("kill",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
				Vector2i point = ConvertWorldPointToMapPoint(Globals::playerInfo.position);
				auto HitPlayerWithBlock = reinterpret_cast<void(*)(Player * pThis, int hitForce, int blockType, Vector2i mapPoint)>(oHitPlayerFromBlock3_0);
				if (argCount == 0)
				{
					HitPlayerWithBlock(localPlayer, 99999, 7, point);
				}
				else if (argCount == 1)
				{
					const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
					int blockType = 0;
					if (command.args[0] == "f" || command.args[0] == "fire") blockType = (int)World_BlockType__Enum::FireTrap;
					else if (command.args[0] == "i" || command.args[0] == "ice") blockType = (int)World_BlockType__Enum::FrostConstantTrap;
					else if (command.args[0] == "e" || command.args[0] == "ele" || command.args[0] == "electric") blockType = (int)World_BlockType__Enum::ElectricTrap;
					else
					{
						if (!sscanf(command.args[0].c_str(), "%i", &blockType))
						{
							blockType = Il2Cpp::Enums::StringToEnum(c, command.args[0].c_str(), false);
						}
					}
					HitPlayerWithBlock(localPlayer, 99999, blockType, point);
				}
			});
		AddCommand("sbk",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
				Vector2i point = ConvertWorldPointToMapPoint(Globals::playerInfo.position);

				const static auto OutgoingMessages_SendResurrect2 = reinterpret_cast<void(*)(DateTime/*System.DateTime*/ clientTimestamp, Vector2i/*BasicTypes.Vector2i*/ mapPoint)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendResurrect(System.DateTime,BasicTypes.Vector2i,)"]->methodPointer);
				const static auto KukouriTime_Get0 = reinterpret_cast<DateTime(*)()>(Globals::Methods["System.DateTime Assembly-CSharp.KukouriTime.Get()"]->methodPointer);
				const static auto OutgoingMessages_ForceKillPlayerByBlockHit3 = reinterpret_cast<void(*)(int/*World.BlockType*/ blocktype, Vector2i/*BasicTypes.Vector2i*/ blockMapPoint, DateTime/*System.DateTime*/ clientTimestamp)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.ForceKillPlayerByBlockHit(World.BlockType,BasicTypes.Vector2i,System.DateTime,)"]->methodPointer);


				for (int x = point.x - 2; x < point.x + 3; x++)
					for (int y = point.y - 2; y < point.y + 3; y++)
					{
						DateTime t = KukouriTime_Get0();
						t.dateData -= 1000;
						OutgoingMessages_ForceKillPlayerByBlockHit3((int)World_BlockType__Enum::SpikeBall, { x, y }, t);
						t.dateData += 1000;
						OutgoingMessages_SendResurrect2(t, localPlayer->respawnMapPoint);
					}

			});
		AddCommand("trapdoor",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
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
			});
		AddCommand("black",
			[](CmdStr& command, int argCount, Il2CppObject* pThis)
			{
				Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
				int& isSkinColorByWeapon = il2cpp_object_get_field_value_by_name(localPlayer, int, localPlayer->klass, "isSkinColorByWeapon");
				int& skinColorIndexBeforeSkinColorByWeapon = il2cpp_object_get_field_value_by_name(localPlayer, int, localPlayer->klass, "skinColorIndexBeforeSkinColorByWeapon");

				const static auto OutgoingMessages_PlayerInfoUpdated4 = reinterpret_cast<void(*)(int/*PlayerData.Gender*/ gender, short/*System.Int16*/ countryCode, int/*System.Int32*/ skinColor, int/*System.Int32*/ skinColorBeforeOverride)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.PlayerInfoUpdated(PlayerData.Gender,System.Int16,System.Int32,System.Int32,)"]->methodPointer);
				OutgoingMessages_PlayerInfoUpdated4(0, 0, 1, 1);
				skinColorIndexBeforeSkinColorByWeapon = 4;
				isSkinColorByWeapon = 1;
			});
	}
};
static ArkAngelChatHandler Chat;