#include "./include/sound.h"
#include <dc/sound/sfxmgr.h>
#include <stdio.h>


void enableSound(Chime* ch)
{
    sfxhnd_t snd = snd_sfx_load(ch->fileName);
    // check if wave file is valid
    if (snd == SFXHND_INVALID)
        {
            fprintf(stderr, "ERROR: ring WAVE file in path %s could not be loaded!\n", ch->fileName);
            return;
        }
    ch->chimeSound = snd;
}
void disableSound(Chime* ch)
{
    snd_sfx_unload(ch->chimeSound);
}

void playChime(Chime* ch)
{
    // Play the sound effect at full volume, centered
    snd_sfx_play(ch->chimeSound, 255, 128);

}
