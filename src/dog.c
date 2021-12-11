/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** dog.c
*/

#include "hunter.h"

dog_t *init_dog(void)
{
    dog_t *dog = malloc(sizeof(dog_t));

    dog->sprite = init_sprite(PNG_DOG, dog_look);
    dog->sprite_dir = 1;
    dog->anim_state = DOG_LOOKIN;
    dog->clock_snif = sfClock_create();
    dog->clock_pause = sfClock_create();
    sfSprite_scale(dog->sprite->sprite, (sfVector2f){2.3, 2.3});
    return dog;
}

void anim_dog_snif(window_t *window)
{
    dog_t *dog = window->dog;

    if (ms_elapsed(dog->sprite) < 140)
        return;
    dog->sprite->state = (dog->sprite->state == 0) ? 1 : 0;
    update_text(dog->sprite, dog_snif);
    sfClock_restart(dog->sprite->clock);
    if (ms_elapsed_clock(dog->clock_snif) > 1000)
        dog->anim_state = DOG_EXCITED;
}

void anim_dog_excited(window_t *window)
{
    dog_t *dog = window->dog;

    if (ms_elapsed(dog->sprite) < 140)
        return;
    dog->sprite->state = 0;
    update_text(dog->sprite, &dog_excite);
    sfClock_restart(dog->sprite->clock);
    dog->anim_state = DOG_JUMP;
}

void update_dog(dog_t *dog, int cmp_texture)
{
    dog->sprite->state = (dog->sprite->state == 0) ? 1 : 0;
    dog->sprite->state = cmp_texture ? 0 : dog->sprite->state;
    dog->sprite_dir = (dog->sprite->state == 0) ? 1 : -1;
    update_text(dog->sprite, dog_jump);
    sfClock_restart(dog->sprite->clock);
}

void anim_dog_jump(window_t *window)
{
    dog_t *dog = window->dog;
    int cmp_texture = cmp_texture_rect(dog->sprite, 58, 0);
    int ms_wait = !cmp_texture * 395 +
    cmp_texture_rect(dog->sprite, 58, 122) * 118;

    if (ms_elapsed(dog->sprite) > 14 && !cmp_texture)
        move(dog->sprite, 1.87, -3.74 * dog->sprite_dir);
    if (dog->sprite->state == 1)
        window->order = DOG_GROUND;
    if (ms_elapsed(dog->sprite) < (cmp_texture ? 350 : ms_wait))
        return;
    if (dog->sprite->state == 1) {
        window->can_shot = 1;
        dog->anim_state = NONE;
        window->duck->anim_state = LAUNCH;
        launch_new_duck(window->duck, window);
        window->can_shot = 1;
        sfSprite_setPosition(dog->sprite->sprite, (sfVector2f){325, 376});
    }
    update_dog(dog, cmp_texture);
}
