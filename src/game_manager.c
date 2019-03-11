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
#include <SFML/Audio.h>
#include <unistd.h>
#include "my_hunter.h"

void put_background(sfSprite *sprite, sfRenderWindow *window)
{
    sfTexture *backgrnd;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f scale;

    scale.x = window_size.x / 1920.0;
    scale.y = window_size.y / 1080.0;
    if (sfSprite_getTexture(sprite) != NULL)
        sfRenderWindow_drawSprite(window, sprite, NULL);
    else {
        backgrnd = sfTexture_createFromFile("./assets/bckgrnd.jpg", NULL);
        sfSprite_setTexture(sprite, backgrnd, sfTrue);
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
    sfSprite *health = sfSprite_create();

    while (game_inf->lives > 0 && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        put_background(background, window);
        sfRenderWindow_drawText(window, text, NULL);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        display_ducks(window, ducks, game_inf, seconds);
        get_events(window, &event, ducks, game_inf);
        display_score(text, game_inf, health, window);
        sfRenderWindow_display(window);
    }
    sfSound_stop(game_inf->duck_sound);
    end_game(ducks, background, nb_ducks, text);
    write(1, "Score : ", 8);
    my_put_nbr(game_inf->score);
    write(1, "\n", 1);
}
