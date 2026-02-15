enum eCustomTuningType {
	CTT_SETTING_1 = 0,
	CTT_SETTING_2 = 1,
	CTT_SETTING_3 = 2,
	NUM_CUSTOM_TUNINGS = 3,
};

enum eOnlineBlueprintType {
	OBT_NONE = 0,
	OBT_SHARED = 1,
	OBT_DLC = 2,
};

class FECarRecord {
public:
	unsigned int Handle;
	unsigned int FEKey;
	unsigned int VehicleKey;
	unsigned int PresetKey;
	unsigned int FilterBits;
	uint8_t Customization;
	uint8_t CareerHandle;
	uint8_t IsPresetSkin;
	uint8_t Padd;
	bool IsPinkSlip;
};

struct FEImpoundData {
	uint8_t mMaxBusted;
	char mTimesBusted;
	int16_t Pad1;
};

class FEInfractionsData {
public:
	uint16_t Speeding;
	uint16_t Racing;
	uint16_t Reckless;
	uint16_t Assault;
	uint16_t HitAndRun;
	uint16_t Damage;
	uint16_t Resist;
	uint16_t OffRoad;
};

class FECareerRecord {
public:
	uint8_t Handle;
	FEImpoundData TheImpoundData;
	float VehicleHeat;
	bool HasNeverBeenInHub;
	unsigned int Bounty;
	uint16_t NumEvadedPursuits;
	uint16_t NumBustedPursuits;
	float DamageLevel;
	int DamageCost;
	FEInfractionsData UnservedInfractions;
	FEInfractionsData ServedInfractions;
};

struct FEKitInfo {
	KIT_TYPE installedType;
	unsigned int installedKitNum;
	unsigned int inventory[4];
};

class FEPaintSV {
	uint8_t s;
	uint8_t v;
};

class FECustomizationRecord {
	uint16_t FirstCarPartRecordIndex;
	uint16_t FirstVinylRecordIndex;
	VehicleCustomizations mBluePrint;
	FEKitInfo mBodykitInfo;
	Physics::Tunings Tunings[3];
	eCustomTuningType ActiveTuning;
	int Preset;
	uint8_t Handle;
	int mType;
	FEPaintSV mPaint[12];
	eOnlineBlueprintType mOnlineType;
	uint8_t mBlueprintTier;
};

template<typename T, typename T2, typename T3, int capacity, int n5, int n6>
class FELinkedPool {
public:
	T mPool[capacity];
};

class FECarPartRecord {
public:
	unsigned int mValue;
	uint16_t mNextElement;
	uint16_t : 2;
	uint16_t mKit : 14;
	uint8_t : 6;
	int8_t mDLC : 1;
	int8_t mCarbon : 1;
};

class FEPlayerCarDB {
public:
	FECarRecord CarTable[330];
	FECustomizationRecord Customizations[70];
	FECareerRecord CareerRecords[70];
	FELinkedPool<FECarPartRecord,unsigned int,unsigned short,9500,-1,65535> CarParts;
	unsigned int SoldHistoryBounty;
	uint16_t SoldHistoryNumEvadedPursuits;
	uint16_t SoldHistoryNumBustedPursuits;
	FEInfractionsData SoldHistoryUnservedInfractions;
	FEInfractionsData SoldHistoryServedInfractions;
	unsigned int LastAwardedKingCarHistoryCarHandle;
	BluePrintType LastAwardedKingCarHistoryCarMode;
	bool mInitializingCarStable;
	unsigned int mQuickRaceCarHandle;
};