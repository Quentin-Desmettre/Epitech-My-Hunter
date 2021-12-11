/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** init_window.c
*/

#include "hunter.h"
#include "sounds_path.h"

sprite_t *init_game_over(void)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfTexture *t = sfTexture_createFromFile(PNG_OVER, NULL);
    sfSprite *s = sfSprite_create();

    sfSprite_setTexture(s, t, 0);
    sfSprite_scale(s, (sfVector2f){2.2, 2.2});
    sfSprite_setPosition(s, (sfVector2f){321.9, 130});
    sprite->clock = sfClock_create();
    sprite->state = 0;
    sprite->sprite = s;
    return sprite;
}

sfSound **init_sounds(void)
{
    sfSound **sounds = malloc(sizeof(sfSound*) * 15);
    sfSoundBuffer *buffer;

    for (int i = 0; i < 12; i++) {
        sounds[i] = sfSound_create();
        buffer = sfSoundBuffer_createFromFile(sounds_paths[i]);
        sfSound_setBuffer(sounds[i], buffer);
        sfSound_setLoop(sounds[i], 0);
    }
    sfSound_setLoop(sounds[SFX_BACKGROUND], 1);
    return sounds;
}

sfRenderWindow *init_render_window(void)
{
    sfView *view = sfView_create();
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){800, 532, 32},
    "My Hunter", sfFullscreen, NULL);

    sfView_setSize(view,
    (sfVector2f){800, 532});
    sfView_setCenter(view, (sfVector2f){400, 266});
    sfRenderWindow_setView(window, view);
    sfRenderWindow_setKeyRepeatEnabled(window, 0);
    return window;
}

window_t *init_window(void)
{
    window_t *window = malloc(sizeof(window_t));

    window->window = init_render_window();
    window->duck = init_duck();
    window->back = init_back();
    window->dog = init_dog();
    window->can_shot = 0;
    window->order = GROUND_DOG;
    window->infos = init_game_infos();
    sfRenderWindow_setFramerateLimit(window->window, 60);
    sfRenderWindow_setMouseCursorVisible(window->window, 0);
    window->anim_state = WINDOW_TITLE_SCREEN;
    window->draws = init_statics();
    window->game_over = init_game_over();
    window->sounds = init_sounds();
    window->index_sound = -1;
    window->title_music = sfMusic_createFromFile(sounds_paths[AUDIO_TITLE]);
    sfMusic_setLoop(window->title_music, 1);
    return window;
}
