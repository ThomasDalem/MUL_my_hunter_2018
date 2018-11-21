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

duck_t **init_ducks(int nb_ducks);
void move_duck(duck_t *duck, float time, int nb_ducks);
void display_ducks(sfRenderWindow *window, duck_t **ducks, int nb_duck);
int analyse_events(sfRenderWindow *window, sfEvent event, duck_t **duck, int nb_ducks);
void reset_dead_ducks(duck_t **duck, int nb_ducks);
void reset_far_ducks(duck_t **ducks, int nb_ducks);
void destroy_ducks(duck_t **ducks, int nb_ducks);
void end_game(duck_t **ducks, int nb_ducks, int score);

void run_game(sfRenderWindow *window, int nb_ducks)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds = 0.0;
    sfEvent event;
    duck_t **ducks = init_ducks(nb_ducks);
    int close_game = 0;
    int score = 0;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        display_ducks(window, ducks, nb_ducks);
        for (int i = 0; i < nb_ducks; i++)
            move_duck(ducks[i], seconds, nb_ducks);
        while (sfRenderWindow_pollEvent(window, &event))
            score += analyse_events(window, event, ducks, nb_ducks);
        reset_dead_ducks(ducks, nb_ducks);
        reset_far_ducks(ducks, nb_ducks);
        sfRenderWindow_display(window);
    }/*
    destroy_ducks(ducks, nb_ducks);
    write(1, "Score : ", 8);
    my_put_nbr(score);
    write(1, "\n", 1);
     */
    end_game(ducks, nb_ducks, score);
}
