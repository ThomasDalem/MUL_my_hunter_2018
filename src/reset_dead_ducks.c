/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Reset the position of the dead ducks
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "my_hunter.h"

void reset_dead_ducks(duck_t **ducks, int nb_ducks)
{
    sfVector2f duck_pos;
    sfVector2f new_pos;
    int prev_y;

    srand(time(NULL));
    for (int i = 0; i < nb_ducks; i++) {
        duck_pos = sfSprite_getPosition(ducks[i]->sprite);
        new_pos.y = rand() % 400;
        new_pos.x = -200;
        if (ducks[i]->is_dead == 1 && duck_pos.y > 800) {
            write(1, "Duck outside of the screen\n", 27);
            sfSprite_setRotation(ducks[i]->sprite, 0);
            sfSprite_setPosition(ducks[i]->sprite, new_pos);
            ducks[i]->is_dead = 0;
        }
    }
}
