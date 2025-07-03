#include "./include/sound.h"
#include <raylib.h>
#include <stdio.h>


void enableWave(Chime* ch)
{
    Wave wav = LoadWave(ch->fileName);
    // check if wave file is valid
    if (!IsWaveValid(wav))
        {
            fprintf(stderr, "ERROR: ring WAVE file in path %s could not be loaded!\n", ch->fileName);
            return;
        }
    ch->chimeWave = wav;
}
void disableWave(Chime* ch)
{
    UnloadWave(ch->chimeWave);
}
void enableSound(Chime* ch)
{
    Sound snd = LoadSoundFromWave(ch->chimeWave);
    // check if sound is valid
    if (!IsSoundValid(snd))
        {
            fprintf(stderr, "ERROR: ring SOUND file in path %s could not be loaded!\n", ch->fileName);
            return;
        }
    ch->chimeSound = snd;
}
void disableSound(Chime* ch)
{
    UnloadSound(ch->chimeSound);
}

void playChime(Chime* ch)
{
    PlaySound(ch->chimeSound);
}
