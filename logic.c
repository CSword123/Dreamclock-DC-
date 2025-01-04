
#include "./include/logic.h"
#include "./include/sprite.h"
#include "./include/config.h"
#include <raylib.h>


// void processInput();
void update(Sprite* faceSpr, Sprite* handSpr)
{
    // rotate seconds hand in sync with frame timing
    handSpr[2].rotation += 360.0f * GetFrameTime();
}
void render(Sprite* faceSpr, Sprite* handSpr)
{
    BeginDrawing();
        ClearBackground(BLUE);
        drawFaceSprite(faceSpr);
        for (int i = 0; i < HAND_COUNT; i++)
        {
            drawRotatedHandSprite(&handSpr[i]);
        }
        drawRotatedHandSprite(handSpr);
        DrawFPS(10, 10);
    EndDrawing();

}
