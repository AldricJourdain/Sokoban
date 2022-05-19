/*
** EPITECH PROJECT, 2022
** crate
** File description:
** crate
*/

#include "my_sokoban.h"

void move_crate(game_t *g, vector_t next)
{
    vector_t nn;
    nn.x = next.x + (next.x - g->player->x);
    nn.y = next.y + (next.y - g->player->y);
    if (g->map[nn.y][nn.x] == ' ' || g->map[nn.y][nn.x] == 'O') {
        g->map[nn.y][nn.x] = 'X';
        crate_update_position(g, next, nn);
        g->map[next.y][next.x] = 'P';
        is_on_hole(g);
        g->player->x = next.x;
        g->player->y = next.y;
    }
}

void crate_update_position(game_t *g, vector_t n, vector_t nn)
{
    for (int i = 0; g->crates[i] != NULL; i++) {
        if (g->crates[i]->x == n.x && g->crates[i]->y == n.y) {
            g->crates[i]->x = nn.x;
            g->crates[i]->y = nn.y;
            break;
        }
    }
}
