/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** my_sokoban
*/

#include "my_sokoban.h"

int sokoban(char *map_path)
{
    int result;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    result = sokoban_game(map_path);
    endwin();
    return result;
}

int sokoban_game(char *map_path)
{
    int result = 0;
    game_t *game;

    if ((game = sokoban_init(map_path)) == NULL)
        return 84;
    if ((game->map = rawmap_to_array(game->raw_map)) == NULL)
        return 84;
    result = sokoban_loop(game, map_path);
    sokoban_free(game);
    if (result == 2)
        result = sokoban_game(map_path);
    return result;
}

game_t *sokoban_init(char *map_path)
{
    game_t *game;
    char *raw_map;

    if ((game = malloc(sizeof(game_t))) == NULL)
        return NULL;
    if ((game->raw_map = get_rawmap(map_path)) == NULL)
        return NULL;
    if (check_map(game->raw_map) == 84)
        return NULL;
    if ((game->holes = get_objects(game->raw_map, 'O')) == NULL)
        return NULL;
    if ((game->crates = get_objects(game->raw_map, 'X')) == NULL)
        return NULL;
    if ((game->player = find_player(game->raw_map)) == NULL)
        return NULL;
    return game;
}

int sokoban_loop(game_t *g, char *map_path)
{
    int key;
    int nb_crates = get_nb_objects(g->raw_map, 'X');

    while (key != 32) {
        clear();
        check_and_move_player(g, key);
        if (check_win(g->map, g->holes, nb_crates) == 1) {
            endgame_show_map(g->map);
            return 0;
        }
        if (check_lose(g) == 1) {
            endgame_show_map(g->map);
            return 1;
        }
        show_map(g->map);
        key = getch();
        refresh();
    }
    return 2;
}

int main(int ac, const char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
            return option_h();
        return sokoban(av[1]);
    }
    return 84;
}
