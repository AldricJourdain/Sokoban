/*
** EPITECH PROJECT, 2021
** include
** File description:
** include
*/

#include <fcntl.h>
#include <ncurses.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef _SOKOBAN
    #define _SOKOBAN

typedef struct vector_s {
    int x;
    int y;
} vector_t;

typedef struct game_s {
    char **map;
    char *raw_map;
    vector_t **holes;
    vector_t **crates;
    vector_t *player;
} game_t;

static const int ENDGAME_SLEEP = 50000;

int my_strlen(char const *str);
char *my_strdup(char const *src);
void my_putchar(char c);
int my_putstr(char const *str);
int my_char_is_in_str(char c, char *str);

int option_h(void);

int sokoban(char *map_path);
int sokoban_game(char *map_path);
game_t *sokoban_init(char *map_path);
int sokoban_loop(game_t *g, char *map_path);

char *get_rawmap(char *path);
char **rawmap_to_array(char *raw_map);
char **str_to_word_array(char *str, const char *separators);
int get_nb_lines(char *raw_map);
void show_map(char **map);
void endgame_show_map(char **map);

int check_map(char *raw_map);
int check_map_invalid_char(char *raw_map);
int is_valid_char(char c);

vector_t *find_player(char *raw_map);

void check_and_move_player(game_t *game, int key);
void move_player(game_t *game, vector_t n);
int next_is_reachable(game_t *g, int k, vector_t p);
void is_on_hole(game_t *g);
void move_crate(game_t *g, vector_t next);
void crate_update_position(game_t *g, vector_t n, vector_t nn);

vector_t **get_objects(char *map, char obj);
int get_nb_objects(char *map, char obj);
void get_objects_position(char *map, vector_t **objects, char obj);

int check_win(char **map, vector_t **holes, int nb_crates);
int check_lose(game_t *game);

void sokoban_free(game_t *game);
#endif
