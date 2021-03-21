#include <bangtal.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARINGS

SceneID background, gamepage;
ObjectID startbutton, image[4][3] = { 0 };
int num[13] = { 0 }, number, random;

ObjectID createObject(ObjectID object, SceneID scene,const char* image, int x, int y, bool shown)
{
	object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown)
	{
		showObject(object);
	}
	return object;
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action)
{
	if (object == startbutton)
	{
		enterScene(gamepage);
		hideObject(startbutton);
	}
}

int main()
{	
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, true);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	srand(time(NULL));
	setMouseCallback(mouseCallback);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
		a: random = rand() % 12 + 1;
			if (num[random] == 0)
			{
				num[random] = 1;
				image[i][j] = random;
			}
			else if (num[random] == 1)
			{
				goto a;
			}
		}
	}

	background = createScene("시작화면", "원본.png");
	gamepage = createScene("게임화면", "배경.png");

	createObject(startbutton, background, "start.png", 370, 120, true);

	startGame(background);
}