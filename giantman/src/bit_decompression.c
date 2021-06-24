/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** bit_decompression
*/

#include "giantman.h"

void change_char(char c, char *decomp, int j)
{
    switch (c) {
    case 11:
        decomp[j] = '\n';
        break;
    case 12:
        decomp[j] = ' ';
        break;
    case 0:
        decomp[j] = '\0';
        break;
    default:
        decomp[j] = c + 47;
        break;
    }
}

void handle_spec_chars(char a, char b, char *decomp, int j)
{
    change_char(a, decomp, j);
    change_char(b, decomp, j + 1);
}

char *bit_decompression(char *buffer, int i)
{
    char *decomp = malloc(sizeof(char) * (my_strlen(buffer) * 2 + 1));
    char a = 0;
    char b = 0;
    int j = i;

    decomp = my_strncpy(decomp, buffer, i);
    while (buffer[i] != '\0') {
        a = buffer[i];
        b = a;
        a >>= 4;
        a &= 15;
        b &= 15;
        handle_spec_chars(a, b, decomp, j);
        j += 2;
        i++;
    }
    decomp[j] = '\0';
    return decomp;
}