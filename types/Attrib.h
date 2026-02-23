namespace Attrib {
	class Vault;
	class Definition;
	class ClassPrivate;

	struct Private {
		uint8_t mData[8];
	};

	class Class {
	public:
		unsigned int mKey;
		ClassPrivate* mPrivates;
	};

	class ClassPrivate : public Class {
	public:
		uint8_t _8[0x18];
		uint16_t mLayoutSize;
		uint16_t mNumDefinitions;
		Definition* mDefinitions;
		Vault* mSource;
		void* mStaticData;
	};

	class Array {
	public:
		uint16_t mAlloc;
		uint16_t mCount;
		uint16_t mSize;
		uint16_t mEncodedTypePad;
	};

	class Node {
	public:
		uint32_t mKey;
		union {
			void* mPtr;
			Attrib::Array* mArray;
			uint32_t mValue;
			uint32_t mOffset;
		};
		uint16_t mTypeIndex;
		uint8_t mMax;
		uint8_t mFlags;
	};

	class Collection {
	public:
		uint8_t _mTable[0xC];
		Collection* mParent;
		uint32_t mKey;
		Class* mClass;
		void* mLayout;
		Vault* mSource;

		static inline auto GetData = (void*(__thiscall*)(Collection*, uint32_t attributeKey, uint32_t index))0x464680;
		static inline auto GetNode = (Attrib::Node*(__thiscall*)(Collection*, uint32_t attributeKey, const Attrib::Collection **container))0x4649B0;
	};

	class Instance {
	public:
		Collection* mCollection;
		void* mLayoutPtr;
		uint32_t mMsgPort;
		uint32_t mFlags;

		Instance() {}

		Instance(const Collection* collection, uint32_t msgPort) {
			((Instance*(__thiscall*)(Instance*, const Collection*, uint32_t))0x462C80)(this, collection, msgPort);
		}
		//~Instance() {
		//	((void(__thiscall*)(Instance*))0x5301F0)(this);
		//}

		static inline auto GetAttributePointer = (void*(__thiscall*)(Instance*, uint32_t attributeKey, uint32_t index))0x4649B0;
	};

	class StringKey {
	public:
		unsigned int mHash32;
		const char *mString;
	};

	class RefSpec {
	public:
		unsigned int mClassKey;
		unsigned int mCollectionKey;
		const Attrib::Collection *mCollectionPtr;
	};

	auto FindCollection = (Collection*(__cdecl*)(uint32_t classKey, uint32_t collectionKey))0x464A20;
	auto StringToKey = (uint32_t(__cdecl*)(const char*))0x463A80;
	auto StringHash32 = StringToKey; // rename
};