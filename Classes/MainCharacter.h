#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "SDL_Setup.h"
#include "Enviroment.h"

#include <math.h>

class MainCharacter
{
public:
	MainCharacter(CSDL_Setup* passed_SDL_Setup, int *passed_MouseX, int *passed_MouseY, float *CameraX, float *CameraY, CEnvironment* passed_Environment);
	~MainCharacter(void);

	double GetDistance(int X1, int Y1, int X2, int Y2);

	void Update();
	void Draw();
private:
	CEnvironment* Environment;
	void UpdateAnimation();
	void UpdateControls();

	float *CameraX;
	float *CameraY;

	int *MouseX;
	int *MouseY;

	CSDL_Setup* csdl_setup;
	//Cowboy Varaible/Sprite is player 1
	CSprite* Cowboy;
	//Sprite varaible declred for the GameHUD
	CSprite* GameHUD;
	//Sprite varaible declred for the Enemy
	CSprite* Enemy;

	int timeCheck;

	bool Follow;
	int Follow_Point_X;
	int Follow_Point_Y;

	float distance;
	bool stopAnimation;
};