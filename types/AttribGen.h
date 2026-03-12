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

enum KIT_TYPE {
	KIT_TYPE_BASE = 0,
	KIT_TYPE_STOCK = 1,
	KIT_TYPE_AUTOSCULPT = 2,
	KIT_TYPE_WIDEBODY = 3,
	NUM_KIT_TYPE = 4,
};

namespace Math {
	static inline auto splint = (float(*)(float xx, float xMin, float xMax, float yMin, float yMax, float *X, float *Y, float *Y2, int numberOfElements))0x6A3060;
}

class VariableArray {
public:
	float *mArray;
	unsigned int mLength;
};

class Curve {
public:
	float xMin;
	float xMax;
	float yMin;
	float yMax;
	float graphScale;
	VariableArray X;
	VariableArray Y;
	VariableArray Y2;
	bool allocatedMemory;

	auto GetValue(float xx) {
		auto f = (float(__thiscall*)(Curve*, float xx))0x706380;
		return f(this, xx);
	}
	auto GetValueLinear(float xx) {
		auto f = (float(__thiscall*)(Curve*, float xx))0x7064A0;
		return f(this, xx);
	}
};

class AxlePair {
public:
	float Front;
	float Rear;

	float At(int index) const {
		return (&Front)[index];
	}
};

class AxlePairCurve {
public:
	Curve Front;
	Curve Rear;

	Curve At(int index) const {
		return (&Front)[index];
	}
};

enum eDecalType {
	DECAL_TYPE_NONE = -1,
	DECAL_TYPE_SKID_CONCRETE = 0,
	DECAL_TYPE_SKID_DIRT = 1,
	DECAL_TYPE_SKID_GRASS = 2,
	DECAL_TYPE_SKID_SAND = 3,
	DECAL_TYPE_SCRAPE_METAL = 4,
	DECAL_TYPE_SCRAPE_PLASTIC = 5,
	DECAL_TYPE_SCRAPE_WOOD = 6,
	DECAL_TYPE_SCRAPE_CONCRETE = 7,
};

enum SCRAPE_SURFACES {
	SCRAPE_NONE = 0,
	SCRAPE_CONCRETE = 1,
	SCRAPE_METAL = 2,
	SCRAPE_RUBBER = 3,
	SCRAPE_OFFROAD = 4,
	MAX_SCRAPES = 5,
};

enum SURFACE_SFX {
	SURFACE_SFX_NONE = 0,
	SURFACE_SFX_LIGHT_CRACK = 1,
	SURFACE_SFX_TAR_STRIP = 3,
	SURFACE_SFX_ROADSIDE_PATCH = 5,
	SURFACE_SFX_HEAVY_PATCH = 6,
	SURFACE_SFX_DIRT = 7,
	MAX_SURFACE_SFX = 8,
};

enum TireCondition {
	kGrip = 0,
	kWet = 1,
	kFlat = 2,
	kDrift = 3,
	kDrag = 4,
};

class TireEffectRecord {
public:
	TireCondition mTireCondition;
	Attrib::RefSpec mEmitter;
	Attrib::RefSpec mEmitterLowLod;
	float mMinSpeed;
	float mMaxSpeed;
};

class RoadNoiseRecord {
public:
	float Frequency;
	float Amplitude;
	float MinSpeed;
	float MaxSpeed;
};

namespace Attrib {
	namespace Gen {
		class presetride : public Attrib::Instance {
		public:
			struct _LayoutStruct {
				const char *PresetName;
				const char *CollectionName;
				float RideHeight;
				type_bStringHash PresetCar;
				eLiveryID Livery;
				KIT_TYPE KitType;
				unsigned int KitNumber;
				BluePrintType BluePrint;
				uint8_t Tier;
			};

			presetride(uint32_t collectionKey, uint32_t msgPort) {
				((presetride*(__thiscall*)(presetride*, uint32_t, uint32_t))0x410720)(this, collectionKey, msgPort);
			}
			~presetride() {
				((void(__thiscall*)(presetride*))0x468820)(this);
			}

			_LayoutStruct* GetLayout() const {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class pvehicle : public Attrib::Instance {
		public:
			struct _LayoutStruct {
				Attrib::StringKey MODEL;
				Attrib::RefSpec frontend;
				const char *DefaultPresetRide;
				const char *CollectionName;
				bool RandomOpponent;
				GRace::Tier RacingTier;
				bool isRateable;
			};

			pvehicle(uint32_t collectionKey, uint32_t msgPort) {
				((pvehicle*(__thiscall*)(pvehicle*, uint32_t, uint32_t))0x4574E0)(this, collectionKey, msgPort);
			}
			~pvehicle() {
				((void(__thiscall*)(pvehicle*))0x468820)(this);
			}

			_LayoutStruct* GetLayout() const {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class car_tuning : public Attrib::Instance {
		public:
			struct _LayoutStruct {
				UMath::Vector4 TENSOR_SCALE;
				AxlePairCurve Toe;
				AxlePairCurve SWAYBAR_STIFFNESS;
				AxlePairCurve STATIC_GRIP;
				AxlePairCurve SHOCK_STIFFNESS;
				AxlePairCurve SHOCK_EXT_STIFFNESS;
				AxlePairCurve Mu0;
				AxlePairCurve Kmu;
				AxlePairCurve CSvsFZ;
				AxlePairCurve CAMBER_LEFT;
				AxlePairCurve C2;
				AxlePairCurve BRAKES;
				AxlePairCurve A1;
				Curve YAW_CONTROL;
				Curve UPSHIFT_THROTTLE;
				Curve UPSHIFT_CLUTCH;
				Curve TORQUE;
				Curve THROTTLE_CONTROL_CURVE;
				Curve STEERING_SPEED;
				Curve STEERING_RANGE;
				Curve STEERING_ALIGNING_TORQUE;
				Curve STEERING;
				Curve ROLL_CENTER;
				Curve EBRAKE;
				Curve DRIFT_EXTRA_THROTTLE_VELOCITY;
				Curve DRIFT_ANGLE_CURVE;
				Curve DOWNSHIFT_THROTTLE;
				Curve DOWNSHIFT_CLUTCH;
				Curve COUNTER_STEER_STRENGTH_MIN;
				Curve COUNTER_STEER_STRENGTH_MED;
				Curve COUNTER_STEER_STRENGTH_MAX;
				Curve COUNTER_STEER_RANGE_THROTTLE_EFFECT;
				Curve CLUTCH_KICK_TORQUE_MULT;
				Curve CLUTCH_KICK_ENGAGE_TIMER;
				Curve CASTER;
				Curve AERO_COEFFICIENT;
				Curve AERO_CG;
				Attrib::RefSpec FORCED_INDUCTION;
				Attrib::RefSpec DRAG_SHIFT_ERROR;
				const char *CollectionName;
				Attrib::Private _Array_SPEED_LIMITER;
				float SPEED_LIMITER[2];
				Attrib::Private _Array_REVERSE_SPEED_LIMITER;
				float REVERSE_SPEED_LIMITER[2];
				Attrib::Private _Array_LONG_FORCE_SCALE;
				float LONG_FORCE_SCALE[10];
				Attrib::Private _Array_GEAR_RATIO;
				float GEAR_RATIO[12];
				Attrib::Private _Array_GEAR_EFFICIENCY;
				float GEAR_EFFICIENCY[10];
				Attrib::Private _Array_ENGINE_BRAKING;
				float ENGINE_BRAKING[3];
				Attrib::Private _Array_DIFFERENTIAL;
				float DIFFERENTIAL[3];
				AxlePair TRAVEL;
				AxlePair TRACK_WIDTH;
				AxlePair SPRING_STIFFNESS;
				AxlePair SPRING_PROGRESSION;
				AxlePair SHOCK_VALVING;
				AxlePair SHOCK_DIGRESSION;
				AxlePair SECTION_WIDTH;
				AxlePair RIM_SIZE;
				AxlePair RIDE_HEIGHT;
				AxlePair GRIP_SCALE;
				AxlePair DYNAMIC_GRIP;
				AxlePair DRIFT_KMU_MULTIPLIER;
				AxlePair BRAKE_LOCK;
				AxlePair ASPECT_RATIO;
				float YAW_CONTROL_ANGLE;
				float WHEEL_BASE;
				float VACUUM;
				float TORQUE_SPLIT;
				float TORQUE_SLIP_SLOPE0;
				float TORQUE_CONVERTER;
				float TORQUE_BOOST;
				float TANK_SLAPPER_TIMER;
				float STATIC_GRIP_OFFTHROTTLE;
				float SQUAT_SPEED;
				float SPOOL_TIME_UP;
				float SPOOL_TIME_DOWN;
				float SPOOL;
				float SLOTCAR_PIN_FORWARDOFFSET;
				float SLOT_CHANGE_SPEED;
				bool SLOT_CAR;
				float SLIP_TO_GRIP_TIME;
				float SLIP_TO_GRIP_STRENGTH;
				float SHOCK_BLOWOUT;
				float SHIFT_SPEED;
				float ROLL_SPEED;
				float REVERSE_TORQUE_MULTIPLIER;
				float REVERSE_STEERING_SPEED_MULT;
				float RENDER_MOTION;
				float RED_LINE;
				float PSI;
				float OUT_OF_GRIP_ANGLE;
				float OPTIMAL_SHIFT;
				float NOS_GRIP_INCREASE;
				float NOS_CAPACITY;
				float MIN_TIRE_TRACTION_TO_SHIFT_UP_FIRST_GEAR;
				float MIN_TIRE_TRACTION_TO_SHIFT_UP;
				float MAX_RPM;
				float MASS;
				float LOW_BOOST;
				float LIFT_HEIGHT_RATIO;
				float LATERALSLIDEFACTOR;
				float IDLE;
				float HIGH_BOOST;
				float GROUNDEFFECT_HEIGHT_RATIO;
				float FRONT_AXLE;
				float FLYWHEEL_MASS_NEUTRAL_MULT;
				float FLYWHEEL_MASS;
				float FLOW_RATE;
				float FINAL_GEAR;
				float EXTRA_FISHTAIL_TORQUE;
				float ENGINE_SHIFT_DOWN_DYNAMIC_FACTOR;
				float ENGINE_REDLINE_TORQUE_MULT;
				float ENGINE_BRAKING_NEUTRAL;
				float ENGINE_ANTIBOG_RAMP_TIME;
				float ENGINE_ANTIBOG_MAX_MULT;
				float DRIVESHAFT_TORQUE_MAX;
				float DRIVESHAFT_TORQUE_EFFECT;
				float DRIFT_FORWARD_FORCE;
				float DRIFT_EXTRA_THROTTLE_VELOCITY_MAX;
				float DRIFT_EBRAKE_GRIP_SCALE;
				float DRAG_COEFFICIENT;
				float DIVE_SPEED;
				float CTRL_SlideSidewayLevel;
				float CTRL_ExtraBrakingLevel;
				float COUNTER_STEER_MIN_ANGLE;
				float CLUTCH_SLIP;
				float BACK_IN_GRIP_ANGLE;
				float AERO_COEFFICIENT_OFFTHROTTLE;
				float AERO_COEFFICIENT_MAX_LIFT;
				float AERO_COEFFICIENT_MAX_GROUND_EFFECT;
				float AERO_COEFFICIENT_90_DEG_LOSS;
			};

			car_tuning(uint32_t collectionKey, uint32_t msgPort) {
				((car_tuning*(__thiscall*)(car_tuning*, uint32_t, uint32_t))0x4574E0)(this, collectionKey, msgPort);
			}
			car_tuning() {
				((car_tuning * (__thiscall*)(car_tuning*, uint32_t, uint32_t))0x4574E0)(this, 0, 0);
			}
			~car_tuning() {
				((void(__thiscall*)(car_tuning*))0x468820)(this);
			}

			_LayoutStruct* GetLayout() const {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class simsurface : public Attrib::Instance {
		public:
			struct _LayoutStruct {
				Attrib::Private _Array_TireSlipEffects;
				TireEffectRecord TireSlipEffects[5];
				const char *CollectionName;
				RoadNoiseRecord RenderNoise;
				float WORLD_FRICTION;
				SURFACE_SFX SurfaceFX_ID;
				float STICK;
				SCRAPE_SURFACES ScrapeFX_ID;
				float ROLLING_RESISTANCE;
				float LATERAL_GRIP;
				float GROUND_FRICTION;
				float DRIVE_GRIP;
				eDecalType Decal;
				uint16_t WheelEffectFrequency;
				uint8_t WheelEffectIntensity;
			};

			simsurface() {}
			simsurface(const Attrib::Collection *collection, uint32_t msgPort) {
				((simsurface*(__thiscall*)(simsurface*, const Attrib::Collection*, uint32_t))0x75F9E0)(this, collection, msgPort);
			}
			~simsurface() {
				((void(__thiscall*)(simsurface*))0x468820)(this);
			}

			_LayoutStruct* GetLayout() const {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};
	}
}