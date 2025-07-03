
#include "./include/logic.h"
#include <raylib.h>
#include <time.h>
#include <stdio.h>

bool isSoundToggleOn = false;

void updateKeyboard(void)
{
    static bool isSKeyPressed = false;
    isSKeyPressed = IsKeyPressed(KEY_S);
    if (isSKeyPressed)
    {
        isSoundToggleOn = !isSoundToggleOn;
        printf("sound toggle = %s\n", isSoundToggleOn ? "true" : "false");
    }
}
void updateController(void)
{
    static bool isAButPressed = false;
    isAButPressed = IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
    if (isAButPressed)
    {
        isSoundToggleOn = !isSoundToggleOn;
        printf("sound toggle = %s\n", isSoundToggleOn ? "true" : "false");
    }
}

void updateDevices(void)
{
    updateController();
    updateKeyboard();
}

void updateCurrentTime(short* hour, short* min, short* sec)
{
    // Get the current system time
    time_t now = time(NULL);
    struct tm* local = localtime(&now);
    // Syncronize the hand rotation to the system time
    *hour = (short) local->tm_hour;
    *min = (short) local->tm_min;
    *sec = (short) local->tm_sec;
}
