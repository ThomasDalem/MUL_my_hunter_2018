/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Displays the buttons on the menu
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "my_hunter.h"

void display_buttons(sfRenderWindow *window, button_t **buttons)
{
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawSprite(window, buttons[i]->sprite, NULL);
}
