#include <vector>

namespace NyaHooks {
	namespace D3DEndSceneHook {
		std::vector<void(*)()> aFunctions;
		std::vector<void(*)()> aPostFunctions;

		auto OrigFunction = (void(*)())nullptr;
		void HookedFunction() {
			for (auto& func : aFunctions) {
				func();
			}
			OrigFunction();
			for (auto& func : aPostFunctions) {
				func();
			}
		}
		
		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x784534, &HookedFunction);
		}
	}
	
	namespace D3DResetHook {
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(*)())nullptr;
		void HookedFunction() {
			for (auto& func : aFunctions) {
				func();
			}
			return OrigFunction();
		}


		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x755F9E, &HookedFunction);
		}
	}

	void PlaceD3DHooks() {
		D3DEndSceneHook::Init();
		D3DResetHook::Init();
	}

	namespace InputBlockerHook {
		bool bInputsBlocked = false;

		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (bool(*)())nullptr;
		bool HookedFunction() {
			if (bInputsBlocked) return true;
			return OrigFunction();
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (bool(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x69D52E, &HookedFunction);
		}
	}

	namespace WndProcHook {
		std::vector<void(*)(HWND, UINT, WPARAM, LPARAM)> aFunctions;

		auto OrigFunction = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))nullptr;
		LRESULT __stdcall HookedFunction(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
			for (auto& func : aFunctions) {
				func(hWnd, msg, wParam, lParam);
			}
			return OrigFunction(hWnd, msg, wParam, lParam);
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))(*(uintptr_t*)0x75630B);
			NyaHookLib::Patch(0x75630B, &HookedFunction);
		}
	}

	namespace LateInitHook {
		std::vector<void(*)()> aPreFunctions;
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(*)(int, char**))nullptr;
		void HookedFunction(int a1, char** a2) {
			for (auto& func : aPreFunctions) {
				func();
			}
			OrigFunction(a1, a2);
			for (auto& func : aFunctions) {
				func();
			}
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)(int, char**))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x6AF22F, &HookedFunction);
		}
	}
	
	namespace WorldServiceHook {
		std::vector<void(*)()> aPreFunctions;
		std::vector<void(*)()> aPostFunctions;

		auto OrigFunction = (void(__thiscall*)(void*))nullptr;
		void __thiscall HookedFunction(void* a1) {
			for (auto& func : aPreFunctions) {
				func();
			}
			OrigFunction(a1);
			for (auto& func : aPostFunctions) {
				func();
			}
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(__thiscall*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x669B9C, &HookedFunction);
		}
	}

	namespace SimServiceHook {
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(__thiscall*)(void*))nullptr;
		void __thiscall HookedFunction(void* a1) {
			for (auto& func : aFunctions) {
				func();
			}
			OrigFunction(a1);
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(__thiscall*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x67BD33, &HookedFunction);
		}
	}
}