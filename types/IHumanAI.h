class IHumanAI : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x405A80;

	virtual bool IsPlayerSteering();
	virtual bool GetAiControl();
	virtual void SetAiControl(bool, bool);
	virtual void SetWorldMoment(const UMath::Vector3 *, float);
	virtual const UMath::Vector3 *GetWorldMomentPosition();
	virtual float GetWorldMomentRadius();
	virtual void ClearWorldMoment();
	virtual bool IsFacingWrongWay_ForRaceRoute();
	virtual bool IsFacingWrongWay_ForRoadDirection();
};