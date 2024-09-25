#include "sl.h"

#include "ScreenManager.h"
#include "credits.h"
#include "Screen.h"

void initCredits()
{

}


void updateCredits()
{
    if (slGetKey(SL_KEY_BACKSPACE))
    {
        currentScreen = menu;
    }
}

void drawCredits()
{
    slSetForeColor(0.0, 0.8, 0.2, 1.0);
    slSetFontSize(60);
    slText(screenWidth / 2, (screenHeight / 20) * 18, "FreakOut");

    slSetFontSize(30);
    slText(screenWidth / 2, (screenHeight / 20) * 14, "Made by Estanislao Sala Barraquero");

    slText(screenWidth / 2, (screenHeight / 20) * 12, "Made using Sigil");

    slText(screenWidth / 2, (screenHeight / 20) * 10, "University ImageCampus");

    slSetFontSize(40);
    slText(screenWidth / 2, (screenHeight / 20) * 6, "Press BackSpace to return to menu");
}