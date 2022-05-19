/*
** EPITECH PROJECT, 2022
** game
** File description:
** game
*/

#include "my_sokoban.h"

int check_win(char **map, vector_t **holes, int nb_crates)
{
    int nb_filled_holes = 0;
    for (int i = 0; holes[i] != NULL; i++) {
        if (map[holes[i]->y][holes[i]->x] == 'X')
            nb_filled_holes++;
    }
    if (nb_filled_holes == nb_crates)
        return 1;
    return 0;
}

int check_lose(game_t *game)
{
    int nb_crates = 0;
    int nb_stuck_crates = 0;
    vector_t n;
    for (int i = 0; game->crates[i] != NULL; i++) {
        n.x = game->crates[i]->x;
        n.y = game->crates[i]->y;
        if (crate_is_stuck(game, n) == 1)
            nb_stuck_crates++;
        nb_crates++;
    }
    if (nb_stuck_crates == nb_crates)
        return 1;
    return 0;
}

int crate_is_stuck(game_t *g, vector_t c)
{
    int x = c.x;
    int y = c.y;
    int c1 = (next_is_reachable(g, KEY_UP, c));
    int c2 = (next_is_reachable(g, KEY_RIGHT, c));
    int c3 = (next_is_reachable(g, KEY_DOWN, c));
    int c4 = (next_is_reachable(g, KEY_LEFT, c));
    int c5 = (c1 && g->map[y - 1][x] == '#' || g->map[y - 1][x] == 'X');
    int c6 = (c2 && g->map[y][x + 1] == '#' || g->map[y][x + 1] == 'X');
    int c7 = (c3 && g->map[y + 1][x] == '#' || g->map[y + 1][x] == 'X');
    int c8 = (c4 && g->map[y][x - 1] == '#' || g->map[y][x - 1] == 'X');
    if ((c5 && c6) || (c6 && c7) || (c7 && c8) || (c8 && c5))
        return 1;
    return 0;
}
