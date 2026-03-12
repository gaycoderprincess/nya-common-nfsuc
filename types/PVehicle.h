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
	uint8_t _0[0x144];
	DriverClass mDriverClass;

	static inline auto Construct = (ISimable*(__cdecl*)(Sim::Param params))0x6F7260;

	auto LookupBehaviorSignature(UCrc32 *result, const Attrib::StringKey *mechanic) {
		auto f = (UCrc32*(__thiscall*)(PVehicle*, UCrc32 *result, const Attrib::StringKey *mechanic))0x6E0130;
		return f(this, result, mechanic);
	}
};
static_assert(offsetof(PVehicle, mDriverClass) == 0x144);

inline auto& BEHAVIOR_MECHANIC_AI = *(Attrib::StringKey*)0xDE7094;
inline auto& BEHAVIOR_MECHANIC_AUDIO = *(Attrib::StringKey*)0xDE6FD4;
inline auto& BEHAVIOR_MECHANIC_DAMAGE = *(Attrib::StringKey*)0xDE710C;
inline auto& BEHAVIOR_MECHANIC_DRAW = *(Attrib::StringKey*)0xDE6FDC;
inline auto& BEHAVIOR_MECHANIC_EFFECTS = *(Attrib::StringKey*)0xDE7060;
inline auto& BEHAVIOR_MECHANIC_ENGINE = *(Attrib::StringKey*)0xDE6F3C;
inline auto& BEHAVIOR_MECHANIC_INPUT = *(Attrib::StringKey*)0xDE6ED0;
inline auto& BEHAVIOR_MECHANIC_RESET = *(Attrib::StringKey*)0xDE7078;
inline auto& BEHAVIOR_MECHANIC_RIGIDBODY = *(Attrib::StringKey*)0xDE7070;
inline auto& BEHAVIOR_MECHANIC_STYLEMAN = *(Attrib::StringKey*)0xDE6F44;
inline auto& BEHAVIOR_MECHANIC_SUSPENSION = *(Attrib::StringKey*)0xDE7124;