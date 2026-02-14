namespace bstl {
	class allocator {};

	//template<typename T, const char* name>
	template<typename T>
	class derived_with_name : public T {};
}

namespace eastl {
	template<typename T>
	class less {};

	template<typename T>
	class equal_to {};

	template<typename T>
	class hash {};

	template<typename T1, typename T2, typename T3, typename T4>
	class map {
	public:
		uint8_t _0[0x1C];
	};

	template<typename T1, typename T2, typename T3, typename T4, typename Allocator, int>
	class hash_map {
	public:
		uint8_t _0[0x20];
	};

	class ListNodeBase {
		ListNodeBase* mpNext;
		ListNodeBase* mpPrev;
	};

	template<typename T, typename Allocator>
	class list {
	public:
		eastl::ListNodeBase mNode;
		unsigned int mSize;
		bstl::allocator mAllocator;
	};
	static_assert(sizeof(list<void*, bstl::allocator>) == 0x10);

	template<typename T, typename T2, typename Allocator>
	class set {
	public:
		uint8_t _0[0x1C];
	};

	template<typename T, typename Allocator>
	class vector {
	public:
		T* mpBegin;
		T* mpEnd;
		T* mpCapacity;
		void* mAllocator;

		T& operator[](int i) { return mpBegin[i]; }

		auto size() { return mpEnd - mpBegin; }
		auto empty() { return mpEnd == mpBegin; }
	};
	static_assert(sizeof(vector<void*, bstl::allocator>) == 0x10);
}