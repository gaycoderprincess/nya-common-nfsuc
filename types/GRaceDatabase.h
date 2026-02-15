class GMissionIndexData;
class GMissionParameters;
class GRaceSaveInfo;
class GRaceDatabase {
public:
	enum {
		kMaxDynamicRaces = 4,
		kMaxEvents = 400,
	};

	unsigned int mRaceCountStatic;
	unsigned int mRaceCountDynamic;
	GRaceIndexData *mRaceIndex;
	GRaceParameters *mRaceParameters;
	GRaceCustom *mRaceCustom[4];
	unsigned int mMissionCountStatic;
	GMissionIndexData *mMissionIndex;
	GMissionParameters *mMissionParameters;
	bstl::derived_with_name<eastl::list<unsigned int,bstl::allocator>> mCriticalStoryEvents;
	bstl::derived_with_name<eastl::list<unsigned int,bstl::allocator>> mDominatableEvents;
	unsigned int mBinCount;
	GRaceBin *mBins;
	Attrib::Class *mGameplayClass;
	GRaceCustom *mCustomEncounterRace;
	GRaceCustom *mStartupRace;
	GRace::Context mStartupRaceContext;
	GMissionParameters *mStartupMission;
	unsigned int mNumInitialUnlocks;
	unsigned int *mInitialUnlockHash;
	GRaceSaveInfo *mRaceScoreInfo;
	eastl::hash_map<unsigned int,IEventParameters *,eastl::hash<unsigned int>,eastl::equal_to<unsigned int>,bstl::allocator,0> mEventParametersMap;
	int mCollectorsEditionRaceCount;

	static inline auto& mObj = *(GRaceDatabase**)0xD9B924;

	static inline auto GetRaceFromHash = (GRaceParameters*(__thiscall*)(GRaceDatabase*, uint32_t))0x6217D0;
	static inline auto GetRaceFromKey = (GRaceParameters*(__thiscall*)(GRaceDatabase*, uint32_t))0x5FD720;
	static inline auto AllocCustomRace = (GRaceCustom*(__thiscall*)(GRaceDatabase*, GRaceParameters*))0x649550;
	static inline auto DestroyCustomRace = (GRaceCustom*(__thiscall*)(GRaceDatabase*, GRaceParameters*))0x5FD830;
	static inline auto ClearStartupRace = (void(__thiscall*)(GRaceDatabase*))0x5FD890;

	static inline auto GetStartupRace = (GRaceCustom*(__thiscall*)(GRaceDatabase*))0x6E8AF0;

	void SetStartupRace(GRaceCustom* custom, GRace::Context context) {
		if (mStartupRace) {
			GRaceDatabase::ClearStartupRace(this);
		}
		mStartupRaceContext = context;
		mStartupRace = custom;
	}
};