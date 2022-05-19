/*
** EPITECH PROJECT, 2022
** get_objects
** File description:
** get_objects
*/

#include "my_sokoban.h"

vector_t **get_objects(char *map, char obj)
{
    vector_t **objects;
    int nb_obj = get_nb_objects(map, obj);
    objects = malloc(sizeof(vector_t *) * nb_obj);
    get_objects_position(map, objects, obj);
    return objects;
}

int get_nb_objects(char *map, char obj)
{
    int x = 0;
    int y = 0;
    int count = 0;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == obj)
            count++;
        x++;
        if (map[i] == '\n') {
            x = 0;
            y++;
        }
    }
    return count;
}

void get_objects_position(char *map, vector_t **objects, char obj)
{
    int x = 0;
    int y = 0;
    int current = 0;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == obj) {
            objects[current] = malloc(sizeof(vector_t));
            objects[current]->x = x;
            objects[current]->y = y;
            current++;
        }
        x++;
        if (map[i] == '\n') {
            x = 0;
            y++;
        }
    }
    objects[current] = NULL;
}
