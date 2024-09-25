#include <iostream>

#include "sl.h"

#include "ScreenManager.h"
#include "Screen.h"
#include "Menu.h"
#include "Game.h"
#include "credits.h"



const int offset = 40;
CurrentScreen currentScreen;
float mouseX;
float mouseY;

int run(void)
{
    init();

    slWindow(screenWidth, screenHeight, "BreakOut", false);

    slSetFont(slLoadFont("res/bloodcrow.ttf"), 24);
    slSetTextAlign(SL_ALIGN_CENTER);


    while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
    {

        initTexture();

        update();

        draw();

        slRender();
    }
    
    slClose();

    return 0;
}

void init()
{
    initMenu();
    CurrentScreen currentScreen = menu;
}

void update()
{
    mouseX = slGetMouseX();
    mouseY = slGetMouseY();

    switch (currentScreen)
    {
    case menu:
        updateMenu();
        break;

    case game:
        updateGame();
        break;

    case credits:
        updateCredits();
        break;

    default:
        break;
    }
}

void draw()
{
    switch (currentScreen)
    {
    case menu:
        drawMenu();
        break;

    case game:
        drawGame();
        break;

    case credits:
        drawCredits();
        break;

    default:
        break;
    }
}

void close()
{

}