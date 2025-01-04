
#include "./include/logic.h"
#include "./include/sprite.h"
#include "./include/config.h"
#include <raylib.h>
#include <time.h>

void updateCurrentTime(short* sec)
{
    // Get the current system time
    time_t now = time(NULL);
    struct tm* local = localtime(&now);
    // Syncronize the second hand rotation to the system time
    *sec = (short) local->tm_sec;
}

// void processInput();
void update(Sprite* faceSpr, Sprite* handSpr)
{
    short seconds = 0;
    updateCurrentTime(&seconds);
    // rotate seconds hand in sync with frame timing
    handSpr[2].rotation = (float) seconds * 6.0f;
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
