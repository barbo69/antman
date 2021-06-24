/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay & baptiste barbotin
** File description:
** header
*/

#ifndef ANTMAN_H_
#define ANTMAN_H_

////////////////////////////////
////////// INCLUDES ////////////
////////////////////////////////
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

////////////////////////////////
/////// GLOBAL VARIABLES ///////
////////////////////////////////


////////////////////////////////
//////////// MACROS ////////////
////////////////////////////////


////////////////////////////////
////////// STRUCTURES //////////
////////////////////////////////

typedef struct list {
    int occu;
    char car;
    struct list *next;
}list_t;

typedef struct st_dictionnary {
    struct st_dictionnary *left;
    struct st_dictionnary *right;
    char *str;
    int weight;
    char car;
    char first;
} dict_t;

////////////////////////////////
////////// PROTOTYPES  /////////
////////////////////////////////

/////// open_file.c ///////////

int stat_init(char *filepath, int s, int *file_size);
int open_file(char *filepath, char **buffer);

////// conversion_to_bin.c ////////

void char_to_bin_control(char *car);

/////// antppm_control.c ///////////

void antppm_control(char *buffer);

////// antppm_compression.c ////////

char *antppm_compression(char *buffer);

///////// occurences_control.c /////

list_t *occurences_control(char *buffer, int *error);

/////// create_dict.c //////////////

dict_t *create_dict(list_t *list);

////// dict_dependencies.c /////////
dict_t *create_leaf(list_t **list);
dict_t *give_smallest(dict_t **queue, int nb_nodes);
void place_node(dict_t *node, dict_t **queue);
char *cat_str(dict_t *left, dict_t *right);

/// convert_char.c ////////
char *buffer_to_binstr(char *buffer, dict_t *tree);
char *array2d_to_str(char **array2d);

#endif /* !ANTMAN_H_ */
