#include <iostream>

#include "sl.h"

#include "brick.h"

#include "Screen.h"
#include "ball.h"

const int spacing = 14;
const int spacingY = 14; // so i can leave a place on top to put lives and score
const int brickWidth = 80;
const int brickHeight = 30;
int startingHeight = screenHeight - 60;

createBrick bricks[rowOfBricks * columnsOfBricks];

void spawnBricks()
{
	int counter = 0;

	for (int row = 0; row < rowOfBricks; row++)
	{
		for (int column = 0; column < columnsOfBricks; column++)
		{
			
			int brickX = (55 + brickWidth) + (row * (brickWidth + spacing));

			int brickY = startingHeight -   column * (brickHeight + spacingY);

			bricks[counter].x = brickX;
			bricks[counter].y = brickY;
			bricks[counter].width = brickWidth;
			bricks[counter].height = brickHeight;
			bricks[counter].state = 1;

			counter++;
		}
	}


}

void checkBrickCollision(createBrick bricks[], int numBricks, createBall& ball, createPlayer& player ) 
{

	for (int i = 0; i < numBricks; i++) 
	{

		float distLeft = abs(ball.x - bricks[i].x);
		float distRight = abs(ball.x - (player.x + bricks[i].width));
		float distTop = abs(ball.y - bricks[i].y);
		float distBottom = abs(ball.y - (bricks[i].y + bricks[i].height));

		if (bricks[i].state && distLeft <= ball.rad + (bricks[i].width / 2) && ball.y >= bricks[i].y && ball.y <= bricks[i].y + bricks[i].height)
		{
			ball.speedX *= -1.0f;
			bricks[i].state = 0;
			player.points += 100;
		}


		if (bricks[i].state && distRight <= ball.rad + (bricks[i].width / 2) && ball.y >= bricks[i].y && ball.y <= bricks[i].y + bricks[i].height)
		{
			bricks[i].state = 0;
			ball.speedX *= -1.0f;
			player.points += 100;
		}


		if (bricks[i].state && distTop <= ball.rad + (bricks[i].height / 2) && ball.x >= bricks[i].x && ball.x <= bricks[i].x + bricks[i].width)
		{
			bricks[i].state = 0;
			ball.speedY *= -1.0f;
			player.points += 100;
		}


		if (bricks[i].state && distBottom <= ball.rad + (bricks[i].height / 2) && ball.x >= bricks[i].x && ball.x <= bricks[i].x + bricks[i].width)
		{
			bricks[i].state = 0;
			ball.speedY *= -1.0f;
			player.points += 100;
		}


		if (bricks[i].state && (ball.x + ball.rad >= bricks[i].x && ball.x - ball.rad <= bricks[i].x + bricks[i].width && ball.y + ball.rad >= bricks[i].y && ball.y - ball.rad <= bricks[i].y + bricks[i].height))
		{
			bricks[i].state = 0;
			ball.speedY *= -1.0f;
			ball.speedX *= -1.0f;
			player.points += 100;
		}

	}
}





/*

	for (int i = 0; i < numBricks; i++) 
	{

		if (bricks[i].state && ball.x + ball.rad > bricks[i].x && ball.x - ball.rad < bricks[i].x + bricks[i].width && ball.y + ball.rad > bricks[i].y && ball.y - ball.rad < bricks[i].y + bricks[i].height)
		{
			bricks[i].state = false;
			ball.speedY *= -1; 
			ball.speedX *= -1;
			player.points += 100;
		}
	}
 void checkBrickCollision(createBrick& brick, createBall& ball) 
{
	// Calculate normal vector
	float normalX = 0;
	float normalY = 0;

	if (ball.x < brick.x + brick.width / 2) {
		normalX = -1; // left side
	}
	else {
		normalX = 1; // right side
	}

	if (ball.y < brick.y + brick.height / 2) {
		normalY = -1; // top side
	}
	else {
		normalY = 1; // bottom side
	}

	// Calculate dot product
	float dotProduct = ball.speedX * normalX + ball.speedY * normalY;

	// Calculate reflection vector
	float reflectionX = ball.speedX - 2 * dotProduct * normalX;
	float reflectionY = ball.speedY - 2 * dotProduct * normalY;

	// Update ball velocity
	ball.speedX = reflectionX;
	ball.speedY = reflectionY;

	// Corner collision
	if (abs(ball.x - brick.x) < brick.width / 4 &&
		abs(ball.y - brick.y) < brick.height / 4) {

		ball.speedX *= -1.0f; // reverse x direction
		ball.speedY *= -1.0f; // reverse y direction
	}
}


void checkBrickCollision(createBall& ball, createPlayer& player)
{
	for (createBrick& brick : bricks)
	{
		if (brick.state && circleRectBrick(ball, brick))
		{
			ball.speedY *= -1.0f;
			ball.speedX *= -1.0f;
			brick.state = false;
			player.points += 100;
		}
	}
}


bool circleRectBrick(createBall& ball, createBrick& brick)
{

	// temporary variables to set edges for testing
	float testX = ball.x;
	float testY = ball.y;

	// which edge is closest?
	if (ball.x < brick.x)         testX = brick.x;      // test left edge
	else if (ball.x > brick.x + brick.width) testX = brick.x + brickWidth;   // right edge
	if (ball.y < ball.y)         testY = brick.y;      // top edge
	else if (ball.y > brick.y + brick.height) testY = brick.y + brick.height;   // bottom edge

	// get distance from closest edges
	float distX = ball.x - testX;
	float distY = ball.y - testY;
	float distance = sqrt((distX * distX) + (distY * distY));

	// if the distance is less than the radius, collision!
	if (distance <= ball.rad) {
		return true;
	}
	return false;
}
*/
