##
## EPITECH PROJECT, 2021
## B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
## File description:
## Makefile
##

SRC = \
	anim_audio.c        \
	anim_dog.c 			\
	anim_duck.c 		\
	anim_window.c 		\
	audio.c 			\
	background.c 		\
	change_duck.c 		\
	change_sprite.c 	\
	cursor.c 			\
	description.c 		\
	dog.c 				\
	duck_meta_inf.c 	\
	duck.c 				\
	high_score.c 		\
	init_game_infos.c 	\
	init_window.c 		\
	main.c 				\
	my_getnbr.c 		\
	nbr_to_str.c 		\
	title_screen.c 		\
	update_game_infos.c \
	window.c

OBJ = $(SRC:.c=.o)

SFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

NAME = my_hunter

all:
	gcc -c -Wall -g -Wextra $(SRC) -I ../include/ $(SFML) -lm
	gcc -o $(NAME) $(OBJ) $(SFML) -lm
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:
	make clean
	rm -f window

re: fclean
	make all
