#pragma once
#include "sl.h"


struct CreateButton
{

	double width;
	double height;
	double posX;
	double posY;

	bool state;
	const char *text;

};

void ButtonCollision(CreateButton& button, float mouseX, float mouseY);