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

void change_duck_pos(duck_t *duck, int new_pos_y);

void reset_far_ducks(duck_t **ducks, int nb_ducks)
{
    sfVector2f duck_pos;
    sfVector2f new_pos;

    for (int i = 0; i < nb_ducks; i++) {
        duck_pos = sfSprite_getPosition(ducks[i]->sprite);
        new_pos.y = rand() % 400;
        if (duck_pos.x > 1000 || duck_pos.x < -200) {
            write(1, "Duck outside the screen\n", 24);
            change_duck_pos(ducks[i], new_pos.y);
            ducks[i]->speed += 1;
        }
    }
}

void reset_dead_ducks(duck_t **ducks, int nb_ducks)
{
    sfVector2f duck_pos;
    sfVector2f new_scale;
    sfVector2f new_pos;

    srand(time(NULL));
    for (int i = 0; i < nb_ducks; i++) {
        duck_pos = sfSprite_getPosition(ducks[i]->sprite);
        new_pos.y = rand() % 400;
        if (ducks[i]->is_dead == 1 && duck_pos.y > 800) {
            write(1, "Duck outside the screen\n", 24);
            change_duck_pos(ducks[i], new_pos.y);
            ducks[i]->is_dead = 0;
            ducks[i]->speed += 1; //<- It works but it's too fast after 2 or 3 times
        }
    }
}
