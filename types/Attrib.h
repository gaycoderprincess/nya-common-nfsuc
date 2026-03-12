namespace Attrib {
	class Vault;
	class Definition;
	class ClassPrivate;

	struct Private {
		uint8_t mData[8];

		auto GetLength() { auto f = (int(__thiscall*)(Private*))0x463010; return f(this); }
	};

	class Class {
	public:
		unsigned int mKey;
		ClassPrivate* mPrivates;

		auto GetFirstCollection() { auto f = (uint32_t(__thiscall*)(Class*))0x464620; return f(this); }
		auto GetNextCollection(uint32_t prev) { auto f = (uint32_t(__thiscall*)(Class*, uint32_t))0x464640; return f(this, prev); }
	};
	static_assert(offsetof(Class, mPrivates) == 4);

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

	class HashMap {
	public:
		Attrib::Node *mTable;
		uint16_t mTableSize;
		uint16_t mNumEntries;
		uint16_t mRefCount;
		uint8_t mWorstCollision;
		uint8_t mKeyShift;
	};

	class Collection {
	public:
		HashMap mTable;
		Collection* mParent;
		uint32_t mKey;
		Class* mClass;
		void* mLayout;
		Vault* mSource;

		static inline auto GetData = (void*(__thiscall*)(Collection*, uint32_t attributeKey, uint32_t index))0x464680;
		static inline auto GetNode = (Attrib::Node*(__thiscall*)(Collection*, uint32_t attributeKey, const Attrib::Collection **container))0x4649B0;
	};
	static_assert(offsetof(Collection, mParent) == 0xC);

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

		static inline auto Change = (void(__thiscall*)(Instance*, const Collection* collection))0x468A70;
		static inline auto GetAttributePointer = (void*(__thiscall*)(Instance*, uint32_t attributeKey, uint32_t index))0x4649B0;
	};

	class DatabasePrivate;
	class Database {
	public:
		DatabasePrivate* mPrivates;

		virtual void _dtor();

		static inline auto& sThis = *(Database**)0xD834D0;
	};
	static_assert(offsetof(Database, mPrivates) == 0x4);

	class ClassTable {
	public:
		class Node {
		public:
			unsigned int mKey;
			Attrib::Class* mPtr;
			unsigned int mMax;
		};
		static_assert(sizeof(Node) == 0xC);

		Node* mTable;
		uint16_t mTableSize;
		uint16_t mNumEntries;
		uint16_t mFixedAlloc;
		uint16_t mWorstCollision;

		static inline auto Find = (int(__thiscall*)(ClassTable*, uint32_t k))0x463BE0;
	};

	class DatabasePrivate : public Database {
	public:
		ClassTable mClasses;
	};
	static_assert(offsetof(DatabasePrivate, mClasses) == 0x8);

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

	inline auto FindCollection = (Collection*(__cdecl*)(uint32_t classKey, uint32_t collectionKey))0x464A20;
	inline auto StringToKey = (uint32_t(__cdecl*)(const char*))0x463A80;
	inline auto StringHash32 = StringToKey; // rename
};