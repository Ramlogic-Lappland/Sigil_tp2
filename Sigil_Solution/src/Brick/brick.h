#pragma once
#include "ball.h"

struct createBrick
{
	int x,y;	
	int width, height;
 
	int lives;
	bool state;
};

void spawnBricks();

const int columnsOfBricks = 8;
const int rowOfBricks = 9;

extern createBrick bricks[rowOfBricks * columnsOfBricks];

void checkBrickCollision(createBrick bricks[], int numBricks, createBall& ball, createPlayer& player);
