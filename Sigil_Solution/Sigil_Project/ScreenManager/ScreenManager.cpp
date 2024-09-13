#include "sl.h"
#include "ScreenManager.h"
#include "Screen.h"
#include "Menu.h"
#include "Game.h"
#include <iostream>

CurrentScreen currentScreen;
float mouseX;
float mouseY;

int run(void)
{
    init();

    slWindow(screenWidth, screenHeight, "BreakOut", false);

    slSetFont(slLoadFont("bloodcrow.ttf"), 24);
    slSetTextAlign(SL_ALIGN_CENTER);


    while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
    {

        update();

        draw();


        slRender();
    }
    
    slClose();

    return 0;
}

void init()
{
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

    default:
        break;
    }
}

void draw()
{
    if (currentScreen == menu)
    {
        drawMenu();
    }
    else if (currentScreen == game)
    {
        drawGame();
    }
}

void close()
{

}