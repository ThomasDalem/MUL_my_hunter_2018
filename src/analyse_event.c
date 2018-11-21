/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Analyse all the events
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/Sprite.h>
#include <unistd.h>
#include "my_hunter.h"

int compare_vectors(sfVector2f vector1, sfVector2f vector2, int duck_scale);

int check_if_hit(sfEvent event, duck_t **duck, int nb_ducks)
{
    sfVector2f mouse_pos;
    sfVector2f duck_pos;
    int score = 0;

    mouse_pos.x = event.mouseButton.x;
    mouse_pos.y = event.mouseButton.y;
    for (int i = 0; i < nb_ducks; i++) {
        duck_pos = sfSprite_getPosition(duck[i]->sprite);
        if (compare_vectors(mouse_pos, duck_pos, duck[i]->direction) && duck[i]->is_dead != 1) {
            duck[i]->is_dead = 1;
            write(1, "Duck killed\n", 12);
            score++;
        }
    }
    return (score);
}

int analyse_game_events(sfRenderWindow *window, sfEvent event, duck_t **ducks, int nb_ducks)
{
    int score = 0;

    if (event.type == sfEvtMouseButtonPressed)
        score = check_if_hit(event, ducks, nb_ducks);
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    return (score);
}

int analyse_menu_events(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        return (1);
    if (event.type == sfEvtMouseButtonPressed)
        return (2);
}
