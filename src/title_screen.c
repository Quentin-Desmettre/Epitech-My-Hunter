/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** title_screen.c
*/

#include "hunter.h"

title_screen_t *init_title(void)
{
    title_screen_t *t = malloc( sizeof(title_screen_t));

    t->cur_pos = 1;
    t->is_score = 0;
    t->cursor = init_sprite(PNG_DOG, dog_look);
    sfSprite_setScale(t->cursor->sprite, (sfVector2f){1.8, 1.8});
    sfSprite_setPosition(t->cursor->sprite, (sfVector2f){CURSOR_X, CURSOR_Y});
    t->title = init_sprite(PNG_TITLE, title);
    sfSprite_setScale(t->title->sprite, (sfVector2f){0.5, 0.52});
    t->scores = init_sprite(PNG_SCORES, title);
    return t;
}

static_draw *init_statics(void)
{
    static_draw *draw = malloc(sizeof(static_draw));

    draw->round = init_sprite(PNG_ROUNDS, rounds);
    sfSprite_setPosition(draw->round->sprite, (sfVector2f){321.9, 130});
    sfSprite_setScale(draw->round->sprite, (sfVector2f){2.2, 2.2});
    draw->congrats = init_sprite(PNG_CONGRATS, congrats);
    sfSprite_setPosition(draw->congrats->sprite, (sfVector2f){321.9, 130});
    sfSprite_setScale(draw->congrats->sprite, (sfVector2f){2.2, 2.2});
    draw->title = init_title();
    return draw;
}

void draw_title(window_t *window)
{
    sfRenderWindow_drawSprite(window->window,
    window->draws->title->title->sprite, NULL);
    if (window->draws->title->cur_pos != 0)
        sfRenderWindow_drawSprite(window->window,
        window->draws->title->cursor->sprite, NULL);
}

void append_char(char **str, char c, int is_free)
{
    char *tmp = *str;
    int len = my_strlen(tmp) + 1;
    char *new = malloc(sizeof(char) * (len + 1));

    my_strcpy(new, tmp);
    new[len - 1] = c;
    new[len] = '\0';
    if (is_free)
        free(tmp);
    *str = new;
}
