/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** anim_duck_others.c
*/

#include "hunter.h"

float my_random(float a, float b)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = b - a;
    float r = random * diff;

    return a + r;
}

void shot(sfMouseButtonEvent *event, window_t *window)
{
    int cont = is_mouse_on_duck(window, event);

    play_audio(window, SFX_SHOT);
    if (window->infos->bullets_left->r == 0 && !cont) {
        fail_shot(window);
        return;
    }
    if (!cont)
        return;
    good_shot(window);
}

void set_duck_dirs_away(duck_t *duck, window_t *window)
{
    window->can_shot = 0;
    duck->rotation = 90;
    duck->distance = 0;
    duck->x_dir = 0;
    duck->y_dir = -2.5;
    duck->scale *= 0.992;
}

void update_text_duck(duck_t *duck)
{
    sfIntRect rect = duck_state[duck->sprite->state];

    rect.left += duck->color * 120;
    sfSprite_setTextureRect(duck->sprite->sprite, rect);
}

int is_mouse_on_duck(window_t *window, sfMouseButtonEvent *event)
{
    sfVector2u size = sfRenderWindow_getSize(window->window);
    sfFloatRect duck_rect =
    sfSprite_getGlobalBounds(window->duck->sprite->sprite);

    event->x *= 800.0 / size.x;
    event->y *= 530.0 / size.y;
    window->infos->bullets_left->r--;
    return sfFloatRect_contains(&duck_rect, event->x, event->y);
}
