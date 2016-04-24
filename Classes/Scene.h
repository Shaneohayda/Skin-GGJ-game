#ifndef _SCENE_H_
#define _SCENE_H_
#include <iostream>

enum  SceneState{ RUNNING, PAUSED, DESTROY };

class Scene{
public:
	//constructor
	Scene();
	//deconstructor
	~Scene();

	virtual void init();
	virtual void run();
	virtual void cleanup();

protected:
	bool initCompleted;
	SceneState thisSceneState;
};
#endif