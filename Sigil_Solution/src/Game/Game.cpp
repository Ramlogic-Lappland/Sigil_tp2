#include "sl.h"

#include "Screen.h"

#include "Game.h"
#include "player.h"

createPlayer player;
bool GameOver;
bool Pause;

void initGame()
{
	initPlayer(player);
	GameOver = 0;
	Pause = 0;
}

void updateGame()
{
	if (!GameOver)
	{
		if (!Pause)
		{

			if (slGetKey(SL_KEY_RIGHT)) {
				movePlayerRight(player);
			}
			if (slGetKey(SL_KEY_LEFT)) {
				movePlayerLeft(player);
			}

		}
	}

}

void drawGame()
{
	slSetForeColor(0.0, 0.8, 0.2, 1.0);
	slSetFontSize(60);
	slRectangleFill(player.posX, player.posY, player.width, player.Height);
}