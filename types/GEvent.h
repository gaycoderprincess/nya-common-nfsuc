class GEvent {
public:
	struct GRoundStats {
		float mScores[3];
	};

	GActivity *mEventActivity;
	eastl::vector<unsigned int,bstl::allocator> mOpponents;
	eastl::map<unsigned int,GRoundStats,eastl::less<unsigned int>,bstl::allocator> mRoundScores;
	float mTeamPointsPerRound[3][3];
	int mNumRounds;
	int mCurrentRound;
	bool mAscending;
	bool mUnplayable;

	static inline auto& sInstance = *(GEvent**)0xD9B7F4;

	static inline auto ClearOpponents = (void(__thiscall*)(GEvent*))0x61FB90;
	static inline auto Prepare = (void(__thiscall*)(GEvent*))0x646C10;
};
static_assert(sizeof(GEvent) == 0x60);