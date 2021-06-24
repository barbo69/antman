/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** conversion_to_char
*/

#include "giantman.h"

void base_check(int rest, char *result, int i)
{
    if (rest == 10)
        result[i] = 'a';
    if (rest == 11)
        result[i] = 'b';
    if (rest == 12)
        result[i] = 'c';
    if (rest == 13)
        result[i] = 'd';
    if (rest == 14)
        result[i] = 'e';
    if (rest == 15)
        result[i] = 'f';
    if (rest < 10)
        result[i] = rest + 48;
    return;
}

int number_of_div(unsigned char decvar, int base)
{
    int i = 0;

    while (decvar > 0) {
        decvar = decvar / base;
        i++;
    }
    return (i);
}

char *decimal_to_base(unsigned char decvar, int base)
{
    int i = 8;
    char *result = malloc(sizeof(char) * (i + 1));
    int rest = 0;

    result[i] = '\0';
    if (i == 0)
        result[0] = '0';
    while (i > 0) {
        rest = decvar % base;
        base_check(rest, result, (i - 1));
        decvar = decvar / base;
        i--;
    }
    return (result);
}

char *bin_to_str_control(unsigned char car)
{
    char *bin = decimal_to_base(car, 2);

    return (bin);
}