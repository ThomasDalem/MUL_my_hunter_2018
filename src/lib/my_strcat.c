/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** Concatenates two string
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int y = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[y] != '\0') {
        dest[i] = src[y];
        y++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
