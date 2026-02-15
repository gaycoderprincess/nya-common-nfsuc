template<typename T>
class GWrapper {
public:
	T Value;
};

class GHub {
public:
	uint8_t _0[0x1C];
	bstl::derived_with_name<eastl::list<unsigned int,bstl::allocator>> mAvailableEvents;
	unsigned int mCurrentEventKey;
	unsigned int mCurrentEventHash;
	unsigned int mRequestedEventKey;
	unsigned int mSelectedEventIndex;
	unsigned int mCurrentEventType;
	bool mRunEventWhenLoadDone;
	bool mInEventSelect;

	static inline auto& sCurrentHub = *(GHub**)0xD9B974;

	virtual const char *GetName();
	virtual void SetupAdapter();
	virtual void Prepare();
	virtual void RequestSetupData();
	virtual void DoSetup(int, unsigned int, int);
	virtual void DoEventSelect();
	virtual void DoRacing();
	virtual void DoEventOver();
	virtual void Cleanup();
	virtual void _dtor();
	virtual bool IsEventSelectFreeRoam();
	virtual void UpdateCars();
	virtual void UpdateSpawnLocation();
	virtual bool RequestStartEvent(int);
	virtual void BeforePrepareEvent();
	virtual bool CanPlayQueuedMedia();
	virtual bool AllowEventMovies();
	virtual void SetupPlayerCar(GWrapper<unsigned int> playerCarHandle, int playerIndex);
	virtual void RefreshAvailableEvents();
	virtual void RefreshAvailableOnlineEvents(const GRace::Type);
	virtual GRace::Type GetOnlineEventType();
	virtual unsigned int GetRandomEventIndex();
	virtual void GetSettingsForRace(GRaceParameters *, GRaceSettings *);
	virtual void OnSaveGameLoaded();
	virtual bool IsRoaming();
	virtual unsigned int GetMinPlayers();
	virtual bool IsAutoSaveAllowed();
	virtual bool CanRaceNow();
	virtual bool CanStartEvent();
	virtual bool IsEventStartAllowed();
	virtual bool CanRunEvent();
	virtual void OnEnterHubSelect();
	virtual void OnExitHubSelect(bool);
	virtual void ApplySettingsToRace(GRaceCustom *);

	static inline auto GetEventKey = (uint32_t(__thiscall*)(GHub*, int))0x625A10;
	static inline auto StartEventFromKey = (void(__thiscall*)(GHub*, uint32_t))0x633820;
	static inline auto StartEventFromIndex = (void(__thiscall*)(GHub*, int))0x636080;
	static inline auto StartCurrentEvent = (void(__thiscall*)(GHub*))0x6338C0;
};
static_assert(sizeof(GHub) == 0x48);
static_assert(offsetof(GHub, mCurrentEventHash) == 0x34);
static_assert(offsetof(GHub, mRequestedEventKey) == 0x38);