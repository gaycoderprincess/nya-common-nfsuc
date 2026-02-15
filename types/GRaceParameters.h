class GRaceParameters;
class GRaceIndexData;
class GVault;
class GTrigger;
class GRaceSettings;
class GRacerInfo;
class GRuntimeInstance;
class GActivity;

namespace Game {
	enum EventRegion {
		kRegion_SunsetHills = 0,
		kRegion_PalmHarbour = 1,
		kRegion_PortCresent = 2,
		kRegion_GoldCoastMountains = 3,
	};

	enum RewardType {
		kReward_None = 0,
		kReward_Bounty = 1,
		kReward_Cash = 2,
		kReward_DriverSkills = 3,
		kReward_PinkSlips = 4,
	};
}

class GRaceIndexData {
public:
	enum {
		kFlag_InitiallyUnlockedQuickRace = 0x1,
		kFlag_InitiallyUnlockedOnline = 0x2,
		kFlag_InitiallyUnlockedChallenge = 0x4,
		kFlag_IsDDayRace = 0x10,
		kFlag_IsBossRace = 0x20,
		kFlag_IsMarkerRace = 0x40,
		kFlag_IsPursuitRace = 0x80,
		kFlag_IsLoopingRace = 0x100,
		kFlag_RankPlayersByPoints = 0x200,
		kFlag_RankPlayersByDistance = 0x400,
		kFlag_CopsEnabled = 0x800,
		kFlag_ScriptedCopsInRace = 0x1000,
		kFlag_NeverInQuickRace = 0x4000,
		kFlag_IsChallengeSeriesRace = 0x8000,
		kFlag_IsCollectorsEditionRace = 0x10000,
		kFlag_UsePresetRide = 0x200000,
		kFlag_IsTeamEvent = 0x400000,
		kFlag_IsMasterEvent = 0x800000,
		kFlag_StoryCritical = 0x1000000,
		//kFlag_ = 0x2000000,
	};

	unsigned int mKey;
	char mEventID[10];
	int16_t mChallengeGoal;
	unsigned int mChallengeType;
	unsigned int mRaceHash;
	unsigned int mFlags;
	float mLength;
	unsigned int mLocalizationTag;
	int16_t mCash;
	int16_t mCashDominate;
	uint16_t mRivalBest;
	uint8_t mNumLaps;
	char mCopDensity;
	char mRaceType;
	char mEventVariant;
	char mNumRounds;
	char mRecommendedCarTier;
	char mRegion;
	char mRewardType;
	unsigned int mPlayerCarTypeHash;
	unsigned int mRivalStringID;
	float mTrackRecord;
	float mXP;
	float mXPDominate;
	float mTrackPosX;
	float mTrackPosY;
	float mLevel;
	unsigned int mTrackLayout;
	float mWorldPosX;
	float mWorldPosY;
	float mWorldPosZ;
	unsigned int mRewardsCollection;
	float mDominationTime;
	float mTimeLimit;
};

class GRaceBin {
public:
	GVault *mChildVault;
	Attrib::Instance mGameplayRecord;
};

class IEventParameters {
public:
	typedef GRace::Type eEventType;

	virtual void _vt0();
	virtual eEventType GetEventType();
	virtual unsigned int GetCollectionKey();
	virtual const Attrib::Instance *GetGameplayObj();
	virtual GActivity *GetActivity();
	virtual GVault *GetChildVault();
	virtual GVault *GetParentVault();
	virtual const char *GetEventID();
	virtual unsigned int GetEventHash();
	virtual float GetCashValue();
	virtual float GetCashValueDominate();
	virtual float GetXP();
	virtual float GetXPDominate();
	virtual float GetLevel();
	virtual Game::EventRegion GetRegion();
	virtual bool GetIsLoaded();
	virtual void BlockUntilLoaded();
	virtual const char *GetPlayerCarType();
	virtual bool GetUsePresetRide();
	virtual const char *GetPresetRide();
	virtual bool GetTrackLocation(UMath::Vector3 *);
	virtual void GetStartPosition(UMath::Vector3 *);
	virtual void GetStartDirection(UMath::Vector3 *);
	virtual void GetStartLocationWorld(UMath::Vector3 *);
	virtual void GetWayPointLocationForMap(UMath::Vector3 *);
	virtual bool GetIsBossRace();
	virtual bool GetIsMasterEvent();
	virtual bool GetIsStoryCritical();
	virtual unsigned int GetLocalizationTag();
	virtual bool GetNeverInQuickRace();
	virtual float GetDominationTime();
	virtual unsigned int GetRivalStringID();
	virtual Game::RewardType GetRewardType();
};

class GRaceParameters : public IEventParameters {
public:
	enum ScoreUnitType {
		kScore_None = 0,
		kScore_Time = 1,
		kScore_Speed = 2,
		kScore_Points = 3,
	};

	GRaceIndexData *mIndex;
	Attrib::Instance *mRaceRecord;
	GVault *mParentVault;
	GVault *mChildVault;
	GVault *mTrackVault;

	virtual void GetCheckpointPosition(unsigned int, UMath::Vector3 *);
	virtual void GetCheckpointDirection(unsigned int, UMath::Vector3 *);

	static inline auto GetIsLoopingRace = (bool(__thiscall*)(GRaceParameters*))0x63EE10;
	static inline auto GetIsPursuitRace = (bool(__thiscall*)(GRaceParameters*))0x63EDA0;
	static inline auto GetIsBossRace = (bool(__thiscall*)(GRaceParameters*))0x63ECC0;
	static inline auto GetIsDDayRace = (bool(__thiscall*)(GRaceParameters*))0x63EC50;
	static inline auto GetNumRaceLaps = (bool(__thiscall*)(GRaceParameters*))0x5FDCD0;
	static inline auto GetNumLaps = GetNumRaceLaps;
	static inline auto GetEventID = (const char*(__thiscall*)(GRaceParameters*))0x5FD960;
};
//static_assert(sizeof(GRaceParameters) == 0x);

class GRaceCustom : public GRaceParameters {
public:
	GActivity *mRaceActivity;
	unsigned int mNumOpponents;
	bool mFreedByOwner;
	bool mNosEnabled;
	int mHeatLevel;
	GRaceIndexData mCustomIndexData;

	static inline auto CreateRaceActivity = (void(__thiscall*)(GRaceCustom*))0x63BF80;

	//static inline auto SetReversed = (void(__thiscall*)(GRaceCustom*, bool))0x;
	//static inline auto SetNumLaps = (void(__thiscall*)(GRaceCustom*, int))0x;
	//static inline auto SetIsPracticeMode = (void(__thiscall*)(GRaceCustom*, bool))0x;
	//static inline auto SetIsSlotcarRace = (void(__thiscall*)(GRaceCustom*, bool))0x;
	//static inline auto SetTrafficDensity = (void(__thiscall*)(GRaceCustom*, int))0x;
	//static inline auto SetNumOpponents = (void(__thiscall*)(GRaceCustom*, int))0x;
	//static inline auto SetDifficulty = (void(__thiscall*)(GRaceCustom*, int))0x;
	//static inline auto SetCopsEnabled = (void(__thiscall*)(GRaceCustom*, bool))0x;
};
static_assert(sizeof(GRaceCustom) == 0x98);