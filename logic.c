
#include "./include/logic.h"
#include "./include/config.h"
#include "./include/sprite.h"
#include <raylib.h>


// void processInput();
// void update();

void render(Sprite* spr)
{
    BeginDrawing();
        ClearBackground(BLUE);
        drawSprite(spr);
    EndDrawing();
}
