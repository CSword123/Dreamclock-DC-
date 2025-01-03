#include <raylib.h>
#include "./include/config.h"
#include "./include/logic.h"
#include "./include/sprite.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dreamclock");
    SetTargetFPS(TARGET_FPS);

    Sprite clkFace;
    initSprite(&clkFace, "assets/images/clockFace.png");
    // create game loop and call functions to check for input, update the game logic and render the current frame
    while (!WindowShouldClose())
    {
        render(&clkFace);
    }
    unloadSprite(&clkFace);
    CloseWindow();
    return 0;
}
//
