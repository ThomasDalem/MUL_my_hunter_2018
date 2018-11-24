/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Compares if two vectors2 are equals or not
*/
#include <SFML/System/Vector2.h>
#include <unistd.h>

int compare_ducks_vectors(sfVector2f vector1, sfVector2f vector2, int duck_scale)
{
    if (vector1.x >= vector2.x && vector1.x <= vector2.x + 110 && duck_scale == 1) {
        if (vector1.y >= vector2.y && vector1.y <= vector2.y + 110)
            return (1);
    }
    if (vector1.x <= vector2.x && vector1.x >= vector2.x - 110 && duck_scale == -1) {
        if (vector1.y >= vector2.y && vector1.y <= vector2.y + 110)
            return (1);
    }
    return (0);
}

int compare_buttons_vectors(sfVector2f vector1, sfVector2f vector2, int size_x, int size_y)
{
    if (vector1.x >= vector2.x && vector1.x <= vector2.x + size_x) {
        if (vector1.y >= vector2.y && vector1.y <= vector2.y + size_y)
            return (1);
    }
    return (0);
}