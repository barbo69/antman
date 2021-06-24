/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** giantman
*/

#ifndef GIANTMAN_H_
#define GIANTMAN_H_
////////////////////////////////
////////// INCLUDES ////////////
////////////////////////////////
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

////////////////////////////////
/////// GLOBAL VARIABLES ///////
////////////////////////////////


////////////////////////////////
//////////// MACROS ////////////
////////////////////////////////
#define HELP1 "Usage: ./giantman filepath compression_type\n"
#define HELP2 "Compression types:\n1->Text files\n2->.html files\n"
#define HELP3 "3->.ppm images\n"

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

///////// giantman_ppm.c ///////
char *get_buffer(char *filepath, int *size);
void jump_first_lines(char *buffer, int *i);
void giant_ppm(char *filepath);
char *bit_decompression(char *buffer, int i);

//////// giant_huff.c //////////
int giant_huff(char *buffer, int size);

//////// convert_to_str.c ////////

char *bin_to_str_control(unsigned char car);

///////// create_dict.c //////////

dict_t *create_dict(list_t *list);

/////// parse_occurencies.c //////

list_t *parse_occurencies(char *buffer, int *i);

/////// giant_huff.c /////////////

void decompress(char *output, char *binstr, dict_t *tree);
char *load_binstr(char *buffer, int size, int i);

int open_file(char *filepath, char **buffer, int *file_size);

#endif /* !GIANTMAN_H_ */