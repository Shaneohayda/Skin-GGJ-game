/*Shane Hayes 
Tower Defence Redemption 
21/03/2016
Advanced Digital Games Design Assignment
*/
#include "stdafx.h"
#include "Main.h"
#include "Music.h"
#include "Timer.h"
#include "Enviroment.h"
#include "SceneManager.h"
#include "Scene.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>

CMain::CMain(int passed_ScreenWidth, int passed_ScreenHeight)
{
	//trying to change between scenes
	enum game_states
	{
		MENU = 0,
		PLAY = 1,
		GAMEOVER = 2
	};
	//setting scene to play scene
	GameState = PLAY;

	CameraX = 0;
	CameraY = 0;
	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHeight;
	quit = false;
	csdl_setup = new CSDL_Setup(&quit, ScreenWidth, ScreenHeight);

	DesertArea = new CEnvironment(ScreenWidth, ScreenHeight, &CameraX, &CameraY, csdl_setup);

	MouseX = 0;
	MouseY = 0;
	//Main Charqacters Stating Posision
	Cowboy = new MainCharacter(csdl_setup, &MouseX, &MouseY, &CameraX, &CameraY, DesertArea);
}


CMain::~CMain(void)
{
	delete csdl_setup;
	delete Cowboy;
}

//setting up game loop
void CMain::GameLoop(void)
{
	while (!quit && csdl_setup->GetMainEvent()->type != SDL_QUIT)
	{
		csdl_setup->Begin();
		SDL_GetMouseState(&MouseX, &MouseY);
		DesertArea->DrawBack();

		Cowboy->Draw();
		Cowboy->Update();
		DesertArea->Update();

		DesertArea->DrawFront();
		csdl_setup->End();
	}
}