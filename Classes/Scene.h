#ifndef _SCENE_H_
#define _SCENE_H_
#include <iostream>

enum  SceneState{ RUNNING, PAUSED, DESTROY };

class Scene{
public:
	Scene(); //constructor


	virtual void init();
	virtual void run();
	virtual void cleanup();
	~Scene(); //deconstructor

protected:
	bool initCompleted;
	SceneState thisSceneState;
};




#endif