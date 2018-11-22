/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Ends the game after the game ending
*/
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <unistd.h>
#include "my_hunter.h"

void destroy_ducks(duck_t **ducks, int nb_ducks);

void end_game(duck_t **ducks, sfSprite *background,int nb_ducks, int score)
{
    sfSprite_destroy(background);
    destroy_ducks(ducks, nb_ducks);
    write(1, "Score : ", 8);
    my_put_nbr(score);
    write(1, "\n", 1);
}
