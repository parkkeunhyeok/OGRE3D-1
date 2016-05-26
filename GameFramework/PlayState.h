#pragma once

#include "GameState.h"

class PlayState : public GameState
{

public:
  void enter(void);
  void exit(void);

  void pause(void);
  void resume(void);

  bool frameStarted(GameManager* game, const Ogre::FrameEvent& evt);
  bool frameEnded(GameManager* game, const Ogre::FrameEvent& evt);

  bool mouseMoved(GameManager* game, const OIS::MouseEvent &e) ;
  bool mousePressed(GameManager* game, const OIS::MouseEvent &e, OIS::MouseButtonID id );
  bool mouseReleased(GameManager* game, const OIS::MouseEvent &e, OIS::MouseButtonID id);

  bool keyPressed(GameManager* game, const OIS::KeyEvent &e);
  bool keyReleased(GameManager* game, const OIS::KeyEvent &e);

  static PlayState* getInstance() { return &mPlayState; }

private:
  void _setLights(void);
  void _drawGroundPlane(void);
  void _drawGridPlane(void);
  void _drawScene(void);
  void _controlCharacter(const Ogre::FrameEvent& evt);

  static PlayState mPlayState;

  Ogre::Root *mRoot;
  Ogre::RenderWindow* mWindow;
  Ogre::SceneManager* mSceneMgr;
  Ogre::Camera* mCamera;

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

  Ogre::Entity* mCharacterEntity;
  Ogre::Entity*	mGround;
  Ogre::Entity** mGroundEntity;

  Ogre::AnimationState* mAnimationState;

  Ogre::Overlay*           mInformationOverlay;

};


