#include <raylib.h>
#include "./include/config.h"
#include "./include/logic.h"
#include "./include/sprite.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dreamclock");
    SetTargetFPS(TARGET_FPS);

    Sprite clockParts[4];
    initSprite(&clockParts[0], "assets/images/clockFace.png");
    initSprite(&clockParts[1], "assets/images/hourHand.png");
    initSprite(&clockParts[2], "assets/images/minuteHand.png");
    initSprite(&clockParts[3], "assets/images/secondHand.png");
    // create game loop and call functions to check for input, update the game logic and render the current frame
    while (!WindowShouldClose())
    {
        render(clockParts, 4);
    }
    unloadSprites(clockParts, 4);
    CloseWindow();
    return 0;
}
//
