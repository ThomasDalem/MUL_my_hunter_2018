/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** header for my_hunter
*/
#ifndef __MY_HUNTER_H__
#define __MY_HUNTER_H__
#include <SFML/Graphics/RenderWindow.h>
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
int my_getnbr(char const *str);
void reset_ducks(duck_t **ducks, int nb_ducks, sfRenderWindow *window);
void move_ducks(duck_t **ducks, int nb_ducks, float time);
void check_malloc(sfRenderWindow *window, void *ptr);
duck_t **init_ducks(int nb_ducks, sfRenderWindow *window);
void move_ducks(duck_t **duck, int nb_ducks, float time);
void display_ducks(sfRenderWindow *window, duck_t **ducks, int nb_duck, float time);
int get_events(sfRenderWindow *window, sfEvent *event, duck_t **ducks, int nb_ducks);
void destroy_ducks(duck_t **ducks, int nb_ducks);
void end_game(duck_t **ducks, sfSprite *background,int nb_ducks, int score);
sfText *init_text(void);
void display_score(sfText *text, int score);
void reset_ducks(duck_t **ducks, int nb_ducks, sfRenderWindow *window);
void check_if_mouse_moved(sfRenderWindow *window, sfEvent event, sfSprite *sprite);
void check_malloc(sfRenderWindow *window, void *ptr);

#endif
