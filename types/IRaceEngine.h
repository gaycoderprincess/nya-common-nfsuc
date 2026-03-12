class IRaceEngine : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x5180B0;

	virtual float GetPerfectLaunchRange(float*);
};