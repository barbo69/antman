/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** create_dict_v2
*/

#include "antman.h"

static void merge_leaves(dict_t **queue, int nb_nodes)
{
    dict_t *right = give_smallest(queue, nb_nodes);
    dict_t *left = give_smallest(queue, nb_nodes);
    dict_t *new = malloc(sizeof(dict_t));

    new->weight = right->weight + left->weight;
    new->car = '\0';
    new->left = left;
    new->right = right;
    new->str = cat_str(left, right);
    new->first = 0;
    place_node(new, queue);
}

static dict_t **create_queue(list_t **list, int nb_nodes)
{
    dict_t **queue = malloc(sizeof(dict_t) * (nb_nodes + 1));

    for (int i = 0; i <= nb_nodes; i++)
        queue[i] = NULL;
    for (int i = 0; i < nb_nodes; i++) {
        queue[i] = create_leaf(list);
    }
    return queue;
}

static int count_list_nodes(list_t *list)
{
    list_t *copy = list;
    int cmpt = 0;

    while (list != NULL) {
        cmpt++;
        list = list->next;
    }
    list = copy;
    return cmpt;
}

dict_t *create_dict(list_t *list)
{
    int nb_nodes = count_list_nodes(list);
    dict_t **queue = create_queue(&list, nb_nodes);
    dict_t *dico;

    for (int i = 0; i < nb_nodes - 1; i++)
        merge_leaves(queue, nb_nodes);
    dico = queue[0];
    dico->first = 1;
    free(queue);
    return dico;
}