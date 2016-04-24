#include "StdAfx.h"
#include "Tower.h"


Tower::Tower(int x_passed, int y_passed, float *passed_CameraX, float *passed_CameraY, CSDL_Setup* csdl_setup)
{
	CameraX = passed_CameraX;
	CameraY = passed_CameraY;

	x = x_passed;
	y = y_passed;

	Trunk = new CSprite(csdl_setup->GetRenderer(), "Tower.png", x, y, 43, 145, CameraX, CameraY, CCollisionRectangle(0, 110, 43, 36));
	Crown = new CSprite(csdl_setup->GetRenderer(), "MiniGun.png", x - 0, y - 0, 50, 60, CameraX, CameraY, CCollisionRectangle());
}


Tower::~Tower(void)
{
	delete Crown;
	delete Trunk;
}

int Tower::GetX()
{
	return x;
}

int Tower::GetY()
{
	return y;
}

void Tower::DrawCrown()
{
	if (97 <= *CameraY + Trunk->GetPositionRect().y)
		Trunk->Draw();

	Crown->Draw();
}

void Tower::DrawTrunk()
{
	if (103 >= *CameraY + Trunk->GetPositionRect().y)
		Trunk->Draw();
}