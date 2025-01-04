#ifndef SPRITE_H
#define SPRITE_H
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Sprite
{
    Texture2D texture;
    Vector2 position;
    float rotation;
    Vector2 origin;
} Sprite;

void initClockFaceSprite(Sprite* faceSpr, const char* path);
void initHandSprite(Sprite* handSpr, const char* path, float rot);
void updateSprite();
void drawFaceSprite(Sprite* faceSpr);
void drawRotatedHandSprite(Sprite* handSpr);
void unloadSprites(Sprite* faceSpr, Sprite* handSpr);

#endif
