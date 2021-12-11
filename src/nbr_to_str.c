/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-quentin.desmettre
** File description:
** nbr_to_str.c
*/

#include "hunter.h"

int my_strlen(char const *str)
{
    int len = 0;

    while (*str) {
        ++len;
        ++str;
    }
    return len;
}

char *my_strcpy(char *dest, char const *src)
{
    int it;

    for (it = 0; src[it]; ++it) {
        dest[it] = src[it];
    }
    dest[it] = src[it];
    return dest;
}

void my_char_swap(char *a, char *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

char *my_revstr(char *str)
{
    int length = my_strlen(str);

    for (int index = 0; index < length / 2; ++index) {
        my_char_swap(str + index, str + length - index - 1);
    }
    return str;
}

char *unsigned_to_str_base(unsigned long long nb, char const *base)
{
    char *str = "";
    unsigned long len = my_strlen(base);
    int i = 0;

    for (i = 0; nb >= len; i++) {
        append_char(&str, base[nb % len], i);
        nb /= len;
    }
    append_char(&str, base[nb % len], i);
    return my_revstr(str);
}
