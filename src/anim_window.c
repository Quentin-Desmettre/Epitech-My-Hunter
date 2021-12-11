/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** anim_window.c
*/

#include "hunter.h"

void draw_round(window_t *window)
{
    int rou = window->infos->round->r;

    if (window->anim_state != WINDOW_ROUND)
        return;
    window->can_shot = 0;
    if (ms_elapsed(window->draws->round) > 1500) {
        window->dog->anim_state = DOG_LOOKIN;
        window->anim_state = WINDOW_OTHER;
        sfSprite_setPosition(window->dog->sprite->sprite,
        (sfVector2f){-70, 335});
    }
    window->draws->round->state = rou - 1;
    update_text(window->draws->round, rounds);
    sfRenderWindow_drawSprite(window->window,
    window->draws->round->sprite, NULL);
}

void draw_congrats(window_t *window)
{
    if (window->anim_state != WINDOW_CONGRATS)
        return;
    window->can_shot = 0;
    if (ms_elapsed(window->draws->congrats) > 1500) {
        window->anim_state = WINDOW_ROUND;
        window->dog->anim_state = NONE;
        sfClock_restart(window->draws->round->clock);
        play_audio(window, SFX_INTRO);
    }
    update_text(window->draws->congrats, congrats);
    sfRenderWindow_drawSprite(window->window,
    window->draws->congrats->sprite, NULL);
}

void anim_game_over(window_t *window)
{
    window->can_shot = 0;
    sfRenderWindow_drawSprite(window->window,
    window->game_over->sprite, NULL);
    if (ms_elapsed(window->game_over) > 4000) {
        update_highest_scores(window->infos->score->r);
        window->anim_state = WINDOW_TITLE_SCREEN;
        window->infos->round->r = 0;
        window->infos->score->r = 0;
        play_audio(window, AUDIO_TITLE);
    }
}

void anim_window(window_t *window)
{
    void (*funcs[4])(window_t *) = {
    &draw_round, &draw_title, &draw_congrats,
    &anim_game_over};

    if (window->anim_state != WINDOW_OTHER)
        funcs[window->anim_state](window);
}

void create_new_round(window_t *window, int d_shot)
{
    window->infos->round->r++;
    window->infos->ducks->r = 10;
    window->anim_state = (d_shot == 10) ? WINDOW_CONGRATS : WINDOW_ROUND;
    if (d_shot == 10) {
        window->infos->score->r += 10000;
        play_audio(window, SFX_PERFECT);
    } else
        play_audio(window, SFX_INTRO);
    sfClock_restart(window->draws->round->clock);
    sfClock_restart(window->draws->congrats->clock);
    window->infos->round->duck_shot = 0;
}
