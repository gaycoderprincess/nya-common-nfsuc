#include <d3d9.h>

struct UCrc32 {
	uint32_t mCRC;
};

enum BluePrintType {
	BLUEPRINT_GRIP = 0,
	BLUEPRINT_DRIFT = 1,
	BLUEPRINT_DRAG = 2,
	BLUEPRINT_SPEED_CHALLENGE = 3,
	BLUEPRINT_FIRST = 0,
	BLUEPRINT_LAST = 0,
	BLUEPRINT_NUM = 1,
};

typedef uint32_t HSIMABLE__;
typedef uint32_t HCAUSE__;
typedef uint32_t HSIMPROFILE__;
typedef HSIMABLE__* HSIMABLE;
typedef HCAUSE__* HCAUSE;
typedef HSIMPROFILE__* HSIMPROFILE;

namespace Hermes {
	typedef uint32_t _h_HHANDLER__;
}

struct type_bStringHash {
	unsigned int hash;
};

#include "types/eastl.h"
#include "types/bNode.h"
#include "types/Attrib.h"
#include "types/ListableSet.h"
#include "types/UCOM.h"
#include "types/UMath.h"
#include "types/Physics.h"
#include "types/VehicleCustomizations.h"
#include "types/IAttachable.h"
#include "types/IPlayer.h"
#include "types/ISimable.h"
#include "types/IVehicle.h"
#include "types/ITransmission.h"
#include "types/IEngine.h"
#include "types/IRigidBody.h"
#include "types/IRBVehicle.h"
#include "types/IHumanAI.h"
#include "types/IInput.h"
#include "types/INIS.h"
#include "types/ICopMgr.h"
#include "types/GRace.h"
#include "types/GRaceStatus.h"
#include "types/GRaceParameters.h"
#include "types/GRaceDatabase.h"
#include "types/GameFlowManager.h"
#include "types/SimSystem.h"
#include "types/PVehicle.h"
#include "types/RideInfo.h"
#include "types/IGameStatus.h"
#include "types/GHub.h"
#include "types/GEvent.h"
#include "types/CarTypeInfo.h"
#include "types/GMW2Game.h"
#include "types/AttribGen.h"
#include "types/FEPlayerCarDB.h"
#include "types/UserProfile.h"
#include "types/eView.h"
#include "types/ChassisSimple.h"

namespace FE {
	class FEPauseStateManager {
	public:
		static inline auto CallERestartRace = (void(__thiscall*)(FEPauseStateManager*))0x563CE0;
	};
}

class GManager {
public:
	static inline auto& mObj = *(GManager**)0xD9B7E4;

	static inline auto ConnectRuntimeInstances = (void(__thiscall*)(GManager*))0x630B70;
	static inline auto StartRaceActivityFromInGame = (void(__thiscall*)(GManager*, GRaceParameters*))0x639E40;
};

class cRenderGlobals {
public:
	uint8_t _0[0x18];
	HWND hWnd; // +18

	static inline auto& mInstance = *(cRenderGlobals**)0xDF1DE0;
};

class DALPauseStates {
public:
	static inline auto& mPauseRequest = *(int*)0xD8E238;
};

auto bInitTicker = (void(*)(float))0x4B04E0;

auto& Tweak_ForceStraightPursuit = *(int*)0xD82118;
auto& SkipMovies = *(bool*)0xDAA18C;

auto LZDecompress = (uint32_t(*)(uint8_t* pSrc, uint8_t* pDst))0x6A6390;

auto& GameWindow = *(HWND*)0xDF1DF8;
auto& GameD3DDevice = *(IDirect3DDevice9**)0xEA0110;

#include "nfsuchooks.h"