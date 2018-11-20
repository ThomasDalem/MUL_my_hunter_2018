/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Displays a given number
*/
void my_putchar(char c);

int create_pow(int nbr)
{
    int i = 0;
    int power = 1;

    while (i < nbr) {
        i++;
        power = power * 10;
    }
    return (power / 10);
}

int check_nb(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    else if (nb == 0) {
        my_putchar('0');
        nb = 0;
    }
    return (nb);
}

void my_put_nbr(int nb)
{
    int nb_rep = 0;
    int nb_div = 0;
    int pow = 0;

    nb = check_nb(nb);
    if (nb == 0)
        return;
    nb_rep = nb;
    while (nb != 0) {
        nb = nb / 10;
        nb_div++;
    }
    pow = create_pow(nb_div);
    for (int i = 0; i < nb_div; i++) {
        my_putchar((nb_rep / pow) % 10 + 48);
        pow = pow / 10;
    }
}
