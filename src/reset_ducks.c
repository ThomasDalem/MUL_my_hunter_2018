/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Reset the position of the dead ducks
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "my_hunter.h"

void change_duck_pos(duck_t *duck, int new_pos_y, int x);

void reset_far_ducks(duck_t **ducks, int nb_ducks, sfRenderWindow *window)
{
    sfVector2f duck_pos;
    sfVector2f new_pos;
    sfVector2u window_size = sfRenderWindow_getSize(window);

    for (int i = 0; i < nb_ducks; i++) {
        duck_pos = sfSprite_getPosition(ducks[i]->sprite);
        new_pos.y = rand() % window_size.y / 1.5;
        if (duck_pos.x > window_size.x + 200 || duck_pos.x < -200) {
            write(1, "Duck outside the screen\n", 24);
            change_duck_pos(ducks[i], new_pos.y, window_size.x);
         }
    }
}

void reset_dead_ducks(duck_t **ducks, int nb_ducks, sfRenderWindow *window)
{
    sfVector2f duck_pos;
    sfVector2f new_scale;
    sfVector2f new_pos;
    sfVector2u window_size = sfRenderWindow_getSize(window);

    srand(time(NULL));
    for (int i = 0; i < nb_ducks; i++) {
        duck_pos = sfSprite_getPosition(ducks[i]->sprite);
        new_pos.y = rand() % window_size.y / 1.5;
        if (ducks[i]->is_dead == 1 && duck_pos.y > window_size.y + 100) {
            write(1, "Duck outside the screen\n", 24);
            change_duck_pos(ducks[i], new_pos.y, window_size.x);
            ducks[i]->is_dead = 0;
            //    ducks[i]->speed += 1;
        }
    }
}
