/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** dict_dependencies - create_dict_v2 subfunctions
*/

#include "antman.h"

dict_t *create_leaf(list_t **list)
{
    dict_t *new = malloc(sizeof(dict_t));

    new->car = (*list)->car;
    new->weight = (*list)->occu;
    new->left = NULL;
    new->right = NULL;
    new->str = NULL;
    new->first = 0;
    (*list) = (*list)->next;
    return new;
}

dict_t *give_smallest(dict_t **queue, int nb_nodes)
{
    int i = 0;
    int smallest = INT_MAX;
    int smallest_pos = i;
    dict_t *smallest_node = NULL;

    while (i < nb_nodes) {
        if (queue[i] != NULL && smallest > queue[i]->weight) {
            smallest = queue[i]->weight;
            smallest_pos = i;
        }
        i++;
    }
    smallest_node = queue[smallest_pos];
    queue[smallest_pos] = NULL;
    return smallest_node;
}

void place_node(dict_t *node, dict_t **queue)
{
    int i = 0;

    while (queue[i] != NULL)
        i++;
    queue[i] = node;
}

static char *cat_char_str(dict_t *left, dict_t *right)
{
    char str3[1];
    char *new;

    if (left->str == NULL) {
        str3[0] = left->car;
        new = my_strcat(str3, right->str);
    } else {
        str3[0] = right->car;
        new = my_strcat(left->str, str3);
    }
    return new;
}

char *cat_str(dict_t *left, dict_t *right)
{
    char *str;

    if (left->str == NULL && right->str == NULL) {
        str = malloc(sizeof(char) * 3);
        str[0] = left->car;
        str[1] = right->car;
        str[2] = '\0';
    } else if (left->str != NULL && right->str != NULL) {
        str = my_strcat(left->str, right->str);
    } else {
        str = cat_char_str(left, right);
    }
    return str;
}