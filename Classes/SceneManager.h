#ifndef _SCENE_MANAGER_
#define _SCENE_MANAGER_
#include "Scene.h"
class SceneManager
{
public:
	//get instance
	static SceneManager* getInstance();
	void init();
	//runwithscene
	void runwithscene(Scene* Scene);

	//getSurrentScene()
	//getSceneState()


private:
	SceneManager();
	~SceneManager();
	Scene* currentRunningScene;
};



#endif