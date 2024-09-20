#include "sl.h"

#include "player.h"
#include "Screen.h"

void initPlayer(createPlayer& player)
{

	player.lives = 3;
	player.speed = 450.0f;

	player.width = screenWidth / 8;
	player.Height = screenHeight / 30;

	player.posX = screenWidth / 2;
	player.posY = 0 + player.Height ;

	player.state = 0;

	player.powerUp = 0; // 1= wide, 2 = small, 3 = fast player, 4 = slow player, 5 = lose points; 

}

void movePlayerRight(createPlayer& player)
{
	if (player.posX < screenWidth - (player.width / 2)) {
		player.posX += player.speed * slGetDeltaTime();
	}
}

void movePlayerLeft(createPlayer& player)
{
	if (player.posX > 0 + (player.width / 2)) {
		player.posX -= player.speed * slGetDeltaTime();
	}
}

void loseLife(createPlayer& player)
{
	if (player.lives > 0)
	{
		player.lives -= 1;
	}	
}