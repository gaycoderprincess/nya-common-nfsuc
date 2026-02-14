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
typedef HSIMABLE__* HSIMABLE;
typedef HCAUSE__* HCAUSE;

namespace Hermes {
	typedef uint32_t _h_HHANDLER__;
}

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

auto LZDecompress = (uint32_t(*)(uint8_t* pSrc, uint8_t* pDst))0x6A6390;

auto& GameWindow = *(HWND*)0xDF1DF8;
auto& GameD3DDevice = *(IDirect3DDevice9**)0xEA0110;

#include "nfsuchooks.h"