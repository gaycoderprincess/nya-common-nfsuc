enum GearID {
	G_REVERSE = 0,
	G_NEUTRAL = 1,
	G_FIRST = 2,
	G_SECOND = 3,
	G_THIRD = 4,
	G_FOURTH = 5,
	G_FIFTH = 6,
	G_SIXTH = 7,
	G_SEVENTH = 8,
	G_EIGHTH = 9,
	G_MAX = 10,
};

enum ShiftStatus {
	SHIFT_STATUS_NONE = 0,
	SHIFT_STATUS_NORMAL = 1,
	SHIFT_STATUS_GOOD = 2,
	SHIFT_STATUS_PERFECT = 3,
	SHIFT_STATUS_MISSED = 4,
};

enum ShiftPotential {
	SHIFT_POTENTIAL_NONE = 0,
	SHIFT_POTENTIAL_DOWN = 1,
	SHIFT_POTENTIAL_UP = 2,
	SHIFT_POTENTIAL_GOOD = 3,
	SHIFT_POTENTIAL_PERFECT = 4,
	SHIFT_POTENTIAL_MISS = 5,
};

enum ClutchState {
	CLUTCH_STATE_ENGAGED = 0,
	CLUTCH_STATE_DISENGAGED = 1,
	CLUTCH_STATE_UPSHIFT = 2,
	CLUTCH_STATE_DOWNSHIFT = 3,
	CLUTCH_STATE_TOTAL = 4,
};

enum eTransmissionOverride {
	OVERRIDE_NONE = 0,
	OVERRIDE_MANUAL = 1,
	OVERRIDE_MANUAL_CLUTCH = 2,
	OVERRIDE_AUTOMATIC = 3,
};

class ITransmission : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x401C60;

	virtual GearID GetGear();
	virtual GearID GetTopGear();
	virtual bool Shift(GearID gear, bool forceOnRemote = false);
	virtual bool IsClutchEngaged();
	virtual bool IsGearChanging();
	virtual bool IsReversing();
	virtual float GetSpeedometer();
	virtual float GetMaxSpeedometer();
	virtual float GetDriveTorqueAtEngine();
	virtual float GetDriveTorque();
	virtual float GetEngineBrakingTorque();
	virtual float GetShiftPoint(GearID, GearID);
	virtual ShiftStatus GetShiftStatus();
	virtual ShiftPotential GetShiftPotential();
	virtual bool DoClutchKick(float);
	virtual float GetTorqueSplit();
	virtual float GetTotalShiftTime();
	virtual ClutchState GetClutchState();
	virtual float GetTimeUntilTransition();
	virtual float GetClutchPosition();
	virtual float GetClutchGrind();
	virtual void SetTransmissionOverride(eTransmissionOverride);
	virtual eTransmissionOverride GetTransmissionOverride();
	virtual float GetPerfectLaunchError();
};