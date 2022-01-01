#pragma once
#include "Framework.h"
#include <unordered_map>
#include <map>
#include "il2cpp-appdata.h"
#include <queue>
#include "imgui/imgui.h"
#include "imgui/imgui_stdlib.h"

typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef void (*FUNC)();
typedef void (*DATAFUNC)(std::vector<void*> data);
struct TickFunc
{
	float timeout;
	float elapsedTime;
	FUNC function;
	TickFunc(float timeout, FUNC function)
	{
		this->timeout = timeout;
		this->function = function;
		this->elapsedTime = 0.f;
	}
};
struct MiscBoolFuncPair
{
	bool value;
	FUNC function;
	DATAFUNC dataFunction;
	MiscBoolFuncPair()
	{
		value = false;
		function = NULL;
		dataFunction = NULL;
	}
	MiscBoolFuncPair(bool intialValue)
	{
		value = intialValue;
		function = NULL;
		dataFunction = NULL;
	}
	MiscBoolFuncPair(FUNC func)
	{
		value = false;
		function = func;
		dataFunction = NULL;
	}
	MiscBoolFuncPair(bool intialValue, FUNC func)
	{
		value = intialValue;
		function = func;
		dataFunction = NULL;
	}
	MiscBoolFuncPair(DATAFUNC func)
	{
		value = false;
		function = NULL;
		dataFunction = func;
	}
	MiscBoolFuncPair(bool initialValue, DATAFUNC func)
	{
		value = initialValue;
		function = NULL;
		dataFunction = func;
	}
};
struct PlayerInfo
{
	Vector2 position;
	Vector2i mapPoint;
	int range;
	std::string name;
	std::string id;
	std::string worldName;
	StaticPlayer_Static* staticPlayer;
	NetworkClient_Static* networkClient;
};
namespace Globals
{
	extern std::unordered_map<std::string, const Il2CppAssembly*> Assemblies;
	extern std::unordered_map<std::string, const MethodInfo*> Methods;
	extern std::unordered_map<std::string, const Il2CppClass*> Classes;
	extern std::queue<FUNC> il2cppFunctionQueue;
	extern std::queue<DATAFUNC> il2cppDataFunctionQueue;
	extern std::vector<TickFunc> il2cppCoroutines;
	extern double deltaTime;
	extern Present oPresent;
	extern WNDPROC oWndProc;
	extern ID3D11Device* pDevice;
	extern ID3D11DeviceContext* pContext;
	extern ID3D11RenderTargetView* mainRenderTargetView;
	extern ImGuiContext* Context;
	extern bool ShowMenu;
	extern HWND hWnd;
	extern bool Ejecting;
	extern bool DirectXHookHasLocked;
	extern bool ShowConsole;
	extern bool ShowPlayerMenu;
	extern bool IsInWorld;
	extern bool Il2CppInited;
	extern Vector2i MousePos;
	extern std::map<std::string, bool> BasicsBools;
	extern std::map<std::string, bool> FishingBools;
	extern std::map<std::string, MiscBoolFuncPair> MiscBools;
	extern std::map<std::string, MiscBoolFuncPair> MapPointExploitBools;
	extern std::map<std::string, MiscBoolFuncPair> ToggleBools;
	extern std::map<std::string, MiscBoolFuncPair> EspBools;
	extern std::vector<void*> GlobalDataBuffer;
	extern Vector2 tileSize;
	extern int textboxLenToChangeTo;
	extern float playerTracerThickness;
	extern float SelfBoxThickness;
	extern float OtherPlayerBoxThickness;
	extern int audioTypeToPlay;
	extern int audioBlockTypeToPlay;
	extern ImVec4 localPlayerESPColor;
	extern ImVec4 otherPlayerESPColor;
	extern ImVec4 playerTracerColor;
	extern float DashTolerency;
	extern float StatusIconTimeout;
	extern bool testState;
	extern float antiKickTimeout;
	extern bool playerPlayStaticAnim;
	extern int playerPlayStaticAnimV;
	extern float tradeAlltimeout;
	extern std::map<std::string, std::string> AdminUsernameIdPairs;
	extern std::vector<std::string> worldHistory;
	extern std::vector<std::string> chatHistory;
	extern int aimbotHitChance;
	extern bool ctrlForActive;
	extern bool aimbot;
	extern std::vector<Vector2> playerTrail;
	extern std::vector<std::vector<Vector2>> otherPlayerTrails;
	extern ImVec4 collectableTracerColor;
	extern ImVec4 collectableBoxColor;
	extern float collectableEspThickness;
	extern float collectableTracerThickness;
	extern ImVec4 monsterTracerColor;
	extern ImVec4 monsterBoxColor;
	extern float monsterEspThickness;
	extern float monsterTracerThickness;
	extern std::map<std::string, MiscBoolFuncPair> MiningBools;
	extern std::vector<int> miningOrder;
	extern bool aiAimbot;
	extern bool showMinimap;
	extern float minimapZoomAmount;
	extern bool autoNether;
	extern std::string playerNameToChangeTo;
	extern float setRunSpeed;
	extern float setHitSpeed;
	extern std::map<std::string, bool> DiscordRPCBools;
	extern StatusIconType playerStatus;
	extern Il2CppObject* playerNameTMP;
	extern float tcolScale1;
	extern LockWorldData* lockWorld;
	extern Il2CppObject* chatUI;
	extern std::vector<Vector2i> visualPathHelper;
	extern PlayerInfo playerInfo;
	extern std::string playeridtoswas;
}