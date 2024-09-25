#include <iostream>
#include <math.h>
#include <string> 

#include "sl.h"

#include "ScreenManager.h"
#include "Screen.h"
#include "Game.h"
#include "player.h"
#include "brick.h"
#include "ball.h"


createPlayer player;
createBall ball;

bool GameOver = 0;
bool Pause = 0;
bool start = 0;
bool Win = 0;

int startDrawingPos;

std::string score = " ";
std::string lives = " ";

int tempScore = 0;
int tempLives = 0;

void initGame()
{
	initPlayer(player);
	initBall(ball, player.x, player.y);

	tempScore = 0;
	tempLives = 0;
	GameOver = 0;
	Pause = 0;

	spawnBricks();



}

void updateGame()
{
	if (Win || GameOver)
	{
		if (slGetKey(SL_KEY_BACKSPACE) && !start)
		{
			initGame;
		}
		if (slGetKey(SL_KEY_HOME) && !start)
		{
		   currentScreen = menu;
		}
	}

	if (player.lives < 1)
	{
		GameOver = 1;
	}

	if (tempScore == 7200)
	{
		Win = 1;
	}

	if (!GameOver || !Win)
	{
		if (slGetKey(SL_KEY_ENTER) && !start)
		{
			start = 1;
			randDirectionBall(ball);
			ball.speedY = ball.speed;
		}


		if (start)
		{
			
			if (slGetKey(SL_KEY_UP)) {
				Pause = !Pause;
			}
			tempScore = player.points;
			tempLives = player.lives;
			score = "Score: " + std::to_string(tempScore);
			lives = "Lives: " + std::to_string(tempLives);

		if (!Pause)
		{
			updateBall(ball);
			checkWallCollision(ball);
			checkPlayerCollision(ball, player);
			checkBrickCollision(bricks, 72, ball, player);


			if (ball.y - ball.rad < 0) {
				start = 0;
				player.x = screenWidth / 2;
				player.y = 0 + player.Height;
				initBall(ball, player.x, player.y);

				player.lives -= 1;
			}


			if (slGetKey(SL_KEY_RIGHT)) {
				movePlayerRight(player);
			}
			if (slGetKey(SL_KEY_LEFT)) {
				movePlayerLeft(player);
			}
		}

		}
	}

}

void drawGame()
{
	slSetForeColor(0.0, 0.8, 0.2, 1.0);

	slSetFontSize(20);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slText(screenWidth - 100, screenHeight - 30, "Press UP to pause");
	slText( 100, screenHeight - 30.0, score.c_str());
	slText( 400,  screenHeight - 30.0, lives.c_str());
	slSetForeColor(0.0, 0.8, 0.2, 1.0);

	slRectangleFill(player.x, player.y, player.width, player.Height);

	


	for (createBrick& Brick : bricks)
	{
		if (Brick.state)
		{
			slRectangleFill(Brick.x, Brick.y, Brick.width, Brick.height);
		}
	}

	if (Pause)
	{
		slSetFontSize(60);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		slText(screenWidth / 2, screenHeight / 2 , "Game Is Paused");
		slSetForeColor(0.0, 0.8, 0.2, 1.0);
		slSetFontSize(30);
	}

	if (GameOver)
	{
		slSetFontSize(60);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		slText(screenWidth / 2, screenHeight / 2, "Game Over");
		slSetForeColor(0.0, 0.8, 0.2, 1.0);
        slSetFontSize(40);
		slText(screenWidth / 2, screenHeight / 3, "Press BackSpace to replay");
		slText(screenWidth / 2, screenHeight / 4, "Press Home to return to menu");
		slSetFontSize(30);
	}

	if (Win)
	{
		slSetFontSize(60);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		slText(screenWidth / 2, screenHeight / 2, "You Win");
		slSetForeColor(0.0, 0.8, 0.2, 1.0);
		slSetFontSize(40);
		slText(screenWidth / 2, screenHeight / 3, "Press BackSpace to replay");
		slText(screenWidth / 2, screenHeight / 3, "Press Home to return to menu");
		slSetFontSize(30);
	}

	slCircleFill(ball.x, ball.y, ball.rad, 500);

}

