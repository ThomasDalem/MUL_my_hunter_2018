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

int analyse_menu_events(sfRenderWindow *window, sfEvent event);
void display_buttons(sfRenderWindow *window, button_t **buttons);
button_t **init_buttons(sfRenderWindow *window);
void destroy_buttons(button_t **buttons);

void run_menu(sfRenderWindow *window)
{
    int choice = 0;
    sfEvent event;
    button_t **buttons = init_buttons(window);

    while (choice == 0 && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_buttons(window, buttons);
        while (sfRenderWindow_pollEvent(window, &event))
            choice = analyse_menu_events(window, event);
        sfRenderWindow_display(window);
    }
    destroy_buttons(buttons);
}