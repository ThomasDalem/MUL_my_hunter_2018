/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Reset the position of the dead ducks
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "my_hunter.h"

void reset_dead_ducks(duck_t **ducks, int nb_ducks)
{
    sfVector2f duck_pos;
    sfVector2f new_pos;

    new_pos.x = 0;
    new_pos.y = 90;
    for (int i = 0; i < nb_ducks; i++) {
        duck_pos = sfSprite_getPosition(ducks[i]->sprite);
        if (ducks[i]->is_dead == 1 && duck_pos.y > 800) {
            write(1, "Duck outside of the screen", 26);
            sfSprite_setPosition(ducks[i]->sprite, new_pos);
            ducks[i]->is_dead = 0;
        }
    }
}
