#include "button.h"
#include <iostream>
void ButtonCollision(CreateButton& button, float mouseX, float mouseY)
{
    
    if (mouseX > button.posX - (button.width/2) && mouseX <  button.posX + (button.width/2) && mouseY > button.posY + button.height*1.2 && mouseY < button.posY + button.height*2.2)
    {
        button.state = 1;
    }
    else
    button.state = 0;
}

