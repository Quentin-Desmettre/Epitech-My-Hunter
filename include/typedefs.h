/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** typedefs.h
*/

#ifndef TYPEDEFS_H
    #define TYPEDEFS_H
    #include "hunter.h"

typedef enum {
    DOG_LOOKIN, DOG_SHOW, DOG_LAUGH,
    DOG_SNIF, DOG_EXCITED, DOG_JUMP, NONE
} dog_anim;

typedef enum {
    DOG_GROUND, GROUND_DOG
} sprite_order;

typedef enum {
    RIGHT_1, RIGHT_2, RIGHT_3,
    UP_R_1, UP_R_2, UP_R_3,
    UP_1, UP_2, UP_3,
    SHOT_1, SHOT_2
} duck_state_e;

typedef enum {
    LAUNCH, FLY, DUCK_SHOT_1,
    NONE_DUCK, FLY_AWAY, DUCK_SHOT_2
} anim_state_duck;

typedef enum {
    DUCK_BLUE, DUCK_BLACK, DUCK_RED
} duck_color;

typedef enum {
    WINDOW_ROUND, WINDOW_TITLE_SCREEN,
    WINDOW_CONGRATS, WINDOW_GAMEOVER,
    WINDOW_OTHER
} anim_state_window;

#endif
