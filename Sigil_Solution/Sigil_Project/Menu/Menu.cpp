#include "Menu.h"
#include "sl.h"
#include "Screen.h"
#include "ScreenManager.h"

void initMenu()
{

}

void updateMenu()
{

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
    slText(510, 600, "Press Enter to play");
    

    
    if (mouseX > 510 - 205 && mouseX < 510 + 200 && mouseY > 610 + 110 && mouseY < 610 + 180)
    {
        slRectangleFill(510, 610, slGetTextWidth("Press Enter to play") + 40, 60);
    }
    else
        slRectangleOutline(510, 610, slGetTextWidth("Press Enter to play") + 40, 60);
    //slSetForeColor(1, 0, 0, 1);
    //slRectangleFill(screenWidth * 0.5, screenHeight * 0.5, 100, 100);
}