/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** antppm
*/

#include "antman.h"

char *antppm_skip(char *buffer, int *len)
{
    int i = 0;
    int n = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            n++;
        if (n == 2)
            break;
        i++;
    }
    *len = i;
    buffer = buffer + (i + 1);
    return (buffer);
}

void antppm_concat(char *buffer, char *buffer_skipped, int len)
{
    char *compressed_ppm;

    buffer[len] = '\0';
    compressed_ppm = my_strcat(buffer, buffer_skipped);
    my_putstr(compressed_ppm);
    free(buffer);
    free(buffer_skipped);
    free(compressed_ppm);
    return;
}

void antppm_control(char *buffer)
{
    int len = 0;
    char *buffer_skipped = antppm_skip(buffer, &len);

    buffer_skipped = antppm_compression(buffer_skipped);
    antppm_concat(buffer, buffer_skipped, len + 1);
    return;
}