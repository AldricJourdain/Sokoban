/*
** EPITECH PROJECT, 2022
** usage
** File description:
** usage
*/

#include "my_sokoban.h"

int option_h(void)
{
    my_putstr("USAGE\n      ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n      map  file representing the warehouse map, ");
    my_putstr("containing '#' for walls,\n           'P' for the player, ");
    my_putstr("'X' for boxes and 'O' for storage locations.\n");
    return 0;
}
