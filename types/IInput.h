class IInput : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x401CA0;

	virtual void ClearInput();
	virtual float GetControlBrake();
	virtual float GetControlGas();
	virtual float GetControlSteering();
	virtual bool GetCruiseControl();
	virtual float GetControlOverSteer();
	virtual bool GetControlNOS();
	virtual float GetControlHandBrake();
	virtual float GetControlClutch();
	virtual void SetControlSteering(float);
	virtual void SetControlOverSteer(float);
	virtual void SetControlGas(float);
	virtual void SetControlBrake(float);
	virtual void SetControlNOS(bool);
	virtual void SetControlHandBrake(float);
	virtual void SetCruiseControl(bool);
	virtual void SetControlClutch(float);
	virtual bool IsLookBackButtonPressed();
	virtual bool IsPullBackButtonPressed();
	virtual bool IsAutomaticShift();
	virtual bool IsManualClutch();
	virtual float GetControlHydraulics(int);
	virtual void SetControlHydraulics(int, float);
};