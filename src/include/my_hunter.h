/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** header for my_hunter
*/

#ifndef __MY_HUNTER_H__
#define __MY_HUNTER_H__

typedef struct duck {
    int speed;
    int is_dead;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    float prev_time_moved;
    float prev_time_rect_moved;
} duck_t;

void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);

#endif
