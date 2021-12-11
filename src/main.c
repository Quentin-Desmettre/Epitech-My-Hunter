/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** main.c
*/

#include "hunter.h"
#include <stdio.h>

void new_round(window_t *window)
{
    dog_t *dog = window->dog;
    int r = window->infos->round->r;
    int d_shot = window->infos->round->duck_shot;

    sfSprite_setPosition(dog->sprite->sprite, (sfVector2f){-70, 335});
    stop_audio(window, AUDIO_TITLE);
    dog->sprite->state = 0;
    update_text(dog->sprite, dog_look);
    window->order = GROUND_DOG;
    dog->anim_state = DOG_LOOKIN;
    sfClock_restart(dog->sprite->clock);
    if (d_shot < nb_to_shot(r) || r >= 9) {
        play_game_over(window);
        return;
    }
    create_new_round(window, d_shot);
}

void draw_dog(window_t *window)
{
    if (window->dog->anim_state == NONE ||
    window->anim_state != WINDOW_OTHER)
        return;
    sfRenderWindow_drawSprite(window->window,
    window->dog->sprite->sprite, NULL);
}

void draw_duck(window_t *window)
{
    if (window->duck->anim_state == NONE_DUCK ||
    window->dog->anim_state != NONE ||
    window->anim_state != WINDOW_OTHER)
        return;
    sfRenderWindow_drawSprite(window->window,
    window->duck->sprite->sprite, NULL);
}

sprite_t *init_sprite(char const *file, sfIntRect const *rect)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfTexture *texture = sfTexture_createFromFile(file, NULL);

    sprite->state = 0;
    sprite->clock = sfClock_create();
    sfClock_restart(sprite->clock);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, texture, 0);
    sfSprite_setTextureRect(sprite->sprite, rect[sprite->state]);
    return sprite;
}

int main(int ac, char **av)
{
    sfEvent event;
    window_t *window;
    sfSprite *cursor;

    if (ac >= 2)
        if (av[1][0] == '-' && av[1][1] == 'h')
            return description();
    srand(time(NULL));
    window = init_window();
    cursor = init_cursor();
    play_audio(window, AUDIO_TITLE);
    while (sfRenderWindow_isOpen(window->window)) {
        analyse_events(window, &event);
        update_sprites(window, cursor);
    }
    destroy_musics(window);
    return 0;
}
