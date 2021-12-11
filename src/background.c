/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** background.c
*/

#include "hunter.h"

background_t *init_back(void)
{
    background_t *back = malloc(sizeof(background_t));

    back->sprite = init_sprite(PNG_BACKROUND, &background);
    back->color = back_blue;
    sfSprite_scale(back->sprite->sprite, (sfVector2f){2.1978, 2.1978});
    back->sprite_away = init_sprite(PNG_TEXTS, fly_away);
    sfSprite_setPosition(back->sprite_away->sprite, (sfVector2f){325, 150});
    sfSprite_setScale(back->sprite_away->sprite, (sfVector2f){2.3, 2.3});
    return back;
}

void update_back_fly_away(window_t *window)
{
    background_t *back = window->back;
    duck_t *duck = window->duck;

    if (duck->anim_state != FLY_AWAY) {
        back->color = back_blue;
        return;
    }
    back->color = back_red;
    sfRenderWindow_drawSprite(window->window,
    back->sprite_away->sprite, NULL);
}

void play_game_over(window_t *window)
{
    play_audio(window, SFX_GAME_OVER);
    sfClock_restart(window->game_over->clock);
    window->duck->anim_state = NONE_DUCK;
    window->dog->anim_state = NONE;
    window->dog->sprite_dir = 1;
    window->anim_state = WINDOW_GAMEOVER;
}

void draw_background(window_t *window)
{
    sfRenderWindow_drawSprite(window->window,
    window->back->sprite->sprite, NULL);
}

void draw_shot(window_t *window)
{
    duck_t *duck = window->duck;
    sfVector2f pos;

    if (duck->anim_state != DUCK_SHOT_1)
        return;
    pos = sfSprite_getPosition(duck->sprite->sprite);
    pos.y += 45;
    pos.x -= 20;
    sfSprite_setTextureRect(duck->shot_sprite->sprite, scores[duck->color]);
    sfSprite_setPosition(duck->shot_sprite->sprite, pos);
    sfRenderWindow_drawSprite(window->window,
    duck->shot_sprite->sprite, NULL);
}
