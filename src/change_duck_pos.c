/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Change randomly the position, the scale and and the rotation of a duck
*/
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my_hunter.h"

void change_duck_pos(duck_t *duck, int new_pos_y, int x)
{
    sfVector2f scale;
    sfVector2f begin_pos;

    srand(time(NULL));
    if (rand() % 1000 > 500) {
        scale.x = -1;
        scale.y = 1;
        begin_pos.x = x + 50;
        duck->direction = -1;
    } else {
        scale.x = 1;
        scale.y = 1;
        begin_pos.x = -50;
        duck->direction = 1;
    }
    begin_pos.y = new_pos_y;
    sfSprite_setPosition(duck->sprite, begin_pos);
    sfSprite_setScale(duck->sprite, scale);
    sfSprite_setRotation(duck->sprite, 0);
}
