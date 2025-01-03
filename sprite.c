#include "./include/sprite.h"
#include "./include/config.h"

void initSprite(Sprite* spr, const char* path)
{

    spr->texture = LoadTexture(path);
    if (!IsTextureValid(spr->texture))
    {
        fprintf(stderr, "ERROR: could not initialize texture from path %s\n", path);
        exit(EXIT_FAILURE);
    }
    spr->position.x = (float) (SCREEN_WIDTH - spr->texture.width) / 2;
    spr->position.y = (float) (SCREEN_HEIGHT - spr->texture.height) / 2;
}

void drawSprite(Sprite* spr)
{
    DrawTexture(spr->texture, spr->position.x, spr->position.y, WHITE);
}

void unloadSprites(Sprite* spr, const int COUNT)
{
    for (int i = 0; i < COUNT; i++)
        UnloadTexture(spr[i].texture);
}
