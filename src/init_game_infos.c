/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** init_game_infos.c
*/

#include "hunter.h"

round_t *init_rounds(void)
{
    round_t *round = malloc(sizeof(round_t));
    sfTexture *text = sfTexture_createFromFile(PNG_TEXTS, NULL);

    round->sprite = sfSprite_create();
    sfSprite_setTexture(round->sprite, text, 0);
    sfSprite_setTextureRect(round->sprite, numbers[1]);
    sfSprite_setScale(round->sprite, (sfVector2f){2, 2});
    round->r = 0;
    round->duck_shot = 1;
    return round;
}

bullets_t *init_bullets(void)
{
    bullets_t *bullets = malloc(sizeof(bullets_t));
    sfTexture *text = sfTexture_createFromFile(PNG_TEXTS, NULL);

    bullets->sprite = sfSprite_create();
    sfSprite_setTexture(bullets->sprite, text, 0);
    sfSprite_setTextureRect(bullets->sprite, bullet[0]);
    sfSprite_setScale(bullets->sprite, (sfVector2f){3.3, 3.3});
    bullets->r = 3;
    return bullets;
}

score_t *init_score(void)
{
    score_t *score = malloc(sizeof(score_t));
    sfTexture *text = sfTexture_createFromFile(PNG_TEXTS, NULL);

    score->sprite = sfSprite_create();
    sfSprite_setTexture(score->sprite, text, 0);
    sfSprite_setScale(score->sprite, (sfVector2f){2.3, 2.3});
    score->r = 0;
    return score;
}

duck_left_t *init_ducks(void)
{
    duck_left_t *duck_left = malloc(sizeof(duck_left_t));
    sfTexture *text = sfTexture_createFromFile(PNG_TEXTS, NULL);

    duck_left->sprite = sfSprite_create();
    sfSprite_setTexture(duck_left->sprite, text, 0);
    sfSprite_setTextureRect(duck_left->sprite, ducks[0]);
    sfSprite_setScale(duck_left->sprite, (sfVector2f){2.2, 2.2});
    duck_left->r = 10;
    return duck_left;
}

game_infos *init_game_infos(void)
{
    game_infos *infos = malloc(sizeof(game_infos));

    infos->bullets_left = init_bullets();
    infos->round = init_rounds();
    infos->score = init_score();
    infos->ducks = init_ducks();
    sfSprite_setPosition(infos->round->sprite, (sfVector2f){209, 441});
    return infos;
}
