/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** anim_audio.c
*/

#include "hunter.h"

void fail_shot(window_t *window)
{
    sfClock_restart(window->duck->state_clock);
    play_audio(window, SFX_FAIL);
    stop_audio(window, SFX_BACKGROUND);
    window->duck->anim_state = FLY_AWAY;
    window->can_shot = 0;
}

void good_shot(window_t *window)
{
    game_infos *inf = window->infos;
    duck_t *duck = window->duck;

    stop_audio(window, SFX_BACKGROUND);
    window->duck->anim_state = DUCK_SHOT_1;
    window->can_shot = 0;
    sfClock_restart(window->duck->sprite->clock);
    inf->score->r += (duck->color + 1) * 500;
    duck->distance = 0;
    inf->round->duck_shot++;
}

void draw_ducks_left(window_t *window, int nb, int color, sfVector2f *pos)
{
    duck_left_t *duck = window->infos->ducks;

    sfSprite_setTextureRect(duck->sprite, ducks[color]);
    for (int i = 0; i < nb; i++) {
        sfSprite_setPosition(duck->sprite, *pos);
        sfRenderWindow_drawSprite(window->window,
        duck->sprite, NULL);
        pos->x -= 18;
    }
}

void update_ducks_left(window_t *window)
{
    duck_left_t *duck = window->infos->ducks;
    int nb_white = duck->r;
    int nb_red = (10 - nb_white <= 10) ? (10 - nb_white) : 10;
    sfVector2f pos = {486, 475};

    draw_ducks_left(window, nb_white, 0, &pos);
    draw_ducks_left(window, nb_red, 1, &pos);
}

void try_shot(sfMouseButtonEvent *event, window_t *window)
{
    if (event->button != sfMouseLeft)
        return;
    shot(event, window);
}
