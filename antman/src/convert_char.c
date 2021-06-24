/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** convert_char - give a char and get binary code equivalent
*/

#include "antman.h"

static int is_in_str(char c, char *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        if (c == str[i])
            return 1;
        i++;
    }
    return 0;
}

static int recursive_search(char c, dict_t *tree, char **bin_path)
{
    char *copy;

    if (tree->car != '\0')
        return 0;
    if (tree->left != NULL)
        if (is_in_str(c, tree->left->str) || c == tree->left->car) {
            copy = my_strcat(*bin_path, "0");
            free(*bin_path);
            *bin_path = copy;
            recursive_search(c, tree->left, bin_path);
            return 0;
        }
    if (tree->right != NULL)
        if (is_in_str(c, tree->right->str) || c == tree->right->car) {
            copy = my_strcat(*bin_path, "1");
            free(*bin_path);
            *bin_path = copy;
            recursive_search(c, tree->right, bin_path);
        }
    return 0;
}

char *char_to_binstr(char c, dict_t *tree)
{
    char *bin_path = malloc(sizeof(char) * 2);

    bin_path[0] = '1';
    bin_path[1] = '\0';
    recursive_search(c, tree, &bin_path);
    return bin_path;
}

char *array2d_to_str(char **array2d)
{
    int len = 0;
    int i = 0;
    char *str = NULL;
    int j = 0;

    while (array2d[i] != NULL) {
        len += my_strlen(array2d[i]);
        i++;
    }
    i = 0;
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

char *buffer_to_binstr(char *buffer, dict_t *tree)
{
    int len = my_strlen(buffer);
    char **array2d = malloc(sizeof(char *) * (len + 1));
    int i = 0;

    while (buffer[i] != '\0') {
        array2d[i] = char_to_binstr(buffer[i], tree);
        i++;
    }
    array2d[i] = NULL;
    free(buffer);
    return array2d_to_str(array2d);
}