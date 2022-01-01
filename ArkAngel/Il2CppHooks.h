#pragma once
#include "Console.h"
#define IsMapPointNearEnough(mapPoint, playerMapPoint, range) (abs(playerMapPoint.x - mapPoint.x) <= range && abs(playerMapPoint.y - mapPoint.y) <= range)
#define il2cpp_hook(method, target, original) if (method != nullptr) {MH_CreateHook(method->methodPointer, target, &original);}
#define rethook(method) if (method != nullptr) {MH_CreateHook(method->methodPointer, retfunc, nullptr);}
#define rethook2(method) if (method != nullptr) {MH_CreateHook(method->methodPointer, retfunc2, nullptr);}

struct AuctionHouseItemPrice
{
	InventoryKey ik;
	std::vector<float> RecentPrices;
};
static bool isWaitingForNextAHh = false;
static bool hasRecievedNextAHh = false;
static AuctionHouseItemPrice nextRecievedData;
static std::vector<AuctionHouseItemPrice> itemPriceDatas;
void* oSendPlayerPosition1 = nullptr;
std::chrono::steady_clock::time_point lastCatchTime = std::chrono::high_resolution_clock::now();

void/*System.Void*/ hkSendPlayerPosition1(Il2CppObject*/*Kernys.Bson.BSONObject*/ playerPosMessage)
{
	return reinterpret_cast<void(*)(Il2CppObject*/*Kernys.Bson.BSONObject*/ playerPosMessage)>(oSendPlayerPosition1)(playerPosMessage);
}
void* oSendPlayerPosition0;
void/*System.Void*/ hkSendPlayerPosition0()
{
	return reinterpret_cast<void(*)()>(oSendPlayerPosition0)();
}
void* oDeathByColliderInCollider1;
void/*System.Void*/ hkDeathByColliderInCollider1(Il2CppObject* pThis, Vector2i/*struct*//*BasicTypes.Vector2i*/ mapPoint)
{
	if (Globals::BasicsBools["Anti-Block Death"])
		return;
	return reinterpret_cast<void(*)(Il2CppObject* pThis, Vector2i/*struct*//*BasicTypes.Vector2i*/ mapPoint)>(oDeathByColliderInCollider1)(pThis, mapPoint);
}
void* oIsPlayerInMapPoint1;
bool/*System.Boolean*/ hkIsPlayerInMapPoint1(Il2CppObject* pThis, Vector2i/*struct*//*BasicTypes.Vector2i*/ mapPoint)
{
	if (Globals::BasicsBools["Place Block on Player"])
		return false;
	return reinterpret_cast<bool(*)(Il2CppObject* pThis, Vector2i/*struct*//*BasicTypes.Vector2i*/ mapPoint)>(oIsPlayerInMapPoint1)(pThis, mapPoint);
}
void* oCanPlaceSeedTopOf1;
bool/*System.Boolean*/ hkCanPlaceSeedTopOf1(int/*struct*//*World.BlockType*/ blockType)
{
	if (Globals::BasicsBools["Place Seed in Air"])
		return true;
	return reinterpret_cast<bool(*)(int/*struct*//*World.BlockType*/ blockType)>(oCanPlaceSeedTopOf1)(blockType);
}
void* oIsBlockSwimming1;
bool/*System.Boolean*/ hkIsBlockSwimming1(int/*struct*//*World.BlockType*/ blockType)
{
	if (Globals::BasicsBools["Anti-Water"])
		return false;
	if (Globals::BasicsBools["Always Water"])
		return true;
	return reinterpret_cast<bool(*)(int/*struct*//*World.BlockType*/ blockType)>(oIsBlockSwimming1)(blockType);
}
void* oIsBlockHot1;
bool/*System.Boolean*/ hkIsBlockHot1(int/*struct*//*World.BlockType*/ blockType)
{
	if (Globals::BasicsBools["Hit By Lava Animation"])
		return true;
	return reinterpret_cast<bool(*)(int/*struct*//*World.BlockType*/ blockType)>(oIsBlockHot1)(blockType);
}
void* oCheckPortals0;
void/*System.Void*/ hkCheckPortals0(Il2CppObject* pThis)
{
	if (Globals::BasicsBools["Anti-Auto Portal"])
		return;
	return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oCheckPortals0)(pThis);
}
//void* oHitPlayerFromBlock3_0;
bool/*System.Boolean*/ hkHitPlayerFromBlock3_0(Il2CppObject* pThis, int/*System.Int32*/ hitForce, int/*struct*//*World.BlockType*/ hitFromBlockBlockType, Vector2i/*struct*//*BasicTypes.Vector2i*/ blockMapPoint)
{
	if (Globals::BasicsBools["Anti-Hurt"])
	{
		static auto f = reinterpret_cast<void(*)(int at, int abt)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendPlayPlayerAudioMessage(System.Int32,System.Int32,)"]->methodPointer);
		f(14, hitFromBlockBlockType);
		return true;
	}
	return reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*System.Int32*/ hitForce, int/*struct*//*World.BlockType*/ hitFromBlockBlockType, Vector2i/*struct*//*BasicTypes.Vector2i*/ blockMapPoint)>(oHitPlayerFromBlock3_0)(pThis, hitForce, hitFromBlockBlockType, blockMapPoint);
}
void* oHitPlayerFromBlock3_1;
bool/*System.Boolean*/ hkHitPlayerFromBlock3_1(Il2CppObject* pThis, int/*struct*//*World.BlockType*/ blocktype, Vector2i/*struct*//*BasicTypes.Vector2i*/ blockMapPoint, bool/*System.Boolean*/ shouldEndDamageFromTrap)
{
	if (Globals::BasicsBools["Anti-Hurt"])
	{
		static auto f = reinterpret_cast<void(*)(int at, int abt)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendPlayPlayerAudioMessage(System.Int32,System.Int32,)"]->methodPointer);
		f(14, blocktype);
		return true;
	}
	return reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*struct*//*World.BlockType*/ blocktype, Vector2i/*struct*//*BasicTypes.Vector2i*/ blockMapPoint, bool/*System.Boolean*/ shouldEndDamageFromTrap)>(oHitPlayerFromBlock3_1)(pThis, blocktype, blockMapPoint, shouldEndDamageFromTrap);
}
void* oHitPlayerFromAIEnemy2_0;
bool/*System.Boolean*/ hkHitPlayerFromAIEnemy2_0(Il2CppObject* pThis, Il2CppObject*/*AIBase*/ aiEnemy, int/*struct*//*AIDamageModelType*/ aiDamageModelType)
{
	if (Globals::BasicsBools["Anti-Hurt"])
		return false;
	return reinterpret_cast<bool(*)(Il2CppObject * pThis, Il2CppObject */*AIBase*/ aiEnemy, int/*struct*//*AIDamageModelType*/ aiDamageModelType)>(oHitPlayerFromAIEnemy2_0)(pThis, aiEnemy, aiDamageModelType);
}
void* oHitPlayerFromAIEnemy2_1;
bool/*System.Boolean*/ hkHitPlayerFromAIEnemy2_1(Il2CppObject* pThis, int/*System.Int32*/ hitForce, int/*struct*//*AIEnemyType*/ aiEnemyType)
{
	if (Globals::BasicsBools["Anti-Hurt"])
		return false;
	return reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*System.Int32*/ hitForce, int/*struct*//*AIEnemyType*/ aiEnemyType)>(oHitPlayerFromAIEnemy2_1)(pThis, hitForce, aiEnemyType);
}
void* oUpdate0_networkClient;
void/*System.Void*/ hkUpdate0_networkClient(Il2CppObject* pThis)
{
	return reinterpret_cast<void(*)(Il2CppObject* pThis)>(oUpdate0_networkClient)(pThis);
}
void* oCensor1_profanityFiler;
Il2CppString*/*System.String*/ hkCensor1_profanityFiler(Il2CppString*/*System.String*/ str)
{
	if (Globals::BasicsBools["Anti-Chat Filter"])
		return str;
	return reinterpret_cast<Il2CppString * (*)(Il2CppString */*System.String*/ str)>(oCensor1_profanityFiler)(str);
}
void* oValidate1_profanityFiler;
bool/*System.Boolean*/ hkValidate1_profanityFiler(Il2CppString*/*System.String*/ input)
{
	if (Globals::BasicsBools["Anti-Chat Filter"])
		return true;
	return reinterpret_cast<bool(*)(Il2CppString*/*System.String*/ input)>(oValidate1_profanityFiler)(input);
}
void* oValidate1_worldNameChecker;
int/*struct*//*NameValidity*/ hkValidate1_worldNameChecker(Il2CppString*/*System.String*/ worldName)
{
	if (Globals::BasicsBools["Anti-Chat Filter"])
		return 0;
	return reinterpret_cast<int/*struct*/(*)(Il2CppString */*System.String*/ worldName)>(oValidate1_worldNameChecker)(worldName);
}
void* oIsMapPointNearEnough3;
bool/*System.Boolean*/ hkIsMapPointNearEnough3(Il2CppObject* pThis, Vector2i/*struct*//*BasicTypes.Vector2i*/ mapPoint, Vector2i/*struct*//*BasicTypes.Vector2i*/ playerMapPoint, int/*System.Int32*/ range)
{
	if (Globals::BasicsBools["Long Hit(Visual)"] || Globals::FishingBools["Fish anywhere"] || Globals::MapPointExploitBools["Infinite Range"].value)
		return true;
	return reinterpret_cast<bool(*)(Il2CppObject * pThis, Vector2i/*struct*//*BasicTypes.Vector2i*/ mapPoint, Vector2i/*struct*//*BasicTypes.Vector2i*/ playerMapPoint, int/*System.Int32*/ range)>(oIsMapPointNearEnough3)(pThis, mapPoint, playerMapPoint, range);
}
void* oOnTriggerEnter2D1__trapProjectile;
void/*System.Void*/ hkOnTriggerEnter2D1_trapProjectile(Il2CppObject* pThis, Il2CppObject*/*UnityEngine.Collider2D*/ other)
{
	if (Globals::BasicsBools["Anti-Hurt"])
	{
		Il2CppObject* myGameObject = il2cpp_object_get_field_value_by_name(pThis, Il2CppObject*, pThis->Il2CppClass.klass, "myGameObject");
		reinterpret_cast<void(*)(Il2CppObject*)>(Globals::Methods["System.Void UnityEngine.CoreModule.Object.Destroy(UnityEngine.Object,)"]->methodPointer)(myGameObject);
		return;
	}
	return reinterpret_cast<void(*)(Il2CppObject* pThis, Il2CppObject*/*UnityEngine.Collider2D*/ other)>(oOnTriggerEnter2D1__trapProjectile)(pThis, other);
}
void* oTakeHitFromOtherPlayer6;
void/*System.Void*/ hkTakeHitFromOtherPlayer6(Il2CppObject* pThis, Il2CppString*/*System.String*/ strikerUserID, bool/*System.Boolean*/ doVelocityChange, bool/*System.Boolean*/ doTakeHitEffect, int/*struct*//*World.BlockType*/ topArmBlockType, int/*System.Int32*/ battleDamage, float/*System.Single*/ healthBarValue)
{
	//Console.AddLog(string_printf("Hit From Player: %s", string_Utf16ToUtf8(strikerUserID)));
	if (Globals::BasicsBools["Anti-KnockBack"])
	{
		doVelocityChange = false;
	}
	return reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppString */*System.String*/ strikerUserID, bool/*System.Boolean*/ doVelocityChange, bool/*System.Boolean*/ doTakeHitEffect, int/*struct*//*World.BlockType*/ topArmBlockType, int/*System.Int32*/ battleDamage, float/*System.Single*/ healthBarValue)>(oTakeHitFromOtherPlayer6)(pThis, strikerUserID, doVelocityChange, doTakeHitEffect, topArmBlockType, battleDamage, healthBarValue);
}
void* oUpdate0_FishingGaugeMinigameUI;
static float timeSinceLastTryCast = 0.0f;
static bool tryCasting = false;
static int lastFishType = 0;
static bool hasPulledCurrentFish = false;
std::vector<double> fishTimingGraph = {};
void/*System.Void*/ hkUpdate0_FishingGaugeMinigameUI(Il2CppObject* pThis)
{
	const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
	float& targetAreaPosition = il2cpp_object_get_field_value_by_name(pThis, float, pThis->Il2CppClass.klass, "targetAreaPosition");
	float& fishPosition = il2cpp_object_get_field_value_by_name(pThis, float, pThis->Il2CppClass.klass, "fishPosition");
	float& fishVelocity = il2cpp_object_get_field_value_by_name(pThis, float, pThis->Il2CppClass.klass, "fishVelocity");
	bool& fishIsOnTheRun = il2cpp_object_get_field_value_by_name(pThis, bool, pThis->Il2CppClass.klass, "fishIsOnTheRun");
	float& fishRunChance = il2cpp_object_get_field_value_by_name(pThis, float, pThis->Il2CppClass.klass, "fishRunChance");
	float& progress = il2cpp_object_get_field_value_by_name(pThis, float, pThis->Il2CppClass.klass, "progress");
	float& fishTargetPoint = il2cpp_object_get_field_value_by_name(pThis, float, pThis->Il2CppClass.klass, "fishTargetPoint");
	Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
	bool& fishingLeftButton = il2cpp_object_get_field_value_by_name(localPlayer, bool, localPlayer->Il2CppClass.klass, "fishingLeftButton");
	bool& fishingRightButton = il2cpp_object_get_field_value_by_name(localPlayer, bool, localPlayer->Il2CppClass.klass, "fishingRightButton");
	if (Globals::FishingBools["Arrow Always on Fish"])
		targetAreaPosition = fishPosition + fishVelocity * Globals::deltaTime;
	//if (Globals::FishingBools["No Fish Runs"] && string_ToLowercase(Il2Cpp::Enums::EnumToString(c, lastFishType)).find("huge") != -1)
	//	fishIsOnTheRun = false;
	if (Globals::FishingBools["Semi-Auto + Bypass Fishing Anti-Cheat"])
	{
		if (string_ToLowercase(Il2Cpp::Enums::EnumToString(c, lastFishType)).find("huge") != -1)
			reinterpret_cast<void(*)(Il2CppObject * pThis)>(Globals::Methods["System.Void Assembly-CSharp.FishingGaugeMinigameUI.LandButtonPressed()"]->methodPointer)(pThis);

		if (progress >= 1.f && !hasPulledCurrentFish)
		{
			//Il2CppObject* worldController = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController" });
			//Il2CppObject* localPlayerData = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myPlayerData"});
			hasPulledCurrentFish = true;
			static auto PlayerData_GetInventoryAsOrderedByInventoryItemType = reinterpret_cast<Il2CppArrayT<InventoryKey>*(*)(Il2CppObject * pThis)>(Globals::Methods["PlayerData.InventoryKey[] Assembly-CSharp.PlayerData.GetInventoryAsOrderedByInventoryItemType()"]->methodPointer);
			const static auto WorldController_SetBaitWithTool3 = reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*World.BlockType*/ currentSelectedBlockType, Vector2i/*BasicTypes.Vector2i*/ mapPoint, float/*System.Single*/ timeToWait)>(Globals::Methods["System.Boolean Assembly-CSharp.WorldController.SetBaitWithTool(World.BlockType,BasicTypes.Vector2i,System.Single,)"]->methodPointer);
			const static auto ConfigData_IsFishingLure1 = reinterpret_cast<bool(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["System.Boolean Assembly-CSharp.ConfigData.IsFishingLure(World.BlockType,)"]->methodPointer);

			reinterpret_cast<void(*)(Il2CppObject * pThis)>(Globals::Methods["System.Void Assembly-CSharp.FishingGaugeMinigameUI.LandButtonPressed()"]->methodPointer)(pThis);

			static bool isFirstTime = true;
			if (!isFirstTime)
			{
				std::chrono::duration<double> et = std::chrono::high_resolution_clock::now() - lastCatchTime;
				lastCatchTime = std::chrono::high_resolution_clock::now();
				fishTimingGraph.push_back(et.count());
			}
			isFirstTime = false;
			//Il2CppArrayT<InventoryKey>* inventoryData = PlayerData_GetInventoryAsOrderedByInventoryItemType(localPlayerData);
			//Vector2i playerMapPoint = il2cpp_object_get_field_value_by_name(localPlayer, Vector2i, localPlayer->Il2CppClass.klass, "currentPlayerMapPoint");
			//playerMapPoint.x -= 1;
			//playerMapPoint.y -= 1;
			//for (int i = 0; i < inventoryData->max_length; i++)
			//{
			//	if (ConfigData_IsFishingLure1(inventoryData->vector[i].blockType))
			//	{
			//		WorldController_SetBaitWithTool3(worldController, inventoryData->vector[i].blockType, playerMapPoint, 0.0f);
			//		break;
			//	}
			//}
		}
		if (targetAreaPosition > fishTargetPoint)
			fishingLeftButton = true;
		else
			fishingRightButton = true;

	}
	return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oUpdate0_FishingGaugeMinigameUI)(pThis);
}
void* oLateUpdate0_FogOfWar;
void/*System.Void*/ hkLateUpdate0_FogOfWar(Il2CppObject* pThis)
{
	Il2CppArray* colors = il2cpp_object_get_field_value_by_name(pThis, Il2CppArray*, pThis->Il2CppClass.klass, "colors");
	if (Globals::BasicsBools["Anti-Fog"])
	{
		for (int i = 0; i < colors->max_length; i++)
		{
			Vector4& color = il2cpp_array_get(colors, Vector4, i);
			color.x = 0;
			color.y = 0;
			color.z = 0;
			color.w = 0.0001;
		}
	}
	return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oLateUpdate0_FogOfWar)(pThis);
}
void* oUpdate0_WorldLighting;
void/*System.Void*/ hkUpdate0_WorldLighting(Il2CppObject* pThis)
{
	
	return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oUpdate0_WorldLighting)(pThis);
}
void* oInsert;
void __stdcall hInputField_Insert(Il2CppObject* pThis, char c)
{
#ifndef AAPUBLICMODE
	if (Globals::MiscBools["Change Textbox Max Length"].value)
	{
		int& charLimit = il2cpp_object_get_field_value_by_name(pThis, int, pThis->Il2CppClass.klass, "m_CharacterLimit");
		int tempCharLimit = charLimit;
		charLimit = Globals::textboxLenToChangeTo;
		reinterpret_cast<void(*)(Il2CppObject*, char)>(oInsert)(pThis, c);
		charLimit = tempCharLimit;
	}
	else
	{
		reinterpret_cast<void(*)(Il2CppObject*, char)>(oInsert)(pThis, c);
	}
#else 
	reinterpret_cast<void(*)(Il2CppObject*, char)>(oInsert)(pThis, c);
#endif
}
bool/*System.Boolean*/ hkSubmit1(Il2CppObject* pThis, Il2CppString*/*System.String*/ text)
{
	std::string message = string_Utf16ToUtf8(text);
	// DO NOT REMOVE THIS CODE!!!!!!!!!!!
	if (string_ToLowercase(message).find("among us") != -1)
	{
		reinterpret_cast<bool(*)(Il2CppObject * pThis, Il2CppString */*System.String*/ text)>(oSubmit1)(pThis, text);
		*(int*)nullptr = 420;
		return false;
	}

#ifndef AAPUBLICMODE
	if (Chat.HandleMessage(pThis, message))
	{
		return false;
	}
	else
	{
		return reinterpret_cast<bool(*)(Il2CppObject* pThis, Il2CppString */*System.String*/ text)>(oSubmit1)(pThis, text);
	}
#else
	return reinterpret_cast<bool(*)(Il2CppObject * pThis, Il2CppString */*System.String*/ text)>(oSubmit1)(pThis, text);
#endif
}
void* oIsBlockTradeable1;
bool/*System.Boolean*/ hkIsBlockTradeable1(int/*struct*//*World.BlockType*/ blockType)
{
	//if (Globals::MiscBools["Bypass Untradeables"].value)
	//{
	//	return true;
	//}
	return reinterpret_cast<bool(*)(int/*struct*//*World.BlockType*/ blockType)>(oIsBlockTradeable1)(blockType);
}
void* oIsBlockUntradeable1;
bool/*System.Boolean*/ hkIsBlockUntradeable1(int/*struct*//*World.BlockType*/ blockType)
{
	//if (Globals::MiscBools["Bypass Untradeables"].value)
	//{
	//	return false;
	//}
	return reinterpret_cast<bool(*)(int/*struct*//*World.BlockType*/ blockType)>(oIsBlockUntradeable1)(blockType);
}
void* oAreMapPointsValidForFishing3;
bool/*System.Boolean*/ hkAreMapPointsValidForFishing3(Il2CppObject* pThis, Vector2i/*struct*//*BasicTypes.Vector2i*/ playerMapPoint, int/*System.Int32*/ targetMapPointX, int/*System.Int32*/ targetMapPointY)
{
	//Console.AddLog("hi");
	if (Globals::FishingBools["Fish anywhere"])
		return true;
	return reinterpret_cast<bool(*)(Il2CppObject* pThis, Vector2i/*struct*//*BasicTypes.Vector2i*/ playerMapPoint, int/*System.Int32*/ targetMapPointX, int/*System.Int32*/ targetMapPointY)>(oAreMapPointsValidForFishing3)(pThis, playerMapPoint, targetMapPointX, targetMapPointY);
}
void* oKukouriCamera_UpdateCameraPosition0;
void/*System.Void*/ hkKukouriCamera_UpdateCameraPosition0(Il2CppObject* pThis)
{
	static Il2CppClass* kukCam = il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", "KukouriCamera");
	static Il2CppClass* pixelCam = il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", "PixelPerfectCamera");
	static int kukcamOffset = il2cpp_class_get_field_from_name((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], "kukouriCamera")->offset;
	static int ppcamOffset = il2cpp_class_get_field_from_name(kukCam, "pixelPerfectCamera")->offset;
	static int camZoomOffset = il2cpp_class_get_field_from_name(pixelCam, "cameraZoom")->offset;
	static int fixedCameraOriginOffset = il2cpp_class_get_field_from_name(pixelCam, "fixedCameraOrigin")->offset;

	Il2CppObject* obj = il2cpp_object_get_field_value_by_offset(pThis, Il2CppObject*, ppcamOffset);//*(Il2CppObject**)((uintptr_t)obj + ppcamOffset);//Il2Cpp::Helpers::GetFieldValue<Il2CppObject*>("pixelPerfectCamera", obj);
	if (obj)
	{
		cameraZoom = il2cpp_object_get_field_value_by_offset(obj, int, camZoomOffset);
		cameraOrigin = il2cpp_object_get_field_value_by_offset(obj, Vector2, fixedCameraOriginOffset);;
	}
	if (Globals::ToggleBools["Freecam"].value)
		return;
	return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oKukouriCamera_UpdateCameraPosition0)(pThis);
}
void* oKukouriCamera_ForceUpdatePosition1;
void/*System.Void*/ hkKukouriCamera_ForceUpdatePosition1(Il2CppObject* pThis, bool/*System.Boolean*/ doForceLoop)
{
	if (Globals::ToggleBools["Freecam"].value)
		return;
	return reinterpret_cast<void(*)(Il2CppObject * pThis, bool/*System.Boolean*/ doForceLoop)>(oKukouriCamera_ForceUpdatePosition1)(pThis, doForceLoop);
}
void* oNetworkClient_HandleMessages1;
void/*System.Void*/ hkNetworkClient_HandleMessages1(Il2CppObject* pThis, Il2CppObject*/*Kernys.Bson.BSONObject*/ messages)
{
	//Console.AddLog(string_printf("%p", messages));
	//FieldInfo* field = &messages->Il2CppClass.klass->fields[0];
	//Il2CppObject* l = il2cpp_object_get_field_value_by_offset(messages, Il2CppObject*, field->offset);
	//if (l)
	//{
	//	const Il2CppType* t1 = field->type->data.generic_class->context.class_inst->type_argv[0];
	//	const Il2CppType* t2 = field->type->data.generic_class->context.class_inst->type_argv[1];
	//	const Il2CppClass* c1 = il2cpp_class_from_il2cpp_type(t1);
	//	const Il2CppClass* c2 = il2cpp_class_from_il2cpp_type(t2);
	//
	//	Il2CppArray* toCopyTo = il2cpp_array_new((Il2CppClass*)c1, reinterpret_cast<int(*)(Il2CppObject* pThis)>(il2cpp_class_get_property_from_name(l->Il2CppClass.klass, "Count")->get->methodPointer)(l));
	//	const PropertyInfo* propi = il2cpp_class_get_property_from_name(l->Il2CppClass.klass, "Keys");
	//	Il2CppObject* keys = il2cpp_runtime_invoke(propi->get, l, nullptr, nullptr);//reinterpret_cast<Il2CppObject*(*)(Il2CppObject* pThis)>(propi->get->methodPointer)(l);
	//	const MethodInfo* kCopyTo = il2cpp_class_get_method_from_name(keys->Il2CppClass.klass, "CopyTo", 2);
	//	reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppArray * arr, int index)>(/*Globals::Methods["System.Void mscorlib.ICollection.CopyTo(System.Array,System.Int32,)"]*/kCopyTo->methodPointer)(keys, toCopyTo, 0);
	//	int s = toCopyTo->max_length;
	//	for (int i = 0; i < s; i++)
	//	{
	//		Console.AddLog(string_Utf16ToUtf8(il2cpp_array_get(toCopyTo, Il2CppString*, i)));
	//	}
	//}
	
	//std::string v = packet_format(l);
	//if (!v.empty())
	//	Console.AddLog(v);
	//if (Globals::testState)
	//	HandleMessagesShit(pThis, messages);

	FieldInfo* field = &messages->Il2CppClass.klass->fields[0];
	Il2CppDictionaryT<Il2CppString*, BSONValue*>* l = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(messages, void*, field->offset);
	//Console.AddLog(bson_format(l));
	int count = l->GetValue(il2cpp_string_new("mc"))->int32;
	Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });

#ifndef AAPUBLICMODE
	for (int i = 0; i < count; i++)
	{
		BSONValue* value = l->GetValue(il2cpp_string_new(("m" + std::to_string(i)).c_str()));

		FieldInfo* field = &((Il2CppObject*)(value))->Il2CppClass.klass->fields[0];
		Il2CppDictionaryT<Il2CppString*, BSONValue*>* l2 = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(value, void*, field->offset);
		std::vector<std::string> ckeys = Il2CppDictUtil::GetKeysStringConverted(l2);
		std::string id = string_Utf16ToUtf8(l2->GetValue(istr("ID"))->_string);
		if (id == "AnP")
		{
			std::string U = string_Utf16ToUtf8(l2->GetValue(istr("U"))->_string);
			std::string adminun = Globals::AdminUsernameIdPairs[U];

			if (!adminun.empty())
			{
				Console.printf("Admin Found! Username: %s", adminun.c_str());
			}

			if (VectorContains<std::string>(ckeys, "AdminSetUndercoverModeValue") || VectorContains<std::string>(ckeys, "AdminSetGhostModeValue"))
			{
				bool isUndercoverAdmin = l2->GetValue(istr("AdminSetUndercoverModeValue"))->_bool;
				bool isGhostModeAdmin = l2->GetValue(istr("AdminSetGhostModeValue"))->_bool;
				Il2CppObject* chat = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "chatUI" });
				std::string un = string_Utf16ToUtf8(l2->GetValue(istr("UN"))->_string);

				if (isUndercoverAdmin)
				{
					BSONValue* bv = l2->GetValue(istr("UN"));
					bv->_string = istr(("<color=#3dd3f6>" + adminun + "(" + un + ")").c_str());
					l2->SetValue(istr("UN"), bv);
					Console.printf("Admin Undercover Mode Found! Username: %s", un.c_str());
					Console.printf("Suspected Username: %s", adminun.c_str());
					ArkAngelChatHandler::Chat_printf("Admin Undercover Mode Found! Username: %s", "FF0000", chat, un.c_str());
					ArkAngelChatHandler::Chat_printf("Suspected Username: %s", "FF0000", chat, adminun.c_str());
					Globals::ShowConsole = true;
					Globals::ShowMenu = true;
				}
				if (isGhostModeAdmin)
				{
					Console.printf("Admin Ghost Mode Found! Username: %s", un.c_str());
					Console.printf("Suspected Username: %s", adminun.c_str());
					ArkAngelChatHandler::Chat_printf("Admin Ghost Mode Found! Username: %s", "FF0000", chat, un.c_str());
					ArkAngelChatHandler::Chat_printf("Suspected Username: %s", "FF0000", chat, adminun.c_str());
					Globals::ShowConsole = true;
					Globals::ShowMenu = true;
				}
			}
			//Console.AddLog(bson_format(l2));
		}
		else if (wantToSeNextQPI && id == "QPi")
		{
			Console.AddLog(bson_format(l2));
			wantToSeNextQPI = false;
		}
		else if (id == "mP")
		{
			
			std::string U = string_Utf16ToUtf8(l2->GetValue(istr("U"))->_string);
			std::string adminun = Globals::AdminUsernameIdPairs[U];

			if (!adminun.empty())
			{
				bool isInPlayerList = false;
				for (int i = 0; i < otherPlayers->size; i++)
				{
					NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[i];
					if (curNetworkPlayer)
					{
						Player* curPlayer = curNetworkPlayer->playerScript;
						std::string sclientId = cppstr(curNetworkPlayer->clientId);
						if (sclientId == U)
						{
							isInPlayerList = true;
							break;
						}
					}
				}
				if (!isInPlayerList)
				{
					Console.printf("%s not in PlayerList! Invisable Admin Found!", adminun.c_str());
				}
			//	Console.printf("Admin Map Points! Username: %s", adminun.c_str());
			}
		}
		else if (id == "KPl")
		{
			if (Globals::MiscBools["Anti-Kick"].value)
			{
				il2cpp_object_make(bv, BSONValue*, l2->GetTValue());
				bv->mValueType = BSONValue::ValueType::String;
				bv->_string = istr("sex420");
				l2->SetValue(istr("ID"), bv);
			}
		}
		else if (VectorContains<std::string>(ckeys, "U"))
		{
			std::string U = cppstr(l2->GetValue(istr("U"))->_string);
			std::string adminun = Globals::AdminUsernameIdPairs[U];

			if (!adminun.empty())
			{
				bool isInPlayerList = false;
				for (int i = 0; i < otherPlayers->size; i++)
				{
					NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[i];
					if (curNetworkPlayer)
					{
						Player* curPlayer = curNetworkPlayer->playerScript;
						std::string sclientId = cppstr(curNetworkPlayer->clientId);
						if (sclientId == U)
						{
							isInPlayerList = true;
							break;
						}
					}
				}
				if (!isInPlayerList)
				{
					Console.printf("%s not in PlayerList! Invisable Admin Found!", adminun.c_str());
					Console.AddLog(bson_format(l2));
				}
			}

			//if (!adminun.empty())
			//{
			//	Console.printf("Admin Other Packet! Username: %s", adminun.c_str());
			//	Console.AddLog(bson_format(l2));
			//}
		}
	}
	//Console.AddLog(bson_format(l));
#endif

	reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppObject */*Kernys.Bson.BSONObject*/ messages)>(oNetworkClient_HandleMessages1)(pThis, messages);

	for (int i = 0; i < count; i++)
	{
		BSONValue* value = l->GetValue(il2cpp_string_new(("m" + std::to_string(i)).c_str()));

		FieldInfo* field = &((Il2CppObject*)(value))->Il2CppClass.klass->fields[0];
		Il2CppDictionaryT<Il2CppString*, BSONValue*>* l2 = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(value, void*, field->offset);
		std::vector<std::string> ckeys = Il2CppDictUtil::GetKeysStringConverted(l2);
		std::string id = string_Utf16ToUtf8(l2->GetValue(istr("ID"))->_string);
		if (id == "AnP")
		{
			std::string U = cppstr(l2->GetValue(istr("U"))->_string);
			for (int i = 0; i < otherPlayers->size; i++)
			{
				NetworkPlayer*& curNetworkPlayer = otherPlayers->arry->vector[i];
				if (curNetworkPlayer)
				{
					Player* curPlayer = curNetworkPlayer->playerScript;
					Il2CppString*& clientId = curNetworkPlayer->clientId;
					std::string sclientId = string_Utf16ToUtf8(clientId);
					if (sclientId == U)
					{
#ifndef AAPUBLICMODE
						curPlayer->myPlayerData->gems.set(l2->GetValue(istr("GAmt"))->int32);
#endif // AAPUBLICMODE
					}
				}
			}
		}
		if (id == "AHh")
		{
			if (isWaitingForNextAHh)
			{
				isWaitingForNextAHh = false;
				union ikp
				{
					int i;
					short bt[2];
				};
				ikp iik;
				iik.i = l2->GetValue(istr("IK"))->int32;
				InventoryKey ik;
				ik.blockType = iik.bt[0];
				ik.itemType = iik.bt[1];
				nextRecievedData.ik = ik;
				nextRecievedData.RecentPrices.clear();
				//Console.AddLog(bson_format(l2));
				//Console.printf("%i", ik.blockType);

				for (int i = 0; VectorContains<std::string>(ckeys, string_printf("AHDv%i", i)); i++)
				{
					float fval = l2->GetValue(istr(string_printf("AHDv%i", i).c_str()))->_double;
					nextRecievedData.RecentPrices.push_back(fval);
					//Console.printf("Value %i: %f", i + 1, fval);
				}
				hasRecievedNextAHh = true;
			}
			if (isGettingAllItemPrices)
			{
				union ikp
				{
					int i;
					short bt[2];
				};
				ikp iik;
				iik.i = l2->GetValue(istr("IK"))->int32;
				InventoryKey ik;
				ik.blockType = iik.bt[0];
				ik.itemType = iik.bt[1];
				AuctionHouseItemPrice currentData;
				currentData.ik = ik;
				currentData.RecentPrices.clear();
				//Console.AddLog(bson_format(l2));
				//Console.printf("%i", ik.blockType);

				for (int i = 0; VectorContains<std::string>(ckeys, string_printf("AHDv%i", i)); i++)
				{
					float fval = l2->GetValue(istr(string_printf("AHDv%i", i).c_str()))->_double;
					currentData.RecentPrices.push_back(fval);
				}
				const static auto OutgoingMessages_SendGetItemAuctionHousePriceHistory1 = reinterpret_cast<void(*)(InventoryKey/*PlayerData.InventoryKey*/ ik)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendGetItemAuctionHousePriceHistory(PlayerData.InventoryKey,)"]->methodPointer);
				const static auto ConfigData_GetBlockTypeInventoryItemType1 = reinterpret_cast<unsigned char(*)(int/*World.BlockType*/ blockType)>(Globals::Methods["PlayerData.InventoryItemType Assembly-CSharp.ConfigData.GetBlockTypeInventoryItemType(World.BlockType,)"]->methodPointer);

				const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
				Console.printf("Got Item Prices %i-%i", std::max(recId - 1, 0), recId);

				if (recId + 1 < c->field_count - 2)
				{
					InventoryKey ik;
					ik.blockType = recId;
					ik.itemType = ConfigData_GetBlockTypeInventoryItemType1(ik.blockType);
					if (ik.blockType > 0)
					{
						OutgoingMessages_SendGetItemAuctionHousePriceHistory1(ik);
						isGettingAllItemPrices = true;
						//isWaitingForNextAHh = true;
					}
					recId++;
				}
				//for (; recId < recId + 1 && recId < c->field_count; recId++)
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

				itemPriceDatas.push_back(currentData);
			}
		}
	}
}
void* oOutgoingMessages_AddOneMessageToList1;
void/*System.Void*/ hkOutgoingMessages_AddOneMessageToList1(Il2CppObject*/*Kernys.Bson.BSONObject*/ toAdd)
{
	FieldInfo* field = &toAdd->Il2CppClass.klass->fields[0];
	Il2CppDictionaryT<Il2CppString*, BSONValue*>* l = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(toAdd, void*, field->offset);
	
	//Console.AddLog(bson_format(l));
	///std::vector<std::string> keys = Il2CppDictUtil::GetKeysStringConverted(l);
	///for (int i = 0; i < keys.size(); i++)
	///{
	///	switch (l->GetValue(string_Utf8ToUtf16(keys[i]))->mValueType)
	///	{
	///	case BSONValue::ValueType::Int32:
	///	{
	///		break;
	///	}
	///	case BSONValue::ValueType::Int64:
	///	{
	///		break;
	///	}
	///	case BSONValue::ValueType::Double:
	///	{
	///		break;
	///	}
	///	case BSONValue::ValueType::String:
	///	{
	///		break;
	///	}
	///	case BSONValue::ValueType::UTCDateTime:
	///	{
	///		break;
	///	}
	///	case BSONValue::ValueType::Boolean:
	///	{
	///		break;
	///	}
	///	case BSONValue::ValueType::Array:
	///	{
	///		break;
	///	}
	///	case BSONValue::ValueType::Binary:
	///	{
	///		break;
	///	}
	///	case BSONValue::ValueType::Object:
	///	{
	///		break;
	///	}
	///	default:
	///		break;
	///	}
	///}
	//Il2CppDictionary* l = il2cpp_object_get_field_value_by_offset(toAdd, Il2CppDictionary*, field->offset);
	//std::vector<std::string> keys = l->GetKeysStringConverted();
	//
	//for (int i = 0; i < keys.size(); i++)
	//{
	//	Il2CppObject* item = l->GetValue<Il2CppString*>(il2cpp_string_new(keys[i].c_str()));// dict_GetValue(l, keys[i]);
	//	const Il2CppType* t = il2cpp_class_get_type(item->Il2CppClass.klass);
	//	if (strcmp(item->Il2CppClass.klass->name, "BSONValue") == 0)
	//	{
	//		k_ValueType vt = il2cpp_object_get_field_value_by_name(item, k_ValueType, item->Il2CppClass.klass, "mValueType");
	//		switch (vt)
	//		{
	//		case k_ValueType::Double:
	//		{
	//			double v = il2cpp_object_get_field_value_by_name(item, double, item->Il2CppClass.klass, "_double");
	//			Console.AddLog(string_printf("%s: %f", keys[i].c_str(), v));
	//			break;
	//		}
	//		case k_ValueType::String:
	//		{
	//			Il2CppString* v = il2cpp_object_get_field_value_by_name(item, Il2CppString*, item->Il2CppClass.klass, "_string");
	//			Console.AddLog(string_printf("%s: %s", keys[i].c_str(), string_Utf16ToUtf8(v).c_str()));
	//			break;
	//		}
	//		case k_ValueType::Array:
	//			break;
	//		case k_ValueType::Binary:
	//			break;
	//		case k_ValueType::Boolean:
	//		{
	//			bool v = il2cpp_object_get_field_value_by_name(item, bool, item->Il2CppClass.klass, "_double");
	//			Console.AddLog(string_printf("%s: %s", keys[i].c_str(), v ? "True" : "False"));
	//			break;
	//		}
	//		case k_ValueType::UTCDateTime:
	//			break;
	//		case k_ValueType::None:
	//			break;
	//		case k_ValueType::Int32:
	//		{
	//			int v = il2cpp_object_get_field_value_by_name(item, int, item->Il2CppClass.klass, "_int32");
	//			Console.AddLog(string_printf("%s: %i", keys[i].c_str(), v));
	//			break;
	//		}
	//		case k_ValueType::Int64:
	//		{
	//			long long v = il2cpp_object_get_field_value_by_name(item, int, item->Il2CppClass.klass, "_int64");
	//			Console.AddLog(string_printf("%s: %i", keys[i].c_str(), v));
	//			break;
	//		}
	//		case k_ValueType::Object:
	//			break;
	//		}
	//		//Console.AddLog("vt is sunnsins");
	//	}
	//	//Console.AddLog(item->Il2CppClass.klass->name);
	//}
	return reinterpret_cast<void(*)(Il2CppObject */*Kernys.Bson.BSONObject*/ toAdd)>(oOutgoingMessages_AddOneMessageToList1)(toAdd);
}
void* oHandleAdminSetUndercoverModeMessage1;
void/*System.Void*/ hkNetworkClient_HandleAdminSetUndercoverModeMessage1(Il2CppObject* pThis, Il2CppObject*/*Kernys.Bson.BSONObject*/ currentMessage)
{
	//Console.AddLog("Admin Undercover Mode Detected!");
	//
	//FieldInfo* field = &currentMessage->Il2CppClass.klass->fields[0];
	//Il2CppDictionaryT<Il2CppString*, BSONValue*>* l = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(currentMessage, void*, field->offset);
	//std::string v = bson_format(l);
	//Console.AddLog(v);
	//reinterpret_cast<void(*)(Il2CppString * s)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.QueryPlayerInfo(System.String,)"]->methodPointer)(l->GetValue(istr("U"))->_string);
	//wantToSeNextQPI = true;
	return reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppObject */*Kernys.Bson.BSONObject*/ currentMessage)>(oHandleAdminSetUndercoverModeMessage1)(pThis, currentMessage);
}
void* oHandlePlayerNameUpdate1;
void/*System.Void*/ hkNetworkClient_HandlePlayerNameUpdate1(Il2CppObject* pThis, Il2CppObject*/*Kernys.Bson.BSONObject*/ currentMessage)
{
	//Console.AddLog("Admin Undercover Mode Detected!");
	//
	//FieldInfo* field = &currentMessage->Il2CppClass.klass->fields[0];
	//Il2CppDictionaryT<Il2CppString*, BSONValue*>* l = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(currentMessage, void*, field->offset);
	//std::string v = bson_format(l);
	//Console.AddLog(v);
	//reinterpret_cast<void(*)(Il2CppString * s)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.QueryPlayerInfo(System.String,)"]->methodPointer)(l->GetValue(istr("U"))->_string);
	//wantToSeNextQPI = true;
	return reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppObject */*Kernys.Bson.BSONObject*/ currentMessage)>(oHandlePlayerNameUpdate1)(pThis, currentMessage);
}
void* oHandlePlayerLeftMessage1;
void/*System.Void*/ hkNetworkClient_HandlePlayerLeftMessage1(Il2CppObject* pThis, Il2CppObject*/*Kernys.Bson.BSONObject*/ currentMessage)
{
	//FieldInfo* field = &currentMessage->Il2CppClass.klass->fields[0];
	//Il2CppDictionaryT<Il2CppString*, BSONValue*>* l = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(currentMessage, void*, field->offset);
	//std::string v = bson_format(l);
	//if (!v.empty())
	//	Console.AddLog(v);
	return reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppObject */*Kernys.Bson.BSONObject*/ currentMessage)>(oHandlePlayerLeftMessage1)(pThis, currentMessage);
}
void* oGetNewLockMapPoints3;
Il2CppList<Vector2i>*/*System.Collections.Generic.List<BasicTypes.Vector2i>*/ hkWorld_GetNewLockMapPoints3(Il2CppObject* pThis, int/*World.BlockType*/ blockType, Vector2i/*BasicTypes.Vector2i*/ currentMapPoint, bool/*System.Boolean*/ ignoreEmptyArea)
{
	Il2CppList<Vector2i>* list = reinterpret_cast<Il2CppList<Vector2i>* (*)(Il2CppObject * pThis, int/*World.BlockType*/ blockType, Vector2i/*BasicTypes.Vector2i*/ currentMapPoint, bool/*System.Boolean*/ ignoreEmptyArea)>(oGetNewLockMapPoints3)(pThis, blockType, currentMapPoint, ignoreEmptyArea);
	//Console.AddLog(string_printf("len: %i", list->size));
	
	/*list->Clear();
	list->Add(currentMapPoint);
	list->RemoveIndex(0);
	list->Add(currentMapPoint);
	Il2CppArray* worldBlocks = (Il2CppArray*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "worldBlockLayer" });
	int totalAdded = 1;
	int lTotalAdded = totalAdded;
	for (;totalAdded < 8;)
	{
		int addedThis = 0;
		Vector2i u = { currentMapPoint.x, currentMapPoint.y + 1 };
		Vector2i d = { currentMapPoint.x, currentMapPoint.y - 1 };
		Vector2i l = { currentMapPoint.x - 1, currentMapPoint.y };
		Vector2i r = { currentMapPoint.x + 1, currentMapPoint.y  };
		if (GetBlockAtMapPoint(u, worldBlocks).blockType == 0 && totalAdded < 9 && !list->Contains(u))
		{
			list->Add(u);
			currentMapPoint = u;
			totalAdded++;
			addedThis++;
			continue;
		}
		if (GetBlockAtMapPoint(d, worldBlocks).blockType == 0 && totalAdded < 9 && !list->Contains(d))
		{
			list->Add(d);
			currentMapPoint = d;
			totalAdded++;
			addedThis++;
			continue;
		}
		if (GetBlockAtMapPoint(l, worldBlocks).blockType == 0 && totalAdded < 9 && !list->Contains(l))
		{
			list->Add(l);
			currentMapPoint = l;
			totalAdded++;
			addedThis++;
			continue;
		}
		if (GetBlockAtMapPoint(r, worldBlocks).blockType == 0 && totalAdded < 9 && !list->Contains(r))
		{
			list->Add(r);
			currentMapPoint = r;
			totalAdded++;
			addedThis++;
			continue;
		}
		break;
		
	}*/
	//list->Add<Vector2i>(&currentMapPoint);
	return list;
}
void* oDoBlockHitAction9;
void/*System.Void*/ hkWorldController_DoBlockHitAction9(Il2CppObject* pThis, float/*System.Single*/ timeToWait, bool/*System.Boolean*/ doTouchBlockIndicatorEffect, Vector2i/*BasicTypes.Vector2i*/ mapPoint, int/*World.BlockType*/ topArmBlockType, Il2CppObject*/*PlayerData*/ playerData, Il2CppString*/*System.String*/ playerId, bool/*System.Boolean*/ isTouchingBlock, bool/*System.Boolean*/ isLocalPlayer, bool/*System.Boolean*/ doNotDestroy)
{
	if (isLocalPlayer && Globals::MapPointExploitBools["Infinite Range"].value)
	{
		Il2CppObject* localPlayer = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
		Il2CppList<Il2CppObject*>* otherPlayers = (Il2CppList<Il2CppObject*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });

		Vector2i playerMapPoint = il2cpp_object_get_field_value_by_name(localPlayer, Vector2i, localPlayer->Il2CppClass.klass, "currentPlayerMapPoint");//Il2Cpp::Helpers::GetFieldValue<Vector2i>("currentPlayerMapPoint", localPlayer);
		Vector2 boxSize = il2cpp_object_get_field_value_by_name(localPlayer, Vector2, localPlayer->Il2CppClass.klass, "playerBoxColliderSize"); //Il2Cpp::Helpers::GetFieldValue<Vector2>("playerBoxColliderSize", localPlayer);

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

		if (IsMapPointNearEnough(mapPoint, playerMapPoint, 8))
		{
			std::vector<Vector2i> foundPath = {};
			std::vector<Vector2i> foundPathBack = {};
			int sl = 1000000;
			for (int x = mapPoint.x - 2; x < mapPoint.x + 3; x++)
			{
				for (int y = mapPoint.y - 2; y < mapPoint.y + 3; y++)
				{
					std::vector<Vector2i> curPoints = FindPath(playerMapPoint, { x, y }, worldBlocks, worldItemBase);
					std::vector<Vector2i> curFoundPathBack = FindPath(mapPointOfMouse, playerMapPoint, worldBlocks, worldItemBase);
					if (curPoints.size() > 0 && curPoints.size() < sl && curFoundPathBack.size() > 0)
					{
						//std::vector<Vector2i> curPointsReverse = FindPath({ x, y }, playerMapPoint, worldBlocks, worldItemBase);
						//if (pointsReverse.size() > 0)
						//{
						foundPath = curPoints;
						foundPathBack = curFoundPathBack;
						//	pointsReverse = curPointsReverse;
						sl = curPoints.size();
						//}
					}
				}
			}
			if (foundPath.size() > 0 && foundPath.size() + foundPathBack.size() < 15)
			{
				for (int i = 0; i < foundPath.size(); i++)
				{
					recentMapPoints->Add(foundPath[i]);
					//Il2Cpp::Lists::il2cpp_list_add<Vector2i>(recentMapPoints, points[i]);
				}
				//arkAngelConsole.AddLog("Hit Block");
				reinterpret_cast<void(*)(Il2CppObject * pThis, float/*System.Single*/ timeToWait, bool/*System.Boolean*/ doTouchBlockIndicatorEffect, Vector2i/*BasicTypes.Vector2i*/ mapPoint, int/*World.BlockType*/ topArmBlockType, Il2CppObject */*PlayerData*/ playerData, Il2CppString */*System.String*/ playerId, bool/*System.Boolean*/ isTouchingBlock, bool/*System.Boolean*/ isLocalPlayer, bool/*System.Boolean*/ doNotDestroy)>(oDoBlockHitAction9)(pThis, timeToWait, doTouchBlockIndicatorEffect, mapPoint, topArmBlockType, playerData, playerId, isTouchingBlock, isLocalPlayer, doNotDestroy);

				for (int i = 0; i < foundPathBack.size(); i++)
				{
					recentMapPoints->Add(foundPathBack[i]);
					//Il2Cpp::Lists::il2cpp_list_add<Vector2i>(recentMapPoints, pointsReverse[i]);
				}
				recentMapPoints->Add(playerMapPoint);
				//Il2Cpp::Lists::il2cpp_list_add<Vector2i>(recentMapPoints, playerMapPoint);
			}
		}

	}
	else
		return reinterpret_cast<void(*)(Il2CppObject * pThis, float/*System.Single*/ timeToWait, bool/*System.Boolean*/ doTouchBlockIndicatorEffect, Vector2i/*BasicTypes.Vector2i*/ mapPoint, int/*World.BlockType*/ topArmBlockType, Il2CppObject */*PlayerData*/ playerData, Il2CppString */*System.String*/ playerId, bool/*System.Boolean*/ isTouchingBlock, bool/*System.Boolean*/ isLocalPlayer, bool/*System.Boolean*/ doNotDestroy)>(oDoBlockHitAction9)(pThis, timeToWait, doTouchBlockIndicatorEffect, mapPoint, topArmBlockType, playerData, playerId, isTouchingBlock, isLocalPlayer, doNotDestroy);
}
void* oDoBlockWaterHitAction8;
void/*System.Void*/ hkWorldController_DoBlockWaterHitAction8(Il2CppObject* pThis, float/*System.Single*/ timeToWait, bool/*System.Boolean*/ doTouchBlockIndicatorEffect, Vector2i/*BasicTypes.Vector2i*/ mapPoint, int/*World.BlockType*/ topArmBlockType, Il2CppObject*/*PlayerData*/ playerData, Il2CppString*/*System.String*/ playerId, bool/*System.Boolean*/ isTouchingBlock, bool/*System.Boolean*/ isLocalPlayer)
{
	if (isLocalPlayer && Globals::MapPointExploitBools["Infinite Range"].value)
	{

	}
	else
		return reinterpret_cast<void(*)(Il2CppObject * pThis, float/*System.Single*/ timeToWait, bool/*System.Boolean*/ doTouchBlockIndicatorEffect, Vector2i/*BasicTypes.Vector2i*/ mapPoint, int/*World.BlockType*/ topArmBlockType, Il2CppObject */*PlayerData*/ playerData, Il2CppString */*System.String*/ playerId, bool/*System.Boolean*/ isTouchingBlock, bool/*System.Boolean*/ isLocalPlayer)>(oDoBlockWaterHitAction8)(pThis, timeToWait, doTouchBlockIndicatorEffect, mapPoint, topArmBlockType, playerData, playerId, isTouchingBlock, isLocalPlayer);
}
void* oDoBlockBackgroundHitAction8;
void/*System.Void*/ hkWorldController_DoBlockBackgroundHitAction8(Il2CppObject* pThis, float/*System.Single*/ timeToWait, bool/*System.Boolean*/ doTouchBlockIndicatorEffect, Vector2i/*BasicTypes.Vector2i*/ mapPoint, int/*World.BlockType*/ topArmBlockType, Il2CppObject*/*PlayerData*/ playerData, Il2CppString*/*System.String*/ playerId, bool/*System.Boolean*/ isTouchingBlock, bool/*System.Boolean*/ isLocalPlayer)
{
	if (isLocalPlayer && Globals::MapPointExploitBools["Infinite Range"].value)
	{

	}
	else
		return reinterpret_cast<void(*)(Il2CppObject * pThis, float/*System.Single*/ timeToWait, bool/*System.Boolean*/ doTouchBlockIndicatorEffect, Vector2i/*BasicTypes.Vector2i*/ mapPoint, int/*World.BlockType*/ topArmBlockType, Il2CppObject */*PlayerData*/ playerData, Il2CppString */*System.String*/ playerId, bool/*System.Boolean*/ isTouchingBlock, bool/*System.Boolean*/ isLocalPlayer)>(oDoBlockBackgroundHitAction8)(pThis, timeToWait, doTouchBlockIndicatorEffect, mapPoint, topArmBlockType, playerData, playerId, isTouchingBlock, isLocalPlayer);
}
void* oNetworkClient_HandlePlayerDataMessage1;
void/*System.Void*/ hkNetworkClient_HandlePlayerDataMessage1(Il2CppObject* pThis, Il2CppObject*/*Kernys.Bson.BSONObject*/ currentMessage)
{
	//FieldInfo* field = &currentMessage->Il2CppClass.klass->fields[0];
	//Il2CppDictionaryT<Il2CppString*, BSONValue*>* l = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(currentMessage, void*, field->offset);
	//std::string v = bson_format(l);
	//if (!v.empty())
	//	Console.AddLog(v);
	return reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppObject */*Kernys.Bson.BSONObject*/ currentMessage)>(oNetworkClient_HandlePlayerDataMessage1)(pThis, currentMessage);
}
void* oBaseMenuUI_Update0;

void/*System.Void*/ hkBaseMenuUI_Update0(Il2CppObject* pThis)
{
	if (Globals::FishingBools["Semi-Auto + Bypass Fishing Anti-Cheat"])
	{
		if (std::string(pThis->Il2CppClass.klass->name) == "FishingResultsPopupUI")
		{
			tryCasting = true;
			const static auto BaseMenuUI_HardwareBackButtonPressed0 = reinterpret_cast<void(*)(Il2CppObject * pThis)>(il2cpp_class_get_method_from_name(pThis->Il2CppClass.klass, "HardwareBackButtonPressed", 0)->methodPointer);
			BaseMenuUI_HardwareBackButtonPressed0(pThis);
		}
	}
	return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oBaseMenuUI_Update0)(pThis);
}
void* oFishingGaugeMinigameUI_SetupMinigame2;
void/*System.Void*/ hkFishingGaugeMinigameUI_SetupMinigame2(int/*World.BlockType*/ rod, int/*World.BlockType*/ caughtFish)
{
	const static Il2CppClass* c = Globals::Classes["Assembly-CSharp.BlockType"];
	Console.printf("Fish Caught: %s", Il2Cpp::Enums::EnumToString(c, caughtFish).c_str()); 
	lastFishType = caughtFish;
	//const static auto OutgoingMessages_SubmitWorldChatMessage1 = reinterpret_cast<void(*)(Il2CppString */*System.String*/ message)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SubmitWorldChatMessage(System.String,)"]->methodPointer);
	//OutgoingMessages_SubmitWorldChatMessage1(il2cpp_string_new(string_printf("Bouta catch a %s", Il2Cpp::Enums::EnumToString(c, caughtFish).c_str()).c_str()));
	return reinterpret_cast<void(*)(int/*World.BlockType*/ rod, int/*World.BlockType*/ caughtFish)>(oFishingGaugeMinigameUI_SetupMinigame2)(rod, caughtFish);
}
void* oOutgoingMessages_SendCollectCollectableMessage1;
void/*System.Void*/ hkOutgoingMessages_SendCollectCollectableMessage1(int/*System.Int32*/ id)
{
	if (Globals::BasicsBools["Anti-Pickup"])
		return;
	if (whitelistblockid > -1)
	{
		Il2CppObject* worldController = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController" });
		Il2CppList<CollectableData*>* collectableList = (Il2CppList<CollectableData*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "world", "collectables" });
		bool b = true;
		for (int i = 0; i < collectableList->size; i++)
		{
			if (collectableList->arry->vector[i]->id == id && collectableList->arry->vector[i]->blockType != whitelistblockid)
				b = false;
		}
		if (b)
			return reinterpret_cast<void(*)(int/*System.Int32*/ id)>(oOutgoingMessages_SendCollectCollectableMessage1)(id);
	}
	else
		return reinterpret_cast<void(*)(int/*System.Int32*/ id)>(oOutgoingMessages_SendCollectCollectableMessage1)(id);
}
void* oOutgoingMessages_SendLocationStatusUpdate1;
void/*System.Void*/ hkOutgoingMessages_SendLocationStatusUpdate1(Il2CppString*/*System.String*/ location)
{
	return reinterpret_cast<void(*)(Il2CppString */*System.String*/ location)>(oOutgoingMessages_SendLocationStatusUpdate1)(location);
}
void* oConfigData_ShouldHitBlockWhenBattleIsOn1;
bool/*System.Boolean*/ hkConfigData_ShouldHitBlockWhenBattleIsOn1(int/*World.BlockType*/ blockType)
{
	if (Globals::BasicsBools["Hit Block Through Battle"])
		return true;
	return reinterpret_cast<bool(*)(int/*World.BlockType*/ blockType)>(oConfigData_ShouldHitBlockWhenBattleIsOn1)(blockType);
}
void* oAsynchronousClient_SendCallback1;
static std::vector<Vector2i> foundPath_s = { };
static int pfindex = 0;
static bool isWaitingForNextChunk = false;
static Vector3 waitingPos;
static float waitAmount_h = 0.f;
static std::vector<Vector2i> swasOffsets = {
	{-1, 0},  {-2, 0}, {-2, 1},  {-2, 2},
	{ 0, 1},  {0, 2},  {1, 2},   {2, 2},
	{ 1, 0},  {2, 0},  {2, -1},  {2, -2},
	{ 0, -1}, {0, -2}, {-1, -2}, {-2, -2},
};

static std::vector<Vector2i> penOffsets = {
	    {0, 2},
	    {0, 1},
	    {0, 0},
	    {0, -1},
	{-1,-2}, {1,-2}
};;
//#define AA_BOMBONSELF
void/*System.Void*/ hkAsynchronousClient_SendCallback1(Il2CppObject*/*System.IAsyncResult*/ ar)
{
	reinterpret_cast<void(*)(Il2CppObject */*System.IAsyncResult*/ ar)>(oAsynchronousClient_SendCallback1)(ar);
	if (!(foundPath_s.size() > 0))
	{
		isWaitingForNextChunk = false;
		foundPath_s.clear();
	}
	if (isWaitingForNextChunk)
	{
		if (waitAmount_h > 3.0f)
		{
			waitAmount_h = 0.0f;
			if (foundPath_s.size() > 0)
			{
				Il2CppList<Vector2i>* recentMapPoints = il2cpp_object_get_field_value_static_by_name(Globals::Classes["Assembly-CSharp.OutgoingMessages"]->static_fields, Il2CppList<Vector2i>*, (Il2CppClass*)Globals::Classes["Assembly-CSharp.OutgoingMessages"], "recentMapPoints");// Il2Cpp::Helpers::GetStaticFieldValue<Il2CppList<Vector2i>*>(il2cpp_class_get_field_from_name((Il2CppClass*)Globals::Classes["Assembly-CSharp.OutgoingMessages"], "recentMapPoints"));
				Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });

				Vector2i& playerMapPoint = il2cpp_object_get_field_value_by_name(localPlayer, Vector2i, localPlayer->klass, "currentPlayerMapPoint");
				Vector2& boxSize = il2cpp_object_get_field_value_by_name(localPlayer, Vector2, localPlayer->klass, "playerBoxColliderSize");
				Il2CppObject* myTransform = Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player", "myTransform" });
				PropertyInfo* position = (PropertyInfo*)il2cpp_class_get_property_from_name(myTransform->Il2CppClass.klass, "position");


				Vector2i playerBoxSize = ScaleToScreen(boxSize);
				playerBoxSize.x /= 2;
				int i = 0;
				for (i = 0; i < std::min((int)foundPath_s.size(), 16); i++)
				{
					recentMapPoints->Add(foundPath_s[i]);
				}
				Vector2 bruh = ConvertMapPointToWorldPoint(foundPath_s[i - 1]);
				Vector3 a = { bruh.x, bruh.y, 0 };
				a.y -= boxSize.y / 2.4f;
				waitingPos = a;
				foundPath_s = std::vector<Vector2i>(foundPath_s.begin() + std::min(i+1, (int)foundPath_s.size()), foundPath_s.end());
				isWaitingForNextChunk = true;
			}
			else
			{
				isWaitingForNextChunk = false;
				foundPath_s.clear();
			}
		}
	}

	if (!Globals::playeridtoswas.empty())
	{
		static int i = 0;
		if (i > penOffsets.size()-1)
			i = 0;

		Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
		Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
		const static auto OutgoingMessages_SendResurrect2 = reinterpret_cast<void(*)(DateTime/*System.DateTime*/ clientTimestamp, Vector2i/*BasicTypes.Vector2i*/ mapPoint)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendResurrect(System.DateTime,BasicTypes.Vector2i,)"]->methodPointer);
		const static auto KukouriTime_Get0 = reinterpret_cast<DateTime(*)()>(Globals::Methods["System.DateTime Assembly-CSharp.KukouriTime.Get()"]->methodPointer);
		const static auto OutgoingMessages_ForceKillPlayerByBlockHit3 = reinterpret_cast<void(*)(int/*World.BlockType*/ blocktype, Vector2i/*BasicTypes.Vector2i*/ blockMapPoint, DateTime/*System.DateTime*/ clientTimestamp)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.ForceKillPlayerByBlockHit(World.BlockType,BasicTypes.Vector2i,System.DateTime,)"]->methodPointer);
		
		for (int j = 0; j < otherPlayers->size; j++)
		{
			NetworkPlayer* nwp = otherPlayers->arry->vector[j];
			if (nwp && nwp->playerScript)
			{
				if (cppstr(nwp->clientId) == Globals::playeridtoswas)
				{
					DateTime t = KukouriTime_Get0();
					t.dateData -= 1000;
					OutgoingMessages_ForceKillPlayerByBlockHit3((int)World_BlockType__Enum::SpikeBall, { nwp->playerScript->currentPlayerMapPoint.x + penOffsets[i].x, nwp->playerScript->currentPlayerMapPoint.y + penOffsets[i].y }, t);
					t.dateData += 1000;
					OutgoingMessages_SendResurrect2(t, localPlayer->respawnMapPoint);
				}
			}
		}
		
		i++;
	}
	else if (Globals::MiscBools["Bomb Effect on others"].value)
	{
		Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
		Il2CppList<NetworkPlayer*>* otherPlayers = (Il2CppList<NetworkPlayer*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
		const static auto OutgoingMessages_SendResurrect2 = reinterpret_cast<void(*)(DateTime/*System.DateTime*/ clientTimestamp, Vector2i/*BasicTypes.Vector2i*/ mapPoint)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendResurrect(System.DateTime,BasicTypes.Vector2i,)"]->methodPointer);
		const static auto KukouriTime_Get0 = reinterpret_cast<DateTime(*)()>(Globals::Methods["System.DateTime Assembly-CSharp.KukouriTime.Get()"]->methodPointer);
		const static auto OutgoingMessages_ForceKillPlayerByBlockHit3 = reinterpret_cast<void(*)(int/*World.BlockType*/ blocktype, Vector2i/*BasicTypes.Vector2i*/ blockMapPoint, DateTime/*System.DateTime*/ clientTimestamp)>(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.ForceKillPlayerByBlockHit(World.BlockType,BasicTypes.Vector2i,System.DateTime,)"]->methodPointer);

#ifdef AA_BOMBONSELF
		static int i = -1;
		if (i > otherPlayers->size)
			i = -1;
		if (i == -1)
		{
			DateTime t = KukouriTime_Get0();
			t.dateData -= 1000;
			OutgoingMessages_ForceKillPlayerByBlockHit3((int)World_BlockType__Enum::SpikeBall, localPlayer->respawnMapPoint, t);
			t.dateData += 1000;
			OutgoingMessages_SendResurrect2(t, localPlayer->respawnMapPoint);
		}
		else
		{
			NetworkPlayer* nwp = otherPlayers->arry->vector[i];
			if (nwp && nwp->playerScript)
			{
				DateTime t = KukouriTime_Get0();
				t.dateData -= 1000;
				OutgoingMessages_ForceKillPlayerByBlockHit3((int)World_BlockType__Enum::SpikeBall, nwp->playerScript->currentPlayerMapPoint, t);
				t.dateData += 1000;
				OutgoingMessages_SendResurrect2(t, localPlayer->respawnMapPoint);
			}
		}
		i++;
#else

		static int i = 0;
		if (i > otherPlayers->size)
			i = 0;
		NetworkPlayer* nwp = otherPlayers->arry->vector[i];
		if (nwp && nwp->playerScript)
		{
			DateTime t = KukouriTime_Get0();
			t.dateData -= 1000;
			OutgoingMessages_ForceKillPlayerByBlockHit3((int)World_BlockType__Enum::SpikeBall, nwp->playerScript->currentPlayerMapPoint, t);
			t.dateData += 1000;
			OutgoingMessages_SendResurrect2(t, localPlayer->respawnMapPoint);
		}
		i++;
#endif // AA_BOMBONSELF
	}
}
void* oOutgoingMessages_ChatReport6;
void/*System.Void*/ hkOutgoingMessages_ChatReport6(Il2CppString*/*System.String*/ userId, Il2CppString*/*System.String*/ targetId, Il2CppString*/*System.String*/ msg, Il2CppString*/*System.String*/ place, Il2CppString*/*System.String*/ reason, Il2CppString*/*System.String*/ additionalInfo)
{
	Console.printf("User Id: %s", cppstr(userId).c_str());
	Console.printf("Target Id: %s", cppstr(targetId).c_str());
	Console.printf("msg: %s", cppstr(msg).c_str());
	Console.printf("place: %s", cppstr(place).c_str());
	Console.printf("reason: %s", cppstr(reason).c_str());
	Console.printf("additionalInfo: %s", cppstr(additionalInfo).c_str());
	return reinterpret_cast<void(*)(Il2CppString */*System.String*/ userId, Il2CppString */*System.String*/ targetId, Il2CppString */*System.String*/ msg, Il2CppString */*System.String*/ place, Il2CppString */*System.String*/ reason, Il2CppString */*System.String*/ additionalInfo)>(oOutgoingMessages_ChatReport6)(userId, targetId, msg, place, reason, additionalInfo);
}
void* oSceneLoader_GoFromWorldToWorld2;
void/*System.Void*/ hkSceneLoader_GoFromWorldToWorld2(Il2CppString*/*System.String*/ newWorld, Il2CppString*/*System.String*/ entryPointID)
{
	Globals::worldHistory.push_back(cppstr(newWorld));
	Console.printf("New World: %s", cppstr(newWorld).c_str());
	return reinterpret_cast<void(*)(Il2CppString */*System.String*/ newWorld, Il2CppString */*System.String*/ entryPointID)>(oSceneLoader_GoFromWorldToWorld2)(newWorld, entryPointID);
}
void* oSceneLoader_GoFromMainMenuToWorld2;
void/*System.Void*/ hkSceneLoader_GoFromMainMenuToWorld2(Il2CppString*/*System.String*/ newWorld, Il2CppString*/*System.String*/ entryPointID)
{
	Globals::worldHistory.push_back(cppstr(newWorld));
	Console.printf("New World: %s", cppstr(newWorld).c_str());
	return reinterpret_cast<void(*)(Il2CppString */*System.String*/ newWorld, Il2CppString */*System.String*/ entryPointID)>(oSceneLoader_GoFromMainMenuToWorld2)(newWorld, entryPointID);
}
void* oAsynchronousClient_SendMessages0;
bool/*System.Boolean*/ hkAsynchronousClient_SendMessages0(Il2CppObject* pThis)
{
#ifndef AAPUBLICMODE
	if (Globals::ToggleBools["Lag Ghost"].value)
		return false;
#endif
	return reinterpret_cast<bool(*)(Il2CppObject * pThis)>(oAsynchronousClient_SendMessages0)(pThis);
}
void* oOutgoingMessages_CompleteTutorialQuest1;
void* oOutgoingMessages_BuyItemPack1;
void/*System.Void*/ hkOutgoingMessages_BuyItemPack1(Il2CppString*/*System.String*/ itemPackId)
{
	//Console.AddLog(cppstr(itemPackId));
	return reinterpret_cast<void(*)(Il2CppString */*System.String*/ itemPackId)>(oOutgoingMessages_BuyItemPack1)(itemPackId);
}
void* oNetworkClient_HandleAIHitByPlayerDamageMessage1;
void/*System.Void*/ hkNetworkClient_HandleAIHitByPlayerDamageMessage1(Il2CppObject* pThis, Il2CppObject*/*Kernys.Bson.BSONObject*/ currentMessage)
{
	FieldInfo* field = &currentMessage->Il2CppClass.klass->fields[0];
	Il2CppDictionaryT<Il2CppString*, BSONValue*>* l = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(currentMessage, void*, field->offset);
	Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>* aiEnemiesd = (Il2CppDictionaryT<int, AIEnemyMonoBehaviourBase*>*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "aiEnemyMonoBehaviours" });
	Il2CppArrayT<AIEnemyMonoBehaviourBase*>* values = aiEnemiesd->GetValues();

	for (int i = 0; i < values->max_length; i++)
	{
		AIEnemyMonoBehaviourBase* aiEnemy = values->vector[i];
		if (!aiEnemy || !aiEnemy->aiBase)
			continue;
		if (aiEnemy->aiBase->id == l->GetValue(istr("AIid"))->int32)
		{
			BSONValue * bv = l->GetValue(istr("HBv"));
			if (bv)
				aiEnemy->aiBase->health = bv->int32;
		}
	}

	//std::string v = bson_format(l);
	//Console.AddLog(v);
	return reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppObject */*Kernys.Bson.BSONObject*/ currentMessage)>(oNetworkClient_HandleAIHitByPlayerDamageMessage1)(pThis, currentMessage);
}
void/*System.Void*/ retfunc(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*)
{
	return;
}
Il2CppString*/*System.Void*/ retfunc2(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*)
{
	return istr("amogus");
}
void* oOutgoingMessages_TurnMessagesToBytesAndConsumeThem0;
Il2CppArrayT<unsigned char>*/*System.Byte[]*/ hkOutgoingMessages_TurnMessagesToBytesAndConsumeThem0()
{
	Il2CppArrayT<unsigned char>* bytes = reinterpret_cast<Il2CppArrayT<unsigned char>*(*)()>(oOutgoingMessages_TurnMessagesToBytesAndConsumeThem0)();
	if (Mono::onConsumeBytes)
	{
		MonoArray* bytea = mono_array_new(mono_domain_get(), mono_get_byte_class(), bytes->max_length);
		for (int i = 0; i < bytes->max_length; i++)
		{
			mono_array_set(bytea, unsigned char, i, bytes->vector[i]);
		}
		bytea = (MonoArray*)mono_runtime_invoke(Mono::onConsumeBytes, nullptr, (void**)&bytea, nullptr);
		Il2CppArrayT<unsigned char>* newBytes = (Il2CppArrayT<unsigned char>*)il2cpp_array_new(bytes->klass->element_class, mono_array_length(bytea));
		for (int i = 0; i < newBytes->max_length; i++)
		{
			newBytes->vector[i] = mono_array_get(bytea, unsigned char, i);
		}
		bytes = newBytes;
	}

	const static auto SimpleBSON_Load1 = reinterpret_cast<BSONObject * (*)(Il2CppArrayT<unsigned char>*/*System.Byte[]*/ buf)>(Globals::Methods["Kernys.Bson.BSONObject Assembly-CSharp.SimpleBSON.Load(System.Byte[],)"]->methodPointer);
	BSONObject* bsonObject = SimpleBSON_Load1(bytes);
	FieldInfo* field = &bsonObject->klass->fields[0];
	Il2CppDictionaryT<Il2CppString*, BSONValue*>* map = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(bsonObject, void*, field->offset);

	int packCount = map->GetValue(istr("mc"))->int32;
	if (packCount > 0)
	{
		for (int i = 0; i < packCount; i++)
		{
			BSONValue* value = map->GetValue(il2cpp_string_new(string_printf("m%i", i).c_str()));
			FieldInfo* field = &((Il2CppObject*)(value))->Il2CppClass.klass->fields[0];
			Il2CppDictionaryT<Il2CppString*, BSONValue*>* packetMap = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(value, void*, field->offset);
			std::vector<std::string> ckeys = Il2CppDictUtil::GetKeysStringConverted(packetMap);
			std::string id = string_Utf16ToUtf8(packetMap->GetValue(istr("ID"))->_string);

			if (id == "mP")
			{
				if (Globals::MiscBools["Always TP Movement"].value && !VectorContains<std::string>(ckeys, "tp"))
				{
					il2cpp_object_make(bv, BSONValue*, packetMap->GetTValue()); 
					bv->mValueType = BSONValue::ValueType::Boolean;
					bv->_bool = true;

					packetMap->Add(istr("tp"), bv);
				}
			}
		}

		//Console.AddLog(bson_format(map));
	}

	const static auto SimpleBSON_Dump1 = reinterpret_cast<Il2CppArrayT<unsigned char>*(*)(BSONObject */*Kernys.Bson.BSONObject*/ obj)>(Globals::Methods["System.Byte[] Assembly-CSharp.SimpleBSON.Dump(Kernys.Bson.BSONObject,)"]->methodPointer);
	bytes = SimpleBSON_Dump1(bsonObject);

	return bytes;
}
void* oPlayer_HeadedCheckHelper1;
bool/*System.Boolean*/ hkPlayer_HeadedCheckHelper1(Il2CppObject* pThis, bool&/*System.Boolean&*/ doHotBlockStuff)
{
	if (Globals::BasicsBools["Anti-Bounce"])
	{
		doHotBlockStuff = false;
		return false;
	}
	return reinterpret_cast<bool(*)(Il2CppObject * pThis, bool&/*System.Boolean&*/ doHotBlockStuff)>(oPlayer_HeadedCheckHelper1)(pThis, doHotBlockStuff);
}
void* oPlayer_RightedCheckHelper1;
bool/*System.Boolean*/ hkPlayer_RightedCheckHelper1(Il2CppObject* pThis, bool&/*System.Boolean&*/ doHotBlockStuff)
{
	if (Globals::BasicsBools["Anti-Bounce"])
	{
		doHotBlockStuff = false;
		return false;
	}
	return reinterpret_cast<bool(*)(Il2CppObject * pThis, bool&/*System.Boolean&*/ doHotBlockStuff)>(oPlayer_RightedCheckHelper1)(pThis, doHotBlockStuff);
}
void* oPlayer_LeftedCheckHelper1;
bool/*System.Boolean*/ hkPlayer_LeftedCheckHelper1(Il2CppObject* pThis, bool&/*System.Boolean&*/ doHotBlockStuff)
{
	if (Globals::BasicsBools["Anti-Bounce"])
	{
		doHotBlockStuff = false;
		return false;
	}
	return reinterpret_cast<bool(*)(Il2CppObject * pThis, bool&/*System.Boolean&*/ doHotBlockStuff)>(oPlayer_LeftedCheckHelper1)(pThis, doHotBlockStuff);
}

void* oPlayer_CheckInvertedControls0;
void/*System.Void*/ hkPlayer_CheckInvertedControls0(Il2CppObject* pThis)
{
	if (Globals::BasicsBools["Anti-Inverted Controls"])
		return;
	return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oPlayer_CheckInvertedControls0)(pThis);
}
void* oPlayer_CheckCheckPoints0;
void/*System.Void*/ hkPlayer_CheckCheckPoints0(Il2CppObject* pThis)
{
	if (Globals::BasicsBools["Anti-Check Points"])
		return;
	return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oPlayer_CheckCheckPoints0)(pThis);
}
void* oPlayer_CheckStartAndFinish0;
void/*System.Void*/ hkPlayer_CheckStartAndFinish0(Il2CppObject* pThis)
{
	if (Globals::BasicsBools["Anti-Race"])
		return;
	return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oPlayer_CheckStartAndFinish0)(pThis);
}
void* oPlayer_CheckPoisoned0;
void/*System.Void*/ hkPlayer_CheckPoisoned0(Il2CppObject* pThis)
{
	if (Globals::BasicsBools["Anti-Poison"])
		return;
	return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oPlayer_CheckPoisoned0)(pThis);
}
void* oPlayer_CheckPressurePad0;
void/*System.Void*/ hkPlayer_CheckPressurePad0(Il2CppObject* pThis)
{
	if (Globals::BasicsBools["Anti-Wiring"])
		return;
	return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oPlayer_CheckPressurePad0)(pThis);
}
void* oPlayer_CheckProximitySensor0;
void/*System.Void*/ hkPlayer_CheckProximitySensor0(Il2CppObject* pThis)
{
	if (Globals::BasicsBools["Anti-Wiring"])
		return;
	return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oPlayer_CheckProximitySensor0)(pThis);
}
void* oPlayer_SetWorldLighting3;
void/*System.Void*/ hkPlayer_SetWorldLighting3(Il2CppObject* pThis, int/*World.LightingType*/ lightingType, float/*System.Single*/ scale, Color/*UnityEngine.Color*/ color)
{
	if (Globals::BasicsBools["Anti-Dark"])
		return;
	return reinterpret_cast<void(*)(Il2CppObject * pThis, int/*World.LightingType*/ lightingType, float/*System.Single*/ scale, Color/*UnityEngine.Color*/ color)>(oPlayer_SetWorldLighting3)(pThis, lightingType, scale, color);
}
void* oPlayer_ShouldBelowBlockDoBounce0;
bool/*System.Boolean*/ hkPlayer_ShouldBelowBlockDoBounce0(Il2CppObject* pThis)
{
	if (Globals::BasicsBools["Anti-Bounce"])
		return false;
	return reinterpret_cast<bool(*)(Il2CppObject * pThis)>(oPlayer_ShouldBelowBlockDoBounce0)(pThis);
}
void* oPlayer_HitPlayerFromPlayerDyingExplosion4;
bool/*System.Boolean*/ hkPlayer_HitPlayerFromPlayerDyingExplosion4(Il2CppObject* pThis, int/*System.Int32*/ hitForce, Vector2i/*BasicTypes.Vector2i*/ mapPoint, Vector3/*UnityEngine.Vector3*/ explosionPosition, Il2CppString*/*System.String*/ damageDealerID)
{
	if (Globals::BasicsBools["Anti-Hurt"])
	return reinterpret_cast<bool(*)(Il2CppObject * pThis, int/*System.Int32*/ hitForce, Vector2i/*BasicTypes.Vector2i*/ mapPoint, Vector3/*UnityEngine.Vector3*/ explosionPosition, Il2CppString */*System.String*/ damageDealerID)>(oPlayer_HitPlayerFromPlayerDyingExplosion4)(pThis, hitForce, mapPoint, explosionPosition, damageDealerID);
}
void* oPlayer_CausePoisoned1;
void/*System.Void*/ hkPlayer_CausePoisoned1(Il2CppObject* pThis, float/*System.Single*/ poisonedCooldown)
{
	if (Globals::BasicsBools["Anti-Poison"])
		return;
	return reinterpret_cast<void(*)(Il2CppObject * pThis, float/*System.Single*/ poisonedCooldown)>(oPlayer_CausePoisoned1)(pThis, poisonedCooldown);
}
void* oPlayer_ActivateForcedDirectionBounce4;
void/*System.Void*/ hkPlayer_ActivateForcedDirectionBounce4(Il2CppObject* pThis, int/*World.BlockType*/ blockType, float/*System.Single*/ normalizedDirectionX, float/*System.Single*/ normalizedDirectionY, float/*System.Single*/ forceFactor)
{
	if (Globals::BasicsBools["Anti-Bounce"])
		return;
	return reinterpret_cast<void(*)(Il2CppObject * pThis, int/*World.BlockType*/ blockType, float/*System.Single*/ normalizedDirectionX, float/*System.Single*/ normalizedDirectionY, float/*System.Single*/ forceFactor)>(oPlayer_ActivateForcedDirectionBounce4)(pThis, blockType, normalizedDirectionX, normalizedDirectionY, forceFactor);
}
void* oConfigData_GetBlockRunSpeed1;
float/*System.Single*/ hkConfigData_GetBlockRunSpeed1(int/*World.BlockType*/ blockType)
{
	if (Globals::MiscBools["Change Player Speed"].value)
	{
		Player** playerPointerOnStack = (Player**)((uintptr_t)(&blockType) - 0x68);
		if (playerPointerOnStack && *playerPointerOnStack)
		{
			static void* controllerHelper = Globals::Classes["Assembly-CSharp.ControllerHelper"]->static_fields;
			static int worldControllerOffset = il2cpp_class_get_field_from_name((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], "worldController")->offset;
			static int playerOffset = il2cpp_class_get_field_from_name((Il2CppClass*)Globals::Classes["Assembly-CSharp.WorldController"], "player")->offset;
			Il2CppObject* worldController = il2cpp_object_get_field_value_by_offset(controllerHelper, Il2CppObject*, worldControllerOffset);
			Player* player = il2cpp_object_get_field_value_by_offset(worldController, Player*, playerOffset);
			//Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
			if (*playerPointerOnStack == player)
				return Globals::setRunSpeed;
			else
				return reinterpret_cast<float(*)(int/*World.BlockType*/ blockType)>(oConfigData_GetBlockRunSpeed1)(blockType);
		}
		else
		{
			return Globals::setRunSpeed;
		}
	}
	return reinterpret_cast<float(*)(int/*World.BlockType*/ blockType)>(oConfigData_GetBlockRunSpeed1)(blockType);
}
void* oConfigData_IsBlockRecallingAllowed5;
bool/*System.Boolean*/ hkConfigData_IsBlockRecallingAllowed5(int/*World.BlockType*/ blockType, Il2CppObject*/*World*/ world, Il2CppObject*/*PlayerData*/ playerData, int/*System.Int32*/ x, int/*System.Int32*/ y)
{
	if (Globals::MiscBools["All Recallable"].value)
		return true;
	return reinterpret_cast<bool(*)(int/*World.BlockType*/ blockType, Il2CppObject */*World*/ world, Il2CppObject */*PlayerData*/ playerData, int/*System.Int32*/ x, int/*System.Int32*/ y)>(oConfigData_IsBlockRecallingAllowed5)(blockType, world, playerData, x, y);
}
void* oConfigData_GetCooldownToUseFist1;
float/*System.Single*/ hkConfigData_GetCooldownToUseFist1(float/*System.Single*/ multiplier)
{
	if (Globals::BasicsBools["Faster-Hit"])
		return Globals::setHitSpeed;
	return reinterpret_cast<float(*)(float/*System.Single*/ multiplier)>(oConfigData_GetCooldownToUseFist1)(multiplier);
}
void* oConfigData_GetBlockJumpHeight4;
float/*System.Single*/ hkConfigData_GetBlockJumpHeight4(int/*World.BlockType*/ blockType, int/*FPSSetting*/ fpsSetting, int/*GravityMode*/ gravityMode, bool/*System.Boolean*/ isJumpFromSwimming)
{
	blockType = 1;
	return reinterpret_cast<float(*)(int/*World.BlockType*/ blockType, int/*FPSSetting*/ fpsSetting, int/*GravityMode*/ gravityMode, bool/*System.Boolean*/ isJumpFromSwimming)>(oConfigData_GetBlockJumpHeight4)(blockType, fpsSetting, gravityMode, isJumpFromSwimming);
}
void* oTMP_Text_set_text1;



const siv::PerlinNoise perlin(78548487834);
void/*System.Void*/ hkTMP_Text_set_text1(Il2CppObject* pThis, Il2CppString*/*System.String*/ value)
{
	if (Globals::playerNameTMP && pThis == Globals::playerNameTMP && Globals::MiscBools["Change Player Visual Name"].value)
	{
		static float elTime = 0.f;
		std::string n = Globals::playerNameToChangeTo;
		Vector3 color = { 1.0f, 0.0f, 0.0f };
		std::string r = "";
		elTime += Globals::deltaTime;

		float v = 0;
		if (audioTest && pMeter)
		{
			float epsilon = 1E-07;
			pMeter->GetPeakValue(&v);
			{
				for (int i = 0; i < n.length(); i++)
				{
					//color.x = 0.f;// 0.5 + 0.5 * cos(elTime + ((float)i / (n.length() / Globals::tcolScale1)) + 0);
					//
					//color.y = 0.5 + 0.5 * cos(elTime + ((float)i / (n.length() / (Globals::tcolScale1 * v))) + 2 * (v * 20));
					//color.z = 0.5 + 0.5 * cos(elTime + ((float)i / (n.length() / (Globals::tcolScale1 * v))) + 4 * (v * 20));


					//color.x = 0.5 + 0.5 * cos(v * i);
					//color.y = 0.5 + 0.5 * sin(v * i);
					//color.z = 0.5 + 0.5 * cos(v * i);

					color.y = 0.5 + 0.5 * cos(elTime + ((float)i / (n.length() / (Globals::tcolScale1))) + 2);
					color.z = 0.5 + 0.5 * cos(elTime + ((float)i / (n.length() / (Globals::tcolScale1))) + 4);

					int ccol = ImGui::GetColorU32(ImVec4{ color.z, color.y, v * 4.5f, 1.0f });
					((char*)&ccol)[3] = 0; 


					r += string_printf("<color=#%06x>%c</color>", ccol, n[i]);
				}
			}
		}
		else if (IsHeartless)
		{
			const char* Heartless = "Heartless Demon";
			for (int i = 0; i < 16; i++)
			{
				float x = elTime + ((float)i / (n.length() / Globals::tcolScale1));
				color.x = 0.5 + 0.5 * cos(elTime + ((float)i / (n.length() / Globals::tcolScale1)) + 0);

				color.y = 0.f;
				color.z = 0.f;

				int ccol = ImGui::GetColorU32(ImVec4{ color.z, color.y, color.x, 1.0f });
				((char*)&ccol)[3] = 0;


				r += string_printf("<color=#%06x>%c</color>", ccol, Heartless[i]);
			}
		}
		else if (HasAHeart)
		{
			const char* HasAHeart = "Demon that has a Heart";
			for (int i = 0; i < 23; i++)
			{
				float x = elTime + ((float)i / (n.length() / Globals::tcolScale1));
				color.x = 0.f;//0.5 + 0.5 * cos(elTime + ((float)i / (n.length() / (Globals::tcolScale1))) + 4);
				color.y = 0.5 + 0.5 * (sin((5 * x + 4) / 5) + sin((3.14159263 * x + 2) / 5));
				color.z = 0.5 + 0.5 * (sin((5 * x + 2) / 5) + sin((3.14159263 * x + 4) / 5));// 0.5 + 0.5 * cos(elTime + ((float)i / (n.length() / Globals::tcolScale1)) + 0);

				int ccol = ImGui::GetColorU32(ImVec4{ color.z, color.y, color.x, 1.0f });
				((char*)&ccol)[3] = 0;


				r += string_printf("<color=#%06x>%c</color>", ccol, HasAHeart[i]);
			}
		}
		else
		{
			for (int i = 0; i < n.length(); i++)
			{
				color.x = 0.f;// 0.5 + 0.5 * cos(elTime + ((float)i / (n.length() / Globals::tcolScale1)) + 0);

				color.y = 0.5 + 0.5 * cos(elTime + ((float)i / (n.length() / (Globals::tcolScale1))) + 2);
				color.z = 0.5 + 0.5 * cos(elTime + ((float)i / (n.length() / (Globals::tcolScale1))) + 4);

				int ccol = ImGui::GetColorU32(ImVec4{ color.z, color.y, color.x, 1.0f });
				((char*)&ccol)[3] = 0;


				r += string_printf("<color=#%06x>%c</color>", ccol, n[i]);
			}
		}
		if (Globals::lockWorld)
		{
			Player* localPlayer = (Player*)Il2Cpp::Helpers::ObjectFromFieldPath((Il2CppClass*)Globals::Classes["Assembly-CSharp.ControllerHelper"], { "worldController", "player" });
			if (cppstr(localPlayer->myPlayerData->playerId) == cppstr(Globals::lockWorld->playerWhoOwnsLockId))
				r = "<sprite=\"FlagAtlas\" name=\"rown\">" + r;
			Il2CppList<Il2CppString*>* playersWhoHaveAccessToLock = Globals::lockWorld->playersWhoHaveAccessToLock;
			Il2CppList<Il2CppString*>* playersWhoHaveMinorAccessToLock = Globals::lockWorld->playersWhoHaveMinorAccessToLock;
			for (int i = 0; i < playersWhoHaveAccessToLock->size; i++)
			{
				std::string id = cppstr(playersWhoHaveAccessToLock->arry->vector[i]).substr(0, 8);
				if (id == cppstr(localPlayer->myPlayerData->playerId))
				{
					r = "<sprite=\"FlagAtlas\" name=\"rmaj\">" + r;
					break;
				}
			}

			for (int i = 0; i < playersWhoHaveMinorAccessToLock->size; i++)
			{
				std::string id = cppstr(playersWhoHaveMinorAccessToLock->arry->vector[i]).substr(0, 8);
				if (id == cppstr(localPlayer->myPlayerData->playerId))
				{
					r = "<sprite=\"FlagAtlas\" name=\"rmin\">" + r;
					break;
				}
			}
		}

		

		value = istr(r.c_str());
		//Console.AddLog(cppstr(value));
	}
	return reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppString */*System.String*/ value)>(oTMP_Text_set_text1)(pThis, value);
}
void* oNetworkClient_HandleMenuWorldLoadInfo1;
void/*System.Void*/ hkNetworkClient_HandleMenuWorldLoadInfo1(Il2CppObject* pThis, Il2CppObject*/*Kernys.Bson.BSONObject*/ currentMessage)
{
	FieldInfo* field = &currentMessage->Il2CppClass.klass->fields[0];
	Il2CppDictionaryT<Il2CppString*, BSONValue*>* l = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(currentMessage, void*, field->offset);
	if (isGettingWorldInfo)
	{
		isGettingWorldInfo = false;
		if (Globals::IsInWorld)
		{
			ArkAngelChatHandler::Chat_printf("Player Count in %s: %i", "00ff00", Globals::chatUI, cppstr(l->GetValue(istr("WN"))->_string).c_str(), l->GetValue(istr("Ct"))->int32);
		}
		return;
	}

	//Console.AddLog(bson_format(l));
	return reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppObject */*Kernys.Bson.BSONObject*/ currentMessage)>(oNetworkClient_HandleMenuWorldLoadInfo1)(pThis, currentMessage);
}
void* oNetworkClient_HandleAuctionHouseGetOrderItemListing1;
void/*System.Void*/ hkNetworkClient_HandleAuctionHouseGetOrderItemListing1(Il2CppObject* pThis, Il2CppObject*/*Kernys.Bson.BSONObject*/ currentMessage)
{
	FieldInfo* field = &currentMessage->Il2CppClass.klass->fields[0];
	Il2CppDictionaryT<Il2CppString*, BSONValue*>* l = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(currentMessage, void*, field->offset);
	Console.AddLog(bson_format(l));
	return reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppObject */*Kernys.Bson.BSONObject*/ currentMessage)>(oNetworkClient_HandleAuctionHouseGetOrderItemListing1)(pThis, currentMessage);
}
void* oNetworkClient_HandleAuctionHouseOrderPlaced1;
void/*System.Void*/ hkNetworkClient_HandleAuctionHouseOrderPlaced1(Il2CppObject* pThis, Il2CppObject*/*Kernys.Bson.BSONObject*/ currentMessage)
{
	FieldInfo* field = &currentMessage->Il2CppClass.klass->fields[0];
	Il2CppDictionaryT<Il2CppString*, BSONValue*>* l = (Il2CppDictionaryT<Il2CppString*, BSONValue*>*)il2cpp_object_get_field_value_by_offset(currentMessage, void*, field->offset);
	Console.AddLog(bson_format(l));
	return reinterpret_cast<void(*)(Il2CppObject * pThis, Il2CppObject */*Kernys.Bson.BSONObject*/ currentMessage)>(oNetworkClient_HandleAuctionHouseOrderPlaced1)(pThis, currentMessage);
}

void* oOutgoingMessages_SendHitOtherPlayerMessage3;
void/*System.Void*/ hkOutgoingMessages_SendHitOtherPlayerMessage3(Vector2i/*BasicTypes.Vector2i*/ hitPosition, Il2CppString*/*System.String*/ targetPlayerId, int/*System.Int32*/ randomHitTextIndex)
{
	if (Globals::MiscBools["Longer-Hit"].value)
	{
		Vector2i playerMapPoint = ConvertWorldPointToMapPoint(Globals::playerInfo.position);
		if (playerMapPoint.x < hitPosition.x)
			hitPosition.x -= Globals::playerInfo.range;
		else
			hitPosition.x += Globals::playerInfo.range;

		if (playerMapPoint.y < hitPosition.y)
			hitPosition.y -= Globals::playerInfo.range;
		else
			hitPosition.y += Globals::playerInfo.range;
	}
	return reinterpret_cast<void(*)(Vector2i/*BasicTypes.Vector2i*/ mapPoint, Il2CppString */*System.String*/ targetPlayerId, int/*System.Int32*/ randomHitTextIndex)>(oOutgoingMessages_SendHitOtherPlayerMessage3)(hitPosition, targetPlayerId, randomHitTextIndex);
}
void* oOutgoingMessages_SendHitAIEnemyMessage3;
void/*System.Void*/ hkOutgoingMessages_SendHitAIEnemyMessage3(Vector2i/*BasicTypes.Vector2i*/ hitPosition, int/*System.Int32*/ aiID, int/*System.Int32*/ randomHitTextIndex)
{
	if (Globals::MiscBools["Longer-Hit"].value)
	{
		Vector2i playerMapPoint = ConvertWorldPointToMapPoint(Globals::playerInfo.position);
		if (playerMapPoint.x < hitPosition.x)
			hitPosition.x -= Globals::playerInfo.range;
		else
			hitPosition.x += Globals::playerInfo.range;

		if (playerMapPoint.y < hitPosition.y)
			hitPosition.y -= Globals::playerInfo.range;
		else
			hitPosition.y += Globals::playerInfo.range;
	}
	return reinterpret_cast<void(*)(Vector2i/*BasicTypes.Vector2i*/ mapPoint, int/*System.Int32*/ aiID, int/*System.Int32*/ randomHitTextIndex)>(oOutgoingMessages_SendHitAIEnemyMessage3)(hitPosition, aiID, randomHitTextIndex);
}
void* oRootUI_SetWorldLighting0;
void/*System.Void*/ hkRootUI_SetWorldLighting0(Il2CppObject* pThis)
{
	if (Globals::BasicsBools["Anti-Dark"])
		return;
	Console.AddLog("World Lighting Set");
	return reinterpret_cast<void(*)(Il2CppObject * pThis)>(oRootUI_SetWorldLighting0)(pThis);
}
void* oOutgoingMessages_SendWorldItemUpdateMessage3;
void/*System.Void*/ hkOutgoingMessages_SendWorldItemUpdateMessage3(Vector2i/*BasicTypes.Vector2i*/ mapPoint, WorldItemBase*/*WorldItemBase*/ wib, unsigned char/*PlayerTool*/ pt)
{
	const static auto TextManager_GetBlockTypeName1 = reinterpret_cast<Il2CppString * (*)(int/*World.BlockType*/ bt)>(Globals::Methods["System.String Assembly-CSharp.TextManager.GetBlockTypeName(World.BlockType,)"]->methodPointer);

	//Console.printf("x: %i, y: %i\nbt: %s\ntool: %i", mapPoint.x, mapPoint.y, cppstr(TextManager_GetBlockTypeName1(wib->blockType)).c_str(), pt);
	return reinterpret_cast<void(*)(Vector2i/*BasicTypes.Vector2i*/ mapPoint, WorldItemBase */*WorldItemBase*/ wib, unsigned char/*PlayerTool*/ pt)>(oOutgoingMessages_SendWorldItemUpdateMessage3)(mapPoint, wib, pt);
}
void SetupIl2CppHooks()
{
#ifndef AAPUBLICMODE
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendWorldItemUpdateMessage(BasicTypes.Vector2i,WorldItemBase,PlayerTool,)"], hkOutgoingMessages_SendWorldItemUpdateMessage3, oOutgoingMessages_SendWorldItemUpdateMessage3);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.RootUI.SetWorldLighting()"], hkRootUI_SetWorldLighting0, oRootUI_SetWorldLighting0);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendHitAIEnemyMessage(BasicTypes.Vector2i,System.Int32,System.Int32,)"], hkOutgoingMessages_SendHitAIEnemyMessage3, oOutgoingMessages_SendHitAIEnemyMessage3);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendHitOtherPlayerMessage(BasicTypes.Vector2i,System.String,System.Int32,)"], hkOutgoingMessages_SendHitOtherPlayerMessage3, oOutgoingMessages_SendHitOtherPlayerMessage3);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.NetworkClient.HandleAuctionHouseOrderPlaced(Kernys.Bson.BSONObject,)"], hkNetworkClient_HandleAuctionHouseOrderPlaced1, oNetworkClient_HandleAuctionHouseOrderPlaced1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.NetworkClient.HandleAuctionHouseGetItemListing(Kernys.Bson.BSONObject,)"], hkNetworkClient_HandleAuctionHouseGetOrderItemListing1, oNetworkClient_HandleAuctionHouseGetOrderItemListing1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.NetworkClient.HandleMenuWorldLoadInfo(Kernys.Bson.BSONObject,)"], hkNetworkClient_HandleMenuWorldLoadInfo1, oNetworkClient_HandleMenuWorldLoadInfo1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendPlayerPosition(Kernys.Bson.BSONObject,)"], hkSendPlayerPosition1, oSendPlayerPosition1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendPlayerPosition()"], hkSendPlayerPosition0, oSendPlayerPosition0);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.Player.DeathByColliderInCollider(BasicTypes.Vector2i,)"], hkDeathByColliderInCollider1, oDeathByColliderInCollider1);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.Player.IsPlayerInMapPoint(BasicTypes.Vector2i,)"], hkIsPlayerInMapPoint1, oIsPlayerInMapPoint1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.Player.CheckPortals()"], hkCheckPortals0, oCheckPortals0);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.Player.HitPlayerFromAIEnemy(AIBase,AIDamageModelType,)"], hkHitPlayerFromAIEnemy2_0, oHitPlayerFromAIEnemy2_0);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.Player.HitPlayerFromAIEnemy(System.Int32,AIEnemyType,)"], hkHitPlayerFromAIEnemy2_1, oHitPlayerFromAIEnemy2_1);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.Player.HitPlayerFromBlock(System.Int32,World.BlockType,BasicTypes.Vector2i,)"], hkHitPlayerFromBlock3_0, oHitPlayerFromBlock3_0);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.Player.HitPlayerFromBlock(World.BlockType,BasicTypes.Vector2i,System.Boolean,)"], hkHitPlayerFromBlock3_1, oHitPlayerFromBlock3_1);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.ConfigData.CanPlaceSeedTopOf(World.BlockType,)"], hkCanPlaceSeedTopOf1, oCanPlaceSeedTopOf1);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.ConfigData.IsBlockSwimming(World.BlockType,)"], hkIsBlockSwimming1, oIsBlockSwimming1);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.ConfigData.IsBlockHot(World.BlockType,)"], hkIsBlockHot1, oIsBlockHot1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.NetworkClient.Update()"], hkUpdate0_networkClient, oUpdate0_networkClient);
	il2cpp_hook(Globals::Methods["System.String Assembly-CSharp.ProfanityFilter.Censor(System.String,)"], hkCensor1_profanityFiler, oCensor1_profanityFiler);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.ProfanityFilter.Validate(System.String,)"], hkValidate1_profanityFiler, oValidate1_profanityFiler);
	il2cpp_hook(Globals::Methods["NameValidity Assembly-CSharp.WorldNameChecker.Validate(System.String,)"], hkValidate1_worldNameChecker, oValidate1_worldNameChecker);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.TrapProjectile.OnTriggerEnter2D(UnityEngine.Collider2D,)"], hkOnTriggerEnter2D1_trapProjectile, oOnTriggerEnter2D1__trapProjectile);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.World.IsMapPointNearEnough(BasicTypes.Vector2i,BasicTypes.Vector2i,System.Int32,)"], hkIsMapPointNearEnough3, oIsMapPointNearEnough3);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.Player.TakeHitFromOtherPlayer(System.String,System.Boolean,System.Boolean,World.BlockType,System.Int32,System.Single,)"], hkTakeHitFromOtherPlayer6, oTakeHitFromOtherPlayer6);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.FishingGaugeMinigameUI.Update()"], hkUpdate0_FishingGaugeMinigameUI, oUpdate0_FishingGaugeMinigameUI);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.FogOfWar.LateUpdate()"], hkLateUpdate0_FogOfWar, oLateUpdate0_FogOfWar);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.WorldLighting.Update()"], hkUpdate0_WorldLighting, oUpdate0_WorldLighting);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.ChatUI.Submit(System.String,)"], hkSubmit1, oSubmit1);
	il2cpp_hook(Globals::Methods["System.Void Unity.TextMeshPro.TMP_InputField.Insert(System.Char,)"], hInputField_Insert, oInsert);
	il2cpp_hook(Globals::Methods["System.Void Unity.TextMeshPro.TMP_Text.set_text"], hkTMP_Text_set_text1, oTMP_Text_set_text1);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.ConfigData.IsBlockTradeable(World.BlockType,)"], hkIsBlockTradeable1, oIsBlockTradeable1);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.ConfigData.IsBlockUntradeable(World.BlockType,)"], hkIsBlockUntradeable1, oIsBlockUntradeable1);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.World.AreMapPointsValidForFishing(BasicTypes.Vector2i,System.Int32,System.Int32,)"], hkAreMapPointsValidForFishing3, oAreMapPointsValidForFishing3);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.KukouriCamera.UpdateCameraPosition()"], hkKukouriCamera_UpdateCameraPosition0, oKukouriCamera_UpdateCameraPosition0);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.KukouriCamera.ForceUpdatePosition(System.Boolean,)"], hkKukouriCamera_ForceUpdatePosition1, oKukouriCamera_ForceUpdatePosition1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.NetworkClient.HandleMessages(Kernys.Bson.BSONObject,)"], hkNetworkClient_HandleMessages1, oNetworkClient_HandleMessages1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.AddOneMessageToList(Kernys.Bson.BSONObject,)"], hkOutgoingMessages_AddOneMessageToList1, oOutgoingMessages_AddOneMessageToList1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.WorldController.DoBlockBackgroundHitAction(System.Single,System.Boolean,BasicTypes.Vector2i,World.BlockType,PlayerData,System.String,System.Boolean,System.Boolean,)"], hkWorldController_DoBlockBackgroundHitAction8, oDoBlockBackgroundHitAction8);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.NetworkClient.HandlePlayerDataMessage(Kernys.Bson.BSONObject,)"], hkNetworkClient_HandlePlayerDataMessage1, oNetworkClient_HandlePlayerDataMessage1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.NetworkClient.HandlePlayerNameUpdate(Kernys.Bson.BSONObject,)"], hkNetworkClient_HandlePlayerNameUpdate1, oHandlePlayerNameUpdate1);
	il2cpp_hook(Globals::Methods["System.Collections.Generic.List<BasicTypes.Vector2i> Assembly-CSharp.World.GetNewLockMapPoints(World.BlockType,BasicTypes.Vector2i,System.Boolean,)"], hkWorld_GetNewLockMapPoints3, oGetNewLockMapPoints3);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.WorldController.DoBlockHitAction(System.Single,System.Boolean,BasicTypes.Vector2i,World.BlockType,PlayerData,System.String,System.Boolean,System.Boolean,System.Boolean,)"], hkWorldController_DoBlockHitAction9, oDoBlockHitAction9);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.WorldController.DoBlockWaterHitAction(System.Single,System.Boolean,BasicTypes.Vector2i,World.BlockType,PlayerData,System.String,System.Boolean,System.Boolean,)"], hkWorldController_DoBlockWaterHitAction8, oDoBlockWaterHitAction8);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.WorldController.DoBlockBackgroundHitAction(System.Single,System.Boolean,BasicTypes.Vector2i,World.BlockType,PlayerData,System.String,System.Boolean,System.Boolean,)"], hkWorldController_DoBlockBackgroundHitAction8, oDoBlockBackgroundHitAction8);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.BaseMenuUI.Update()"], hkBaseMenuUI_Update0, oBaseMenuUI_Update0);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.FishingGaugeMinigameUI.SetupMinigame(World.BlockType,World.BlockType,)"], hkFishingGaugeMinigameUI_SetupMinigame2, oFishingGaugeMinigameUI_SetupMinigame2);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendCollectCollectableMessage(System.Int32,)"], hkOutgoingMessages_SendCollectCollectableMessage1, oOutgoingMessages_SendCollectCollectableMessage1);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.ConfigData.ShouldHitBlockWhenBattleIsOn(World.BlockType,)"], hkConfigData_ShouldHitBlockWhenBattleIsOn1, oConfigData_ShouldHitBlockWhenBattleIsOn1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.AsynchronousClient.SendCallback(System.IAsyncResult,)"], hkAsynchronousClient_SendCallback1, oAsynchronousClient_SendCallback1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.ChatReport(System.String,System.String,System.String,System.String,System.String,System.String,)"], hkOutgoingMessages_ChatReport6, oOutgoingMessages_ChatReport6);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.SceneLoader.GoFromWorldToWorld(System.String,System.String,)"], hkSceneLoader_GoFromWorldToWorld2, oSceneLoader_GoFromWorldToWorld2);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.SceneLoader.GoFromMainMenuToWorld(System.String,System.String,)"], hkSceneLoader_GoFromMainMenuToWorld2, oSceneLoader_GoFromMainMenuToWorld2);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.AsynchronousClient.SendMessages()"], hkAsynchronousClient_SendMessages0, oAsynchronousClient_SendMessages0);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.BuyItemPack(System.String,)"], hkOutgoingMessages_BuyItemPack1, oOutgoingMessages_BuyItemPack1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.NetworkClient.HandleAIHitByPlayerDamageMessage(Kernys.Bson.BSONObject,)"], hkNetworkClient_HandleAIHitByPlayerDamageMessage1, oNetworkClient_HandleAIHitByPlayerDamageMessage1);
	il2cpp_hook(Globals::Methods["System.Byte[] Assembly-CSharp.OutgoingMessages.TurnMessagesToBytesAndConsumeThem()"], hkOutgoingMessages_TurnMessagesToBytesAndConsumeThem0, oOutgoingMessages_TurnMessagesToBytesAndConsumeThem0);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.Player.HeadedCheckHelper(System.Boolean&,)"], hkPlayer_HeadedCheckHelper1, oPlayer_HeadedCheckHelper1);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.Player.RightedCheckHelper(System.Boolean&,)"], hkPlayer_RightedCheckHelper1, oPlayer_RightedCheckHelper1);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.Player.LeftedCheckHelper(System.Boolean&,)"], hkPlayer_LeftedCheckHelper1, oPlayer_LeftedCheckHelper1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.Player.CheckInvertedControls()"], hkPlayer_CheckInvertedControls0, oPlayer_CheckInvertedControls0);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.Player.CheckCheckPoints()"], hkPlayer_CheckCheckPoints0, oPlayer_CheckCheckPoints0);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.Player.CheckStartAndFinish()"], hkPlayer_CheckStartAndFinish0, oPlayer_CheckStartAndFinish0);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.Player.CheckPoisoned()"], hkPlayer_CheckPoisoned0, oPlayer_CheckPoisoned0);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.Player.CheckPressurePad()"], hkPlayer_CheckPressurePad0, oPlayer_CheckPressurePad0);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.Player.CheckProximitySensor()"], hkPlayer_CheckProximitySensor0, oPlayer_CheckProximitySensor0);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.Player.SetWorldLighting(World.LightingType,System.Single,UnityEngine.Color,)"], hkPlayer_SetWorldLighting3, oPlayer_SetWorldLighting3);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.Player.ShouldBelowBlockDoBounce()"], hkPlayer_ShouldBelowBlockDoBounce0, oPlayer_ShouldBelowBlockDoBounce0);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.Player.HitPlayerFromPlayerDyingExplosion(System.Int32,BasicTypes.Vector2i,UnityEngine.Vector3,System.String,)"], hkPlayer_HitPlayerFromPlayerDyingExplosion4, oPlayer_HitPlayerFromPlayerDyingExplosion4);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.Player.CheckCheckPoints()"], hkPlayer_CheckCheckPoints0, oPlayer_CheckCheckPoints0);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.Player.CausePoisoned(System.Single,)"], hkPlayer_CausePoisoned1, oPlayer_CausePoisoned1);
	il2cpp_hook(Globals::Methods["System.Void Assembly-CSharp.Player.ActivateForcedDirectionBounce(World.BlockType,System.Single,System.Single,System.Single,)"], hkPlayer_ActivateForcedDirectionBounce4, oPlayer_ActivateForcedDirectionBounce4);
	il2cpp_hook(Globals::Methods["System.Single Assembly-CSharp.ConfigData.GetBlockRunSpeed(World.BlockType,)"], hkConfigData_GetBlockRunSpeed1, oConfigData_GetBlockRunSpeed1);
	il2cpp_hook(Globals::Methods["System.Boolean Assembly-CSharp.ConfigData.IsBlockRecallingAllowed(World.BlockType,World,PlayerData,System.Int32,System.Int32,)"], hkConfigData_IsBlockRecallingAllowed5, oConfigData_IsBlockRecallingAllowed5);
	il2cpp_hook(Globals::Methods["System.Single Assembly-CSharp.ConfigData.GetCooldownToUseFist(System.Single,)"], hkConfigData_GetCooldownToUseFist1, oConfigData_GetCooldownToUseFist1);
	il2cpp_hook(Globals::Methods["System.Single Assembly-CSharp.ConfigData.GetBlockJumpHeight(World.BlockType,FPSSetting,GravityMode,System.Boolean,)"], hkConfigData_GetBlockJumpHeight4, oConfigData_GetBlockJumpHeight4);

	rethook(Globals::Methods["System.Void Assembly-CSharp.OutgoingMessages.SendListOfUsedPlayerNames(System.String,)"]);
	const Il2CppClass* DevtodevAnalytics = Globals::Classes["Assembly-CSharp.DevtodevAnalytics"];
	for (int i = 0; i < DevtodevAnalytics->method_count; i++)
	{
		const MethodInfo* m = DevtodevAnalytics->methods[i];
		//if (std::string(m->name).find("Track") != -1)
		//{
			rethook(m);
		//}
	}
#endif
	MH_EnableHook(MH_ALL_HOOKS);
}