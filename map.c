/*
** EPITECH PROJECT, 2022
** map
** File description:
** map
*/

#include "my_sokoban.h"

char **rawmap_to_array(char *raw_map)
{
    char *sep = malloc(sizeof(char) * 2);

    sep[0] = '\n';
    sep[1] = '\0';
    return str_to_word_array(raw_map, sep);
}

char *get_rawmap(char *path)
{
    char *raw_map;
    struct stat *info;
    int file;

    if ((info = malloc(sizeof(struct stat))) == NULL)
        return NULL;
    if ((stat(path, info)) == -1)
        return NULL;
    if ((file = open(path, O_RDONLY)) == -1)
        return NULL;
    if ((raw_map = malloc(sizeof(char) * (info->st_size + 1))) == NULL)
        return NULL;
    read(file, raw_map, info->st_size);
    raw_map[info->st_size] = '\0';
    close(file);
    return raw_map;
}
