#pragma once


struct createPlayer
{
	int lives;
	float speed;

	double width;
	double Height;

	float posY;
	float posX;

	bool state;

	int powerUp;
};

void initPlayer(createPlayer& player);

void movePlayerRight(createPlayer& player);

void movePlayerLeft(createPlayer& player);

void loseLife(createPlayer& player);
