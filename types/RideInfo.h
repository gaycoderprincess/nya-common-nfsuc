enum CARPART_LOD {
	CARPART_LOD_OFF = -1,
	CARPART_LOD_START = 0,
	CARPART_LOD_A = 0,
	CARPART_LOD_B = 1,
	CARPART_LOD_C = 2,
	CARPART_LOD_D = 3,
	CARPART_LOD_E = 4,
	CARPART_LOD_NUM = 5,
};

enum CarRenderUsage {
	CarRenderUsage_Player = 0,
	CarRenderUsage_RemotePlayer = 1,
	CarRenderUsage_AIRacer = 2,
	CarRenderUsage_AICop = 3,
	CarRenderUsage_AITraffic = 4,
	CarRenderUsage_AIHeli = 5,
	carRenderUsage_NISCar = 6,
	CarRenderUsage_Ghost = 7,
	CarRenderUsage_Invalid = 8,
};

enum ePaintMaterialIndex {
	ePaintMaterialWhite = 0,
	ePaintMaterialSilver = 1,
	ePaintMaterialBlack = 2,
	ePaintMaterialRed = 3,
	ePaintMaterialViolet = 4,
	ePaintMaterialIndigo = 5,
	ePaintMaterialBlue = 6,
	ePaintMaterialGreen = 7,
	ePaintMaterialYellow = 8,
	ePaintMaterialOrange = 9,
};

namespace Csis {
	enum Type_car_color {
		Invalid_Type_car_color = 0x0,
		Type_car_color_Red = 0x1,
		Type_car_color_Black = 0x2,
		Type_car_color_White = 0x4,
		Type_car_color_Blue = 0x8,
		Type_car_color_Green = 0x10,
		Type_car_color_Orange = 0x20,
		Type_car_color_Silver = 0x40,
		Type_car_color_Gold = 0x80,
		Type_car_color_Purple = 0x100,
		Type_car_color_Brown = 0x200,
		Type_car_color_Yellow = 0x400,
		Type_car_color_Pink = 0x800,
		Type_car_color_Beige = 0x1000,
		Type_car_color_No_colour = 0x2000,
	};
}

enum AutoSculptRegionID {
	RegionFrontBumper = 0x0,
	RegionRearBumper = 0x1,
	RegionSkirtLeft = 0x2,
	RegionSkirtRight = 0x3,
	RegionRimsFront = 0x4,
	RegionRimsRear = 0x5,
	RegionDoorLeft = 0x6,
	RegionDoorRight = 0x7,
	RegionDoorRearLeft = 0x8,
	RegionDoorRearRight = 0x9,
	RegionFenderFrontLeft = 0xA,
	RegionFenderFrontRight = 0xB,
	RegionBody = 0xC,
	RegionHoods = 0xD,
	RegionSpoilers = 0xE,
	RegionRoofScoops = 0xF,
	RegionRoofHeight = 0x10,
	RegionExhaust = 0x11,
	RegionFrontWindow = 0x12,
	RegionRearWindow = 0x13,
	RegionFrontLeftWindow = 0x14,
	RegionFrontRightWindow = 0x15,
	RegionRearLeftWindow = 0x16,
	RegionRearRightWindow = 0x17,
	RegionLeftDoor = 0x18,
	RegionRightDoor = 0x19,
	RegionInterior = 0x1A,
	RegionDoorline = 0x1B,
	RegionWindTunnelType1 = 0x1C,
	RegionWindTunnelType2 = 0x1D,
	RegionWindTunnelType3 = 0x1E,
	RegionWindTunnelType4 = 0x1F,
	RegionWindTunnelType5 = 0x20,
	RegionWindTunnelType6 = 0x21,
	RegionWindTunnelType7 = 0x22,
	RegionWindTunnelType8 = 0x23,
	RegionWindTunnelType9 = 0x24,
	RegionWindTunnelType10 = 0x25,
	RegionRearBumperExtra = 0x26,
	RegionFrontBumperExtra = 0x27,
	RegionNum = 0x28,
	RegionInvalid = 0x29,
	RegionStart = 0x0,
	RegionEnd = 0x28,
	RegionWindTunnelStart = 0x1C,
	RegionWindTunnelEnd = 0x25,
	RegionPresetRideLast = 0x11,
};

enum AutoSculptZoneID {
	SculptZone0 = 0x0,
	SculptZone1 = 0x1,
	SculptZone2 = 0x2,
	SculptZone3 = 0x3,
	SculptZone4 = 0x4,
	SculptZone5 = 0x5,
	SculptZone6 = 0x6,
	SculptZone7 = 0x7,
	SculptZone8 = 0x8,
	SculptZone9 = 0x9,
	SculptZone10 = 0xA,
	SculptZoneNum = 0xB,
};

class IAttachmentSystem;
class eLightMaterial;
class DBCarPart;

class VinylColorPartInfo {
	uint8_t hue;
	uint8_t saturation;
	uint8_t brightness;
};

class DBCarPart {
public:
	char isValid;
	uint8_t CarTypeNameHashIndex;
	uint16_t AttributeTableOffset;
	const Attrib::Collection *partAttributes;
	uint16_t kitNum;
	uint16_t materialFlags;
	uint8_t padding;
};

class VinylLayerPartInfo {
public:
	DBCarPart vinyl;
	VinylColorPartInfo colors[4];
	VinylSystem::VinylTransformPacked transform;
};

class DecalLayerPartInfo {
public:
	DBCarPart decal;
	VinylSystem::VinylTransformPacked transform;
	VinylColorPartInfo color;
};

class CarPaintSwatch {
public:
	unsigned int rgb;
	ePaintMaterialIndex material_a;
	ePaintMaterialIndex material_b;
	float blend;
	Csis::Type_car_color speechColour;
};

class CarPaintRecord {
public:
	Attrib::Instance group;
	CarPaintSwatch swatch;
	uint8_t swatch_index;
	float saturation;
	float variance;
};

class CarPaint {
public:
	eLightMaterial *resultLightMaterial;
	CarPaintRecord paintRecord;
};

class AutoSculptRegion {
public:
	float mSculptZoneBlendAmount[11];
	bool mModified;
};

class AutoSculpt {
public:
	class SculptGroupNode {
		struct {
			AutoSculptRegionID region;
			unsigned int solidHash;
		};
		AutoSculptZoneID zone;
		int groupId;
	};

	bool mIsInitialized;
	AutoSculptRegion mRegionList[40];
	eastl::vector<SculptGroupNode,bstl::allocator> mLinkedGroups;
	bool mLinkedGroupsInitialized;
};

class RideInfo {
public:
	enum CreateSkinLoadState {
		CREATE_SKIN_NOT_LOADED = 0,
		CREATE_SKIN_LOADING = 1,
		CREATE_SKIN_LOADED = 2,
	};

	int Type;
	char InstanceIndex;
	char Initialized;
	char ForceLowRez;
	char loadedFE;
	VinylsAttrib::VinylFinish mVinylFinish;
	CARPART_LOD mMinLodLevel;
	CARPART_LOD mMaxLodLevel;
	CARPART_LOD mMinFELodLevel;
	CARPART_LOD mMaxFELodLevel;
	CARPART_LOD mMaxLicenseLodLevel;
	CARPART_LOD mMinTrafficDiffuseLodLevel;
	CARPART_LOD mMinShadowLodLevel;
	CARPART_LOD mMaxShadowLodLevel;
	CARPART_LOD mMaxExhaustLodLevel;
	CARPART_LOD mMaxTireLodLevel;
	CARPART_LOD mMaxBrakeLodLevel;
	CARPART_LOD mMaxSpoilerLodLevel;
	CARPART_LOD mMaxRoofScoopLodLevel;
	CARPART_LOD mMaxSeatLodLevel;
	CARPART_LOD mMinReflectionLodLevel;
	CARPART_LOD mMaxInteriorLodLevel;
	CARPART_LOD mMinInteriorLodLevel;
	unsigned int mCompositeSkinHash;
	unsigned int mCompositeWheelHash[2];
	DBCarPart mPartsTable[115];
	char mPartsEnabled[115];
	DBCarPart *PreviewPart;
	CarPaint mCustomPaints[12];
	bool mCustomPaintValid[12];
	eLightMaterial *partLightMaterials[19];
	int mMyCarLoaderHandle;
	CarRenderUsage mMyCarRenderUsage;
	uint8_t mSpecialLODBehavior;
	float mRideHeight;
	VinylLayerPartInfo mVinylLayers[20];
	DecalLayerPartInfo mDecalLayers[20];
	unsigned int mVinylMirrorBits;
	uint64_t mDecalMirrorBits;
	uint16_t mNumVinylLayers;
	uint16_t mNumDecalLayers;
	uint16_t mVinylEditLayer;
	uint16_t mDecalEditLayer;
	uint8_t mEditingVinyl;
	uint8_t mEditingDecal;
	uint16_t mFastVinyl;
	AutoSculpt mAutoSculpt;
	IAttachmentSystem *mAttachmentSystem;
	CreateSkinLoadState mCreateSkinLoadState;
	KIT_TYPE kitTypeInstalled;
	unsigned int kitNumInstalled;
	BluePrintType bluePrintType;
	Physics::Upgrades::Tuning PhysicsTuning[32];

	RideInfo() {
		((RideInfo*(__thiscall*)(RideInfo*))0x882F30)(this);
	}
	//~RideInfo() {
	//	((void(__thiscall*)(RideInfo*))0x872740)(this);
	//}

	static inline auto Init = (void(__thiscall*)(RideInfo*, int type, CarRenderUsage usage, int has_dash, int can_be_vertex_damaged, int force_low_rez, IAttachmentSystem *attachmentSystem))0x880E70;
	static inline auto SetStockParts = (void(__thiscall*)(RideInfo*))0x883870;
};
static_assert(sizeof(RideInfo) == 0x1920);