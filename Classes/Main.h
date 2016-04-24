#pragma once
#include "SDL_Setup.h"
#include "Sprite.h"
#include "MainCharacter.h"
#include "Enviroment.h"
#include <math.h> 

class CMain
{
public:
	CMain(int passed_ScreenWidth, int passed_ScreenHeight);
	~CMain(void);
	void GameLoop();

private:
	float CameraX;
	float CameraY;

	MainCharacter *Cowboy;
	CEnvironment* DesertArea;
	int GameState;

	int ScreenWidth;
	int ScreenHeight;

	bool quit;

	CSDL_Setup* csdl_setup;

	int MouseX;
	int MouseY;
};