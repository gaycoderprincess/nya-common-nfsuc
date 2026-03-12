class IInductable : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x5180A0;

	virtual int GetInductionType();
	virtual float GetSpool();
	virtual float GetCurrentPSI();
	virtual float GetMaxPSI();
	virtual bool HasBlowoffValve();
	virtual bool HasBypassValve();
	virtual float GetRelativeTorqueGain();
	virtual float GetBypassPosition();
	virtual bool IsBlowoffOpened();
	virtual bool IsWastegateOpened();
};