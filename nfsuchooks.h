#include <vector>

namespace NyaHooks {
	namespace D3DEndSceneHook {
		inline std::vector<void(*)()> aFunctions;
		inline std::vector<void(*)()> aPostFunctions;

		inline auto OrigFunction = (void(*)())nullptr;
		inline void HookedFunction() {
			for (auto& func : aFunctions) {
				func();
			}
			OrigFunction();
			for (auto& func : aPostFunctions) {
				func();
			}
		}
		
		inline void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x784534, &HookedFunction);
		}
	}
	
	namespace D3DResetHook {
		inline std::vector<void(*)()> aFunctions;

		inline auto OrigFunction = (void(*)())nullptr;
		inline void HookedFunction() {
			for (auto& func : aFunctions) {
				func();
			}
			return OrigFunction();
		}


		inline void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x755F9E, &HookedFunction);
		}
	}

	inline void PlaceD3DHooks() {
		D3DEndSceneHook::Init();
		D3DResetHook::Init();
	}

	namespace InputBlockerHook {
		inline bool bInputsBlocked = false;

		inline std::vector<void(*)()> aFunctions;

		inline auto OrigFunction = (bool(*)())nullptr;
		inline bool HookedFunction() {
			if (bInputsBlocked) return true;
			return OrigFunction();
		}

		inline void Init() {
			if (OrigFunction) return;
			OrigFunction = (bool(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x69D52E, &HookedFunction);
		}
	}

	namespace WndProcHook {
		inline std::vector<void(*)(HWND, UINT, WPARAM, LPARAM)> aFunctions;

		inline auto OrigFunction = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))nullptr;
		inline LRESULT __stdcall HookedFunction(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
			for (auto& func : aFunctions) {
				func(hWnd, msg, wParam, lParam);
			}
			return OrigFunction(hWnd, msg, wParam, lParam);
		}

		inline void Init() {
			if (OrigFunction) return;
			OrigFunction = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))(*(uintptr_t*)0x75630B);
			NyaHookLib::Patch(0x75630B, &HookedFunction);
		}
	}

	namespace CameraMoverHook {
		inline std::vector<void(*)(CameraMover*)> aFunctions;

		inline auto OrigFunction = (void(__thiscall*)(CameraMover*, float))nullptr;
		inline void __fastcall HookedFunction(CameraMover* a1, uintptr_t, float a2) {
			OrigFunction(a1, a2);
			for (auto& func : aFunctions) {
				func(a1);
			}
		}

		inline void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(__thiscall*)(CameraMover*, float))(*(uintptr_t*)0xBE4948);
			NyaHookLib::Patch(0xBE4948, &HookedFunction);
		}
	}

	namespace LateInitHook {
		inline std::vector<void(*)()> aPreFunctions;
		inline std::vector<void(*)()> aFunctions;

		inline auto OrigFunction = (void(*)(int, char**))nullptr;
		inline void HookedFunction(int a1, char** a2) {
			for (auto& func : aPreFunctions) {
				func();
			}
			OrigFunction(a1, a2);
			for (auto& func : aFunctions) {
				func();
			}
		}

		inline void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)(int, char**))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6AF22F, &HookedFunction);
		}
	}
	
	namespace WorldServiceHook {
		inline std::vector<void(*)()> aPreFunctions;
		inline std::vector<void(*)()> aPostFunctions;

		inline auto OrigFunction = (void(__thiscall*)(void*))nullptr;
		inline void __fastcall HookedFunction(void* a1) {
			for (auto& func : aPreFunctions) {
				func();
			}
			OrigFunction(a1);
			for (auto& func : aPostFunctions) {
				func();
			}
		}

		inline void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(__thiscall*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x669B9C, &HookedFunction);
		}
	}

	namespace SimServiceHook {
		inline std::vector<void(*)()> aFunctions;

		inline auto OrigFunction = (void(__thiscall*)(void*))nullptr;
		inline void __fastcall HookedFunction(void* a1) {
			for (auto& func : aFunctions) {
				func();
			}
			OrigFunction(a1);
		}

		inline void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(__thiscall*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x67BD33, &HookedFunction);
		}
	}
}