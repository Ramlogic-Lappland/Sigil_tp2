#include "sl.h"

#include "Screen.h"
#include "vector2.h"

#include "Game.h"
#include "player.h"
#include "brick.h"

#include <math.h>


createPlayer player;
bool GameOver;
bool Pause;

const int amountOfBricks = 15;
const int linesOfBricks  =  6;

int startDrawingPos;

static createBrick brick[linesOfBricks][amountOfBricks] = { 0 };


void initGame()
{
	initPlayer(player);

	startDrawingPos = screenHeight - player.Height * 2;	

	brickSizeX = screenWidth / 15;
	brickSizeY = screenHeight / 30;

	GameOver = 0;
	Pause = 0;

	for (int i = 0; i < linesOfBricks; i++)
	{
		for (int j = 0; j < amountOfBricks; j++)
		{
			brick[i][j].brickPositionX =  j * brickSizeX + brickSizeX;
			brick[i][j].brickPositionY =  i * brickSizeY + startDrawingPos;
			brick[i][j].state = true;
		}
	}
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

	if (brick[linesOfBricks][amountOfBricks].state)
	{
		if ((linesOfBricks + amountOfBricks) % 2 == 0) slRectangleFill(brick[linesOfBricks][amountOfBricks].brickPositionX - brickSizeX / 2, brick[linesOfBricks][amountOfBricks].brickPositionY - brickSizeY / 2, brickSizeX, brickSizeY);
		else
		{
			slSetForeColor(0.0, 0.8, 0.2, 1.0);
		}
	}
}

