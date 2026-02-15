enum eSensitivitySetting {
	SS_LOW = 0,
	SS_MEDUIM = 1,
	SS_HIGH = 2,
	NUM_SENSITIVITY_SETTINGS = 3,
	SS_MIN = 0,
	SS_MAX = 2,
};

enum eControllerConfig {
	CC_CONFIG1 = 0,
	CC_CONFIG2 = 1,
	CC_CONFIG3 = 2,
	CC_CONFIG4 = 3,
	CC_MSWHEEL = 4,
	NUM_CONTROLLER_CONFIGS = 5,
	NUM_CONTROLLER_DRIVE_CONFIGS = 5,
	MIN_CONFIG = 0,
	MAX_CONFIG = 4,
	MIN_WHEEL_CONFIG = 0,
	MAX_WHEEL_CONFIG = 0,
};

enum ePlayerSettingsCameras {
	PSC_BUMPER = 0,
	PSC_HOOD = 1,
	PSC_CLOSE = 2,
	PSC_FAR = 3,
	PSC_DRIFT = 4,
	NUM_CAMERAS_IN_OPTIONS = 5,
	PSC_STAGING = 6,
	PSC_PAUSE = 7,
	PSC_SLOTCAR = 8,
	PSC_TUNING = 9,
	PSC_MIN = 0,
	PSC_MAX = 4,
	PSC_DEFAULT = 2,
};

enum eDriverAssistLevel {
	DA_FAMILY = 0,
	DA_RACER = 1,
	DA_KING = 2,
	NUM_ASSIST_LEVELS = 3,
};

class VideoSettings {
public:
	float FEScale;
	float ScreenOffsetX;
	float ScreenOffsetY;
	bool WideScreen;
	float TimeOfDay;
	float Brightness;

	virtual void _dtor();
};

class ForceFeedbackSettings {
public:
	float mFFScale;

	virtual void _dtor();
};

class GameplaySettings {
public:
	bool AutosaveOn;
	bool RearviewOn;
	bool PipOn;
	bool Damage;
	uint8_t SpeedoUnits;
	uint8_t RacingMiniMapMode;
	uint8_t ExploringMiniMapMode;
	uint8_t ReplayOn;
	uint8_t CrashPlaybackOn;
	uint8_t NamesAboveOn;
	unsigned int MapItems;
	uint8_t LastMapZoom;
	uint8_t LastPursuitMapZoom;
	uint8_t LastMapView;
	bool MapScreenHelpShown;
	bool MapScreenRandEncHelpShown;
	bool JumpCam;
	float HighlightCam;

	virtual void _dtor();
};

class AudioSettings {
public:
	float MasterVol;
	float SpeechVol;
	float FEMusicVol;
	float IGMusicVol;
	float SoundEffectsVol;
	float EngineVol;
	float CarVol;
	float AmbientVol;
	float SpeedVol;
	int AudioMode;
	int InteractiveMusicMode;
	int EATraxMode;
	int UseCarClassSongFiltering;
	int AudioQuality;
	int PlayState;

	virtual void _dtor();
};

class PlayerSettings {
public:
	bool GaugesOn;
	bool PositionOn;
	bool LapInfoOn;
	bool RaceInfoOn;
	bool ScoreOn;
	bool Rumble;
	bool LeaderboardOn;
	bool HipMusicStreamOn;
	bool SectorDisplayOn;
	bool CrewInfoOn;
	bool TransmissionPromptOn;
	bool DriveWithAnalog;
	uint8_t GripTransmission;
	uint8_t GripCarCamera;
	uint8_t GripBrakes;
	uint8_t GripTractionControl;
	uint8_t GripElectronicControl;
	eSensitivitySetting SensitivitySetting;
	eControllerConfig Config;
	ePlayerSettingsCameras CurCam;
	eDriverAssistLevel DriverAssistLevel;
	uint8_t SplitTimeType;
	uint8_t Transmission;
	uint8_t Handling;
	uint8_t Player;
	uint8_t TextPopupsOn;
	uint8_t BestLineOn;
	uint8_t ArrowIndicatorsOn;
	uint8_t InGameLeaderboardOn;
};

class OptionsSettings {
public:
	VideoSettings TheVideoSettings;
	ForceFeedbackSettings TheForceFeedbackSettings;
	GameplaySettings TheGameplaySettings;
	AudioSettings TheAudioSettings;
	PlayerSettings ThePlayerSettings[4];
};

namespace Database {
	class UserProfile : public EA::Memcard::IMemcardNotifiable {
	public:
		uint8_t _4[0x80];
		unsigned int mEasterEggs;
		FEPlayerCarDB mCarStable;
		OptionsSettings mOptionsSettings;
		float mGameSessionTimer;
		float mLastSavedGameTime;

		static inline auto spUserProfiles = (UserProfile**)0xD8E1A4;
	};
	//static_assert(sizeof(UserProfile) == 0x4D740);
	static_assert(offsetof(UserProfile, mCarStable) == 0x88);
	static_assert(offsetof(UserProfile, mOptionsSettings) == 0x4D5F0);
}