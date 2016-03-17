#include "MenuScene.h"
#include "SceneManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 400;

void MenuScene::init()
{
	Scene::init();
}

void MenuScene::run()
{
	if (!initCompleted)
	{
		init();
	}
	thisSceneState = RUNNING;

	int lifetimeofscene = 2000;

	//while (thisSceneState == RUNNING)
	{
		std::cout << "Menu Scene Running!" << std::endl;
		lifetimeofscene--;
		if (lifetimeofscene <1)
			thisSceneState = DESTROY;
	}
	Scene* nextScene = new Scene();
	SceneManager::getInstance()->runwithscene(nextScene);
}