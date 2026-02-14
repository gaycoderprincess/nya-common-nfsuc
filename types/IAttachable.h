class IAttachable : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x4018B0;

	class List : eastl::list<IAttachable *,bstl::allocator> {};

	virtual bool Attach(UCOM::IUnknown*);
	virtual bool Detach(UCOM::IUnknown*);
	virtual bool IsAttached(const UCOM::IUnknown*);
	virtual void OnAttached(IAttachable*);
	virtual void OnDetached(IAttachable*);
	virtual const List* GetAttachments(IAttachable*);
};