/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** giant_huff
*/

#include "giantman.h"

static char *array2d_to_str(char **array2d)
{
    int len = 0;
    int i = 0;
    char *str = NULL;
    int j = 0;

    for (int x = 0; array2d[x] != NULL; x++)
        len += my_strlen(array2d[x]);
    str = malloc(sizeof(char) * (len + 1));
    while (array2d[i] != NULL) {
        j += my_strcpy(str + j, array2d[i]);
        free(array2d[i]);
        i++;
    }
    str[j] = '\0';
    free(array2d);
    return str;
}

static void skip_end(char *binstr, int *j)
{
    while (binstr[*j] != '\0')
        (*j)++;
}

static char get_char_tree(char *binstr, int *j, dict_t *tree)
{
    dict_t *first = tree;
    char c = 0;

    if (binstr[*j] == '1')
        (*j)++;
    else if (binstr[*j] == '0') {
        skip_end(binstr, j);
        return '\0';
    }
    while (tree->car == '\0' && binstr[*j] != '\0') {
        if (binstr[*j] == '0')
            tree = tree->left;
        else
            tree = tree->right;
        (*j)++;
    }
    c = tree->car;
    tree = first;
    return c;
}

void decompress(char *output, char *binstr, dict_t *tree)
{
    int i = 0;
    int j = 0;

    while (binstr[j] != '\0') {
        output[i] = get_char_tree(binstr, &j, tree);
        i++;
    }
    output[i] = '\0';
}

char *load_binstr(char *buffer, int size, int i)
{
    int j = 0;
    char **array2d = malloc(sizeof(char*) * (size + 1));

    while (i <= size) {
        array2d[j] = bin_to_str_control(buffer[i]);
        i++;
        j++;
    }
    array2d[j] = NULL;
    return array2d_to_str(array2d);
}