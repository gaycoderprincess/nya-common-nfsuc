class FastMem {
public:
	class FreeBlock;
	class AllocDesc;

	FreeBlock *mFreeLists[64];
	const char *mName;
	unsigned int mExpansionSize;
	unsigned int mLocks;
	bool mInited;
	void *mBlock;
	unsigned int mBytes;
	unsigned int mUsed;
	unsigned int mDonated;
	unsigned int mAlloc[64];
	unsigned int mAvail[64];
	unsigned int mAllocOver;
	void *mAllocator;
	AllocDesc *mTrack;
	unsigned int mTrackMax;
	unsigned int mTrackCount;

	auto Alloc(size_t bytes, const char* kind) { auto f = (void*(__thiscall*)(FastMem*, size_t, const char*))0x5F6340; return f(this, bytes, kind); }
	auto Free(void* ptr, size_t bytes, const char* kind) { auto f = (void(__thiscall*)(FastMem*, void*, size_t, const char*))0x5F5AF0; return f(this, ptr, bytes, kind); }
};

auto& gFastMem = *(FastMem*)0xDA5320;