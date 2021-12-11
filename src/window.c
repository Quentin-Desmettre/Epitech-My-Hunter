/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** window.c
*/

#include "hunter.h"

void update_sprites(window_t *window, sfSprite *cursor)
{
    sfRenderWindow_clear(window->window, window->back->color);
    draw_duck(window);
    if (window->order == GROUND_DOG) {
        draw_background(window);
        draw_dog(window);
    } else {
        draw_dog(window);
        draw_background(window);
    }
    update_back_fly_away(window);
    update_game_infos(window);
    draw_shot(window);
    update_cursor(window, cursor);
    anim_window(window);
    if (window->draws->title->cur_pos == 0)
        init_scores(window);
    sfRenderWindow_display(window->window);
}

void title_move_cursor(sfKeyCode code, window_t *window)
{
    int dir = (code == sfKeyUp) ? -1 : 1;
    int *pos = &window->draws->title->cur_pos;

    if (*pos == 0)
        return;
    *pos += dir;
    if (*pos > 3)
        *pos = 1;
    if (*pos < 1)
        *pos = 3;
    sfSprite_setPosition(window->draws->title->cursor->sprite,
    (sfVector2f){CURSOR_X, CURSOR_Y + (*pos - 1) * 68});
}

void title_choose(window_t *window)
{
    sprite_t *tmp;
    int pos = window->draws->title->cur_pos;

    if (pos == 1) {
        window->anim_state = WINDOW_ROUND;
        new_round(window);
    }
    if (pos == 2 || pos == 0) {
        tmp = window->draws->title->title;
        window->draws->title->title = window->draws->title->scores;
        window->draws->title->scores = tmp;
        window->draws->title->cur_pos = (pos == 0) ? 2 : 0;
    } else if (pos == 3)
        sfRenderWindow_close(window->window);
}

void analyze_keys(sfKeyEvent *event, window_t *window)
{
    if (event->code == sfKeyEscape) {
        update_highest_scores(window->infos->score->r);
        sfRenderWindow_close(window->window);
    }
    if (window->anim_state != WINDOW_TITLE_SCREEN)
        return;
    if (event->code == sfKeyUp || event->code == sfKeyDown)
        title_move_cursor(event->code, window);
    if (event->code == sfKeyEnter)
        title_choose(window);
}

void analyse_events(window_t *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window->window, event)) {
        if (event->type == sfEvtKeyPressed)
            analyze_keys(&event->key, window);
        if (event->type == sfEvtClosed) {
            update_highest_scores(window->infos->score->r);
            sfRenderWindow_close(window->window);
        }
        if (event->type == sfEvtMouseButtonPressed && window->can_shot)
            try_shot(&event->mouseButton, window);
    }
    if (window->anim_state <= WINDOW_TITLE_SCREEN ||
    window->anim_state == WINDOW_GAMEOVER)
        return;
    if (window->dog->anim_state != NONE)
        anim_dog(window);
    else if (window->infos->ducks->r + 1)
        anim_duck(window);
    else
        new_round(window);
}
