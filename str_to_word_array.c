/*
** EPITECH PROJECT, 2022
** str_to_args
** File description:
** str_to_args
*/

#include <stdlib.h>

int is_separator(char c, const char *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        if (c == s[i])
            return 1;
    }
    return 0;
}

int get_size(char *str, const char *separ)
{
    int size = my_strlen(str);
    int nb_space = 0;
    int nb_words = 0;
    char prev = str[0];
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_separator(str[i], separ))
            nb_space++;
        if (!is_separator(str[i], separ) && is_separator(prev, separ))
            nb_words++;
        prev = str[i];
    }
    return (size - nb_space + nb_words);
}

int get_word_size(char *str, int start, const char *separators)
{
    int size = 0;
    for (int i = start; str[i] != '\0'; i++) {
        if (is_separator(str[i], separators))
            break;
        size++;
    }
    return size;
}

char *get_word(int *i, char *str, const char *separators)
{
    int k = 0;
    int char_in_word = 0;
    int word_size = get_word_size(str, *i, separators);
    char *word_str = malloc((word_size + 1) * sizeof(char));
    for (k = *i; k < *i + word_size; k++) {
        word_str[char_in_word] = str[k];
        char_in_word++;
    }
    word_str[char_in_word] = '\0';
    *i = k;
    return word_str;
}

char **str_to_word_array(char *str, const char *separators)
{
    int i = 0;
    int word = 0;
    int size = get_size(str, separators);
    char **args = malloc((size) * sizeof(char *));
    for (; str[i] != '\0'; i++) {
        if (!is_separator(str[i], separators)) {
            args[word] = get_word(&i, str, separators);
            word++;
        }
    }
    args[word] = NULL;
    return args;
}
