/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Checks the malloc
*/
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>

void check_malloc(sfRenderWindow *window, void *ptr)
{
    if (ptr == NULL)
        sfRenderWindow_close(window);
}
