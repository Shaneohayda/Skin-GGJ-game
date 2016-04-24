#include "stdafx.h"
#include "Main.h"
#include "Music.h"
#include "Timer.h"
#include "Scene.h"
#include "SceneManager.h"

static SceneManager *instance = NULL;

int main(int argc, char *argv[])
{
	CMain* cmain = new CMain(600, 500);

	Music::init();
	Music music("music.ogg");
	music.loop();
	cmain->GameLoop();

	delete cmain;
	return 0;
}

