namespace EA {
	namespace Memcard {
		class IMemcardNotifiable {
		public:
			virtual void _dtor();
			virtual void RegisterForNotify();
			virtual void OnNotifySave();
			virtual void OnNotifySaveComplete();
			virtual void OnNotifyLoadComplete();
		};
	}
}

namespace GLogic {
	class ICache {
	public:
		virtual void BeginUpdate();
		virtual void EndUpdate();
	};
}

class GCareerLevels;
class GCareerUnlocks;
class GCareerEvents;
class GCareerPresentationQ;
class GMW2Game : public EA::Memcard::IMemcardNotifiable, GLogic::ICache {
public:
	enum ePositionType {
		kPositionTeleport = 0,
		kPositionRestore = 1,
	};

	Attrib::Class *mGameplayClass;
	GCareerLevels *mGCareerLevels;
	GCareerUnlocks *mGCareerUnlocks;
	GCareerEvents *mGCareerEvents;
	GCareerPresentationQ *mGCareerPresentationQ;
	float mLastCareerCash;
	float mLastCareerDominateCash;
	float mLastCareerDominateXPAwarded;
	float mCurrentCareerXP;
	float mLastCareerXPAwarded;
	float mCareerCostToState;
	float mCareerMostCostToState;
	float mCareerStylePoints;
	float mCareerMostStylePoints;
	float mRewardModifiers[11];
	bool mDoFlasher;
	bool mLeveledUp;
	bool mShopDiscovered;
	bool mCareerComplete;
	bool mCareerDominated;
	bool mCareer100Percent;
	int mCareerID;
	unsigned int mGenericFlasherHash1;
	unsigned int mGenericFlasherHash2;
	unsigned int mGenericFlasherHash3;
	unsigned int mGenericFlasherHash4;
	unsigned int mGenericFlasherHash5;
	unsigned int mGenericFlasherHash6;
	int mPursuitEndCount;
	UMath::Vector3 mStartPostion;
	float mStartRotation;
	ePositionType mStartPositionType;
	float mStartSpeed;
	unsigned int mCellPhoneHash1;
	unsigned int mCellPhoneHash2;
	float mCareerProgress;
	float mLastCareerProgress;
	float mPctGameComplete;
	float mPreviousLevel;
	float mFlasherTimer;
	bool mDoOpenWorldFlash;
	bool mSetPosition;
	unsigned int mStartPositionHash1;
	unsigned int mStartPositionHash2;
	bool mAutosSavePendingSerialization;
	bool mSaving;

	static inline auto& mObj = *(GMW2Game**)0xD9B940;
};
static_assert(sizeof(GMW2Game) == 0xD8);