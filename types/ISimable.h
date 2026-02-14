namespace Sim { class IEntity; }
namespace EventSequencer { class IEngine; }

enum SimableType {
	SIMABLE_INVALID = 0,
	SIMABLE_VEHICLE = 1,
	SIMABLE_SMACKABLE = 2,
	SIMABLE_EXPLOSION = 3,
	SIMABLE_HUMAN = 4,
	SIMABLE_WEAPON = 5,
	SIMABLE_NEWTON = 6,
	SIMABLE_SENTRY = 7,
	SIMABLE_FRAGMENT = 8,
};

class IPlayer;
class IRigidBody;
class IModel;
class WWorldPos;
class ISimable : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x4018C0;

	virtual SimableType GetSimableType();
	virtual void Kill();
	virtual bool Attach(UCOM::IUnknown *);
	virtual bool Detach(UCOM::IUnknown *);
	virtual const IAttachable::List *GetAttachments();
	virtual void AttachEntity(Sim::IEntity *);
	virtual void DetachEntity();
	virtual IPlayer *GetPlayer();
	virtual bool IsPlayer();
	virtual bool IsOwnedByPlayer();
	virtual Sim::IEntity *GetEntity();
	virtual void DebugObject();
	virtual HSIMABLE__ *GetOwnerHandle();
	virtual ISimable *GetOwner();
	virtual bool IsOwnedBy(ISimable *);
	virtual void SetOwnerObject(ISimable *);
	virtual const Attrib::Instance *GetAttributes();
	virtual const IRigidBody *_GetRigidBody();
	virtual IRigidBody *GetRigidBody();
	virtual bool IsRigidBodySimple();
	virtual bool IsRigidBodyComplex();
	virtual const UMath::Vector3 *GetPosition();
	virtual void GetTransform(UMath::Matrix4 *);
	virtual void GetLinearVelocity(UMath::Vector3 *);
	virtual void GetAngularVelocity(UMath::Vector3 *);
	virtual unsigned int GetWorldID();
	virtual EventSequencer::IEngine *GetEventSequencer();
	virtual void ProcessStimulus(unsigned int);
	virtual const IModel *_GetModel();
	virtual IModel *GetModel();
	virtual void SetCausality(HCAUSE__ *, float);
	virtual HCAUSE__ *GetCausality();
	virtual float GetCausalityTime();
};