/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** score_infos.c
*/

#include "hunter.h"

void draw_score(window_t *window, sfVector2f pos, sfVector2f scale)
{
    score_t *score = window->infos->score;
    int s = score->r;

    for (int i = 0; i < 6; i++) {
        sfSprite_setTextureRect(score->sprite,
        numbers[s % 10]);
        s /= 10;
        sfSprite_setScale(score->sprite, scale);
        sfSprite_setPosition(score->sprite, pos);
        sfRenderWindow_drawSprite(window->window,
        score->sprite, NULL);
        pos.x -= 8 * scale.x;
    }
}

void update_bullets(window_t *window)
{
    bullets_t *b = window->infos->bullets_left;
    sfVector2f pos = {179, 479};

    for (int i = 0; i < b->r; i++) {
        sfSprite_setPosition(b->sprite, pos);
        sfRenderWindow_drawSprite(window->window,
        b->sprite, NULL);
        pos.x += 16;
    }
}

void update_round(window_t *window)
{
    round_t *round = window->infos->round;

    sfSprite_setTextureRect(round->sprite,
    numbers[round->r]);
    sfRenderWindow_drawSprite(window->window, round->sprite, 0);
}

void update_score(window_t *window)
{
    sfVector2f pos = {632, 473};

    draw_score(window, pos, (sfVector2f){2.3, 2.3});
}

void update_game_infos(window_t *window)
{
    update_bullets(window);
    update_round(window);
    update_score(window);
    update_ducks_left(window);
}
