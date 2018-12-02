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

duck_t *create_duck(sfVector2u window_size, sfRenderWindow *window)
{
    duck_t *duck = malloc(sizeof(duck_t));
    sfVector2f scale;

    check_malloc(window, duck);
    scale.x = 1; // A change pour le scale
    scale.y = scale.x;
    srand(time(NULL));
    duck->speed = 7;
    duck->is_dead = 0;
    duck->direction = 1;
    duck->texture = sfTexture_createFromFile("../ressources/duck_anim.png", NULL);
    duck->sprite = sfSprite_create();
    sfSprite_setScale(duck->sprite, scale);
    duck->rect.width = 110;
    duck->rect.height = 110;
    duck->rect.left = 0;
    duck->rect.top = 0;
    duck->prev_time_moved = 0.0;
    duck->prev_time_rect_moved = 0.0;
}

void destroy_ducks(duck_t **ducks, int nb_ducks)
{
    for (int i = 0; i < nb_ducks; i++) {
        sfSprite_destroy(ducks[i]->sprite);
        sfTexture_destroy(ducks[i]->texture);
        free(ducks[i]);
    }
}

duck_t **init_ducks(int nb_ducks, sfRenderWindow *window)
{
    duck_t **ducks;
    sfVector2f begin_pos;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    int y = 1;

    ducks = malloc(sizeof(duck_t *) * nb_ducks);
    check_malloc(window, ducks);
    if (ducks == NULL)
        return (NULL);
    for (int i = 0; i < nb_ducks; i++) {
        srand(time(NULL) + y);
        begin_pos.x = -200;
        begin_pos.y = rand() % window_size.y * 0.5;
        ducks[i] = create_duck(window_size, window);
        y += 327;
        if (ducks[i] == NULL)
            return (NULL);
        sfSprite_setPosition(ducks[i]->sprite, begin_pos);
    }
    return (ducks);
}
