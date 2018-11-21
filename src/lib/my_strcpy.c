/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** Copies a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i + 1] = '\0';
    return (dest);
}
