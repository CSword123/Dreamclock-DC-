// Name: Dreamclock
// Author: Hector E (BluesRedSun)
// Date: 1-4-2025
#include <raylib.h>
#include "./include/config.h"
#include "./include/logic.h"
#include "./include/sprite.h"
#include "./include/sound.h"

static Chime ringGetChime, ringLossChime;
static Sprite clockFace = {0};
static Sprite clockHands[3] = {0};

void processInput(void);
void update(void);
void render(void);

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dreamclock");
    SetTargetFPS(TARGET_FPS);
    // start raylibs audio device and context
    InitAudioDevice();
    // load chime sounds into memory
    ringGetChime.fileName = "rd/sounds/ring_get.WAV";
    ringLossChime.fileName = "rd/sounds/ring_loss.WAV";
    enableWave(&ringGetChime);
    enableWave(&ringLossChime);
    enableSound(&ringGetChime);
    enableSound(&ringLossChime);
    // load sprite textures
    initClockFaceSprite(&clockFace, "rd/images/clockFace.png");
    initHandSprite(&clockHands[0], "rd/images/hourHand.png", 0.0f);
    initHandSprite(&clockHands[1], "rd/images/minuteHand.png", 0.0f);
    initHandSprite(&clockHands[2], "rd/images/secondHand.png", 0.0f );
    // create game loop and call functions to check for input, update the game logic and render the current frame
    while (!WindowShouldClose())
    {
        processInput();
        update();
        render();
    }
    unloadSprites(&clockFace, clockHands);
    disableSound(&ringGetChime);
    disableSound(&ringLossChime);
    disableWave(&ringGetChime);
    disableWave(&ringLossChime);
    CloseAudioDevice();
    CloseWindow();          // close Opengl context and raylib window
    return 0;
}
void processInput(void)
{
    if(IsGamepadAvailable(0))
    {
        updateController();
    }
    updateKeyboard();
}
void update(void)
{
    static short lastHour = -1;
    short hours = 0, minutes = 0, seconds = 0;
    updateCurrentTime(&hours, &minutes, &seconds);
    // rotate hands in sync with system time and play chimes on the hour
    if (isSoundToggleOn && hours != lastHour)
    {
        if (minutes != 0)
        {
            playChime(&ringGetChime);
        }
        else
        {
            playChime(&ringLossChime);
        }
        lastHour = hours;
    }
    clockHands[0].rotation = (float) hours * 30.0f;
    clockHands[1].rotation = (float) minutes * 6.0f;
    clockHands[2].rotation = (float) seconds * 6.0f;
}
void render(void)
{
    BeginDrawing();
        ClearBackground(BLUE);
        drawFaceSprite(&clockFace);
        for (int i = 0; i < HAND_COUNT; i++)
        {
            drawRotatedHandSprite(&clockHands[i]);
        }
    EndDrawing();
}
