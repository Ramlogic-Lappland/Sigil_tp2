#include "sl.h"
#include "ScreenManager.h"
#include "Screen.h"
#include "Menu.h"


CurrentScreen currentScreen;


int run(void)
{
    init();

    slWindow(width, height, "BreakOut", false);

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
    switch (currentScreen)
    {
    case menu:
        updateMenu();
        break;

    case game:
        //updateGame();
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
        //drawGame();
    }
}

void close()
{

}