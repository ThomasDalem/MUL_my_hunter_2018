/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Analyse all the events
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "my_hunter.h"

int compare_ducks_vectors(sfVector2f vector1, sfVector2f vector2, int duck_scale, duck_t *duck);
int compare_buttons_vectors(sfVector2f vector1, sfVector2f vector2, int size_x, int size_y);
void run_menu(sfRenderWindow *window);

int check_if_hit(sfEvent event, duck_t **duck, infos_t *game_inf)
{
    sfVector2f mouse_pos;
    sfVector2f duck_pos;
    sfVector2f move_dead;
    int score = 0;

    srand(time(NULL));
    move_dead.y = 0;
    mouse_pos.x = event.mouseButton.x;
    mouse_pos.y = event.mouseButton.y;
    for (int i = 0; i < game_inf->nb_ducks; i++) {
        duck_pos = sfSprite_getPosition(duck[i]->sprite);
        if (compare_ducks_vectors(mouse_pos, duck_pos, duck[i]->direction, duck[i]) && duck[i]->is_dead != 1) {
            duck[i]->is_dead = 1;
            move_dead.x = 110 * duck[i]->direction;
            sfSprite_move(duck[i]->sprite, move_dead);
            write(1, "Duck killed\n", 12);
            game_inf->score += 100;
            duck[i]->speed += 0.5 + rand() % 1;
        }
    }
    return (score);
}

int analyse_game_events(sfRenderWindow *window, sfEvent event, duck_t **ducks, infos_t *game_inf)
{
    int score = 0;
    if (event.type == sfEvtMouseButtonPressed) {
        sfSound_play(game_inf->sound);
        check_if_hit(event, ducks, game_inf);
    }
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.key.code == sfKeyEscape) {
        sfSound_pause(game_inf->duck_sound);
        run_menu(window);
        sfSound_play(game_inf->duck_sound);
    }
    return (score);
}

int check_if_clicked_button(sfEvent event, button_t **buttons)
{
    sfVector2f mouse_pos;
    sfVector2f button_pos;
    sfVector2f button_scale;
    sfVector2f button_size;

    mouse_pos.x = event.mouseButton.x;
    mouse_pos.y = event.mouseButton.y;
    for (int i = 0; i < 2; i++) {
        button_pos = sfSprite_getPosition(buttons[i]->sprite);
        button_scale = sfSprite_getScale(buttons[i]->sprite);
        button_size.x = 400 * button_scale.x;
        button_size.y = 200 * button_scale.y;
        if (compare_buttons_vectors(mouse_pos, button_pos, button_size.x, button_size.y) == 1)
            return (buttons[i]->choice);
    }
    return (0);
}

int analyse_menu_events(sfRenderWindow *window, sfEvent event, button_t **buttons)
{
    if (event.type == sfEvtMouseButtonPressed)
        return (check_if_clicked_button(event, buttons));
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    return (0);
}

int get_events(sfRenderWindow *window, sfEvent *event, duck_t **ducks, infos_t *game_inf)
{
    int score = 0;

    while (sfRenderWindow_pollEvent(window, event))
        analyse_game_events(window, *event, ducks, game_inf);
    display_cursor(window, *event);
    return (score);
}