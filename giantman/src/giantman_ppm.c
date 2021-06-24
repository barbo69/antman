/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** giantman_ppm
*/

#include "giantman.h"

char *get_buffer(char *filepath, int *size)
{
    struct stat statbuf;
    char *buffer;
    int fd = open(filepath, O_RDONLY);

    stat(filepath, &statbuf);
    buffer = malloc(sizeof(char) * (statbuf.st_size + 1));
    read(fd, buffer, statbuf.st_size);
    buffer[statbuf.st_size] = '\0';
    *size = (int)statbuf.st_size;
    close(fd);
    return buffer;
}

void jump_first_lines(char *buffer, int *i)
{
    while (buffer[*i] != '\n' && buffer[*i] != '\0')
        (*i)++;
    if (buffer[*i] == '\n')
        (*i)++;
    while (buffer[*i] != '\n' && buffer[*i] != '\0')
        (*i)++;
    if (buffer[*i] == '\n')
        (*i)++;
}

void giant_ppm(char *filepath)
{
    int size = 0;
    char *buffer = get_buffer(filepath, &size);
    char *decompressed;
    int i = 0;

    jump_first_lines(buffer, &i);
    decompressed = bit_decompression(buffer, i);
    my_putstr(decompressed);
    free(decompressed);
}