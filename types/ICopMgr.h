class AIPursuit;

enum CopSpawnGoal {
	kGoal_None = 0x1,
	kGoal_Pit = 0x2,
	kGoal_Ram = 0x4,
	kGoal_Flee = 0x8,
	kGoal_Patrol = 0x10,
	kGoal_Search = 0x20,
	kGoal_Pursuit = 0x40,
	kGoal_Pullover = 0x80,
	kGoal_RoadBlock = 0x100,
	kGoal_HeadOnRam = 0x200,
	kGoal_Investigate = 0x400,
	kGoal_SupportHeavy = 0x800,
	kGoal_SupportLeader = 0x1000,
};

enum CopSpawnLocation {
	kCopSpawnLoc_None = 0,
	kCopSpawnLoc_AnyValid = 1,
	kCopSpawnLoc_Ahead = 2,
	kCopSpawnLoc_Behind = 3,
	kCopSpawnLoc_Side = 4,
	kCopSpawnLoc_RoadBlock = 5,
};

class ICopMgr : public UCOM::IUnknown {
public:
	static inline uint32_t IHandle = 0x402900;

	static inline auto& mInstance = *(ICopMgr**)0xDE6DAC;

	virtual void EnableCops(bool);
	virtual bool AreCopsEnabled();
	virtual bool IsSpawningEnabled();
	virtual void ResetAllBusting();
	virtual void PursuitIsEvaded(AIPursuit *);
	virtual bool IsCopRequestPending();
	virtual bool IsCopSpawnPending();
	virtual void SpawnCop(unsigned int, CopSpawnGoal, const UMath::Vector3 *, const UMath::Vector3 *, const UMath::Vector3 *, CopSpawnLocation, bool, float);
	virtual bool PlayerPursuitHasCop();
	virtual bool CanPursueRacers();
	virtual bool IsPlayerPursuitActive();
	virtual void LockoutCops(bool);
	virtual void LockoutNonScriptedCops(bool);
	virtual void AllowNewPursuits(bool);
	virtual void PursueAtHeatLevel(int, bool);
	virtual float GetLockoutTimeRemaining();
	virtual bool AddTargetPursuer(IVehicle *, ISimable *);
	virtual bool RemoveTargetPursuer(IVehicle *);
	virtual bool RefreshPursuitTarget();
	virtual IVehicle *GetClosestCop(const UMath::Vector3 *, const float);
	virtual bool IsCopWithinPhysicsProximity(const UMath::Vector3 *, const UMath::Vector3 *);
	virtual bool IsHeliSpawnFromDebug();
	virtual IVehicle *GetActiveCopVehicleFromOutOfView(UCrc32);
	virtual void InvokeRoadBlock(ISimable *, unsigned int, bool);
	virtual void DebugReportCostToState(const char *, int);
	virtual void EndPursuits();
};