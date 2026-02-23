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

	static inline auto GetValue = (float(__thiscall*)(Curve*, float xx))0x706380;
	static inline auto GetValueLinear = (float(__thiscall*)(Curve*, float xx))0x7064A0;
};

class AxlePair {
public:
	float Front;
	float Rear;
};

class AxlePairCurve {
public:
	Curve Front;
	Curve Rear;
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

			_LayoutStruct* GetLayout() {
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

			_LayoutStruct* GetLayout() {
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
			~car_tuning() {
				((void(__thiscall*)(car_tuning*))0x468820)(this);
			}

			_LayoutStruct* GetLayout() {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};
	}
}