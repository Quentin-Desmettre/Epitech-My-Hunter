/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** functions.h
*/

#ifndef FUNCTIONS_H
    #define FUNCTIONS_H
    #include "hunter.h"

void sort_int_array(int *a, int size);
int description(void);
void fail_shot(window_t *window);
void good_shot(window_t *window);
void draw_ducks_left(window_t *window, int nb, int color, sfVector2f *pos);
void update_ducks_left(window_t *window);
void try_shot(sfMouseButtonEvent *event, window_t *window);
void reset_dog_launch(window_t *window);
void anim_dog_looking(window_t *window);
void anim_dog_show(window_t *window);
void anim_dog_laugh(window_t *window);
void anim_dog(window_t *window);
void anim_duck_launch(duck_t *duck, window_t *window);
void anim_duck_fly(duck_t *duck, window_t *window);
void anim_duck_fly_away(duck_t *duck, window_t *window);
void anim_duck_shot_2(duck_t *duck, window_t *window);
void anim_duck(window_t *window);
void draw_round(window_t *window);
void draw_congrats(window_t *window);
void anim_game_over(window_t *window);
void anim_window(window_t *window);
void create_new_round(window_t *window, int d_shot);
void stop_audio(window_t *window, int index);
void pause_audio(window_t *window, int index);
void play_audio(window_t *window, int index);
void resume_audio(window_t *window, int index);
void destroy_musics(window_t *window);
background_t *init_back(void);
void update_back_fly_away(window_t *window);
void play_game_over(window_t *window);
void draw_background(window_t *window);
void draw_shot(window_t *window);
float my_random(float a, float b);
void shot(sfMouseButtonEvent *event, window_t *window);
void set_duck_dirs_away(duck_t *duck, window_t *window);
void update_text_duck(duck_t *duck);
int is_mouse_on_duck(window_t *window, sfMouseButtonEvent *event);
int cmp_texture_rect(sprite_t *sprite, int top, int left);
int ms_elapsed_clock(sfClock *clock);
void update_text(sprite_t *sprite, sfIntRect const *rect);
void move(sprite_t *sprite, float x, float y);
sfSprite *init_sf_sprite(char const *text, sfIntRect *rect,
sfVector2f pos, sfVector2f scale);
int nb_to_shot(int round);
void update_cursor_pos(window_t *window, sfSprite *cursor);
void update_cursor(window_t *window, sfSprite *cursor);
sfSprite *init_cursor(void);
void anim_duck_shot_1(duck_t *duck, window_t *window);
dog_t *init_dog(void);
void anim_dog_snif(window_t *window);
void anim_dog_excited(window_t *window);
void update_dog(dog_t *dog, int cmp_texture);
void anim_dog_jump(window_t *window);
duck_t *init_duck(void);
void change_duck_dir(duck_t *duck, window_t *window);
void launch_new_duck(duck_t *duck, window_t *window);
void cycle_duck_sprite(duck_t *duck, double rota);
void update_duck_sprite(duck_t *duck);
double difficulty(int round);
void check_directions(duck_t *duck);
double double_mod(double base, double mod);
void update_dist(duck_t *duck);
duck_color rand_color(int r);
int *get_high_scores(void);
void init_scores(window_t *window);
void write_highest_scores(int *scores, int fd);
void update_highest_scores(int score);
int ms_elapsed(sprite_t *s);
round_t *init_rounds(void);
bullets_t *init_bullets(void);
score_t *init_score(void);
duck_left_t *init_ducks(void);
game_infos *init_game_infos(void);
sprite_t *init_game_over(void);
sfSound **init_sounds(void);
sfRenderWindow *init_render_window(void);
window_t *init_window(void);
void new_round(window_t *window);
void draw_dog(window_t *window);
void draw_duck(window_t *window);
sprite_t *init_sprite(char const *file, sfIntRect const *rect);
int my_getnbr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
void my_char_swap(char *a, char *b);
char *my_revstr(char *str);
char *unsigned_to_str_base(unsigned long long nb, char const *base);
title_screen_t *init_title(void);
static_draw *init_statics(void);
void draw_title(window_t *window);
void append_char(char **str, char c, int is_free);
void draw_score(window_t *window, sfVector2f pos, sfVector2f scale);
void update_bullets(window_t *window);
void update_round(window_t *window);
void update_score(window_t *window);
void update_game_infos(window_t *window);
void update_sprites(window_t *window, sfSprite *cursor);
void title_move_cursor(sfKeyCode code, window_t *window);
void title_choose(window_t *window);
void analyze_keys(sfKeyEvent *event, window_t *window);
void analyse_events(window_t *window, sfEvent *event);

#endif
