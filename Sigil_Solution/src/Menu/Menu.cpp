#include "sl.h"
#include "Screen.h"

#include "Menu.h"
#include "ScreenManager.h"
#include "button.h"
#include "Game.h"
#include "credits.h"

#include <iostream>

CreateButton plyGameBttn;
CreateButton creditsBttn;

int background;

void initMenu()
{

    plyGameBttn.text = "Play";
    plyGameBttn.width = 400 + offset;
    plyGameBttn.height = 80;

    plyGameBttn.posX = screenWidth / 2;
    plyGameBttn.posY = (screenHeight / plyGameBttn.height) * 60;

    plyGameBttn.state = 0;

    creditsBttn.text = "Credits";
    creditsBttn.width = 400 + offset;
    creditsBttn.height = 80;

    creditsBttn.posX = screenWidth / 2;
    creditsBttn.posY = (screenHeight / plyGameBttn.height) * 40;

    creditsBttn.state = 0;
}

void initTexture()
{
    background = slLoadTexture("res/menubackground.png");
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

    ButtonCollision(creditsBttn, mouseX, mouseY);
    if (creditsBttn.state)
    {
        if (slGetMouseButton(SL_MOUSE_BUTTON_1))
        {
            initCredits();
            currentScreen = credits;          
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
    slSprite(background, screenWidth / 2, screenHeight / 2, screenWidth, screenHeight);
    slSetFontSize(60);
    slText(screenWidth/2, (screenHeight /20) * 18, "FreakOut");
    slSetForeColor(0.0, 0.0, 0.0, 1.0);
    slRectangleFill(screenWidth/2, (screenHeight / 20) * 17 + 30, 300, 3); // divide screen in 20 segments pick the nr 17 below 18 cuz text is 18 and add half of the font size
    slSetForeColor(0.0, 0.8, 0.2, 1.0);

    //Press Enter to play



    
    
    if (plyGameBttn.state)
    {
        slSetForeColor(0.1, 0.1, 0.1, 1.0);
        slRectangleFill(plyGameBttn.posX, plyGameBttn.posY, plyGameBttn.width, plyGameBttn.height);
        slSetForeColor(1.0, 1.0, 1.0, 0.01);
        slText(plyGameBttn.posX, plyGameBttn.posY - 10, "Play");
    }
    else
        slSetForeColor(0.0, 0.0, 0.0, 1.0);
        slRectangleFill(plyGameBttn.posX, plyGameBttn.posY, plyGameBttn.width, plyGameBttn.height);
        slSetForeColor(0.0, 0.8, 0.2, 1.0);
        slText(plyGameBttn.posX, plyGameBttn.posY - 10, "Play");


    if (creditsBttn.state)
    {
        slSetForeColor(0.1, 0.1, 0.1, 1.0);
        slRectangleFill(creditsBttn.posX, creditsBttn.posY, creditsBttn.width, creditsBttn.height);
        slSetForeColor(1.0, 1.0, 1.0, 0.01);
        slText(creditsBttn.posX, creditsBttn.posY - 10, "Credits");
    }
    else
        slSetForeColor(0.0, 0.0, 0.0, 1.0);
        slRectangleFill(creditsBttn.posX, creditsBttn.posY, creditsBttn.width, creditsBttn.height);
        slSetForeColor(0.0, 0.8, 0.2, 1.0);
        slText(creditsBttn.posX, creditsBttn.posY - 10, "Credits");
}

