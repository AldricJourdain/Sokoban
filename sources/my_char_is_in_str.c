/*
** EPITECH PROJECT, 2022
** my_char_is_in_str
** File description:
** my_char_is_in_str
*/

#include "stdlib.h"

char *my_strdup(char const *src);

int my_char_is_in_str(char c, char *str)
{
    char *new_str = my_strdup(str);
    if (new_str == NULL)
        return 1;
    for (int i = 0; new_str[i] != '\0'; i++) {
        if (new_str[i] == c)
            return 1;
    }
    return 0;
}
