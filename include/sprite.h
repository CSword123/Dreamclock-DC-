#ifndef SPRITE_H
#define SPRITE_H
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Sprite
{
    Texture2D texture;
    Vector2 position;
} Sprite;

void initSprite(Sprite* spr, const char* path);
//void updateSprite();
void drawSprite(Sprite* spr);
void unloadSprite(Sprite* spr);

#endif
