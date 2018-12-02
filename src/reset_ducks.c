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

int change_duck_pos(duck_t *duck, int new_pos_y, int x);

void reset_far_ducks(duck_t *ducks, infos_t *game_inf, sfRenderWindow *window)
{
    sfVector2f duck_pos;
    sfVector2f new_pos;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    int new_rand_pos = 1;

    for (int i = 0; i < game_inf->nb_ducks; i++) {
        duck_pos = sfSprite_getPosition(ducks->sprite);
        new_pos.y = rand() * new_rand_pos % window_size.y / 1.5;
        if (duck_pos.x > window_size.x + 200 || duck_pos.x < -200) {
            write(1, "Duck outside the screen\n", 24);
            new_rand_pos = change_duck_pos(ducks, new_pos.y, window_size.x);
            game_inf->lives -= 1;
            my_put_nbr(game_inf->lives);
         }
    }
}

void reset_dead_ducks(duck_t *ducks, infos_t *game_inf, sfRenderWindow *window)
{
    sfVector2f duck_pos;
    sfVector2f new_pos;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    int new_rand_pos = 1;

    duck_pos = sfSprite_getPosition(ducks->sprite);
    new_pos.y = rand() * new_rand_pos % window_size.y / 1.5;
    if (ducks->is_dead == 1 && duck_pos.y > window_size.y + 100) {
        write(1, "Duck outside the screen\n", 24);
        new_rand_pos = change_duck_pos(ducks, new_pos.y, window_size.x);
        ducks->is_dead = 0;
    }
}

void reset_ducks(duck_t **ducks, infos_t *game_inf, sfRenderWindow *window) 
{
    for (int i = 0; i < game_inf->nb_ducks; i++) {
        reset_far_ducks(ducks[i], game_inf, window);
        reset_dead_ducks(ducks[i], game_inf, window);
    }
}