/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** sfintrects.h
*/

#ifndef SFINTRECTS_H
    #define SFINTRECTS_H
    #include "hunter.h"

static const sfIntRect numbers[10] = {
    {0, 0, NUM_WIDTH, NUM_HEIGHT},
    {8, 0, NUM_WIDTH, NUM_HEIGHT},
    {16, 0, NUM_WIDTH, NUM_HEIGHT},
    {24, 0, NUM_WIDTH, NUM_HEIGHT},
    {32, 0, NUM_WIDTH, NUM_HEIGHT},
    {40, 0, NUM_WIDTH, NUM_HEIGHT},
    {48, 0, NUM_WIDTH, NUM_HEIGHT},
    {56, 0, NUM_WIDTH, NUM_HEIGHT},
    {64, 0, NUM_WIDTH, NUM_HEIGHT},
    {72, 0, NUM_WIDTH, NUM_HEIGHT}
};

static const sfIntRect scores[3] = {
    {0, 8, SCORE_WIDTH, SCORE_HEIGHT},
    {15, 8, SCORE_WIDTH, SCORE_HEIGHT},
    {30, 8, SCORE_WIDTH, SCORE_HEIGHT}
};

static const sfIntRect ducks[2] = {
    {47, 8, DUCK_WIDTH, DUCK_HEIGHT},
    {55, 8, DUCK_WIDTH, DUCK_HEIGHT}
};

static const sfIntRect bullet[1] = {
    {64, 8, BULLET_WIDTH, BULLET_HEIGHT}
};

static const sfIntRect shot_rect[1] = {
    {0, 33, SHOT_WIDTH, SHOT_HEIGHT}
};

static const sfIntRect fly_away[1] = {
    {0, 16, FLY_AWAY_WIDTH, FLY_AWAY_HEIGHT}
};

static const sfIntRect dog_laugh[2] = {
    {183, 58, DOG_WIDTH, DOG_HEIGHT},
    {244, 58, DOG_WIDTH, DOG_HEIGHT}
};

static const sfIntRect dog_show = {
    331, 0, 44, 44
};

static const sfIntRect dog_look[2] = {
    {0, 0, DOG_WIDTH, DOG_HEIGHT},
    {61, 0, DOG_WIDTH, DOG_HEIGHT}
};

static const sfIntRect dog_snif[2] = {
    {183, 0, DOG_WIDTH, DOG_HEIGHT},
    {244, 0, DOG_WIDTH, DOG_HEIGHT}
};

static const sfIntRect dog_excite = {
    0, 58, DOG_WIDTH, DOG_HEIGHT
};

static const sfIntRect dog_jump[2] = {
    {61, 58, DOG_WIDTH, DOG_HEIGHT},
    {122, 58, DOG_WIDTH, DOG_HEIGHT}
};

static const sfIntRect background = {
    0, 0, 368, 244
};

static const sfColor back_blue = {
    94, 156, 255, 255
    };
static const sfColor back_red = {
    255, 199, 192, 255
};

static const sfIntRect duck_state[11] = {
    {0, 0, REAL_DUCK_WIDTH, REAL_DUCK_HEIGHT},
    {40, 0, REAL_DUCK_WIDTH, REAL_DUCK_HEIGHT},
    {80, 0, REAL_DUCK_WIDTH, REAL_DUCK_HEIGHT},
    {0, 38, REAL_DUCK_WIDTH, REAL_DUCK_HEIGHT},
    {40, 38, REAL_DUCK_WIDTH, REAL_DUCK_HEIGHT},
    {80, 38, REAL_DUCK_WIDTH, REAL_DUCK_HEIGHT},
    {0, 76, REAL_DUCK_WIDTH, REAL_DUCK_HEIGHT},
    {40, 76, REAL_DUCK_WIDTH, REAL_DUCK_HEIGHT},
    {80, 76, REAL_DUCK_WIDTH, REAL_DUCK_HEIGHT},
    {0, 114, REAL_DUCK_WIDTH, REAL_DUCK_HEIGHT},
    {40, 114, REAL_DUCK_WIDTH, REAL_DUCK_HEIGHT}
};

static const sfIntRect rounds[9] = {
    {0, 0, ROUND_WIDTH, ROUND_HEIGHT},
    {71, 0, ROUND_WIDTH, ROUND_HEIGHT},
    {142, 0, ROUND_WIDTH, ROUND_HEIGHT},
    {213, 0, ROUND_WIDTH, ROUND_HEIGHT},
    {284, 0, ROUND_WIDTH, ROUND_HEIGHT},
    {0, 33, ROUND_WIDTH, ROUND_HEIGHT},
    {71, 33, ROUND_WIDTH, ROUND_HEIGHT},
    {142, 33, ROUND_WIDTH, ROUND_HEIGHT},
    {213, 33, ROUND_WIDTH, ROUND_HEIGHT}
};

static const sfIntRect congrats[1] = {
    {0, 0, CONGRATS_WIDTH, CONGRATS_HEIGHT}
};

static const sfIntRect title[1] = {
    {0, 0, TITLE_WIDTH, TITLE_HEIGHT}
};

#endif
