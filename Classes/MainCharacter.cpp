#include "MainCharacter.h"


MainCharacter::MainCharacter(CSDL_Setup* passed_SDL_Setup, int *passed_MouseX, int *passed_MouseY, float *passed_CameraX, float *passed_CameraY, CEnvironment* passed_Environment)
{
	Environment = passed_Environment;

	CameraX = passed_CameraX;
	CameraY = passed_CameraY;

	csdl_setup = passed_SDL_Setup;
	MouseX = passed_MouseX;
	MouseY = passed_MouseY;

	//Players Sprite is created, given size and posistion as well as Collision Rectangle/Circle placed around sprite
	Cowboy = new CSprite(csdl_setup->GetRenderer(), "Cowboy.png", 150, 125, 50, 60, CameraX, CameraY,CCollisionRectangle(120, 70, 60, 60));
	//Players Sprite is then anaimted
	Cowboy->SetUpAnimation(4, 4);
	//Players Sprite is then given origin point
	Cowboy->SetOrgin(Cowboy->GetWidth() / 2.0f, Cowboy->GetHeight());

	//Enemy Sprite is created, given size and posistion as well as Collision Rectangle/Circle placed around sprite
	Enemy = new CSprite(csdl_setup->GetRenderer(), "Enemy.png", 350, 425, 50, 60, CameraX, CameraY, CCollisionRectangle(320, 370, 60, 60));
	//Enemy Sprite is then anaimted
	Enemy->SetUpAnimation(4, 4);
	//Enemy Sprite is then given origin point
	Enemy->SetOrgin(Cowboy->GetWidth() / 2.0f, Cowboy->GetHeight());

	//GameHUD created and placed at the bottom of the screen with a given size
	GameHUD = new CSprite(csdl_setup->GetRenderer(), "GameHUD.png", 0, 500, 730, 135, CameraX, CameraY, CCollisionRectangle(120, 70, 60, 60));
	GameHUD->SetOrgin(Cowboy->GetWidth() / 5.0f, Cowboy->GetHeight());

	timeCheck = SDL_GetTicks();
	Follow = false;
	distance = 0;
	stopAnimation = false;
}


MainCharacter::~MainCharacter(void)
{
	delete Cowboy;
	delete Enemy;
}
void MainCharacter::Draw()
{
	Cowboy->DrawSteady();
	GameHUD->DrawSteady();
	Enemy->DrawSteady();
}
//Player 1's Character aniamtion function is handeled
void MainCharacter::UpdateAnimation()
{
	float angle = atan2(Follow_Point_Y - *CameraY, Follow_Point_X - *CameraX);
	angle = (angle * (180 / 3.14)) + 180;

	if (!stopAnimation)
	{
		if (angle > 45 && angle <= 135)
		{
			//down
			if (distance > 15)
				Cowboy->PlayAnimation(0, 3, 0, 200);
			else
				Cowboy->PlayAnimation(1, 1, 0, 200);

		}
		else if (angle > 135 && angle <= 225)
		{
			//left
			if (distance > 15)
				Cowboy->PlayAnimation(0, 3, 1, 200);
			else
				Cowboy->PlayAnimation(1, 1, 1, 200);
		}
		else if (angle > 225 && angle <= 315)
		{
			//up

			if (distance > 15)
				Cowboy->PlayAnimation(0, 3, 3, 200);
			else
				Cowboy->PlayAnimation(1, 1, 3, 200);

		}
		else if ((angle <= 360 && angle > 315) || (angle >= 0 && angle <= 45))
		{
			//right
			if (distance > 15)
				Cowboy->PlayAnimation(0, 3, 2, 200);
			else
				Cowboy->PlayAnimation(1, 1, 2, 200);

		}
	}
	if (!stopAnimation)
	{
		//Enemy Character aniamtion function is handeled
		if (angle > 45 && angle <= 135)
		{
			//animation for when the character is moving down
			if (distance > 15)
				Enemy->PlayAnimation(0, 3, 0, 200);
			else
				Enemy->PlayAnimation(1, 1, 0, 200);

		}
		else if (angle > 135 && angle <= 225)
		{
			//animation for when the character is moving left
			if (distance > 15)
				Enemy->PlayAnimation(0, 3, 1, 200);
			else
				Enemy->PlayAnimation(1, 1, 1, 200);
		}
		else if (angle > 225 && angle <= 315)
		{
			//animation for when the character is moving up
			if (distance > 15)
				Enemy->PlayAnimation(0, 3, 3, 200);
			else
				Enemy->PlayAnimation(1, 1, 3, 200);

		}
		else if ((angle <= 360 && angle > 315) || (angle >= 0 && angle <= 45))
		{
			//animation for when the character is moving right
			if (distance > 15)
				Enemy->PlayAnimation(0, 3, 2, 200);
			else
				Enemy->PlayAnimation(1, 1, 2, 200);
		}
	}
}

void MainCharacter::UpdateControls()
{
	if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN || csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION)
	{
		if (csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
		{
			Follow_Point_X = *CameraX - *MouseX + 300;
			Follow_Point_Y = *CameraY - *MouseY + 250;
			Follow = true;
		}
	}

	if (timeCheck + 10 < SDL_GetTicks() && Follow)
	{

		distance = GetDistance(*CameraX, *CameraY, Follow_Point_X, Follow_Point_Y);

		if (distance == 0)
			stopAnimation = true;
		else
			stopAnimation = false;


		if (distance > 15)
		{

			bool collding = false;

			for (int i = 0; i < Environment->GetTowers().size(); i++)
			{
				if (Cowboy->isColliding(Environment->GetTowers()[i]->GetTrunk()->GetCollisionRect()))
				{
					if (*CameraX > Follow_Point_X)
					{
						*CameraX = *CameraX + 5;
					}
					if (*CameraX < Follow_Point_X)
					{
						*CameraX = *CameraX - 5;
					}

					if (*CameraY > Follow_Point_Y)
					{
						*CameraY = *CameraY + 5;
					}
					if (*CameraY < Follow_Point_Y)
					{
						*CameraY = *CameraY - 5;
					}

					Follow_Point_X = *CameraX;
					Follow_Point_Y = *CameraY;
					distance = 0;
					Follow = false;
					collding = true;
				}
			}

			if (!collding)
			{
				if (*CameraX != Follow_Point_X)
				{
					*CameraX = *CameraX - (((*CameraX - Follow_Point_X) / distance) * 2.7f);
				}

				if (*CameraY != Follow_Point_Y)
				{
					*CameraY = *CameraY - (((*CameraY - Follow_Point_Y) / distance) * 2.7f);
				}
			}
		}
		else
			Follow = false;

		timeCheck = SDL_GetTicks();
	}
}

void MainCharacter::Update()
{
	UpdateAnimation();
	UpdateControls();

}

double MainCharacter::GetDistance(int X1, int Y1, int X2, int Y2)
{
	double DifferenceX = X1 - X2;
	double DifferenceY = Y1 - Y2;
	double distance = sqrt((DifferenceX * DifferenceX) + (DifferenceY * DifferenceY));
	return distance;
}