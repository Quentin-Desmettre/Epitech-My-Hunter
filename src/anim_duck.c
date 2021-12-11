/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** anim_duck.c
*/

#include "hunter.h"

void anim_duck_launch(duck_t *duck, window_t *window)
{
    if (duck->anim_state == NONE_DUCK)
        launch_new_duck(duck, window);
    check_directions(duck);
    move(duck->sprite, duck->x_dir, duck->y_dir);
    update_dist(duck);
    if (ms_elapsed(duck->sprite) < 75)
        return;
    update_duck_sprite(duck);
    update_text_duck(duck);
    if (sfSprite_getPosition(duck->sprite->sprite).y < 340) {
        duck->anim_state = FLY;
        duck->distance = (120 + window->infos->round->r * 50) - 10;
        sfClock_restart(duck->state_clock);
        sfClock_restart(duck->sprite->clock);
    }
    sfClock_restart(duck->sprite->clock);
}

void anim_duck_fly(duck_t *duck, window_t *window)
{
    if (duck->distance > (120 + window->infos->round->r * 50)) {
        change_duck_dir(duck, window);
        duck->distance = 0;
    }
    check_directions(duck);
    move(duck->sprite, duck->x_dir, duck->y_dir);
    update_dist(duck);
    if (ms_elapsed(duck->sprite) < 75)
        return;
    update_duck_sprite(duck);
    update_text_duck(duck);
    if (ms_elapsed_clock(duck->state_clock) > 5000) {
        stop_audio(window, SFX_BACKGROUND);
        play_audio(window, SFX_FAIL);
        duck->anim_state = FLY_AWAY;
        sfClock_restart(duck->state_clock);
    }
    sfClock_restart(duck->sprite->clock);
}

void anim_duck_fly_away(duck_t *duck, window_t *window)
{
    dog_t *dog = window->dog;
    sfVector2f pos = sfSprite_getPosition(duck->sprite->sprite);

    if (pos.y < -30 && ms_elapsed_clock(duck->state_clock) > 1700) {
        dog->anim_state = DOG_LAUGH;
        duck->anim_state = NONE_DUCK;
        play_audio(window, SFX_LAUGH);
        dog->sprite_dir = 1;
        sfClock_restart(duck->state_clock);
        return;
    }
    set_duck_dirs_away(duck, window);
    move(duck->sprite, duck->x_dir, duck->y_dir);
    update_text_duck(duck);
    if (ms_elapsed(duck->sprite) < 30)
        return;
    update_duck_sprite(duck);
    sfClock_restart(duck->sprite->clock);
}

void anim_duck_shot_2(duck_t *duck, window_t *window)
{
    dog_t *dog = window->dog;

    duck->sprite->state = 10;
    update_text_duck(duck);
    move(duck->sprite, 0, 4);
    if (ms_elapsed(duck->sprite) > 75) {
        sfSprite_scale(duck->sprite->sprite, (sfVector2f){-1, 1});
        sfClock_restart(duck->sprite->clock);
    }
    if (sfSprite_getPosition(duck->sprite->sprite).y > 380) {
        dog->anim_state = DOG_SHOW;
        play_audio(window, SFX_SHOW);
        stop_audio(window, SFX_DUCK_FALL);
        duck->distance = 0;
        dog->sprite_dir = -1;
    }
}

void anim_duck(window_t *window)
{
    duck_t *duck = window->duck;
    void (*animations[6])(duck_t *, window_t *) =
    {&anim_duck_launch, &anim_duck_fly, &anim_duck_shot_1,
    &anim_duck_launch, &anim_duck_fly_away, &anim_duck_shot_2};

    if (duck->anim_state == NONE_DUCK && window->dog->anim_state != NONE)
        return;
    animations[duck->anim_state](duck, window);
}
