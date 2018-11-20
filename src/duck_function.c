/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Functions related to the duck struct
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include <time.h>
#include "my_hunter.h"

duck_t *create_duck(void)
{
    duck_t *duck = malloc(sizeof(duck_t));

    srand(time(NULL));
    duck->speed = 1;
    duck->is_dead = 0;
    duck->direction = 1;
    duck->texture = sfTexture_createFromFile("../ressources/duck_anim.png", NULL);
    duck->sprite = sfSprite_create();
    duck->rect.width = 110;
    duck->rect.height = 110;
    duck->rect.left = 0;
    duck->rect.top = 0;
    duck->prev_time_moved = 0.0;
    duck->prev_time_rect_moved = 0.0;
}

void destroy_duck(duck_t *duck)
{
    sfSprite_destroy(duck->sprite);
    sfTexture_destroy(duck->texture);
    free(duck);
}

duck_t **init_ducks(int nb_ducks)
{
    duck_t **ducks;
    sfVector2f begin_pos;

    srand(time(NULL));
    ducks = malloc(sizeof(duck_t *) * nb_ducks);
    for (int i = 0; i < nb_ducks; i++) {
        begin_pos.x = -200;
        begin_pos.y = rand() % 400;
        ducks[i] = create_duck();
        sfSprite_setPosition(ducks[i]->sprite, begin_pos);
    }
    return (ducks);
}
