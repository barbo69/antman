/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** open_file
*/

#include "giantman.h"

int open_init(char *filepath, int fd)
{
    fd = open(filepath, O_RDONLY);
    if (fd < 0) {
        my_puterr("FILE CANNOT BE OPENED\n");
        return (fd);
    }
    return (fd);
}

int stat_init(char *filepath, int s, int *file_size)
{
    struct stat file_info;

    s = stat(filepath, &file_info);
    if (s < 0) {
        my_puterr("FILE CANNOT BE OPENED\n");
        return (s);
    }
    *file_size = file_info.st_size;
    return (s);
}

int read_init(int fd, int file_size, char **buffer)
{
    int r = 0;
    char *str = malloc(sizeof(char) * (file_size + 1));

    r = read(fd, str, file_size);
    if (r < 0) {
        my_puterr("UNREADABLE FILE\n");
        return (r);
    }
    str[file_size] = '\0';
    *buffer = str;
    return (r);
}

int open_file(char *filepath, char **buffer, int *file_size)
{
    int fd = 0;
    int s = 0;
    int r = 0;

    fd = open_init(filepath, fd);
    if (fd < 0)
        return (84);
    s = stat_init(filepath, s, file_size);
    if (s < 0)
        return (84);
    r = read_init(fd, *file_size, buffer);
    if (r < 0)
        return (84);
    return (0);
}