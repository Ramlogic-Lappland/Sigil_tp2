#pragma once
#include "player.h"

struct createBall
{
	int x, y;
	float rad;
	float speed, speedX, speedY;
};

void initBall(createBall& ball, float playerPosX, float playerPosY);

void modifySpeedUp(createBall& ball);

void modifySpeedDown(createBall& ball);

void modifySizeDown(createBall& ball);

void modifySizeUp(createBall& ball);

void randDirectionBall(createBall& ball);

void updateBall(createBall& ball);

void checkWallCollision(createBall& ball);

void checkPlayerCollision(createBall& ball, createPlayer& player);