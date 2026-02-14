class CAnimScene;
class ICEScene;
class RevPatternDataStruct;

enum ICEContextIDs {
	eICE_NISProto = 0,
	eICE_NISFinish = 1,
	eICE_NISRaceIntros = 2,
	eICE_NISUserArrested = 3,
	eICE_NISPursuitBreaker = 4,
	eICE_NISDriverJobs = 5,
	eICE_FMV = 6,
	eICE_MARKETING = 7,
	eICE_REPLAY = 8,
	eICE_RECORDED = 9,
	eICE_GENERIC = 10,
	eICE_FE = 11,
};

class INIS : public UCOM::IUnknown {
public:
	enum eFacePixelateState {
		kFACEPIX_Default = 0,
		kFACEPIX_ForcedOn = 1,
		kFACEPIX_ForcedOff = 2,
	};

	static inline uint32_t IHandle = 0x4559D0;

	static inline auto& mInstance = *(INIS**)0x127995C;

	virtual void SetPreMovie(const char *);
	virtual void SetPostMovie(const char *);
	virtual void LoadNIS(const char *, int, unsigned int, int);
	virtual void Release();
	virtual void SetSceneComplete();
	virtual void AddSimOverflowTime(float);
	virtual void Pause();
	virtual void UnPause();
	virtual bool GetDrawHud();
	virtual void SetDrawHud(bool);
	virtual void ServiceLoads();
	virtual void StartEvents();
	virtual void FireEventTag(unsigned int);
	virtual unsigned int GetNumTags();
	virtual unsigned int GetTag(unsigned int);
	virtual void ResetEvents(float);
	virtual bool IsLoaded();
	virtual bool IsPlaying();
	virtual bool IsComplete();
	virtual bool InMovie();
	virtual bool IsPursuitBreaker();
	virtual bool UseNISAudio();
	virtual bool InPreRaceMatchUp();
	virtual bool IsHUB();
	virtual const UMath::Vector3 *GetStartLocation();
	virtual unsigned __int16 GetStartDirection();
	virtual const bMatrix4 *GetStartTransform();
	virtual const UMath::Vector3 *GetStartCameraLocation();
	virtual ICEContextIDs GetICEContextID();
	virtual const char *GetSceneName();
	virtual ICEScene *GetScene();
	virtual CAnimScene *GetAnimScene();
	virtual unsigned int GetSceneKey();
	virtual int GetAvatarCount();
	virtual const char *GetAvatarName(int);
	virtual void GetAvatarMatrix(int, bMatrix4 *, bool);
	virtual void GetAvatarVelocity(int, bVector3 *);
	virtual IVehicle *GetNISCarByChannel(UCrc32);
	virtual IVehicle *GetNISCarByIndex(int);
	virtual IVehicle *GetAnimatedNISCarByIndex(int);
	virtual int GetNumNISCars();
	virtual int GetNumAnimatedNISCars();
	virtual bool GetCarAudioData(const IVehicle *, RevPatternDataStruct *);
	virtual int GetCarAnimationByIndex(int);
	virtual void SetFacePixelateState(eFacePixelateState);
	virtual eFacePixelateState GetFacePixelateState();
};