#pragma once
#include "stdafx.h"
#include <vector>
#include "SDL_Setup.h"
#include "Sprite.h"
#include "Tower.h"
#include <fstream>
#include <string>
#include <sstream>

class CEnvironment
{
public:
	CEnvironment(int ScreenWidth, int ScreenHeight, float *CameraX, float *CameraY, CSDL_Setup* csdl_setup);
	~CEnvironment(void);


	void DrawBack();
	void DrawFront();

	void Update();

	void SaveToFile();
	void LoadFromFile();

	enum ModeType
	{
		GamePlay,
		LevelCreation
	};

	std::vector<Tower*> GetTowers() { return Towers; }

private:
	int Mode;
	CSDL_Setup* csdl_setup;
	float* CameraX;
	float* CameraY;

	bool OnePressed;
	CSprite* Desert[4][7];

	std::vector<Tower*> Towers;
};