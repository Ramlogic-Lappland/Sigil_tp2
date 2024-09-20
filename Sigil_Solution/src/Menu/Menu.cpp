#include "sl.h"
#include "Screen.h"

#include "Menu.h"
#include "ScreenManager.h"
#include "button.h"
#include "Game.h"

#include <iostream>

CreateButton plyGameBttn;


void initMenu()
{
    plyGameBttn.text = "Press Enter to play";
    plyGameBttn.width = 400 + offset;
    plyGameBttn.height = 80;

    plyGameBttn.posX = screenWidth / 2;
    plyGameBttn.posY = (screenHeight / plyGameBttn.height) * 60;

    plyGameBttn.state = 0;
}

void updateMenu()
{
    ButtonCollision(plyGameBttn, mouseX, mouseY);
    if (plyGameBttn.state)
    {
      if (slGetMouseButton(SL_MOUSE_BUTTON_1))
      {
         currentScreen = game;
         initGame();
      }
    }

    if (slGetKey(SL_KEY_ENTER)) {
        currentScreen = game;
        initGame();
    }
}

void drawMenu()
{ 

    //Menu text
    slSetForeColor(0.0, 0.8, 0.2, 1.0);
    slSetFontSize(60);
    slText(screenWidth/2, (screenHeight /20) * 18, "BreakOut");
    slRectangleFill(screenWidth/2, (screenHeight / 20) * 17 + 30, 300, 3); // divide screen in 20 segments pick the nr 17 below 18 cuz text is 18 and add half of the font size

    //Press Enter to play
    slSetFontSize(40);
    slText(plyGameBttn.posX, plyGameBttn.posY - 10, "Press Enter to play");
    
    
    if (plyGameBttn.state)
    {
        slRectangleFill(plyGameBttn.posX, plyGameBttn.posY, plyGameBttn.width, plyGameBttn.height);
        slSetForeColor(0.0, 0.0, 0.0, 1.0);
        slText(plyGameBttn.posX, plyGameBttn.posY - 10, "Press Enter to play");
    }
    else
        slSetForeColor(0.0, 0.8, 0.2, 1.0);
        slRectangleOutline(plyGameBttn.posX, plyGameBttn.posY, plyGameBttn.width, plyGameBttn.height);

}

