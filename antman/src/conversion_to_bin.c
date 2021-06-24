/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** conversion_to_bin
*/

#include "antman.h"

char bin_to_char(char *bin)
{
    int last = my_strlen(bin) - 1;
    int power_of_two = 1;
    char result = 0;

    for (int j = last; j >= 0; j--) {
        if (bin[j] == '1')
            result += power_of_two;
        power_of_two = power_of_two * 2;
    }
    return result;
}

void clean_temp(char (*temp)[9])
{
    for (int i = 0; i <= 7; i++) {
        temp[0][i] = '0';
    }
    return;
}

void char_to_bin_free(char *strcompr, int x)
{
    write(1, strcompr, x + 1);
    free(strcompr);
}

void char_to_bin_control(char *str)
{
    int len = my_strlen(str);
    char *str_compr = malloc(sizeof(char) * (len / 8 + len % 8 + 1));
    char temp[9] = {'\0'};
    int i = 0;
    int x = 0;

    while (str[i] != '\0') {
        for (int n = 0; n <= 7 && str[i] != '\0'; n++) {
            temp[n] = str[i];
            i++;
        }
        str_compr[x] = bin_to_char(temp);
        clean_temp(&temp);
        x++;
    }
    str_compr[(len / 8) + 1] = '\0';
    char_to_bin_free(str_compr, x);
    return;
}