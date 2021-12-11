/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** audio.c
*/

#include "hunter.h"

void stop_audio(window_t *window, int index)
{
    if (index < 0)
        return;
    if (index == AUDIO_TITLE)
        sfMusic_stop(window->title_music);
    else
        sfSound_stop(window->sounds[index]);
}

void pause_audio(window_t *window, int index)
{
    if (index < 0)
        return;
    if (index == AUDIO_TITLE)
        sfMusic_pause(window->title_music);
    else
        sfSound_pause(window->sounds[index]);
}

void play_audio(window_t *window, int index)
{
    window->index_sound = index;
    if (index < 0)
        return;
    if (index == 12 && !window->title_music)
        return;
    else if (index != 12 && !window->sounds[window->index_sound])
        return;
    if (window->index_sound == AUDIO_TITLE) {
        if (window->title_music)
            sfMusic_play(window->title_music);
    } else
        sfSound_play(window->sounds[window->index_sound]);
}

void resume_audio(window_t *window, int index)
{
    if (window->index_sound < 0)
        return;
    play_audio(window, index);
}

void destroy_musics(window_t *window)
{
    sfMusic_destroy(window->title_music);
    for (int i = 0; i < 12; i++) {
        sfSoundBuffer_destroy(
        (sfSoundBuffer *)sfSound_getBuffer(window->sounds[i]));
        sfSound_destroy(window->sounds[i]);
    }
}
