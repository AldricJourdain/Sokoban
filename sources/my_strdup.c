/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int i = 0;
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1));
    for (i = 0; i < len; i++) {
        str[i] = src[i];
    }
    str[i] = '\0';
    return (str);
}
