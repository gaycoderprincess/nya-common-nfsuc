enum EVIEW_ID {
	EVIEW_NONE = -1,
	EVIEW_FLAILER = 0x0,
	EVIEW_PLAYER1 = 0x1,
	EVIEW_PLAYER2 = 0x2,
	EVIEW_PLAYER1_RVM = 0x3,
	EVIEW_SNAP = 0x4,
	EVIEW_PLAYER1_REFLECTION = 0x5,
	EVIEW_PLAYER2_REFLECTION = 0x6,
	EVIEW_PLAYER1_GLOW = 0x7,
	EVIEW_PLAYER2_GLOW = 0x8,
	EVIEW_PLAYER1_TIREBLUR0 = 0x9,
	EVIEW_PLAYER1_TIREBLUR1 = 0xA,
	EVIEW_PLAYER1_TIREBLUR2 = 0xB,
	EVIEW_PLAYER1_TIREBLUR3 = 0xC,
	EVIEW_PLAYER1_SMOKE = 0xD,
	EVIEW_PLAYER2_SMOKE = 0xE,
	EVIEW_PLAYER1_PIP = 0xF,
	EVIEW_PLAYER1_SPECULAR = 0x10,
	EVIEW_PLAYER2_SPECULAR = 0x11,
	EVIEW_ANTI_ALIAS = 0x12,
	EVIEW_HEADLIGHT_P1 = 0x13,
	EVIEW_HEADLIGHT_P2 = 0x14,
	EVIEW_ENVMAP_PARABOLOID0_FRONT = 0x15,
	EVIEW_ENVMAP_PARABOLOID0_BACK = 0x16,
	EVIEW_ENVMAP_PARABOLOID1_FRONT = 0x17,
	EVIEW_ENVMAP_PARABOLOID1_BACK = 0x18,
	EVIEW_ENVMAP_PARABOLOID2_FRONT = 0x19,
	EVIEW_ENVMAP_PARABOLOID2_BACK = 0x1A,
	EVIEW_ENVMAP_PLANE0_FRONT = 0x1B,
	EVIEW_DEPTHTEXTURE = 0x1C,
	EVIEW_HDR_SCENE = 0x1D,
	EVIEW_SHADOWMAP10 = 0x1E,
	EVIEW_SHADOWMAP11 = 0x1F,
	EVIEW_SHADOWMAP12 = 0x20,
	EVIEW_LIGHTPROJ1 = 0x21,
	EVIEW_LIGHTPROJ2 = 0x22,
	EVIEW_SHADOWMAPCAR1 = 0x23,
	EVIEW_SHADOWMAPCAR2 = 0x24,
	EVIEW_LIGHTPROJCAR1 = 0x25,
	EVIEW_LIGHTPROJCAR2 = 0x26,
	EVIEW_SHADOWMATTE = 0x27,
	EVIEW_ENVMAP0F = 0x28,
	EVIEW_ENVMAP0R = 0x29,
	EVIEW_ENVMAP0B = 0x2A,
	EVIEW_ENVMAP0L = 0x2B,
	EVIEW_ENVMAP0U = 0x2C,
	EVIEW_ENVMAP0D = 0x2D,
	EVIEW_FIRST = 0x0,
	EVIEW_LAST = 0x2D,
	EVIEW_FIRST_RENDER = 0x1,
	EVIEW_LAST_RENDER = 0x2D,
	EVIEW_FIRST_PLAYER = 0x1,
	EVIEW_LAST_PLAYER = 0x2,
	EVIEW_FIRST_RVM = 0x3,
	EVIEW_LAST_RVM = 0x3,
	EVIEW_FIRST_ENVMAP = 0x28,
	EVIEW_LAST_ENVMAP = 0x2D,
	NUM_EVIEWS = 0x2E,
	NUM_RENDER_VIEWS = 0x2D,
	NUM_PLAYER_VIEWS = 0x2,
	NUM_RVM_VIEWS = 0x1,
};

enum ePlayerList {
	PLAYER_ALL = 0,
	PLAYER_LOCAL = 1,
	PLAYER_REMOTE = 2,
	PLAYER_MAX = 3,
};

enum ePlayerHudType {
	PHT_NONE = 0,
	PHT_STANDARD = 1,
	PHT_DRAG = 2,
	PHT_SPLIT1 = 3,
	PHT_SPLIT2 = 4,
	PHT_DRAG_SPLIT1 = 5,
	PHT_DRAG_SPLIT2 = 6,
};

class ISimable;
class IHud;
class IFeedback;
class ISteeringWheel;
class PlayerSettings;

class IPlayer : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x5F9F00;

	virtual ISimable *GetSimable();
	virtual bool IsLocal();
	virtual const UMath::Vector3 *GetPosition();
	virtual bool SetPosition(const UMath::Vector3 *);
	virtual PlayerSettings *GetSettings();
	virtual void SetSettings(int);
	virtual int GetSettingsIndex();
	virtual IHud *GetHud();
	virtual void SetHud(ePlayerHudType);
	virtual void ReleaseHud();
	virtual void SetRenderPort(EVIEW_ID);
	virtual EVIEW_ID GetRenderPort();
	virtual void SetControllerPort(int, bool);
	virtual int GetControllerPort();
	virtual bool UseRemoteVehicleCamera();
	virtual IFeedback *GetFFB();
	virtual ISteeringWheel *GetSteeringDevice();
	virtual bool InGameBreaker();
	virtual bool CanRechargeNOS();
	virtual void ResetGameBreaker(bool);
	virtual void ChargeGameBreaker(float);
	virtual float GetGameBreakerCharge();
	virtual bool ToggleGameBreaker();
	virtual float GetNOSRechargeModifier();
	virtual void SetNOSRechargeModifier(float);
	virtual float GetNOSTorqueModifier();
	virtual void SetNOSTorqueModifier(float);
	virtual float GetNOSCapacityModifier();
	virtual void SetNOSCapacityModifier(float);
	virtual void SetGameBreakerModifier(float);
	virtual bool GetNoBrakesModifier();
	virtual void SetNoBrakesModifier(bool);
};

#define PLAYER_LIST UTL::ListableSet<IPlayer, 8, ePlayerList, PLAYER_MAX, 0xDE99A8>
static_assert(sizeof(PLAYER_LIST::_buckets[0]) == 0x30);