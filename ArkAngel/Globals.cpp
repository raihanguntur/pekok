#include "Globals.h"
namespace Globals
{
	std::unordered_map<std::string, const Il2CppAssembly*> Assemblies = {};
	std::unordered_map<std::string, const MethodInfo*> Methods = {};
	std::unordered_map<std::string, const Il2CppClass*> Classes = {};
	std::queue<FUNC> il2cppFunctionQueue = {};
	std::queue<DATAFUNC> il2cppDataFunctionQueue = {};
	std::vector<TickFunc> il2cppCoroutines = {};
	double deltaTime = 0.016666;
	Present oPresent;
	WNDPROC oWndProc;
	ID3D11Device* pDevice = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
	ID3D11RenderTargetView* mainRenderTargetView = nullptr;
	ImGuiContext* Context;
	bool ShowMenu = true;
	HWND hWnd;
	bool Ejecting = false;
	bool DirectXHookHasLocked = false;
	bool ShowConsole = true;
	bool IsInWorld = false;
	bool Il2CppInited = false;
	Vector2i MousePos = { 0, 0 };
	std::map<std::string, bool> BasicsBools =
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
	std::map<std::string, bool> FishingBools =
	{
		{"Arrow Always on Fish", true},
		{"No Fish Runs", true},
		{"Semi-Auto + Bypass Fishing Anti-Cheat", true},
		{"Fish anywhere", false},
	};
	std::map<std::string, MiscBoolFuncPair> MiscBools =
	{
		{"Change Textbox Max Length", MiscBoolFuncPair(true, []() { ImGui::SliderInt("Textbox Length to Change to", &Globals::textboxLenToChangeTo, 1, 2048); })},
		{"Play Annoying Audio", MiscBoolFuncPair(false, []() { ImGui::SliderInt("Audio Type To Play", &Globals::audioTypeToPlay, 1, 20); ImGui::SliderInt("Audio Block Type To Play", &Globals::audioBlockTypeToPlay, 1, 4000); })},
		{"Bypass Untradeables", MiscBoolFuncPair(false)},
		{"Trade All Spam", MiscBoolFuncPair(false, []() { ImGui::SliderFloat("Trade All Timeout", &Globals::tradeAlltimeout, 0, 1); })},
		{"Change Player Visual Name", MiscBoolFuncPair(true, []() { ImGui::InputText("Player Name", &playerNameToChangeTo); ImGui::DragFloat("Col Scale", &Globals::tcolScale1, 0.1); })},
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
		{"Longer-Hit", MiscBoolFuncPair(true)},
		{"Always TP Movement", MiscBoolFuncPair(false)},
		{"Anti-Kick", MiscBoolFuncPair(false)},
		{"Bomb Effect on others", MiscBoolFuncPair(false)},
		{"Trapbot", MiscBoolFuncPair(false)},
	};
	std::map<std::string, MiscBoolFuncPair> EspBools =
	{
		{"Collectable ESP Boxes", MiscBoolFuncPair(true)},
		{"Show Monster Heath", MiscBoolFuncPair(true)},
		{"Collectable Tracers", MiscBoolFuncPair(false)},
		{"Monster Tracers", MiscBoolFuncPair(true)},
		{"Monster ESP Boxes", MiscBoolFuncPair(true)},
		{"Local Player ESP Boxes", MiscBoolFuncPair(true)},
		{"ESP Tracers", MiscBoolFuncPair(true)},
		{"ESP Names", MiscBoolFuncPair(false)},
		{"Player Trail", MiscBoolFuncPair(false)},
		{"Other Player ESP Boxes", MiscBoolFuncPair(true,
		[]() {
				ImGui::SliderFloat("Local Player ESP Thickness", &Globals::SelfBoxThickness, 0.1f, 5.0f);
				ImGui::SliderFloat("Other Player ESP Thickness", &Globals::OtherPlayerBoxThickness, 0.1f, 5.0f);
				ImGui::SliderFloat("Tracer Thickness", &Globals::playerTracerThickness, 0.1f, 5.0f);

				ImGui::ColorEdit4("Local Player ESP Color", &localPlayerESPColor.x);
				ImGui::ColorEdit4("Other Player ESP Color", &otherPlayerESPColor.x);
				ImGui::ColorEdit4("Tracer Color", &playerTracerColor.x);

				ImGui::SliderFloat("Collectable ESP Thickness", &Globals::collectableEspThickness, 0.1f, 5.0f);
				ImGui::SliderFloat("Collectable Tracer Thickness", &Globals::collectableTracerThickness, 0.1f, 5.0f);
				ImGui::ColorEdit4("Collectable ESP Color", &collectableBoxColor.x);
				ImGui::ColorEdit4("Collectable Tracer Color", &collectableTracerColor.x);

				ImGui::SliderFloat("Monster ESP Thickness", &Globals::monsterEspThickness, 0.1f, 5.0f);
				ImGui::SliderFloat("Monster Tracer Thickness", &Globals::monsterTracerThickness, 0.1f, 5.0f);
				ImGui::ColorEdit4("Monster ESP Color", &monsterBoxColor.x);
				ImGui::ColorEdit4("Monster Tracer Color", &monsterTracerColor.x);
			})},
	};
	std::map<std::string, MiscBoolFuncPair> MiningBools =
	{
		{"Auto-Mine", MiscBoolFuncPair(false,
		[]() {
			for (int i = 0; i < miningOrder.size(); i++)
			{
				ImGui::PushStyleVar(ImGuiStyleVar_::ImGuiStyleVar_ItemSpacing, ImVec2{0, 1});
				ImGui::PushID(i + 50);
				if (ImGui::Button("^", ImVec2(20, 0)))
				{
					if (i > 0)
					{
						int temp = miningOrder[i - 1];
						miningOrder[i - 1] = miningOrder[i];
						miningOrder[i] = temp;
					}
				}
				ImGui::SameLine();
				if (ImGui::Button("v", ImVec2(20, 0)))
				{
					if (i + 1 < miningOrder.size())
					{
						int temp = miningOrder[i + 1];
						miningOrder[i + 1] = miningOrder[i];
						miningOrder[i] = temp;
					}
				}
				ImGui::SameLine();
				ImGui::PopID();
				ImGui::PopStyleVar();

				if (miningOrder[i] == 0)
				{
					ImGui::Button("Collect Collectables");
				}
				if (miningOrder[i] == 1)
				{
					ImGui::Button("Break All Gem Blocks");
				}
				if (miningOrder[i] == 2)
				{
					ImGui::Button("Kill Monsters");
				}
			}
			})},
	};
	std::vector<int> miningOrder = { 0, 1, 2 };
	std::map<std::string, MiscBoolFuncPair> MapPointExploitBools =
	{
		{"Teleport to Map Point", {true}},
		{"Teleport Visualizer", {true}},
		{"Anti-Kick flight", {false, []() { ImGui::SliderFloat("Anti-Kick Timeout", &Globals::antiKickTimeout, 0.1f, 1.5f); }}},
		{"Send position packet", {true}},
		{"Infinite Range", {false}}
	};
	std::map<std::string, MiscBoolFuncPair> ToggleBools =
	{
		{"Freecam", MiscBoolFuncPair(false)},
		{"Item Data Tooltip", MiscBoolFuncPair(true)},
		{"Keys to Fly", MiscBoolFuncPair(false)},
		{"Lag Ghost", MiscBoolFuncPair(false)},
	};
	std::vector<void*> GlobalDataBuffer = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
	Vector2 tileSize = {};
	int audioTypeToPlay = 14;
	int audioBlockTypeToPlay = 959;
	int textboxLenToChangeTo = 640;
	float playerTracerThickness = .1f;
	float SelfBoxThickness = .1f;
	float OtherPlayerBoxThickness = .1f;
	ImVec4 localPlayerESPColor = { 0, 1.f, 0, 1.f };
	ImVec4 otherPlayerESPColor = { 1.f, 0, 0, 1.f };
	ImVec4 playerTracerColor = { 0, 0, 1.f, 1.f };
	ImVec4 collectableTracerColor = { 0, 0, 1.f, 1.f };
	ImVec4 collectableBoxColor = { 0, 0, 1.f, 1.f };
	float collectableEspThickness = .1f;
	float collectableTracerThickness = .1f;
	float DashTolerency = 0.2f;
	float StatusIconTimeout = 0.2f;
	bool testState = false;
	float antiKickTimeout = 0.7f;
	bool playerPlayStaticAnim = false;
	int playerPlayStaticAnimV = 0;
	bool ShowPlayerMenu = false;
	float tradeAlltimeout = 0.f;

	std::map<std::string, std::string> AdminUsernameIdPairs =
	{
		{"DY4LVBNE", "BlackWight"},
		{"1BYM5371", "Rabia"},
		{"VSL1HVDO", "Citrina"},
		{"LKB469T7", "Starfire1178"},
		{"95F6JEWA", "ionas"},
		{"I501W0UX", "xSHANEx"},
		{"60FPOJ55", "Invalid"},
		{"VZ7RALO", "ColdUnwanted"},
		{"LNBJ9SK", "Quqqo"},
		{"IRIME6M", "Lupuss"},
		{"SAZUT30", "Freak"},
		{"OMD5ECO", "Hinter"},
		{"2SYJQ2R", "SEAF"},
		{"5V6MYXQ3", "NicoKapell"},
		{"G2D8FGE", "MrGrandman"},
		// admins
		{"34N8P51", "Jake"},
		{"HN55GSS", "EndlesS"},
		{"74RL1AE", "MidnightWalker"},
		{"8HN45WF", "Dev"},
		{"F2RQK1W", "Commander_K"},
	};
	std::vector<std::string> worldHistory = {};
	std::vector<std::string> chatHistory = {};
	int aimbotHitChance = 50;
	bool ctrlForActive = true;
	bool aimbot = false;
	bool aiAimbot = false;
	std::vector<Vector2> playerTrail = {};
	std::vector<std::vector<Vector2>> otherPlayerTrails = {};
	ImVec4 monsterTracerColor = ImVec4{ 1,0,1,1 };
	ImVec4 monsterBoxColor = ImVec4{ 1,0,0,1 };
	float monsterEspThickness = 0.1f;
	float monsterTracerThickness = 0.1f;
	bool showMinimap = false;
	float minimapZoomAmount = 6.0f;
	bool autoNether = false;
	std::string playerNameToChangeTo = "Project ArkAngel";
	float setRunSpeed = 2.5f;
	float setHitSpeed = 0.15f;
	std::map<std::string, bool> DiscordRPCBools = 
	{
		{"Show Logged in Username", false},
		{"Show Current World", true},
		{"Show Current Player Count In World", true},
		{"Show Amount of Time Playing", true},
		{"Use Rich Presence", true},
	};
	StatusIconType playerStatus = StatusIconType::None;
	Il2CppObject* playerNameTMP = nullptr;
	float tcolScale1 = 4.0f;
	LockWorldData* lockWorld = nullptr;
	Il2CppObject* chatUI = nullptr;
	std::vector<Vector2i> visualPathHelper = {};
	PlayerInfo playerInfo = {};
	std::string playeridtoswas = "";
}