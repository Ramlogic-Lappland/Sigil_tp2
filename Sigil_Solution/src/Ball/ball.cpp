#include <random>
#include <iostream>

#include "sl.h"

#include "ball.h"
#include "Screen.h"
#include "player.h"


void initBall(createBall& ball, float playerPosX, float playerPosY )
{
	ball.x = playerPosX;
	ball.y = playerPosY + 35.0f;

	ball.rad = 10.0f;


	ball.speed = 450;
	ball.speedX = 0;
	ball.speedY = 0;
}


void modifySpeedUp(createBall& ball)
{
	ball.speed *= 2.0f;
}

void modifySpeedDown(createBall& ball)
{
	ball.speed *= 0.5f;
}

void modifySizeDown(createBall& ball)
{
	ball.rad *= 0.5f;
}


void modifySizeUp(createBall& ball)
{
	ball.rad *= 2;
}

void randDirectionBall(createBall& ball)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution <> ra(1, 10);

	int randomNum = ra(gen);

	if (randomNum > 5)
	{
		ball.speedX = ball.speed * -1;
	}
	else
		ball.speedX = ball.speed;

}

void updateBall(createBall& ball) 
{
	ball.x += ball.speedX * slGetDeltaTime();
	ball.y += ball.speedY * slGetDeltaTime();
}

void checkWallCollision(createBall& ball)
{
	if (ball.x - ball.rad < 0 || ball.x + ball.rad > screenWidth) {
		if (ball.x - ball.rad < 0 )
		{
			ball.x += ball.rad;
		}
		if (ball.x + ball.rad > screenWidth)
		{
			ball.x -= ball.rad;
		}
		ball.speedX *= -1.0f; // side walls

	}
	if (ball.y - ball.rad > screenHeight) {
		ball.y -= ball.rad;
		ball.speedY *= -1.0f; //  top wall
	}
}

void checkPlayerCollision(createBall& ball, createPlayer& player)
{

	float distLeft = abs(ball.x - player.x);
	float distRight = abs(ball.x - (player.x + player.width));
	float distTop = abs(ball.y - player.y);
	float distBottom = abs(ball.y - (player.y + player.Height));


	if (distLeft <= ball.rad + (player.width/2) && ball.y >= player.y && ball.y <= player.y + player.Height)
	{
		ball.x -= (ball.rad / 2);
		ball.speedY *= -1.0f;
	}


	if (distRight <= ball.rad + (player.width / 2) && ball.y >= player.y && ball.y <= player.y + player.Height)
	{
		ball.x += (ball.rad / 2);
		ball.speedY *= -1.0f;
	}


	if (distTop <= ball.rad + (player.Height / 2) && ball.x >= player.x && ball.x <= player.x + player.width)
	{
		ball.y += (ball.rad / 2);
		ball.speedY *= -1.0f;
	}


	if (distBottom <= ball.rad + (player.Height / 2) && ball.x >= player.x && ball.x <= player.x + player.width)
	{
		ball.y += (ball.rad / 2);
		ball.speedY *= -1.0f;
	}


	if ((ball.x + ball.rad >= player.x && ball.x - ball.rad <= player.x + player.width && ball.y + ball.rad >= player.y && ball.y - ball.rad <= player.y + player.Height))
	{
		ball.x += (ball.rad / 2);
		ball.y += (ball.rad / 2);

		ball.speedY *= -1.0f;
		ball.speedX *= -1.0f;
	}
}
