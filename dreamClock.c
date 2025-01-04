#include <raylib.h>
#include "./include/config.h"
#include "./include/logic.h"
#include "./include/sprite.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dreamclock");
    SetTargetFPS(TARGET_FPS);

    Sprite clockFace = {0};
    Sprite clockHands[3] = {0};
    initClockFaceSprite(&clockFace, "assets/images/clockFace.png");
    initHandSprite(&clockHands[0], "assets/images/hourHand.png", 0.0f);
    initHandSprite(&clockHands[1], "assets/images/minuteHand.png", 0.0f);
    initHandSprite(&clockHands[2], "assets/images/secondHand.png", 0.0f );

    // create game loop and call functions to check for input, update the game logic and render the current frame
    while (!WindowShouldClose())
    {
        update(&clockFace, clockHands);
        render(&clockFace, clockHands);
    }
    unloadSprites(&clockFace, clockHands);
    CloseWindow();
    return 0;
}
//
