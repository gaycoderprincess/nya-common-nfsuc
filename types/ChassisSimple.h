class IDrafter : public UCOM::IUnknown {};
class IAttributeable : public UCOM::IUnknown {};
class INISCarControl : public UCOM::IUnknown {};
class IChassis : public UCOM::IUnknown {};
class ICollisionBody;
class IEngineDamage;
class ISpikeable;
struct Wind;
namespace Sim {
	namespace Collision {
		class IListener : public UCOM::IUnknown {};
	}
}

template<typename T>
class AttributeStructPtr : public T {};

template<typename T>
class BehaviorSpecsPtr : public AttributeStructPtr<T> {};

class Cone {
public:
	UMath::Vector3 center;
	float radius;
	float angle;
	UMath::Vector3 direction;
	UMath::Vector3 left;
	float mOffsetOfConeCenter;
	float mSideSoftWallWidth;
	float mInclanationSideSoftWall;
	float mBottomSoftWallWidth;
	float mInclanationBottomSoftWall;
	float mBufferZoneWidth;
	float mInclanationBufferZone;
	float mInclanationDraftingZone;
};

class DraftZone {
public:
	Cone mDraftCone;
	Cone mStableCone;
	float mOffsetOfDraftCone;
	float mOffsetOfStableCone;
};

struct SituationInDraftZone {
	bool inDraftZone;
	bool isRight;
	float simTimeEnteredDraftZone;
	float timeInDraftZone;
	HSIMABLE leadDrafter;
	float draftValue;
	float distanceToDraftZone;
	float leadDrafterSpeed;
	float alignmentAngle;
	float normalizedDistanceToCenter;
};

class PhysicsObject;
class Behavior {
public:
	uint8_t _4[0x20];
	bool mPaused;
	PhysicsObject *mOwner;
	ISimable *mIOwner;
	UCrc32 mMechanic;
	UCrc32 mSignature;
	int mPriority;
	HSIMPROFILE mProfile;

	virtual void _vt0();
};
static_assert(offsetof(Behavior, mPriority) == 0x38);

class VehicleBehavior : public Behavior {
public:
	IVehicle* mVehicle;
};
static_assert(offsetof(VehicleBehavior, mVehicle) == 0x40);

class Chassis : public VehicleBehavior, IChassis {
public:
	struct State {
		UMath::Matrix4 matrix;
		UMath::Vector3 local_vel;
		float gas_input;
		UMath::Vector3 linear_vel;
		float brake_input;
		UMath::Vector3 angular_vel;
		float ground_effect;
		UMath::Vector3 cog;
		float ebrake_input;
		UMath::Vector3 dimension;
		float steer_input;
		float hydraulic_heights[4];
		UMath::Vector3 local_angular_vel;
		float slipangle;
		UMath::Vector3 inertia;
		float mass;
		UMath::Vector3 world_cog;
		float speed;
		float time;
		int flags;
		int16_t driver_style;
		int16_t driver_class;
		int16_t gear;
		int16_t blown_tires;
		bool nos_engaged;
		bool nos_moment;
		float nos_boost;
		float shift_boost;
		float torque_split;
		float clutch_engaged;
		float drive_torque;
		float engine_braking_torque;
		float drafting_coefficient;
		float esc_wheel_brakes_on[4];
		float esc_wheel_torque_on[4];
		int abs_level;
		float perfect_launch_error;
		const WCollider *collider;
		float over_steer_input;
		bool is_articulated;
	};

	IRigidBody *mRB;
	ICollisionBody *mCollisionBody;
	IInput *mInput;
	IEngine *mEngine;
	ITransmission *mTransmission;
	IEngineDamage *mEngineDamage;
	ISpikeable *mSpikeDamage;
	BehaviorSpecsPtr<Attrib::Gen::car_tuning> mAttributes;
	float mJumpTime;
	float mJumpAlititude;
	bool mPredictedJumpLand;
	UMath::Vector3 mPredictedJumpLandNormal;
	UMath::Vector3 mvecAngularLastFrame;
	bool mbGroundCollisionLastFrame;
	float mTireHeat;
	float mTimeFromLanding;
	float mLastJumpTime;
	int mABSLevel;
	int mABSMaxLevel;
	Wind *mWind;
	float mOffThrottleTimer;
	float mCopProximityAeroMultiplier;
	Physics::Core::Aerodynamics::State mAeroState;
	Physics::Core::Aerodynamics::Result mAeroResult;
	bool mDontSendToRigidBody;
	Chassis::State mState;
	float mSleepTimer;
	bool mShocksDecompressed;
};
static_assert(offsetof(Chassis, mInput) == 0x54);
static_assert(offsetof(Chassis, mAeroState) == 0xC0);
static_assert(offsetof(Chassis, mAeroResult) == 0x19C);
static_assert(offsetof(Chassis, mVehicle) == 0x40);

class SimSurface : public Attrib::Instance {};
class Wheel {
public:
	WWorldPos mWorldPos;
	UMath::Vector3 mNormal;
	float mHeightAboveRoad;
	UMath::Vector3 mPosition;
	unsigned int mFlags;
	UMath::Vector3 mForce;
	float mAirTime;
	UMath::Vector3 mLocalArm;
	float mCompression;
	UMath::Vector3 mWorldArm;
	int pad1;
	UMath::Vector3 mVelocity;
	int pad2;
	SimSurface mSurface;
	float mSurfaceStick;
	UMath::Vector4 mIntegral;
};

class ChassisSimple : public Chassis, Sim::Collision::IListener, IAttributeable, INISCarControl {
public:
	class DraftControl;

	class Tire : public Wheel {
		float mRadius;
		float mBrake;
		float mEBrake;
		float mAV;
		float mLoad;
		float mLateralForce;
		float mLongitudeForce;
		float mAppliedTorque;
		float mTractionBoost;
		float mSlip;
		float mLateralSpeed;
		int mWheelIndex;
		float mRoadSpeed;
		const Attrib::Gen::car_tuning *mVehicleInfo;
		float mSlipAngle;
		int mAxleIndex;
		float mTraction;
		bool mBrakeLocked;
		bool mAllowSlip;
		float mLastTorque;
		float mAngularAcc;
		float mMaxSlip;
		float mGripBoost;
		float mTotalBrakeTorque;
		float mIdealTorque;
		float mTorqueRatio;
		float mNISBurnout;
	};

	DraftControl *mDraftControl;
	BehaviorSpecsPtr<Attrib::Gen::car_tuning> mVehicleInfo;
	IInput *mInput;
	IVehicleAI *mAI;
	float mFrictionBoost;
	float mDraft;
	bool mPowerSliding;
	float mWheelSteer[2];
	float mYawControlMultiplier;
	unsigned int mNumWheelsOnGround;
	float mAgainstWall;
	float mMaxSteering;
	float mTimeInAir;
	float mSleepTime;
	bool mDriftPhysics;
	float mBurnout;
	bool mNISBrakeLockFront;
	bool mNISBrakeLockRear;
	float mNISSteerAngle;
	float mNISSteerWeight;
	Tire *mTires[4];
	DraftZone mDraftZone;

	static inline auto DoSteering = (void(__thiscall*)(ChassisSimple*, Chassis::State *state, UMath::Vector3 *right, UMath::Vector3 *left))0x6FDE60;
	static inline auto DoDriveForces = (void(__thiscall*)(ChassisSimple*, Chassis::State *state))0x713650;
	static inline auto ComputeState = (void(__thiscall*)(ChassisSimple*, float dT, Chassis::State *state))0x726D00;
};
static_assert(offsetof(ChassisSimple, mAeroState) == 0xC0);
static_assert(offsetof(ChassisSimple, mAeroResult) == 0x19C);
static_assert(offsetof(ChassisSimple, mVehicleInfo) == 0x35C);
static_assert(offsetof(ChassisSimple, mInput) == 0x36C);
static_assert(offsetof(ChassisSimple, mMaxSteering) == 0x394);