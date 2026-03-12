class ITiptronic : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x401C70;

	virtual bool SportShift(GearID);
};