namespace Physics {
	enum ePerformanceType {
		PERFORMANCE_SIMPLE_TIME_0_TO_100_MPH = 0x0,
		PERFORMANCE_SIMPLE_TIME_0_TO_60_MPH = 0x1,
		PERFORMANCE_SIMPLE_TIME_70_TO_150_MPH = 0x2,
		PERFORMANCE_SIMPLE_TIME_100_TO_0_MPH = 0x3,
		PERFORMANCE_SIMPLE_TIME_60_TO_0_MPH = 0x4,
		PERFORMANCE_SIMPLE_DISTANCE_60_TO_0_MPH = 0x5,
		PERFORMANCE_SIMPLE_DISTANCE_100_TO_0_MPH = 0x6,
		PERFORMANCE_SIMPLE_TIME_QUARTER_MILE = 0x7,
		PERFORMANCE_SIMPLE_SPEED_QUARTER_MILE_MPH = 0x8,
		PERFORMANCE_SIMPLE_TIME_60_FEET = 0x9,
		PERFORMANCE_SIMPLE_TOPSPEED = 0xA,
		PERFORMANCE_SIMPLE_MAX_GS_30_MPH = 0xB,
		PERFORMANCE_SIMPLE_MAX_GS_60_MPH = 0xC,
		PERFORMANCE_SIMPLE_MAX_GS_100_MPH = 0xD,
		PERFORMANCE_SIMPLE_TIME_CORNER_200M_40M_300M = 0xE,
		PERFORMANCE_SIMPLE_DOWNFORCE = 0xF,
		PERFORMANCE_SIMPLE_DRAG = 0x10,
		PERFORMANCE_SIMPLE_FRONT_TOE_30_MPH = 0x11,
		PERFORMANCE_SIMPLE_FRONT_TOE_60_MPH = 0x12,
		PERFORMANCE_SIMPLE_FRONT_TOE_100_MPH = 0x13,
		PERFORMANCE_SIMPLE_CASTER = 0x14,
		PERFORMANCE_SIMPLE_FRONT_WEIGHT_BIAS = 0x15,
		PERFORMANCE_SIMPLE_EBRAKE = 0x16,
		PERFORMANCE_SIMPLE_STEERING_ALIGNMENT_TORQUE = 0x17,
		PERFORMANCE_SIMPLE_AERO_CG = 0x18,
		PERFORMANCE_SIMPLE_ROLL_CENTER = 0x19,
		PERFORMANCE_SIMPLE_SPRING_STIFFNESS = 0x1A,
		PERFORMANCE_SIMPLE_SWAYBAR_STIFFNESS = 0x1B,
		PERFORMANCE_SIMPLE_SHOCK_DIGRESSION = 0x1C,
		PERFORMANCE_SIMPLE_SHOCK_VALVING = 0x1D,
		PERFORMANCE_SIMPLE_HORSEPOWER = 0x1E,
		PERFORMANCE_SIMPLE_HORSEPOWERRPM = 0x1F,
		PERFORMANCE_SIMPLE_PEAKTORQUE = 0x20,
		PERFORMANCE_SIMPLE_PEAKTORQUERPM = 0x21,
		PERFORMANCE_SIMPLE_WEIGHT = 0x22,
		PERFORMANCE_SIMPLE_WEIGHT_TO_POWER_RATIO = 0x23,
		PERFORMANCE_COMPLEX_GRIP = 0x24,
		PERFORMANCE_COMPLEX_TOPSPEED = 0x25,
		PERFORMANCE_COMPLEX_ACCELERATION = 0x26,
		PERFORMANCE_COMPLEX_HANDLING = 0x27,
		PERFORMANCE_SIMPLE_START = 0x0,
		PERFORMANCE_SIMPLE_LAST = 0x23,
		NUMBER_PERFORMANCE_SIMPLE = 0x24,
		PERFORMANCE_COMPLEX_START = 0x24,
		PERFORMANCE_COMPLEX_LAST = 0x27,
		NUMBER_PERFORMANCE_COMPLEX = 0x4,
		PERFORMANCE_START = 0x0,
		PERFORMANCE_LAST = 0x27,
		NUMBER_PERFORMANCE = 0x28,
	};

	namespace Upgrades {
		class Tuning {
		public:
			float lowerBound;
			float upperBound;
			float position;
		};
	}

	namespace Info {
		class AbsolutePerformanceStats {
		public:
			float performanceTypeMap[40];
		};

		class PerformanceLevels {
		public:
			float performanceTypeMap[40];
		};

		class Performance {
		public:
			AbsolutePerformanceStats absolutePerformanceStats;
			PerformanceLevels performanceLevels;
			BluePrintType bluePrintType;
		};

		class CorrectedPerformance {
		public:
			AbsolutePerformanceStats absolutePerformanceStats;
			PerformanceLevels performanceLevels;
			Performance stockMeasuredPerformance;
			Performance highendMeasuredPerformance;
			BluePrintType bluePrintType;
			Performance stockFastPerformance;
			Performance highendFastPerformance;

			virtual void Compute(const Attrib::Instance*, const BluePrintType);
			virtual void Recompute(const Attrib::Instance*);
		};

		struct PerformanceMatching {
			ePerformanceType performanceType;
			bool isPerformanceLevel;
			float performanceValue;
		};

		class HAT {
		public:
			float Handling;
			float Acceleration;
			float TopSpeed;
		};
	}

	namespace Core {
		namespace Aerodynamics {
			struct State {
				UMath::Matrix4 bodyMatrix;
				UMath::Vector3 linearVelocity;
				UMath::Vector3 angularVelocity;
				UMath::Vector3 carLocalVelocity;
				UMath::Vector3 centerOfGravity;
				UMath::Vector3 carBodyDimension;
				float dragCoefficient;
				float draftingCoefficient;
				float draftedCoefficient;
				float aeroCG;
				float aeroCoefficient;
				float liftHeightRatio;
				float bodyRideHeightNoDownforce;
				float frontToRearHeightRatio;
				float aeroCoefficientMaxGroundEffect;
				float aeroCoefficientMaxLift;
				float aeroCoefficient90DegLoss;
				float gasInput;
				float carSpeed;
				float slipAngle;
				float minHeightAtRest;
				float bodyRideHeight;
				float groundEffect;
				float groundEffectHeightRatio;
				float deltaHeightSlope;
				float aeroFrontZ;
				float aeroRearZ;
				float liftTimer;
				float dT;
				float driver_style;
			};

			struct Result {
				UMath::Vector3 dragForce;
				UMath::Vector3 dragCenter;
				UMath::Vector3 windCenter;
				UMath::Vector3 downForce;
				UMath::Vector3 downCenter;
				UMath::Vector3 sideForce;
				UMath::Vector3 sideCenter;
				float liftTimer;
				UMath::Vector3 dragTorque;
			};
		}
	}

	class Tunings {
	public:
		float Value[7];
	};
}
static_assert(sizeof(Physics::Upgrades::Tuning) == 0xC);
static_assert(sizeof(Physics::Tunings) == 0x1C);