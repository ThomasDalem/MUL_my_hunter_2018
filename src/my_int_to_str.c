/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2018
** File description:
** my_int_to_str
*/
#include <stdlib.h>
#include "my_hunter.h"

int get_number_size(int number)
{
    int size = 1;
    int result = number;

    while (result > 9) {
        result /= 10;
        size++;
    }
    return (size);
}

char *my_int_to_str(int nb)
{
    int number_size = get_number_size(nb);
    char *str = malloc(sizeof(char) * (number_size + 1));
    int i = 0;

    if (str == NULL)
        return (NULL);
    while (i < number_size) {
        str[i] = nb % 10 + '0';
        nb /= 10;
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}
