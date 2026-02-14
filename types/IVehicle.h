enum eVehicleList {
	VEHICLE_ALL = 0,
	VEHICLE_PLAYERS = 1,
	VEHICLE_AI = 2,
	VEHICLE_AIRACERS = 3,
	VEHICLE_AICOPS = 4,
	VEHICLE_AITRAFFIC = 5,
	VEHICLE_RACERS = 6,
	VEHICLE_REMOTE = 7,
	VEHICLE_INACTIVE = 8,
	VEHICLE_TRAILERS = 9,
	VEHICLE_ACTIVERACERS = 10,
	VEHICLE_GHOST = 11,
	VEHICLE_MAX = 12,
};

enum DriverStyle {
	STYLE_RACING = 0,
	STYLE_DRAG = 1,
	STYLE_DRIFT = 2,
	STYLE_HIGH_SPEED = 3,
	STYLE_TRAFFIC = 4,
};

enum PhysicsMode {
	PHYSICS_MODE_INACTIVE = 0,
	PHYSICS_MODE_SIMULATED = 1,
	PHYSICS_MODE_ONLINE_INTERPROLATED = 2,
	PHYSICS_MODE_SIMPLE = 3,
};

enum DriverClass {
	DRIVER_HUMAN = 0,
	DRIVER_TRAFFIC = 1,
	DRIVER_COP = 2,
	DRIVER_RACER = 3,
	DRIVER_NONE = 4,
	DRIVER_NIS = 5,
	DRIVER_REMOTE = 6,
	DRIVER_REMOTE_RACER = 7,
	DRIVER_GHOST = 8,
	DRIVER_MAX = 9,
};

enum AIDriverSubclass {
	AIDRIVER_INVALID = -1,
	AIDRIVER_RACER = 0,
	AIDRIVER_ALLY = 1,
	AIDRIVER_THUG = 2,
	AIDRIVER_BOSS = 3,
	AIDRIVER_MAX = 4,
};

typedef int CarType;

namespace VehicleFX {
	enum ID {
		LIGHT_NONE = 0x0,
		LIGHT_LHEAD = 0x1,
		LIGHT_RHEAD = 0x2,
		LIGHT_CHEAD = 0x4,
		LIGHT_LBRAKE = 0x8,
		LIGHT_RBRAKE = 0x10,
		LIGHT_CBRAKE = 0x20,
		LIGHT_LREVERSE = 0x40,
		LIGHT_RREVERSE = 0x80,
		LIGHT_LRSIGNAL = 0x100,
		LIGHT_RRSIGNAL = 0x200,
		LIGHT_LFSIGNAL = 0x400,
		LIGHT_RFSIGNAL = 0x800,
		LIGHT_COPRED = 0x1000,
		LIGHT_COPBLUE = 0x2000,
		LIGHT_COPWHITE = 0x4000,
		LIGHT_COPORANGE = 0x8000,
		LIGHT_COPS = 0xF000,
		LIGHT_LSIGNAL = 0x500,
		LIGHT_RSIGNAL = 0xA00,
		LIGHT_HAZARDS = 0xF00,
		LIGHT_HEADLIGHTS = 0x7,
		LIGHT_REVERSE = 0xC0,
		LIGHT_BRAKELIGHTS = 0x38,
	};

	enum WindowFXID {
		WINDOW_NONE = 0x0,
		WINDOW_FRONT = 0x1,
		WINDOW_LEFT_FRONT = 0x2,
		WINDOW_LEFT_REAR = 0x4,
		WINDOW_RIGHT_FRONT = 0x8,
		WINDOW_RIGHT_REAR = 0x10,
		WINDOW_REAR = 0x20,
	};
}

enum DriverAidType {
	TRACTION_CONTROL = 0x0,
	ANTI_BRAKE_LOCK = 0x1,
	STABILITY_MANAGEMENT = 0x2,
	DRIFT_STEERING_ASSIST = 0x3,
	DRIFT_GLUE_TO_ROAD = 0x4,
	DRIFT_DYNAMIC_BRAKE = 0x5,
	DRIFT_SPEED_CONTROL = 0x6,
	RACELINE_ASSIST = 0x7,
	BRAKING_ASSIST = 0x8,
	DRIVER_AID_FIRST = 0x0,
	DRIVER_AID_LAST = 0x8,
	DRIVER_AID_NUMBER = 0x9,
};

class IVehicleAI;

namespace EventSequencer {
	class System;
}

namespace EventSys {
	class DynamicData;
}

class IVehicle : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x402990;

	virtual ISimable *GetSimable();
	virtual const ISimable *_GetSimable();
	virtual const UMath::Vector3 *GetPosition();
	virtual void SetBehaviorOverride(UCrc32, UCrc32);
	virtual void RemoveBehaviorOverride(UCrc32);
	virtual void CommitBehaviorOverrides();
	virtual void ReleaseBehaviorAudio();
	virtual void SetStaging(bool);
	virtual bool IsStaging();
	virtual void Launch();
	virtual float GetPerfectLaunch();
	virtual void SetDriverStyle(DriverStyle);
	virtual DriverStyle GetDriverStyle();
	virtual void SetPhysicsMode(PhysicsMode);
	virtual PhysicsMode GetPhysicsMode();
	virtual void SetDraftZoneModifier(float);
	virtual float GetDraftZoneModifier();
	virtual int GetModelType();
	virtual const WWorldPos *_GetWPos();
	virtual WWorldPos *GetWPos();
	virtual bool IsSpooled();
	virtual bool IsLowRez();
	virtual bool IsPhysicsOnly();
	virtual const UCrc32 *GetVehicleClass();
	virtual const Attrib::Instance *GetVehicleAttributes();
	virtual const char *GetVehicleName();
	virtual unsigned int GetVehicleKey();
	virtual unsigned int GetPresetKey();
	virtual unsigned int GetStockVehicleKey();
	virtual void SetDriverClass(DriverClass);
	virtual DriverClass GetDriverClass();
	virtual void SetAIDriverSubclass(AIDriverSubclass);
	virtual AIDriverSubclass GetAIDriverSubclass();
	virtual bool IsLoading();
	virtual float GetOffscreenTime();
	virtual float GetOnScreenTime();
	virtual bool SetVehicleOnGround(const UMath::Vector3 *, const UMath::Vector3 *, bool);
	virtual void ForceStopOn(char);
	virtual void ForceStopOff(char);
	virtual char GetForceStop();
	virtual bool InShock();
	virtual bool IsDestroyed();
	virtual void Activate();
	virtual void Deactivate();
	virtual bool IsActive();
	virtual float GetSpeedometer();
	virtual float GetSpeed();
	virtual void SetSpeed(float);
	virtual void SetVelocity(float, float, float);
	virtual float GetAbsoluteSpeed();
	virtual bool IsGlareOn(VehicleFX::ID);
	virtual void GlareOn(VehicleFX::ID);
	virtual void GlareOff(VehicleFX::ID);
	virtual bool IsCollidingWithSoftBarrier();
	virtual IVehicleAI *GetAIVehiclePtr();
	virtual float GetSlipAngle();
	virtual const UMath::Vector3 *GetLocalVelocity();
	virtual void ComputeHeading(UMath::Vector3 *);
	virtual bool IsAnimating();
	virtual void SetAnimating(bool);
	virtual bool IsOffWorld();
	virtual void SignalTeleportToRemoteMachines();
	virtual const VehicleCustomizations *GetCustomizations();
	virtual void SetCustomizations(const VehicleCustomizations *);
	virtual const Physics::Tunings *GetTunings();
	virtual void SetTunings(const Physics::Tunings *);
	virtual bool GetPerformance(Physics::Info::HAT *);
	virtual bool GetPerformance(Physics::Info::CorrectedPerformance *);
	virtual const char *GetCacheName();
	virtual bool GetDynamicData(const EventSequencer::System *, EventSys::DynamicData *);
	virtual bool IsDriverAidOn(DriverAidType);
	virtual void SetDriverAidLevel(DriverAidType, int);
	virtual int GetDriverAidLevel(DriverAidType);
	virtual int GetDriverAidMaxLevel(DriverAidType);
	virtual void DisableDriverAidTemporarilyAll();
	virtual void DisableDriverAidTemporarily(DriverAidType);
	virtual void ReenableDriverAidAll();
	virtual void ReenableDriverAid(DriverAidType);
	virtual ISimable *SpawnPart(UCrc32, UCrc32, UCrc32);
	virtual void HidePart(UCrc32);
	virtual void ResetPart(UCrc32);
	virtual void FlashHeadlights(unsigned int);
	virtual bool CanFlashHeadlights();
};

//#define VEHICLE_LIST UTL::ListableSet<IVehicle, 12, eVehicleList, VEHICLE_MAX, 0xACE100>
//static_assert(sizeof(VEHICLE_LIST::_buckets[0]) == 0x40);