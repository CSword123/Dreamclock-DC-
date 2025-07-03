#ifndef SOUND_H
#define SOUND_H
#include <raylib.h>

typedef struct chime
{
    const char* fileName;
    Wave chimeWave;
    Sound chimeSound;
} Chime;

void enableWave(Chime* ch);                           // loads both wave files as sounds
void disableWave(Chime* ch);
void enableSound(Chime* ch);                           // loads both ring sfx
void disableSound(Chime* ch);
void playChime(Chime* ch);

#endif
