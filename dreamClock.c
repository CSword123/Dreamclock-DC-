// Name: Dreamclock
// Author: Hector E (BluesRedSun)
// Date: 1-4-2025
#include <raylib.h>
#include <kos.h>
#include <dc/sound/sound.h>
#include "./include/config.h"
#include "./include/logic.h"
#include "./include/sprite.h"
#include "./include/sound.h"

KOS_INIT_FLAGS(INIT_DEFAULT);

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
    // initialize the KOS sound system
    snd_init();
    // load chime sounds into memory
    ringGetChime.fileName = "rd/sounds/ring_get.WAV";
    ringLossChime.fileName = "rd/sounds/ring_loss.WAV";
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
    // shut the KOS sound system down
    snd_shutdown();
    CloseWindow();          // close Opengl context and raylib window
    return 0;
}
void processInput(void)
{
    if(IsGamepadAvailable(0))
    {
        // printf("Controller detected.\n");
        updateController();
    }
    updateKeyboard();
}
void update(void)
{
    static bool lastToggleState = false;
    static short lastHour = -1;
    static short lastMinute = -1;
    short hours = 0, minutes = 0, seconds = 0;
    updateCurrentTime(&hours, &minutes, &seconds);
    // rotate hands in sync with system time and play chimes on the hour
    if (isSoundToggleOn && !lastToggleState)
    {
        playChime(&ringGetChime);
    }
    if (isSoundToggleOn)                     // if sound playback is enabled by user and current hours value gets updated
    {
        if (hours != lastHour)                                        // hour 00 is midnight, hour 12 is noon
        {
            playChime(&ringLossChime);
        }
        else if (minutes == 30 && lastMinute != minutes)
        {
            playChime(&ringGetChime);
        }
    }
    lastToggleState = isSoundToggleOn;
    lastHour = hours;
    lastMinute = minutes;
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
       // DrawFPS(10, 10);
    EndDrawing();
}
