/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Displays the cursor on the window
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

void display_cursor(sfRenderWindow *window, sfEvent event)
{
    sfTexture *texture = sfTexture_createFromFile("../ressources/cursor.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos;

    pos.x = mouse_pos.x - 25.0;
    pos.y = mouse_pos.y - 25.0;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}