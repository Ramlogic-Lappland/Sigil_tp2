#include "sl.h"

#include "player.h"
#include "Screen.h"

void initPlayer(createPlayer& player)
{

	player.lives = 3;
	player.speed = 480.0f;

	player.width = screenWidth / 10;
	player.Height = screenHeight / 35;

	player.x = screenWidth / 2;
	player.y = 0 + player.Height ;

	player.points = 0;

	player.state = 0;

	player.powerUp = 0; // 1= wide, 2 = small, 3 = fast player, 4 = slow player, 5 = lose points; 

}

void movePlayerRight(createPlayer& player)
{
	if (player.x < screenWidth - (player.width / 2)) {
		player.x += player.speed * slGetDeltaTime();
	}
}

void movePlayerLeft(createPlayer& player)
{
	if (player.x > 0 + (player.width / 2)) {
		player.x -= player.speed * slGetDeltaTime();
	}
}

void loseLife(createPlayer& player)
{
	if (player.lives > 0)
	{
		player.lives -= 1;
	}	
}