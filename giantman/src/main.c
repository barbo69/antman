/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-antman-amoz.pay
** File description:
** main
*/

#include "giantman.h"

static void print_help(void)
{
    write(2, HELP1, my_strlen(HELP1));
    write(2, HELP2, my_strlen(HELP2));
    write(2, HELP3, my_strlen(HELP3));
    return;
}

int giant_huff(char *buffer, int size)
{
    int i = 0;
    list_t *list = parse_occurencies(buffer, &i);
    dict_t *dict;
    char *binstr;
    char *output;

    if (list == NULL) {
        return 0;
    }
    dict = create_dict(list);
    binstr = load_binstr(buffer, size, i);
    output = malloc(sizeof(char) * (my_strlen(binstr) + 1));
    decompress(output, binstr, dict);
    free(binstr);
    my_putstr(output);
    return (0);
}

static int handle_errors(int ac, char **av, int *size, char **buffer)
{
    int fd = 0;

    if (ac != 3) {
        print_help();
        return 84;
    }
    if ((open_file(av[1], buffer, size) == 84))
        return (84);
    if (my_getnbr(av[2]) < 1 || my_getnbr(av[2]) > 3) {
        write(2, "Invalid compression type.\n", 26);
        return 84;
    }
    close(fd);
    return 0;
}

int main(int ac, char **av)
{
    int size;
    char *buffer;

    if (handle_errors(ac, av, &size, &buffer) == 84)
        return 84;
    if (size == 0) {
        return 0;
    }
    return (giant_huff(buffer, size));
}