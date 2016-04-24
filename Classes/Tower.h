#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"
#include "Sprite.h"

class Tower
{
public:
	Tower(int x, int y, float *CameraX, float *CameraY, CSDL_Setup* csdl_setup);
	~Tower(void);

	void DrawCrown();
	void DrawTrunk();

	int GetX();
	int GetY();

	CSprite* GetCrown() { return Crown; }
	CSprite* GetTrunk() { return Trunk; }

private:
	int x, y;
	CSprite* Crown;
	CSprite* Trunk;

	float *CameraX;
	float *CameraY;
};