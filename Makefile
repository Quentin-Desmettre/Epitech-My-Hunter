##
## EPITECH PROJECT, 2021
## B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
## File description:
## Makefile
##

all:
	make -s -C src/

clean:
	make -s -C src/ clean

fclean:
	make -s -C src/ fclean
	rm -f my_hunter

re: fclean
	make -s -C src/ re
