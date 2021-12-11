/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** cursor.c
*/

#include "hunter.h"

int nb_to_shot(int round)
{
    return round + 1;
}

void update_cursor_pos(window_t *window, sfSprite *cursor)
{
    sfVector2u size = sfRenderWindow_getSize(window->window);
    sfVector2i cpos = sfMouse_getPositionRenderWindow(window->window);

    cpos.x *= cpos.x * BASE_X / size.x;
    cpos.y *= cpos.y * BASE_Y / size.y;
    sfSprite_setPosition(cursor, (sfVector2f){cpos.x, cpos.y});
}

void update_cursor(window_t *window, sfSprite *cursor)
{
    sfVector2i cpos = sfMouse_getPositionRenderWindow(window->window);
    sfVector2u size = sfRenderWindow_getSize(window->window);

    sfSprite_setPosition(cursor,
    (sfVector2f){cpos.x * BASE_X / size.x - 22.4,
    cpos.y * BASE_Y / size.y - 22.4});
    sfRenderWindow_drawSprite(window->window, cursor, NULL);
}

sfSprite *init_cursor(void)
{
    sfTexture *text = sfTexture_createFromFile(PNG_CURSOR, NULL);
    sfSprite *s = sfSprite_create();

    sfSprite_setTexture(s, text, 0);
    sfSprite_setTextureRect(s, (sfIntRect){0, 0, 32, 32});
    sfSprite_setScale(s, (sfVector2f){CURSOR_SCALE, CURSOR_SCALE});
    return s;
}

void anim_duck_shot_1(duck_t *duck, window_t *window)
{
    duck->sprite->state = 9;
    sfSprite_setScale(duck->sprite->sprite, (sfVector2f){2.3, 2.3});
    update_text_duck(duck);
    if (ms_elapsed(duck->sprite) > 500) {
        play_audio(window, SFX_DUCK_FALL);
        duck->anim_state = DUCK_SHOT_2;
        sfClock_restart(duck->sprite->clock);
    }
}
