enum CarUsageType {
	CAR_USAGE_TYPE_RACING = 0,
	CAR_USAGE_TYPE_COP = 1,
	CAR_USAGE_TYPE_TRAFFIC = 2,
	CAR_USAGE_TYPE_WHEELS = 3,
	CAR_USAGE_TYPE_UNIVERSAL = 4,
};

enum eLiveryID {
	LIVERYID_NONE = -1,
	LIVERYID_COP_CAR_MID_05_01 = 0x0,
	LIVERYID_COP_CAR_MUS = 0x1,
	LIVERYID_COP_CAR_GTR = 0x2,
	LIVERYID_COP_CAR_POR_911 = 0x3,
	LIVERYID_COP_SUV = 0x4,
	LIVERYID_BOSS_CARMEN = 0x5,
	LIVERYID_BOSS_CHASE = 0x6,
	LIVERYID_BOSS_ISF = 0x7,
	LIVERYID_BOSS_NICKEL = 0x8,
	LIVERYID_BOSS_ROSE = 0x9,
	LIVERYID_BOSS_ZACK = 0xA,
	LIVERYID_BOSS_INTRO = 0xB,
	LIVERYID_MEGANE = 0xC,
	LIVERYID_BOSS_GMAC = 0xD,
	LIVERYID_TERLINGUA = 0xE,
	LIVERYID_BOSS_HECTOR = 0xF,
	LIVERYID_DCAST_GT2 = 0x10,
	LIVERYID_DCAST_R8 = 0x11,
	LIVERYID_DCAST_CAMARO = 0x12,
	LIVERYID_DCAST_CHARGER = 0x13,
	LIVERYID_DCAST_VIPER = 0x14,
	LIVERYID_DCAST_MUSTANG = 0x15,
	LIVERYID_DCAST_MURCIELAGO = 0x16,
	LIVERYID_DCAST_ISF = 0x17,
	LIVERYID_DCAST_MPS3 = 0x18,
	LIVERYID_DCAST_GTO = 0x19,
	LIVERYID_DCAST_GTR = 0x1A,
	LIVERYID_DCAST_911_TURBO = 0x1B,
	LIVERYID_DCAST_GOLF = 0x1C,
	LIVERYID_DCAST_CAMARO2 = 0x1D,
	LIVERYID_BOSS_ROSES = 0x1E,
	LIVERYID_MAX = 0x1F,
};

class CarTypeInfo {
public:
	char CarTypeName[32];
	char BaseModelName[16];
	char GeometryFilename[64];
	char ManufacturerName[64];
	unsigned int CarTypeNameHash;
	float HeadlightFOV;
	char padHighPerformance;
	char NumAvailableSkinNumbers;
	char WhatGame;
	char ConvertableFlag;
	char WheelOuterRadius;
	char WheelInnerRadiusMin;
	char WheelInnerRadiusMax;
	char pad0;
	bVector3 HeadlightPosition;
	bVector3 DriverRenderingOffset;
	bVector3 InCarSteeringWheelRenderingOffset;
	int Type;
	CarUsageType UsageType;
	unsigned int CarMemTypeHash;
	char MaxInstances[5];
	char WantToKeepLoaded[5];
	char pad4[2];
	float MinTimeBetweenUses[5];
	char AvailableSkinNumbers[10];
	char DefaultSkinNumber;
	char Skinnable;
	int Padding;
	int DefaultBasePaint;
};
static_assert(sizeof(CarTypeInfo) == 0x130);

auto& CarTypeInfoArray = *(CarTypeInfo**)0x1336598;
auto& NUM_CARTYPES = *(int*)0xD5AAE8;

auto GetCarTypeInfoFromHash = (CarTypeInfo*(*)(uint32_t))0x843630;