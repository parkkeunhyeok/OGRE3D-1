#pragma once
#include "inc/fmod.hpp"
#pragma comment (lib,"fmodex_vc.lib")
using namespace FMOD;

enum SELECTSOUND {
	SD_1,
	SD_2,
	SD_3
};


#include "GameState.h"
class LobyState :
	public GameState
{
public:
	void enter(void);
	void exit(void);

	void pause(void);
	void resume(void);

	bool frameStarted(GameManager* game, const Ogre::FrameEvent& evt);
	bool frameEnded(GameManager* game, const Ogre::FrameEvent& evt);

	bool mouseMoved(GameManager* game, const OIS::MouseEvent &e);
	bool mousePressed(GameManager* game, const OIS::MouseEvent &e, OIS::MouseButtonID id);
	bool mouseReleased(GameManager* game, const OIS::MouseEvent &e, OIS::MouseButtonID id);

	bool keyPressed(GameManager* game, const OIS::KeyEvent &e);
	bool keyReleased(GameManager* game, const OIS::KeyEvent &e);

	static LobyState* getInstance() { return &mLobyState; }
	void soundInit();
	void Release();

private:
	void _setLights(void);
	void _drawGroundPlane(void);
	void _drawGridPlane(void);
	void _drawScene(void);
	void _inputFile(void);
	void _makeTestStagePattern(void);
	void _constructTestStageSceneNode(void);
	void _controlCharacter(const Ogre::FrameEvent& evt);


	static LobyState mLobyState;
	std::vector<std::string> mInputFile;
	std::vector<Ogre::Vector3> mPattern;
	bool mCollisionCheck[90][7];

	Ogre::Root *mRoot;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager* mSceneMgr;
	Ogre::Camera* mCamera;
	OIS::Mouse* mMouse;

	Ogre::Light *mLightP, *mLightD, *mLightS;

	Ogre::SceneNode* mCharacterRoot;
	Ogre::SceneNode* mCharacterYaw;
	//Ogre::SceneNode* mCamera;
	Ogre::Vector3 mCharacterDirection;
	Ogre::SceneNode** mGroundNode;
	Ogre::SceneNode* mCameraRoot;
	Ogre::SceneNode* mCameraHolder;
	Ogre::SceneNode* mCameraYaw;
	Ogre::SceneNode* mCameraPitch;
	Ogre::SceneNode* mTitaniumNode;
	Ogre::SceneNode* mTitaniumNode2;
	Ogre::SceneNode* mTitaniumNode3;

	Ogre::Entity* mCharacterEntity;
	Ogre::Entity*	mGround;
	Ogre::Entity** mGroundEntity;

	//Ogre::AnimationState* mAnimationState;
	Ogre::AnimationState* mRunState;
	Ogre::AnimationState* mIdleState;

	Ogre::Overlay*           mInformationOverlay;
	Ogre::Overlay*           mlobyOverlay;

	FMOD_SYSTEM *g_System; //사운드 시스템 생성 하는 부분이고
	FMOD_SOUND *g_Sound[SD_3]; //사운드 설정하는부분
	FMOD_CHANNEL *g_Channel[SD_3]; //채널 설정하는부분이고
	FMOD_BOOL mIsPlaying;

	int iCount1;
	int iCount2;
	int iCount3;
};

