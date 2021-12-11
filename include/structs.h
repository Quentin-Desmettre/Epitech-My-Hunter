/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** structs.h
*/

#ifndef STRUCTS_H
    #define STRUCTS_H
    #include "hunter.h"

typedef struct sprite {
    sfSprite *sprite;
    sfClock *clock;
    int state;
} sprite_t;

typedef struct duck {
    sprite_t *sprite;
    float x_dir;
    float y_dir;
    float rotation;
    int ms_new_dir;
    duck_color color;
    float distance;
    sfClock *state_clock;
    duck_state_e state;
    anim_state_duck anim_state;
    int sprite_dir;
    float scale;
    sprite_t *shot_sprite;
} duck_t;

typedef struct dog {
    sprite_t *sprite;
    dog_anim anim_state;
    float sprite_dir;
    sfClock *clock_snif;
    sfClock *clock_pause;
} dog_t;

typedef struct background {
    sprite_t *sprite;
    sfColor color;
    sprite_t *sprite_away;
} background_t;

typedef struct {
    int r;
    sfSprite *sprite;
    int duck_shot;
} round_t;

typedef struct {
    int r;
    sfSprite *sprite;
} tempo;

typedef tempo bullets_t;
typedef tempo score_t;
typedef tempo duck_left_t;

typedef struct {
    round_t *round;
    bullets_t *bullets_left;
    score_t *score;
    duck_left_t *ducks;
} game_infos;

typedef struct {
    sprite_t *title;
    sprite_t *scores;
    int cur_pos;
    sprite_t *cursor;
    int is_score;
} title_screen_t;

typedef struct {
    sprite_t *round;
    sprite_t *congrats;
    title_screen_t *title;
} static_draw;

typedef struct my_window {
    sfRenderWindow *window;
    background_t *back;
    dog_t *dog;
    duck_t *duck;
    int can_shot;
    sprite_order order;
    game_infos *infos;
    anim_state_window anim_state;
    static_draw *draws;
    sprite_t *game_over;
    sfSound **sounds;
    int index_sound;
    sfMusic *title_music;
} window_t;

#endif
