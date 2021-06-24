/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** antppm_compression
*/

#include "antman.h"

void antppm_switch(char *buffer, int *i, int *compt, char *nb)
{
    if (*compt == 0) {
        *nb = buffer[*i] - 47;
        *nb = (*nb << 4);
        *i = *i + 1;
        *compt = 1;
    }
}

void antppm_spec_car(char *buffer, int i)
{
    if (buffer[i] == ' ')
        buffer[i] = 12 + 47;
    if (buffer[i] == '\n')
        buffer[i] = 11 + 47;
}

char *antppm_compression(char *buffer)
{
    int len = my_strlen(buffer);
    char *str = malloc(sizeof(char) * len);
    char nb;
    int compt = 0;
    int n = 0;

    for (int i = 0; i < len; i++) {
        antppm_spec_car(buffer, i);
        antppm_switch(buffer, &i, &compt, &nb);
        antppm_spec_car(buffer, i);
        if (compt == 1 && buffer[i] != '\0') {
            nb = (nb | (buffer[i] - 47));
            str[n] = nb;
            n++;
            compt = 0;
        } else
            str[n] = nb;
    }
    return (str);
}