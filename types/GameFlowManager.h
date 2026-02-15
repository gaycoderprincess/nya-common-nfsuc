enum GameFlowState {
	GAMEFLOW_STATE_NONE = 0,
	GAMEFLOW_STATE_LOADING_FRONTEND = 1,
	GAMEFLOW_STATE_UNLOADING_FRONTEND = 2,
	GAMEFLOW_STATE_IN_FRONTEND = 3,
	GAMEFLOW_STATE_LOADING_REGION = 4,
	GAMEFLOW_STATE_LOADING_TRACK = 5,
	GAMEFLOW_STATE_RACING = 6,
	GAMEFLOW_STATE_UNLOADING_TRACK = 7,
	GAMEFLOW_STATE_UNLOADING_REGION = 8,
	GAMEFLOW_STATE_EXIT_DEMO_DISC = 9,
};

class GameFlowManager {
public:
	void (*pLoopingFunction)();
	const char *pLoopingFunctionName;
	GameFlowState CurrentGameFlowState;

	static inline auto LoadTrack = (void(__thiscall*)(GameFlowManager*))0x69E330;
	static inline auto LoadFrontend = (void(__thiscall*)(GameFlowManager*))0x69E300;
	static inline auto UnloadFrontend = (void(__thiscall*)(GameFlowManager*))0x6AE650;
	static inline auto ReloadTrack = (void(__thiscall*)(GameFlowManager*))0x69E3A0;
};
static_assert(sizeof(GameFlowManager) == 0xC);

auto& TheGameFlowManager = *(GameFlowManager*)0xDA57B0;