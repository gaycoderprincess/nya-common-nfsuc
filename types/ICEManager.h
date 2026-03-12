class ICETake;
class ICECameraMover;
class ICEController;
class ICEChannelManager;
class ICEManager {
public:
	ICETake *mPlaybackTake;
	bool mPlaybackDataSet;
	float mSceneElevation;
	unsigned int nPlayGenericGroupHash;
	int nPlayGenericTakeIndex;
	int nPlayGenericContextID;
	ICECameraMover *mCameraMover;
	ICEController *mICEController;
	ICEChannelManager *mChannelManager;
};
inline auto& TheICEManager = *(ICEManager*)0xD35E10;