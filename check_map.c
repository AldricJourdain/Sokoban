/*
** EPITECH PROJECT, 2022
** check_map
** File description:
** check_map
*/

#include "my_sokoban.h"

int check_map(char *raw_map)
{
    int nb_p = 0;
    int nb_c = 0;
    int nb_h = 0;
    for (int i = 0; raw_map[i] != '\0'; i++) {
        if (raw_map[i] == 'P')
            nb_p++;
        if (raw_map[i] == 'X')
            nb_c++;
        if (raw_map[i] == 'O')
            nb_h++;
    }
    if (nb_p != 1 || nb_h < nb_c)
        return 84;
    if (check_map_invalid_char(raw_map) == 1)
        return 84;
    return 0;
}

int check_map_invalid_char(char *raw_map)
{
    char *authorized = " \n#XOP";

    for (int i = 0; raw_map[i] != '\0'; i++) {
        if (my_char_is_in_str(raw_map[i], authorized) == 0)
            return 1;
    }
    return 0;
}
