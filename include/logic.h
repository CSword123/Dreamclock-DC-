#ifndef LOGIC_H
#define LOGIC_H
#include <raylib.h>

extern bool isSoundToggleOn;

void updateKeyboard(void);
void updateController(void);
void updateCurrentTime(short* hour, short* min, short* sec);

#endif
