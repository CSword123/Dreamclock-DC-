
#include "./include/logic.h"
#include <raylib.h>
#include <time.h>

bool isSoundToggleOn = false;

void updateKeyboard(void)
{
    bool isSKeyPressed = false;
    isSKeyPressed = IsKeyPressed(KEY_S);
    if (isSKeyPressed)
        isSoundToggleOn = !isSoundToggleOn;
}
void updateController(void)
{
    bool isAButPressed = false;
    isAButPressed = IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
    if (isAButPressed && !isSoundToggleOn)
        isSoundToggleOn = !isSoundToggleOn;
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
