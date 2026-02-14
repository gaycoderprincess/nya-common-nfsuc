class GRaceParameters;
class GRaceSettings;
class GRacerInfo;
class GTrigger;
class GRaceBin;
class GRuntimeInstance;
class GKnockoutRaceStatus;
class WorldModel;
class AcidEffect;
class GCountDownBehaviour;
class GAdaptiveBonus;
class GActivity;
class GCharacter;

class GTimer {
public:
	int64_t mStartTime;
	float mTotalTime;
	bool mRunning;
};

class GHurryUpTimer {
public:
	Hermes::_h_HHANDLER__ *mStartHurryUpTimer;
	Hermes::_h_HHANDLER__ *mStopHurryUpTimer;
	bool mIsRunning;
	bool mIsFinishTimer;
	float mTimeRemaining;
};

class GAIRaceSettings {
public:
	Physics::Info::HAT MinPerformance;
	Physics::Info::HAT MaxPerformance;
	Physics::Info::HAT BiasPerformance;
	float MinSkill;
	float MaxSkill;
	unsigned int Glue;
	unsigned int PerformanceAttribs;
};

enum GNOSMode {
	kGameNOSAllowed = 0,
	kGameNOSOn = 1,
	kGameNOSOff = 2,
};

class GRaceSettings {
public:
	bool UseDefinedAI;
	unsigned int NumOpponents;
	GAIRaceSettings AISettings;
	int NumLaps;
	int TrafficDensity;
	GRace::Difficulty Difficulty;
	GNOSMode NOSMode;
	bool IsAdaptive;
};

class IRaceStatus {
public:
	enum eAdaptiveGainReason {
		kAdaptiveGain_FromElimination = 0,
		kAdaptiveGain_FromRacerFinished = 1,
		kAdaptiveGain_FromAbandonment = 2,
	};

	static inline auto& mInstance = *(IRaceStatus**)0xDE6DC8;

	virtual void _vt0();
	virtual void FinalizeStatistics();
	virtual void CalculateRankings();
	virtual void SortCheckPointRankings();
	virtual void UpdatePursuitRace(float);
	virtual GRace::Context GetRaceContext();
	virtual void SetRaceContext(GRace::Context);
	virtual GRace::Type GetRaceType();
	virtual GRaceParameters *GetRaceParameters();
	virtual GRaceBin *GetCurrentBin();
	virtual void RefreshBinWhileInGame();
	virtual const GRaceSettings *GetSettings();
	virtual GRacerInfo *GetRacerInfo(ISimable *);
	virtual GRacerInfo *GetRacerInfo(int);
	virtual GRacerInfo *GetRacerInfoFromOpponentId(unsigned int);
	virtual int GetRacerIndex(ISimable *);
	virtual int GetRacerCount();
	virtual GRacerInfo *GetWinningPlayerInfo();
	virtual GRacerInfo *GetRaceLeader();
	virtual ISimable *GetRacePursuitTarget(int *);
	virtual void StateOverrideAll(int);
	virtual void StateCatchupAll(int, int);
	virtual bool StateCheckAll(int);
	virtual bool StateCheck(int, int);
	virtual bool StateRangeCheckAny(int, int, int);
	virtual bool StateCheckAny(int);
	virtual bool StateCheckAny(int, int);
	virtual bool StateCheckFirst(int);
	virtual bool StateCheckFirst(int, int);
	virtual void RacerStateChanged(int, int);
	virtual int GetNumRacers();
	virtual int GetNumHumanRacers();
	virtual int GetNumStillRacing();
	virtual void StartMasterTimer();
	virtual void StopMasterTimer();
	virtual bool IsRaceTimeElapsing();
	virtual float GetRaceTimeElapsed();
	virtual void AdvanceTime(__int64);
	virtual bool GetIsTimeLimited();
	virtual float GetRaceTimeRemaining();
	virtual void ClearTimes();
	virtual void SetLapTime(int, int, float);
	virtual float GetLapTime(int, int, bool);
	virtual void SetCheckpointTime(int, int, int, float);
	virtual float GetCheckpointTime(int, int, int, bool);
	virtual int GetLapPosition(int, int, bool);
	virtual int GetCheckpointPosition(int, int, int);
	virtual float GetFinishTimeBehind(int);
	virtual float GetBestLapTime(int);
	virtual float GetWorstLapTime(int);
	virtual int GetLapsLed(int);
	virtual int GetLeaderLapCount();
	virtual GTrigger *GetEncounterFinish();
	virtual void SetEncounterFinish(GTrigger *);
	virtual void SetStatsArbitrating(bool);
	virtual bool IsStatsArbitrating();
	virtual bool ShouldOnlineGameEnd();
	virtual int GetNumberOfConnectedRacers();
	virtual bool IsAIControllerDisconnected();
	virtual void ResetRaceData();
	virtual float GetAveragePercentComplete();
	virtual bool AreOpponentsValid();
	virtual void DoEventOverCleanup();
	virtual bool IsSprintRace();
	virtual bool IsCircuitRace();
	virtual bool IsCheckPointRace();
	virtual bool IsPursuitRace();
	virtual bool IsHighwayBattleRace();
	virtual bool IsOutRunRace();
	virtual bool IsChaseRace();
	virtual bool IsCopsAndRobbers();
	virtual bool IsCareerEvent();
	virtual bool IsHurryUpTimerRunning();
	virtual bool IsMoneyPickedUp();
	virtual void SkipToEndOfRaceForRacer(ISimable *, int, float);
	virtual void SkipToEndOfRaceInPlace(int, float);
	virtual void TeleportAllRacersToJustBeforeTheEndOfTheRaceAndPretendTheyRacedThere();
	virtual bool WasPartOfRaceSkipped();
	virtual void ClearRacers();
	virtual GRacerInfo *AddSimablePlayer(ISimable *);
	virtual int AddRacer(GRuntimeInstance *);
	virtual void DebugSetRaceParameters(GRaceParameters *);
	virtual void EnterSuddenDeath();
	virtual bool GetIsSuddenDeath();
	virtual void EnableBarriers();
	virtual void DisableBarriers();
	virtual void PrepareBarriers();
	virtual void EnableBinBarriers();
	virtual void DisableBinBarriers();
	virtual void ClearCheckpoints();
	virtual void AddCheckpoint(GRuntimeInstance *);
	virtual void SetNextCheckpointPos(GRuntimeInstance *);
	virtual void DetermineRaceLength();
	virtual bool GetNodeRaceDistance(unsigned __int16, float *);
	virtual float DATAtCheckpoint(int);
	virtual int GetNumRaceSegments();
	virtual bool GetRaceRouteError();
	virtual bool GetShortcutError();
	virtual unsigned int GetRaceRouteFlags();
	virtual float GetRaceLength();
	virtual float GetFirstLapLength();
	virtual float GetSegmentLength(int, int);
	virtual float GetSegmentLength(int);
	virtual float GetSubsequentLapLength();
	virtual float GetLapLength(int);
	virtual bool IsRevealed(int);
	virtual void SetRevealed(int);
	virtual bool IsSlowcut(int);
	virtual int GetShortcutPair(int);
	virtual int GetSideRouteShortcutNumber(__int16);
	virtual bool WasExitSegmentReachedByActivatedPathy(int);
	virtual void SetExitSegmentReachedByActivatedPathy(int);
	virtual bool WasExittedByActivatedPathy(int);
	virtual void SetExittedByActivatedPathy(int);
	virtual int GetIndexOfLastShortcutInRace();
	virtual bool IsPrimaryRaceSegment(__int16);
	virtual float GetAdaptiveDifficutly();
	virtual void UpdateAdaptiveDifficulty(eAdaptiveGainReason, ISimable *);
	virtual void ComputeAdaptiveDifficulty();
	virtual void AddAvailableEventToMap(GRuntimeInstance *, GRuntimeInstance *);
	virtual void AddSpeedTrapToMap(GRuntimeInstance *);
	virtual void AwardBonusTime(float);
	virtual void ResetTimeRemaining();
	virtual void SetTaskTime(float);
	virtual float GetTaskTime();
	virtual void SetActivelyRacing(bool);
	virtual bool GetActivelyRacing();
	virtual int GetCheckpointCount();
	virtual GTrigger *GetCheckpoint(int);
	virtual GTrigger *GetNextCheckpoint();
	virtual int GetNumRaceSpeedTraps();
	virtual float GetRaceSpeedTrapSpeed(int, int);
	virtual int GetRaceSpeedTrapPosition(int, int);
	virtual float GetBestSpeedTrapSpeed(int);
	virtual float GetWorstSpeedTrapSpeed(int);
	virtual GTrigger *GetRaceSpeedTrap(int);
	virtual int GetNumRaceTimeBonusCheckpoints();
	virtual float GetRaceTollboothTime(int, int);
	virtual void RefreshBinAfterRace();
	virtual void RaceAbandoned();
	virtual void EndStopAll();
	virtual void PlayerPursuitInCoolDown(bool);
	virtual bool GetHasBeenWon();
	virtual void SetHasBeenWon(bool);
	virtual bool GetPlayerWon();
	virtual bool GetPlayerDominated();
	virtual void CheckDisconnects();
	virtual GKnockoutRaceStatus *GetKnockoutRaceStatus();
	virtual const UMath::Vector3 *GetSavedEngagePos();
	virtual void SetSavedEngagePos(UMath::Vector3);
	virtual float GetMaxPursuitContribution();
	virtual float GetPursuitArrestFactor(ISimable *);
	virtual void ResolvePursuitTagDisconnect(int, int);
	virtual void SetWaitForMusicTransition();
	virtual bool GetIsRestartAllowed();
	virtual void SetIsRestartAllowed(bool);
	virtual void StartNewPursuitTagChase();
	virtual float GetPursuitTagEvasionBonus();
	virtual void OnlineRaceStarted();
	virtual int GetOnlineStartIndex(int);
	virtual void DoCountDownBehaviour(GRuntimeInstance *, bool);
	virtual void ResetSequenceEngine();
	virtual void ProcessStimulus(const char *);
	virtual void ToggleAllowPursuitCooldown(bool);
	virtual bool IsPursuitCooldownAllowed();
	virtual void Finish(int);
	virtual void Prepare();
	virtual void PlaceGrid(GRuntimeInstance *);
	virtual void Cleanup();
	virtual void RepairAllLocalAI();
};

class GElapsedCallback;
class GCallbackTimer {
public:
	float mInterval;
	bool mRunning;
	float mElapsed;
	unsigned int mNameHash;
	char mName[20];
	GElapsedCallback *mCallback;
};

class GElapsedCallback {
public:
	virtual void Elapsed(GCallbackTimer *);
};

struct GArbitratedRacerStats {
	unsigned int mFinishReason;
	float mPointTotal;
	float mRaceTime;
	int mLapsCompleted;
	int mNumPickUps;
	int mNumDropOffs;
	float mTopSpeed;
	float mAvgSpeed;
	float mBestLapTime;
	float mPoundsNOSUsed;
	float mBestSectorPoints;
	float mCheckpointTopSpeeds[16];
	float mRaceResult;
	float mAccumulatedCheckpointSpeeds;
	float mDragWheelieDistance;
};

class GRacerInfo {
public:
	enum {
		kMaxTimers = 0x1,
		kNamesAvail = 0xA2,
	};

	enum FinishReason {
		kReason_Unknown = 0x0,
		kReason_Completed = 0x2,
		kReason_CrossedFinish = 0x6,
		kReason_DidNotFinish = 0xA,
		kReason_KnockedOut = 0x1A,
		kReason_Totalled = 0x2A,
		kReason_EngineBlown = 0x4A,
		kReason_Busted = 0x8A,
		kReason_ChallengeCompleted = 0x102,
		kReason_Disconnected = 0x20A,
		kReason_FalseStart = 0x40A,
	};

	enum State {
		kState_Initial = 1,
		kState_NIS = 2,
		kState_PreStaging = 3,
		kState_Staging = 4,
		kState_PostStaging = 5,
		kState_Handicap = 6,
		kState_Countdown = 7,
		kState_Racing = 8,
		kState_RaceOver = 9,
		kState_Spectate = 10,
		kState_Done = 11,
	};

	enum Type {
		kType_Human = 1,
		kType_Artifical = 2,
	};

	struct GLocalRacerStats {
		float mPctRaceComplete;
		float mPctLapComplete;
		float mPctRaceCompleteHighWaterMark;
		int mCheckpointsHitThisLap;
		float mTimeRemainingToBooth[16];
		float mDistToNextCheckpoint;
		float mDistanceDriven;
		float mDeltaXP;
		float mTimeFacingWrongWay;
		float mPercentTimes[100];
		bool mFinishedBackwards;
		float mSkillLevel;
		float mCurrentAirTime;
		float mTimeCrossedLastCheck;
		float mTotalUpdateTime;
		int mSpeedTrapsCrossed;
		float mSpeedTrapSpeed[16];
		int mSpeedTrapPosition[16];
		float mFinishingSpeed;
		int mNumPerfectShifts;
		int mNumTrafficCarsHit;
		float mSpeedBreakerTime;
		float mZeroToSixtyTime;
		float mQuarterMileTime;
		float mSplitTimes[4];
		int mSplitRankings[4];
		float mLongestAirTime;
		int mTollboothsCrossed;
		int mNumRaceBreakersActivated;
		float mDistanceToStartLine;
		float mDistanceToFinish;
	};

	struct GRacerStats {
		GArbitratedRacerStats arbitrated;
		GRacerInfo::GLocalRacerStats local;
	};

	State mState;
	unsigned int mOpponentId;
	HSIMABLE__ *mhSimable;
	GCharacter *mGameCharacter;
	char mName[32];
	int mIndex;
	int mRanking;
	int mAiRanking;
	GRacerStats mStats;
	bool mUseLowResModel;
	bool mCameraDetached;
	float mPercScoreAsRacer;
	float mPercScoreAsCop;
	GTimer mRaceTimer;
	GTimer mLapTimer;
	GTimer mCheckTimer;
	GCallbackTimer mTimers[1];
	bool mAssetHolder;
	float mPursuitContrib;
	float mPursuitContribSinceLastMsg;
	UMath::Vector3 mSavedPosition;
	float mSavedHeatLevel;
	UMath::Vector3 mSavedDirection;
	float mSavedSpeed;
	bool mIsControllingAI;
	int mNumBusts;
	int mNumTimesBusted;
	float mLeadingDistance;
	unsigned int mCurrentGoal;
	eastl::map<enum GRace::Type,enum FinishReason (GRacerInfo::*)(enum FinishReason),eastl::less<enum GRace::Type>,bstl::allocator> mExtrapolateFinishFuncs;
	bool mUpdateDistanceToFinish;
};
static_assert(sizeof(GRacerInfo) == 0x450);

class GKnockoutRacer {
public:
	int mIndex;
	float mRacerBestCollisionScore;
	float mLapScore[10];
	float mBestArbitratedScore;
};

class GKnockoutRaceStatus {
public:
	int mRacerHit;
	bool mCheckedHigh;
	bool mRacerHitWall;
	bool mRacerSpinHalf;
	bool mRacerSpinFull;
	bool mRacerHitWallAward;
	bool mRacerSpinHalfAward;
	bool mRacerSpinFullAward;
	float mLastHighScore;
	float mTimeNextHighScore;
	float mRacerCollisionTime;
	float mRacerCollisionScore;
	float mRacerMultiplierAwarded;
	UMath::Vector3 mRacerCollisionDir;
	Hermes::_h_HHANDLER__ *mCollisionHandler;
	GKnockoutRacer mRacers[8];
};

class IEventStatus {
public:
	virtual void _vt0();
	virtual void Update(float);
	virtual void SetEventActivity(GActivity *);
	virtual bool IsLoading();
	virtual bool IsAudioLoading();
	virtual bool IsModelsLoading();
	virtual bool GetIsScriptWaitingForLoading();
	virtual void NotifyScriptWhenLoaded();
	virtual bool IsVehicleUsedInEvent(const IVehicle *);
	virtual void OnStartEvent();
	virtual void OnEnterRoaming();
	virtual void GetInUseVehicles(eastl::list<HSIMABLE__ *,bstl::allocator> *);
};

class GRaceStatus : public IRaceStatus, IEventStatus {
public:
	static inline auto& fObj = *(GRaceStatus**)0xDE6DC8; // for compatibility only

	eastl::vector<unsigned int,bstl::allocator> mOpponents;
	GRacerInfo mRacerInfo[8];
	GRacerInfo *mLazyRankingInfo[8];
	int mRacerCount;
	int mPlayerHighestRanking;
	bool mIsLoading;
	GRace::Context mRaceContext;
	GRaceParameters *mRaceParms;
	GRaceBin *mRaceBin;
	GTimer mRaceMasterTimer;
	bool mPlayerPursuitInCooldown;
	float mBonusTime;
	float mTaskTime;
	bool mSuddenDeathMode;
	bool mTimeExpiredMsgSent;
	bool mActivelyRacing;
	int mLastSecondTickSent;
	WorldModel *mCheckpointModel;
	AcidEffect *mCheckpointEmitter;
	bool mQueueBinChange;
	int mNumTimeBonusCheckpoints;
	bool mScriptWaitingForLoad;
	bool mRefreshBinAfterRace;
	bool mWaitForMusicTransition;
	bool mOpponentsValid;
	bstl::derived_with_name<eastl::vector<GTrigger *,bstl::allocator>> mCheckpoints;
	GTrigger *mNextCheckpoint;
	GTrigger *mEncounterFinish;
	float mLapTimes[10][8];
	float mCheckTimes[10][32][8];
	int mNumRaceSegments;
	float mSegmentLengths[34];
	float fRaceLength;
	float fFirstLapLength;
	float fSubsequentLapLength;
	eastl::set<short,eastl::less<short>,bstl::allocator> mPrimaryRaceRouteSet;
	bstl::derived_with_name<eastl::map<unsigned short,float,eastl::less<unsigned short>,bstl::allocator>> mRaceDistanceMap;
	uint8_t mRevealedShortcuts[32];
	int16_t mSideRoutes[32];
	uint8_t mSlowcuts[32];
	int mShortcutPairs[32];
	uint8_t mShortcutsExitSegmentReachedByActivatedPathy[32];
	uint8_t mShortcutsExittedByActivatedPathy[32];
	int mIndexOfLastShortcutInRace;
	bool mCaluclatedAdaptiveGain;
	float fAveragePercentComplete;
	int nSpeedTraps;
	GTrigger *aSpeedTraps[16];
	unsigned int mRaceRouteFlags;
	bool mHasBeenWon;
	GKnockoutRaceStatus mKnockoutStatus;
	UMath::Vector3 mSavedEngagePos;
	unsigned int mFinishFlareState;
	bool mRestartAllowed;
	float mPursuitTagTimeRemaining;
	float mPursuitTagTimeRequired;
	int mPursuitTagCountdown;
	bool mStatsArbitrating;
	GCountDownBehaviour *mCountdown;
	GHurryUpTimer mHurryUpTimer;
	GRaceSettings mRaceSettings;
	bool mSkippedPartOfRace;
	GAdaptiveBonus *mAdaptiveBonus;
	GActivity *mRaceActivity;
	bool mEndOfRaceStimulusSent;
	bool mAllowPursuitCooldown;
	eastl::map<unsigned int,bool,eastl::less<unsigned int>,bstl::allocator> mEnabledBarriers;
	Hermes::_h_HHANDLER__ *mRaceStartHandler;
};
static_assert(sizeof(GRaceStatus) == 0x5150);
static_assert(offsetof(GRaceStatus, mRacerInfo) == 0x18);