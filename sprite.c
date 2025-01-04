#include "./include/sprite.h"
#include "./include/config.h"
#include <raylib.h>

void initClockFaceSprite(Sprite* faceSpr, const char* path)
{
    faceSpr->texture = LoadTexture(path);
    if (!IsTextureValid(faceSpr->texture))
    {
        fprintf(stderr, "ERROR: could not initialize clock texture from path %s\n", path);
        exit(EXIT_FAILURE);
    }

    faceSpr->position.x = (float) (SCREEN_WIDTH - faceSpr->texture.width) / 2;
    faceSpr->position.y = (float) (SCREEN_HEIGHT - faceSpr->texture.height) / 2;
    faceSpr->rotation = 0.0f;
    // Calculate the origin to rotate around (pivot at the center of the texture)
    faceSpr->origin.x = 0;
    faceSpr->origin.y = 0;
}

void initHandSprite(Sprite* handSpr, const char* path, float rot)
{

    handSpr->texture = LoadTexture(path);
    if (!IsTextureValid(handSpr->texture))
    {
        fprintf(stderr, "ERROR: could not initialize hand texture from path %s\n", path);
        exit(EXIT_FAILURE);
    }
    handSpr->position.x = (float) SCREEN_WIDTH / 2;
    handSpr->position.y = (float) SCREEN_HEIGHT / 2;
    handSpr->rotation = rot;
    // Calculate the origin to rotate around (pivot at the center of the texture)
    handSpr->origin.x = handSpr->texture.width / 2;
    handSpr->origin.y = handSpr->texture.height / 2;
}
void drawFaceSprite(Sprite* faceSpr)
{
    DrawTexture(faceSpr->texture, faceSpr->position.x, faceSpr->position.y, WHITE);
}
void drawRotatedHandSprite(Sprite* handSpr)
{
     DrawTexturePro(
        handSpr->texture,
        (Rectangle) {0, 0, handSpr->texture.width, handSpr->texture.height},
        (Rectangle) {handSpr->position.x, handSpr->position.y, handSpr->texture.width, handSpr->texture.height},
        handSpr->origin,
        handSpr->rotation,
        WHITE );
}
void unloadSprites(Sprite* faceSpr, Sprite* handSpr)
{
    UnloadTexture(faceSpr->texture);
    for (int i = 0; i < HAND_COUNT; i++)
        UnloadTexture(handSpr[i].texture);
}
