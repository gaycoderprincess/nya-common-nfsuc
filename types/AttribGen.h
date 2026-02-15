namespace Attrib {
	namespace Gen {
		class presetride : public Attrib::Instance {
		public:
			struct _LayoutStruct {
				const char *PresetName;
				const char *CollectionName;
				float RideHeight;
				type_bStringHash PresetCar;
				eLiveryID Livery;
				KIT_TYPE KitType;
				unsigned int KitNumber;
				BluePrintType BluePrint;
				uint8_t Tier;
			};

			presetride(uint32_t collectionKey, uint32_t msgPort) {
				((presetride*(__thiscall*)(presetride*, uint32_t, uint32_t))0x410720)(this, collectionKey, msgPort);
			}
			~presetride() {
				((void(__thiscall*)(presetride*))0x468820)(this);
			}

			_LayoutStruct* GetLayout() {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class pvehicle : public Attrib::Instance {
		public:
			struct _LayoutStruct {
				Attrib::StringKey MODEL;
				Attrib::RefSpec frontend;
				const char *DefaultPresetRide;
				const char *CollectionName;
				bool RandomOpponent;
				GRace::Tier RacingTier;
				bool isRateable;
			};

			pvehicle(uint32_t collectionKey, uint32_t msgPort) {
				((pvehicle*(__thiscall*)(pvehicle*, uint32_t, uint32_t))0x4574E0)(this, collectionKey, msgPort);
			}
			~pvehicle() {
				((void(__thiscall*)(pvehicle*))0x468820)(this);
			}

			_LayoutStruct* GetLayout() {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};
	}
}