/*
** EPITECH PROJECT, 2020
** my_putstr by Amoz PAY
** File description:
** Displays the content of a string
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_puterr(char const *str)
{
    write(2, str, my_strlen(str));
    return (0);
}
