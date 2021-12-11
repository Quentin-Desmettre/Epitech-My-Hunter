/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** description.c
*/

#include "hunter.h"

int description2(void)
{
    write(1,
    "|     it flies away, so be quick and precise !                        |\n"
    "|                                                                     |\n"
    "| If you scored a high enough score, it will be stored and printed in |\n"
    "|     the high scores section.                                        |\n"
    "|                                                                     |\n"
    "|                            Good luck !                              |\n"
    "|                                                                     |\n"
    " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
    " ~~~~~~~~~~~  My hunter, 2021 - Made by Quentin Desmettre  ~~~~~~~~~~~ \n"
    " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n",
    722);
    return 0;
}

int description(void)
{
    write(1,
    "\n"
    " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
    " ~~~~~~~~~~~  My hunter - A Duck Hunt inspired video game  ~~~~~~~~~~~ \n"
    " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
    "|                                                                     |\n"
    "| In this game, you have 9 rounds to shoot as much duck as possible.  |\n"
    "| Each successful shot increases your score,                          |\n"
    "|     according to the duck color.                                    |\n"
    "|                                                                     |\n"
    "| Each round, you can shoot up to 10 ducks. To get to the n + 1       |\n"
    "|     round, you have to shoot at least n + 1 ducks.                  |\n"
    "|                                                                     |\n"
    "| Beware, the duck's speed depends on the round and on his color,     |\n"
    "|     and their movements are randomized !                            |\n"
    "|                                                                     |\n"
    "| Blue ducks are slow, black ones are normal and red ones are fast.   |\n"
    "| You only have 3 bullets and 5 seconds to shoot a duck before        |\n"
    , 1154);
    return description2();
}
