/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** duck.c
*/

#include "hunter.h"

duck_t *init_duck(void)
{
    duck_t *duck = malloc(sizeof(duck_t));

    duck->scale = 2.2;
    duck->sprite = init_sprite(PNG_DUCKS, duck_state);
    sfSprite_setScale(duck->sprite->sprite,
    (sfVector2f){duck->scale, duck->scale});
    sfSprite_setOrigin(duck->sprite->sprite,
    (sfVector2f){REAL_DUCK_WIDTH / 2.0, REAL_DUCK_HEIGHT / 2.0});
    duck->shot_sprite = init_sprite(PNG_TEXTS, duck_state);
    sfSprite_setScale(duck->shot_sprite->sprite, (sfVector2f){3, 3});
    duck->sprite->state = UP_1;
    duck->x_dir = 1;
    duck->y_dir = 1;
    duck->color = -1;
    duck->state_clock = sfClock_create();
    duck->anim_state = NONE_DUCK;
    return duck;
}

void change_duck_dir(duck_t *duck, window_t *window)
{
    int r = window->infos->round->r;
    int c = duck->color;

    duck->rotation += my_random(-45, 45);
    duck->rotation -= (duck->rotation >= 360) ? 360 : 0;
    duck->rotation += (duck->rotation <= -360) ? 360 : 0;
    duck->x_dir = difficulty(r) * log(c + 5) * cos(duck->rotation);
    duck->y_dir = difficulty(r) * log(c + 5) * sin(duck->rotation);
    duck->distance = 0;
}

void launch_new_duck(duck_t *duck, window_t *window)
{
    int r = window->infos->round->r;
    int c = duck->color;

    duck->rotation = (rand() % 2 == 0) ? -M_PI / 4 : M_PI / 4;
    duck->color = rand_color(r);
    duck->x_dir = difficulty(r) * log(c + 5) * cos(duck->rotation) *  1.2;
    duck->x_dir *= (rand() % 2) ? 1 : -1;
    duck->y_dir = difficulty(r) * log(c + 5) * sin(duck->rotation) * 1.2;
    duck->y_dir = (duck->y_dir < 0) ? duck->y_dir : -1 * duck->y_dir;
    duck->distance = 0;
    sfClock_restart(duck->state_clock);
    sfSprite_setPosition(duck->sprite->sprite,
    (sfVector2f){my_random(288, 511), 372});
    duck->scale = 2.2;
    sfSprite_setScale(duck->sprite->sprite,
    (sfVector2f){duck->scale, duck->scale});
    duck->anim_state = LAUNCH;
    window->infos->ducks->r -= 1;
    play_audio(window, SFX_BACKGROUND);
}

void cycle_duck_sprite(duck_t *duck, double rota)
{
    if (rota < 30)
        duck->sprite->state = (duck->sprite->state < 2) ?
        duck->sprite->state + 1 : RIGHT_1;
    else if (rota < 60)
        duck->sprite->state = (duck->sprite->state < 5 &&
        duck->sprite->state > 2) ? duck->sprite->state + 1 : UP_R_1;
    else
        duck->sprite->state = (duck->sprite->state < 8 &&
        duck->sprite->state > 4) ? duck->sprite->state + 1 : UP_1;
}

void update_duck_sprite(duck_t *duck)
{
    double rota = double_mod(duck->rotation, 90);

    sfSprite_setScale(duck->sprite->sprite,
    (sfVector2f){duck->scale, duck->scale});
    cycle_duck_sprite(duck, rota);
    if (rota < 30 && duck->x_dir < 0)
        sfSprite_scale(duck->sprite->sprite, (sfVector2f){-1, 1});
    if (rota < 60 && rota > 30) {
        if (duck->x_dir < 0)
            sfSprite_scale(duck->sprite->sprite, (sfVector2f){-1, 1});
        if (duck->y_dir > 0)
            sfSprite_scale(duck->sprite->sprite, (sfVector2f){1, -1});
    }
}
