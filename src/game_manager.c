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
    sfSprite *background = sfSprite_create();
    sfSprite *cursor = sfSprite_create();
    sfText *text = init_text();
    infos_t *game_inf = init_game(nb_ducks);

    while (game_inf->lives > 0) {
        sfRenderWindow_clear(window, sfBlack);
        display_score(text, game_inf);
        put_background(background, window);
        sfRenderWindow_drawText(window, text, NULL);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        display_ducks(window, ducks, game_inf, seconds);
        get_events(window, &event, ducks, game_inf);
        sfRenderWindow_display(window);
    }
    end_game(ducks, background, nb_ducks, text);
    sfRenderWindow_close(window);
}
