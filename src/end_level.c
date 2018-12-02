/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Ends the game after the game ending
*/
#include <SFML/Graphics.h>
#include <unistd.h>
#include "my_hunter.h"

void destroy_ducks(duck_t **ducks, int nb_ducks);

void end_game(duck_t **ducks, sfSprite *background,int nb_ducks, sfText *score)
{
    sfSprite_destroy(background);
    destroy_ducks(ducks, nb_ducks);
    sfText_destroy(score);
}
