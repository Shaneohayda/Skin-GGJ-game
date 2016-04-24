#include "Enviroment.h"

CEnvironment::CEnvironment(int ScreenWidth, int ScreenHeight, float *passed_CameraX, float *passed_CameraY, CSDL_Setup* passed_csdl_setup)
{
	csdl_setup = passed_csdl_setup;

	CameraX = passed_CameraX;
	CameraY = passed_CameraY;

	//Setting up Games Background Image
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			Desert[i][j] = new CSprite(csdl_setup->GetRenderer(), "Desert.png", ScreenWidth * i, ScreenHeight  * j, ScreenWidth, ScreenHeight, CameraX, CameraY, CCollisionRectangle());
		}
	}

	Mode = LevelCreation;
	LoadFromFile();

	OnePressed = false;
}


CEnvironment::~CEnvironment(void)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			delete Desert[i][j];
		}

	}

	for (std::vector<Tower*>::iterator i = Towers.begin(); i != Towers.end(); ++i)
	{
		delete (*i);
	}

	Towers.clear();
}

void CEnvironment::DrawBack()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			Desert[i][j]->Draw();
		}
	}

	for (std::vector<Tower*>::iterator i = Towers.begin(); i != Towers.end(); ++i)
	{
		(*i)->DrawTrunk();
	}
}

void CEnvironment::DrawFront()
{
	for (std::vector<Tower*>::iterator i = Towers.begin(); i != Towers.end(); ++i)
	{
		(*i)->DrawCrown();
	}
}
//Have Posisition of towers save to a text file
void CEnvironment::LoadFromFile()
{	//text file is placed within the game folder
	std::ifstream LoadedFile("Save.txt");

	std::string line;

	enum ObjectType{
		TypeNone,
		TypeTower
	};

	int CurrentType = TypeNone;

	if (LoadedFile.is_open())
	{
		while (LoadedFile.good())
		{
			std::getline(LoadedFile, line);
			if (line == "Tower Posisition")
			{
				CurrentType = TypeTower;
			}
			else if (line == " ")
			{
				CurrentType = TypeNone;
			}
			else
			{
				if (CurrentType == TypeTower)
				{

					std::istringstream iss(line);

					int TempX = 0;
					int TempY = 0;
					std::string PreviousWord = "";

					while (iss)
					{
						std::string word;
						iss >> word;
						//X coordiantes found and saved to txt file
						if (PreviousWord == "x:")
						{
							TempX = atoi(word.c_str());
						}
						//Y coordinates found and saves to text file
						if (PreviousWord == "y:")
						{
							TempY = atoi(word.c_str());

							Towers.push_back(new Tower(TempX, TempY, CameraX, CameraY, csdl_setup));
						}

						PreviousWord = word;
					}


				}
			}
		}
	}
	else
	{
		//if the file can not be found print message to command prompt
		std::cout << "File Could Not Be Open: Save.txt" << std::endl;
	}
}

void CEnvironment::SaveToFile()
{
	std::ofstream LoadedFile;
	//load possitions of towers from text file
	LoadedFile.open("Save.txt");

	LoadedFile << "Tower Posisiton" << std::endl;

	for (std::vector<Tower*>::iterator i = Towers.begin(); i != Towers.end(); ++i)
	{
		LoadedFile << "x: " << (*i)->GetX() << "\ty: " << (*i)->GetY() << std::endl;

	}

	LoadedFile << " " << std::endl;

	LoadedFile.close();
	//when you press f11 the posistion of the towers is saved to the command prompt
	std::cout << "Level Saved!" << std::endl;
}


void CEnvironment::Update()
{
	if (Mode == LevelCreation)
	{

		if (csdl_setup->GetMainEvent()->type == SDL_KEYDOWN)
		{
			if (!OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F11)
			{
				SaveToFile();
				OnePressed = true;
			}
		}

		if (csdl_setup->GetMainEvent()->type == SDL_KEYUP)
		{
			if (OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F11)
			{
				OnePressed = false;
			}
		}

		if (csdl_setup->GetMainEvent()->type == SDL_KEYDOWN)
		{
			if (!OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F1)
			{
				Towers.push_back(new Tower(-*CameraX + 275, -*CameraY + 90, CameraX, CameraY, csdl_setup));
				OnePressed = true;
			}
		}//When f1 is pressed a tower is palced in that posistion

		if (csdl_setup->GetMainEvent()->type == SDL_KEYUP)
		{
			if (OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F1)
			{
				OnePressed = false;
			}
		}

		//When F2 is pressed last tower placed is removed
		if (csdl_setup->GetMainEvent()->type == SDL_KEYDOWN)
		{
			if (!OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F2)
			{
				if (Towers.size() > 0)
				{

					delete Towers[Towers.size() - 1];

					Towers.pop_back();

				}
				OnePressed = true;
			}
		}

		if (csdl_setup->GetMainEvent()->type == SDL_KEYUP)
		{
			if (OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F2)
			{
				OnePressed = false;
			}
		}
	}
	}
