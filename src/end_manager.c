/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Manages the end game menu
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "my_hunter.h"

int run_end_menu(sfRenderWindow *window)
{
    sfSprite *background = sfSprite_create();
    button_t **buttons = init_end_buttons(window);
    int choice = 0;
    sfEvent event;

    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    while (choice == 0 && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_background(window, background);
        display_buttons(window, buttons);
        while (sfRenderWindow_pollEvent(window, &event))
            choice = analyse_menu_events(window, event, buttons);
        sfRenderWindow_display(window);
        if (choice == 2)
            sfRenderWindow_close(window);
    }
    return (1);
}