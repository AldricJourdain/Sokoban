/*
** EPITECH PROJECT, 2022
** free
** File description:
** free
*/

#include "my_sokoban.h"

void sokoban_free(game_t *game)
{
    free(game->player);
    free(game->raw_map);
    for (int i = 0; game->crates[i] != NULL; i++)
        free(game->crates[i]);
    free(game->crates);
    for (int i = 0; game->holes[i] != NULL; i++)
        free(game->holes[i]);
    free(game->holes);
    for (int i = 0; game->map[i] != NULL; i++)
        free(game->map[i]);
    free(game->map);
    free(game);
}
