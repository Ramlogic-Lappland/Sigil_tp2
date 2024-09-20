#pragma once

int run(void);
void init();
void update();
void draw();
void close(); 

enum CurrentScreen
{
    menu,
    game,
};

extern CurrentScreen currentScreen;
extern float mouseX;
extern float mouseY;

extern const int offset;