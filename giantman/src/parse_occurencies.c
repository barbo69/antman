/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** parse_occurencies
*/

#include "giantman.h"

static void jump_next(char *buffer, int *i)
{
    while (buffer[*i] <= '9' && buffer[*i] >= '0')
        (*i)++;
    if (buffer[*i] == '\\')
        (*i)++;
}

static int check_end_dict(char *buffer, int *i)
{
    if (!(buffer[*i] == '\n' && buffer[(*i) + 1] == '\n'))
        return 1;
    return 0;
}

list_t *create_new_list(char *buffer, int *i)
{
    list_t *new = malloc(sizeof(list_t));

    new->next = NULL;
    new->car = buffer[*i];
    (*i)++;
    new->occu = my_getnbr(buffer + (*i));
    if (new->occu < 1)
        new->occu = new->occu * -1;
    return new;
}

list_t *parse_occurencies(char *buffer, int *i)
{
    list_t *new = NULL;
    list_t *prev = NULL;
    list_t *first = NULL;

    if (buffer[0] != '\a')
        return NULL;
    else
        (*i)++;
    while (buffer[*i] != '\0' && check_end_dict(buffer, i)) {
        new = create_new_list(buffer, i);
        if (prev != NULL)
            prev->next = new;
        if (first == NULL)
            first = new;
        prev = new;
        jump_next(buffer, i);
    }
    (*i) += 2;
    return first;
}