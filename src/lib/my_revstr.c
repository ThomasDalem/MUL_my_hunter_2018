/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** Returns the reversed string given in parameter
*/

char *my_revstr(char *str)
{
    int nb_l = 0;
    int nb_r = 0;
    int buffer = 0;

    while (str[nb_r] != '\0')
        nb_r++;
    nb_r--;
    while (nb_l < nb_r) {
        buffer = str[nb_l];
        str[nb_l] = str[nb_r];
        str[nb_r] = buffer;
        nb_l = nb_l + 1;
        nb_r = nb_r - 1;
    }
    return (str);
}
