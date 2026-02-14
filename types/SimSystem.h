namespace Sim {
	enum State {
		STATE_NONE = 0,
		STATE_INITIALIZING = 1,
		STATE_ACTIVE = 3,
		STATE_IDLE = 4,
	};

	auto Exists = (bool(*)())0x7B6050;
	auto GetTime = (uint64_t(*)())0x7B61B0;
	auto GetState = (State(*)())0x7B6060;
}

class SimSystem;

namespace Sim {
	namespace Internal {
		auto& mSystem = *(SimSystem**)0x1278FFC;
	}
}