class WCollider;

class ICollisionBody : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x401B00;

	virtual UMath::Vector3 *GetDimension(UMath::Vector3 *result);
	virtual void SetAnimating(bool);
	virtual void SetAnimBlending(bool);
	virtual bool IsModeling();
	virtual void DisableModeling();
	virtual void EnableModeling();
	virtual bool IsTriggering();
	virtual void DisableTriggering();
	virtual void EnableTriggering();
	virtual bool IsSleeping();
	virtual bool HasHadCollision();
	virtual bool HasHadGroundCollision();
	virtual bool HasHadBarrierCollision();
	virtual bool HasHadObjectCollision();
	virtual void EnableCollisionGeometries(UCrc32, bool);
	virtual bool DistributeMass();
	virtual bool IsAttachedToWorld();
	virtual void AttachedToWorld(bool, float);
	virtual bool IsInGroundContact();
	virtual const UMath::Vector3 *GetGroundNormal();
	virtual float GetHeightAboveGround();
	virtual float GetGravity();
	virtual unsigned int SetWorldCollisionMask(unsigned int);
	virtual const WCollider *GetWCollider();
	virtual void PlaceObject(const UMath::Matrix4 *, const UMath::Vector3 *);
	virtual unsigned int GetRenderMask();
	virtual bool IsInCollisionWorld();
};