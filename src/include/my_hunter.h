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
    int direction;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    float prev_time_moved;
    float prev_time_rect_moved;
} duck_t;

typedef struct button {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int choice;
} button_t;

void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

#endif
