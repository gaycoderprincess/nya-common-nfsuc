enum eInvulnerablitiy {
	INVULNERABLE_NONE = 0,
	INVULNERABLE_FROM_MANUAL_RESET = 1,
	INVULNERABLE_FROM_RESET = 2,
	INVULNERABLE_FROM_CONTROL_SWITCH = 3,
	INVULNERABLE_FROM_PHYSICS_SWITCH = 4,
	INVULNERABLE_FROM_RACE_EXIT = 5,
};

class IRBVehicle : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x405330;

	virtual void SetCollisionMass(float);
	virtual void SetCollisionCOG(const UMath::Vector3 *);
	virtual void EnableObjectCollisions(bool);
	virtual bool AreObjectCollisionsEnabled();
	virtual void SetInvulnerability(eInvulnerablitiy, float);
	virtual eInvulnerablitiy GetInvulnerability();
	virtual void SetReactions(DriverClass, const Attrib::Instance *);
	virtual const Attrib::Instance *GetReactions(DriverClass);
	virtual void ApplyAnyOnlineVelocityAdjustment();
	virtual void SetLinearVelocityAdustmentThisFrame(const UMath::Vector3 *);
	virtual void SetAngularVelocityAdustmentThisFrame(const float);
	virtual UMath::Vector3 *GetLinearVelocityAdustmentThisFrame(UMath::Vector3 *result);
	virtual void ToggleSpeedBreakerImmunity(bool);
	virtual bool HasSpeedBreakerImmunity();
};