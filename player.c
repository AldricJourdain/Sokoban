/*
** EPITECH PROJECT, 2022
** player
** File description:
** player
*/

#include "my_sokoban.h"

void check_and_move_player(game_t *game, int key)
{
    vector_t n;
    n.x = game->player->x;
    n.y = game->player->y;
    if (next_is_reachable(game, key, *game->player) == 0)
        return;
    if (key == KEY_RIGHT)
        n.x++;
    if (key == KEY_LEFT)
        n.x--;
    if (key == KEY_UP)
        n.y--;
    if (key == KEY_DOWN)
        n.y++;
    move_player(game, n);
}

void move_player(game_t *game, vector_t n)
{
    if (game->map[n.y][n.x] != '#') {
        if (game->map[n.y][n.x] == 'X') {
            move_crate(game, n);
            return;
        }
        game->map[n.y][n.x] = 'P';
        is_on_hole(game);
        game->player->x = n.x;
        game->player->y = n.y;
    }
}

int next_is_reachable(game_t *g, int k, vector_t p)
{
    int x = p.x;
    int y = p.y;
    if (k == KEY_RIGHT && g->map[y][x + 1] != '\0')
        return 1;
    if (k == KEY_LEFT && x - 1 >= 0)
        return 1;
    if (k == KEY_UP && y - 1 >= 0 && my_strlen(g->map[y - 1]) >= y + 1)
        return 1;
    if (k == KEY_DOWN) {
        if (g->map[y + 1] != NULL && my_strlen(g->map[y + 1]) >= y + 1)
            return 1;
    }
    return 0;
}

void is_on_hole(game_t *g)
{
    vector_t *p = g->player;
    for (int i = 0; g->holes[i] != NULL; i++) {
        if (g->holes[i]->x == p->x && g->holes[i]->y == p->y) {
            g->map[g->player->y][g->player->x] = 'O';
            return;
        }
    }
    g->map[g->player->y][g->player->x] = ' ';
}

vector_t *find_player(char *raw_map)
{
    int x = 0;
    int y = 0;
    vector_t *player;

    if ((player = malloc(sizeof(vector_t))) == NULL)
        return NULL;
    for (int i = 0; raw_map[i] != '\0'; i++) {
        if (raw_map[i] == 'P') {
            player->x = x;
            player->y = y;
        }
        x++;
        if (raw_map[i] == '\n') {
            x = 0;
            y++;
        }
    }
    return player;
}
