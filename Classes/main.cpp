
//#include <iostream>
#include "MenuScene.h"
#include "SceneManager.h"

//#include "MenuScene.h"
/* TODO : Create a scene class
/////SCENE /////
main functions
init
update
cleanup
delete
enum States : paused | running
TODO : Create a Scene Manager
//// SCENE MANAGER /////
main functions
init
runwithscene(enum SceneName)
enum states : MENU | MAIN
*/



int main()
{
	std::cout << "syntax is your friend" << std::endl;


	MenuScene* testScene = new MenuScene();
	SceneManager::getInstance()->runwithscene(testScene);



}



