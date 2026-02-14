namespace GRace {
	enum Difficulty {
		kRaceDifficulty_Easy = 0,
		kRaceDifficulty_Medium = 1,
		kRaceDifficulty_Hard = 2,
		kRaceDifficulty_NumDifficulties = 3,
	};

	enum Context {
		kRaceContext_QuickRace = 0,
		kRaceContext_TimeTrial = 1,
		kRaceContext_Online = 2,
		kRaceContext_Career = 3,
		kRaceContext_Count = 4,
	};

	enum Type {
		kEventType_None = -1,
		kEventType_P2P = 0,
		kEventType_Circuit = 1,
		kEventType_Checkpoint = 2,
		kEventType_CopsAndRobbers = 3,
		kEventType_OutRun = 4,
		kEventType_HighWayBattle = 5,
		kEventType_Challenge = 6,
		kEventType_Challenge_Bounty = 7,
		kEventType_Challenge_Cop_Takeout = 8,
		kEventType_Challenge_Escape = 9,
		kEventType_Mission = 10,
		kEventType_Shop = 11,
		kEventType_NotSupported = 12,
		kEventType_NumTypes = 13,
	};
}