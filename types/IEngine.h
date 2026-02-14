class IEngine : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x402920;

	virtual float GetRPM();
	virtual float GetEngineBogRPM();
	virtual float GetRedline();
	virtual float GetMaxRPM();
	virtual float GetMinRPM();
	virtual float GetPeakTorqueRPM();
	virtual float GetTorqueRatio();
	virtual void MatchSpeed(float);
	virtual float GetNOSCapacity();
	virtual void SetNOSCapacity(float);
	virtual bool IsNOSEngaged();
	virtual float GetNOSFlowRate();
	virtual float GetNOSBoost();
	virtual bool HasNOS();
	virtual bool CanUseNOS();
	virtual void ChargeNOS(float);
	virtual float GetMaxHorsePower();
	virtual float GetMinHorsePower();
	virtual float GetHorsePower();
	virtual float GetThrottle();
	virtual bool IsTractionControlOn();
	virtual int GetTractionControlLevel();
	virtual void SetTractionControlLevel(int);
	virtual float GetEngineTemperature();
	virtual float GetPeakTorque();
};