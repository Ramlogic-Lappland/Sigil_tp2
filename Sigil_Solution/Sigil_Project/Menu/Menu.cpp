#include "Menu.h"
#include "sl.h"
#include "Screen.h"
#include "ScreenManager.h"
#include "button.h"

#include <iostream>

CreateButton plyGameBttn;


void initMenu()
{
    plyGameBttn.text = "Press Enter to play";
    plyGameBttn.width = 400 + offset;
    plyGameBttn.height = 80;

    plyGameBttn.posX = 510;
    plyGameBttn.posY = 610;

    plyGameBttn.state = 0;
}

void updateMenu()
{
    ButtonCollision(plyGameBttn, mouseX, mouseY);
}

void drawMenu()
{ 

    //Menu text
    slSetForeColor(0.0, 0.8, 0.2, 1.0);
    slSetFontSize(60);
    slText(510, 800, "BreakOut");
    slRectangleFill(510, 780, 300, 5);

    //Press Enter to play
    slSetFontSize(40);
    slText(plyGameBttn.posX, plyGameBttn.posY - 10, "Press Enter to play");
    
    
    if (plyGameBttn.state)
    {
        slRectangleFill(plyGameBttn.posX, plyGameBttn.posY, plyGameBttn.width, plyGameBttn.height);
        slSetForeColor(0.0, 0.0, 0.0, 1.0);
        slText(plyGameBttn.posX, plyGameBttn.posY - 10, "Press Enter to play");
        if (slGetMouseButton(SL_MOUSE_BUTTON_1))
        {
            currentScreen = game;
        }
    }
    else
        slSetForeColor(0.0, 0.8, 0.2, 1.0);
        slRectangleOutline(plyGameBttn.posX, plyGameBttn.posY, plyGameBttn.width, plyGameBttn.height);

}


/*
   if (mouseX > 510 - 201 && mouseX < 510 + 201 && mouseY > 610 + 100 && mouseY < 610 + 180)
    {
        slRectangleFill(510, 610, slGetTextWidth("Press Enter to play") + 40, 60);
        slSetForeColor(0.0, 0.0, 0.0, 1.0);
        slText(510, 600, "Press Enter to play");
        if (slGetMouseButton(SL_MOUSE_BUTTON_1))
        {
            currentScreen = game;
        }

    }
*/