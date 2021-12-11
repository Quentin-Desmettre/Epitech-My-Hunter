/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** anim_dog.c
*/

#include "hunter.h"

void reset_dog_launch(window_t *window)
{
    window->dog->anim_state = NONE;
    window->can_shot = 1;
    window->infos->bullets_left->r = 3;
    if (window->infos->ducks->r > 0) {
        window->duck->anim_state = LAUNCH;
        launch_new_duck(window->duck, window);
    } else
        window->infos->ducks->r = -1;
    sfSprite_setPosition(window->dog->sprite->sprite,
    (sfVector2f){325, 376});
}

void anim_dog_looking(window_t *window)
{
    dog_t *dog = window->dog;

    move(dog->sprite, 2.7, 0);
    if (ms_elapsed(dog->sprite) < 140)
        return;
    window->can_shot = 0;
    dog->sprite->state = (dog->sprite->state == 0) ? 1 : 0;
    update_text(dog->sprite, dog_look);
    sfClock_restart(dog->sprite->clock);
    if (sfSprite_getPosition(dog->sprite->sprite).x >= 240) {
        dog->anim_state = DOG_SNIF;
        sfClock_restart(dog->clock_snif);
    }
}

void anim_dog_show(window_t *window)
{
    dog_t *dog = window->dog;
    double y_pos;

    if (!cmp_texture_rect(dog->sprite, 0, 331)) {
        dog->sprite->state = 0;
        dog->sprite_dir = -1;
        update_text(dog->sprite, &dog_show);
    }
    move(dog->sprite, 0, 3.5 * dog->sprite_dir);
    y_pos = sfSprite_getPosition(dog->sprite->sprite).y;
    if (dog->sprite_dir <= 1 && y_pos <= 275 &&
    dog->sprite_dir != 0) {
        dog->sprite_dir = 0;
        sfClock_restart(dog->clock_pause);
    }
    if (dog->sprite_dir == 0 && ms_elapsed_clock(dog->clock_pause) > 680)
        dog->sprite_dir = 1;
    if (y_pos > 380)
        reset_dog_launch(window);
    sfClock_restart(dog->sprite->clock);
}

void anim_dog_laugh(window_t *window)
{
    dog_t *dog = window->dog;
    double y_pos;

    move(dog->sprite, 0, -3.5 * dog->sprite_dir);
    if (ms_elapsed(dog->sprite) < 100)
        return;
    y_pos = sfSprite_getPosition(dog->sprite->sprite).y;
    dog->sprite->state = (dog->sprite->state == 0) ? 1 : 0;
    update_text(dog->sprite, dog_laugh);
    if (dog->sprite_dir >= 1 && y_pos <= 275) {
        dog->sprite_dir = 0;
        sfClock_restart(dog->clock_pause);
    }
    if (dog->sprite_dir == 0 && ms_elapsed_clock(dog->clock_pause) > 680)
        dog->sprite_dir = -1;
    if (y_pos > 380)
        reset_dog_launch(window);
    sfClock_restart(dog->sprite->clock);
}

void anim_dog(window_t *window)
{
    void (*func[6])(window_t *) = {&anim_dog_looking,
    &anim_dog_show, &anim_dog_laugh,
    &anim_dog_snif, &anim_dog_excited, &anim_dog_jump};

    if (window->dog->anim_state != NONE)
        func[window->dog->anim_state](window);
}
