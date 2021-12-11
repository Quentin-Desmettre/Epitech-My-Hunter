/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** duck_meta_inf.c
*/

#include "hunter.h"

double difficulty(int round)
{
    return 2 * atan(round / 1.5 - 3.0) + 5.0;
}

void check_directions(duck_t *duck)
{
    sfVector2f pos = sfSprite_getPosition(duck->sprite->sprite);

    if (duck->anim_state == LAUNCH)
        return;
    if (pos.x + duck->x_dir > 780 ||
    pos.x + duck->x_dir < 20)
        (duck->x_dir *= -1);
    if (pos.y + duck->y_dir > 340 ||
    pos.y + duck->y_dir < 20)
        (duck->y_dir *= -1);
}

double double_mod(double base, double mod)
{
    while (base > mod)
        base -= mod;
    return base;
}

void update_dist(duck_t *duck)
{
    float x = duck->x_dir * duck->x_dir;
    float y = duck->y_dir * duck->y_dir;

    duck->distance += sqrt(x + y);
}

duck_color rand_color(int r)
{
    int n = rand() % 100;

    if (n < 10 + (r - 1) * 2)
        return DUCK_RED;
    else if (n < 25 + (r - 1) * 2)
        return DUCK_BLACK;
    else
        return DUCK_BLUE;
}
