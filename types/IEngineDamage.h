class IEngineDamage : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x4EA370;

	virtual bool IsBlown();
	virtual bool Blow();
	virtual void Sabotage(float);
	virtual bool IsSabotaged();
	virtual void Repair();
};