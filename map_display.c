/*
** EPITECH PROJECT, 2022
** map_display
** File description:
** map_display
*/

#include "my_sokoban.h"

void show_map(char **map)
{
    int hei = 0;
    int len = 0;
    int tmp_len = 0;
    char *msg = "Too small window (please resize the window)";
    for (int y = 0; map[y] != NULL; y++)
        hei++;
    for (int y = 0; map[y] != NULL; y++) {
        tmp_len = my_strlen(map[y]);
        if (tmp_len > len)
            len = tmp_len;
    }
    if (hei > LINES || len > COLS) {
        mvprintw(LINES / 2, COLS / 2 - my_strlen(msg) / 2, "%s", msg);
        return;
    }
    for (int y = 0; map[y] != NULL; y++)
        mvprintw(LINES / 2 + y - hei / 2, COLS / 2 - len / 2, "%s", map[y]);
}

void endgame_show_map(char **map)
{
    show_map(map);
    refresh();
    usleep(ENDGAME_SLEEP);
}
