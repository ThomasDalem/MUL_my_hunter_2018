/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Displays the health bar
*/
#include <SFML/Graphics.h>
#include "my_hunter.h"

sfIntRect change_rect(sfSprite *sprite, int health)
{
    sfIntRect rect;

    rect.left = 0;
    rect.top = 0;
    rect.width = 429;
    rect.height = 139;
    if (health == 2)
        rect.left = 429.0 / 3.0;
    else if (health == 1)
        rect.left = 429 - 134;
    if (health == 0) {
        rect.width = 0;
        rect.height = 0;
    }
    sfSprite_setTextureRect(sprite, rect);
    return (rect);
}
 
void display_heatlh(sfRenderWindow *window, sfSprite *sprite, int health_cnt)
{
    sfTexture *health_texture;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;

    scale.x = 0.5;
    scale.y = scale.x;
    pos.x = window_size.x - 429.0 * scale.x;
    pos.y = window_size.y - 139.0 * scale.y;
    if (sfSprite_getTexture(sprite) != NULL) {
        change_rect(sprite, health_cnt);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    } else {
        health_texture = sfTexture_createFromFile("../ressources/health.png", NULL);
        sfSprite_setTexture(sprite, health_texture, sfTrue);
        sfSprite_setScale(sprite, scale);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfSprite_setPosition(sprite, pos);
    }
}