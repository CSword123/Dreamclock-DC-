#ifndef SOUND_H
#define SOUND_H
#include <dc/sound/sfxmgr.h>
#include <raylib.h>

typedef struct chime
{
    const char* fileName;
    sfxhnd_t chimeSound;
} Chime;

void enableSound(Chime* ch);                           // loads both ring sfx
void disableSound(Chime* ch);
void playChime(Chime* ch);

#endif
