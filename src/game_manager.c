/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Main loop for a level of the game
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System.h>
#include <unistd.h>
#include "my_hunter.h"

duck_t **init_ducks(int nb_ducks, sfRenderWindow *window);
void move_ducks(duck_t **duck, int nb_ducks, float time);
void display_ducks(sfRenderWindow *window, duck_t **ducks, int nb_duck);
int analyse_game_events(sfRenderWindow *window, sfEvent event, duck_t **duck, int nb_ducks);
void destroy_ducks(duck_t **ducks, int nb_ducks);
void end_game(duck_t **ducks, sfSprite *background,int nb_ducks, int score);
sfText *init_text(sfRenderWindow *window, int score);
void display_score(sfText *text, int score);
void reset_ducks(duck_t **ducks, int nb_ducks, sfRenderWindow *window);

void put_background(sfSprite *sprite, sfRenderWindow *window)
{
    sfTexture *background;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f scale;

    scale.x = window_size.x / 1920.0;
    scale.y = window_size.y / 1080.0;
    if (sfSprite_getTexture(sprite) != NULL)
        sfRenderWindow_drawSprite(window, sprite, NULL);
    else {
        background = sfTexture_createFromFile("../ressources/game_background.jpg", NULL);
        sfSprite_setTexture(sprite, background, sfTrue);
        sfSprite_setScale(sprite, scale);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
}

void run_game(sfRenderWindow *window, int nb_ducks)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds = 0.0;
    sfEvent event;
    duck_t **ducks = init_ducks(nb_ducks, window);
    sfSprite *sprite = sfSprite_create();
    int score = 0;
    sfText *text = init_text(window, score);

    while (sfRenderWindow_isOpen(window)) {
        if (ducks == NULL)
            sfRenderWindow_close(window);
        sfRenderWindow_clear(window, sfBlack);
        display_score(text, score);
        put_background(sprite, window);
        sfRenderWindow_drawText(window, text, NULL);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        display_ducks(window, ducks, nb_ducks);
        while (sfRenderWindow_pollEvent(window, &event))
            score += analyse_game_events(window, event, ducks, nb_ducks);
        reset_ducks(ducks, nb_ducks, window);
        move_ducks(ducks, nb_ducks, seconds);
        sfRenderWindow_display(window);
    }
    end_game(ducks, sprite, nb_ducks, score);
}
