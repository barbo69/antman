/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** ocurrences_control
*/

#include "antman.h"

list_t *create_linked_list(char *buffer)
{
    int len = my_strlen(buffer) - 1;
    list_t *last = NULL;
    list_t *new;

    for (int i = len; i >= 0; i--) {
        new = malloc(sizeof(list_t));
        new->car = buffer[i];
        new->next = last;
        last = new;
    }
    return (new);
}

int check_double(list_t *list, char double_check)
{
    list_t *last = NULL;
    int compt = 1;

    while (list != NULL) {
        if (list->car == double_check && last != NULL) {
            last->next = list->next;
            free(list);
            list = last->next;
            compt++;
        }
        else {
            last = list;
            list = list->next;
        }
    }
    return (compt);
}

void delet_double(list_t *list)
{
    list_t *character = list;

    while (character != NULL) {
        character->occu = check_double(character, character->car);
        character = character->next;
    }
    return;
}

list_t *occurences_control(char *buffer, int *error)
{
    list_t *list;

    if (buffer[0] == '\0') {
        *error = 84;
        return (NULL);
    }
    list = create_linked_list(buffer);
    delet_double(list);
    return (list);
}