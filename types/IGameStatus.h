class IGameStatus {
public:
	enum ePlayMode {
		kPlayMode_None = -1,
		kPlayMode_Roaming = 0,
		kPlayMode_EventRunning = 1,
	};
	typedef GRace::Type eEventType;

	static inline auto& mInstance = *(IGameStatus**)0xDE6DC4;

	virtual void _vt0();
	virtual void Prepare(const unsigned int);
	virtual void Update(float);
	virtual ePlayMode GetPlayMode();
	virtual eEventType GetEventType();
	virtual bool IsLoading();
	virtual bool IsAudioLoading();
	virtual bool IsModelsLoading();
	virtual bool GetIsScriptWaitingForLoading();
	virtual void NotifyScriptWhenLoaded();
	virtual void LockVehicleCache(bool);
	virtual void ClearUsedVehicleList();
	virtual void PopulateInUseVehiclesList();
	virtual float GetElapsedRoamingTime();
	virtual int GetTrafficDensity();
	virtual void SetTrafficDensity(int);
	virtual unsigned int GetTrafficPattern();
	virtual unsigned int GetTrafficHighwaySequence();
	virtual int GetTrafficHighwayDifficulty();
	virtual void SetTrafficPattern(unsigned int);
	virtual void SetTrafficHighwaySequence(unsigned int);
	virtual void SetTrafficHighwayDifficulty(int);
	virtual void ClearTrafficPattern();
	virtual void ClearTrafficHighwaySequence();
	virtual void ClearTrafficHighwayDifficulty();
	virtual bool IsRoaming();
	virtual bool IsRacing();
	virtual void SetRoaming();
	virtual void SetRacing();
	virtual void WarpWhenInFreeRoam(unsigned int);
	virtual void SetRaceActivity(GActivity *);
	virtual void SetMissionActivity(GActivity *);
	virtual void EventLaunched();
	virtual void SetEventLoadingComplete();
	virtual bool IsWaitingForEventLaunch();
	virtual bool IsOverridingCar();
	virtual bool IsEventPendingLaunch();
	virtual void ToggleShortMissionIntroNIS(bool);
	virtual bool ShouldPlayShortMissionIntorNIS();
};