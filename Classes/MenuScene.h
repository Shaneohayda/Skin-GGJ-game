#ifndef _MENU_SCENE_H
#define _MENU_SCENE_H

#include "Scene.h"

class MenuScene : public  Scene
{
public:
	MenuScene(){ init(); }
	virtual void init();
	virtual void run();
	~MenuScene(){}
private:

};



#endif