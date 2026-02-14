namespace Sim {
	class Param {
	public:
		UCrc32 mType;
		const Sim::Param* mSource;
		unsigned int pad;
		unsigned int pad1;
	};
}

class IVehicleCache;
class RideInfo;

class VehicleResource {
public:
	unsigned int mBudget;
	unsigned int mFlags;
	int mCarType;
};

class VehicleParams : public Sim::Param {
public:
	unsigned int mErrorFlags;
	unsigned int mCreateFlags;
	DriverClass mDriverClass;
	IVehicleCache *mVehicleCache;
	unsigned int mSkinKey;
	unsigned int mPresetKey;
	unsigned int mVehicleKey;
	Attrib::Instance mVehicleAttrib;
	BluePrintType mBlueprintType;
	VehicleResource mVehicleResource;
	UMath::Vector3 mPosition;
	UMath::Vector3 mDirection;
	RideInfo *mRideInfo;
	VehicleCustomizations *mCustomization;
	const Physics::Info::Performance *mPerformanceMatch;
	VehicleParams *mSelf;

	VehicleParams() {
		mType.mCRC = Attrib::StringHash32("VehicleParams");
		mSource = this;
	}
};
static_assert(sizeof(VehicleParams) == 0x74);
static_assert(offsetof(VehicleParams, mSelf) == 0x70);

class PVehicle {
public:
	static inline auto Construct = (ISimable*(__cdecl*)(Sim::Param params))0x6F7260;
};