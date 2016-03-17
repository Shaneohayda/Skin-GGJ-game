#include "SceneManager.h"

static SceneManager *instance = NULL;



SceneManager* SceneManager::getInstance()
{
	if (instance == 0)
	{
		instance = new SceneManager();
	}

	return instance;
}

SceneManager::SceneManager()
{
	init();
}

void SceneManager::init()
{
	currentRunningScene = 0;
}

SceneManager::~SceneManager()
{
	delete instance;
}

void SceneManager::runwithscene(Scene* scene)
{
	if (currentRunningScene != 0)
	{
		delete currentRunningScene;
	}

	currentRunningScene = scene;

	currentRunningScene->run();
}

