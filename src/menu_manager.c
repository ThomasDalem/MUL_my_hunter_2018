/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Runs the menu
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "my_hunter.h"

void display_background(sfRenderWindow *window, sfSprite *sprite)
{
    sfTexture *background;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f scale;

    scale.x = window_size.x / 1920.0;
    scale.y = window_size.y / 1080.0;
    if (sfSprite_getTexture(sprite) != NULL)
        sfRenderWindow_drawSprite(window, sprite, NULL);
    else {
        background = sfTexture_createFromFile("../ressources/bckgrnd.jpg", NULL);
        sfSprite_setTexture(sprite, background, sfTrue);
        sfSprite_setScale(sprite, scale);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
}

void display_title(sfRenderWindow *window, sfSprite *sprite)
{
    sfTexture *background;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f scale;
    sfVector2f pos;

    scale.x = window_size.x / 768.0 / 3.0;
    scale.y = window_size.y / 384.0 / 3.0;
    pos.x = window_size.x / 3.0 - scale.x;
    pos.y = window_size.y / 10.0 - scale.y;
    if (sfSprite_getTexture(sprite) != NULL) {
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    else {
        background = sfTexture_createFromFile("../ressources/title.png", NULL);
        sfSprite_setTexture(sprite, background, sfTrue);
        sfSprite_setScale(sprite, scale);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
}

void run_menu(sfRenderWindow *window)
{
    int choice = 0;
    sfEvent event;
    button_t **buttons = init_menu_buttons(window);
    sfSprite *background = sfSprite_create();
    sfSprite *title = sfSprite_create();

    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    while (choice == 0 && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_background(window, background);
        display_title(window, title);
        display_buttons(window, buttons);
        while (sfRenderWindow_pollEvent(window, &event))
            choice = analyse_menu_events(window, event, buttons);
        sfRenderWindow_display(window);
        if (choice == 2)
            sfRenderWindow_close(window);
    }
    destroy_buttons(buttons);
}