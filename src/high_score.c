/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** high_score.c
*/

#include "hunter.h"

int *get_high_scores(void)
{
    int *scores = malloc(sizeof(int) * 3);
    FILE *fd = fopen("scores", "r");
    char *tmp = 0;
    unsigned long t = 0;

    for (int i = -1; i < 2; i++, scores[i] = 0);
    if (!fd)
        return scores;
    for (int i = 0; i < 3; i++) {
        getline(&tmp, &t, fd);
        t = my_getnbr(tmp);
        free(tmp);
        tmp = 0;
        scores[i] = t;
    }
    fclose(fd);
    return scores;
}

void init_scores(window_t *window)
{
    int *scores = get_high_scores();

    sort_int_array(scores, 3);
    for (int i = 0; i < 3; i++) {
        window->infos->score->r = scores[2 - i];
        draw_score(window, (sfVector2f){450, 190 + i * 84},
        (sfVector2f){5.2, 5.2});
    }
    window->infos->score->r = 0;
    free(scores);
}

void write_highest_scores(int *scores, int fd)
{
    char *tmp;

    for (int i = 0; i < 3; i++) {
        tmp = unsigned_to_str_base(scores[3 - i], "0123456789");
        write(fd, tmp, my_strlen(tmp));
        write(fd, "\n", 1);
        free(tmp);
    }
}

void update_highest_scores(int score)
{
    int *scores = get_high_scores();
    int *dup = malloc(sizeof(int) * 4);
    int fd = open("scores", O_WRONLY | O_TRUNC | O_CREAT,
    S_IROTH | S_IRGRP | S_IRUSR | S_IWUSR | S_IWGRP | S_IWOTH);

    if (fd < 0 || scores == 0)
        return;
    for (int i = 0; i < 3; i++)
        dup[i] = scores[i];
    dup[3] = score;
    sort_int_array(dup, 4);
    write_highest_scores(dup, fd);
    free(dup);
    free(scores);
    close(fd);
}

int ms_elapsed(sprite_t *s)
{
    return sfTime_asMilliseconds(sfClock_getElapsedTime(s->clock));
}
