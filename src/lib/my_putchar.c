/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Prints a character
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
