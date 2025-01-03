
#include "./include/logic.h"
#include "./include/sprite.h"
#include <raylib.h>


// void processInput();
// void update();

void render(Sprite* spr, const int COUNT)
{
    BeginDrawing();
        ClearBackground(BLUE);
        for (int i = 0; i < COUNT; i++)
            drawSprite(&spr[i]);
    EndDrawing();
}
