/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** change_sprite.c
*/

#include "hunter.h"

int cmp_texture_rect(sprite_t *sprite, int top, int left)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite->sprite);

    return (rect.top == top && rect.left == left) ? 1 : 0;
}

int ms_elapsed_clock(sfClock *clock)
{
    return sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
}

void update_text(sprite_t *sprite, sfIntRect const *rect)
{
    sfSprite_setTextureRect(sprite->sprite, rect[sprite->state]);
}

void move(sprite_t *sprite, float x, float y)
{
    sfSprite_move(sprite->sprite, (sfVector2f){x, y});
}

sfSprite *init_sf_sprite(char const *text, sfIntRect *rect,
sfVector2f pos, sfVector2f scale)
{
    sfTexture *t = sfTexture_createFromFile(text, 0);
    sfSprite *s = sfSprite_create();

    sfSprite_setTexture(s, t, 0);
    if (rect)
        sfSprite_setTextureRect(s, *rect);
    if (pos.x && pos.y)
        sfSprite_setPosition(s, pos);
    sfSprite_scale(s, scale);
    return s;
}
