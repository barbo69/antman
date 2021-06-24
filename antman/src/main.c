/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** main
*/

#include "antman.h"

void print_list(list_t *list)
{
    list_t *copy = list;
    char conv_proof = '\a';

    write(1, &conv_proof, 1);
    while (list != NULL) {
        my_putchar(list->car);
        my_put_nbr(list->occu);
        my_putchar('\\');
        list = list->next;
    }
    write(1, "\n\n", 2);
    list = copy;
}

int ant_huffman_control(char *filepath)
{
    list_t *list;
    dict_t *dict;
    char *buffer;
    char *str;
    int error = 0;

    if ((open_file(filepath, &buffer)) == 0) {
        list = occurences_control(buffer, &error);
        if (error == 0) {
            print_list(list);
            dict = create_dict(list);
            str = buffer_to_binstr(buffer, dict);
            char_to_bin_control(str);
        }
        return (0);
    }
    return (84);
}

int is_num(char *arg)
{
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] > '9' || arg[i] < '0')
            return 84;
    }
    return (0);
}

int syntax_error_control(int ac, char **av)
{
    if (ac != 3) {
        write(2, "Usage: ./antman filepath type\n", 30);
        return 84;
    }
    if (my_strlen(av[2]) != 1 || is_num(av[2]) == 84) {
        write(2, "error: expected type (1~3) but got: ", 35);
        write(2, av[2], my_strlen(av[2]));
        write(2, "\n", 1);
        return (84);
    }
    if (my_getnbr(av[2]) > 3 || my_getnbr(av[2]) < 1) {
        write(2, "error: expected type (1~3) but got:", 35);
        write(2, av[2], my_strlen(av[2]));
        write(2, "\n", 1);
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    int error = 84;

    if (syntax_error_control(ac, av) == 84)
        return 84;
    error = ant_huffman_control(av[1]);
    return (error);
}