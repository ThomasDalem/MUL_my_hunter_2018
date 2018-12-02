/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Functions related to the button struct
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_hunter.h"

button_t *create_button(sfVector2f pos, char *texture_path, sfVector2u window_size, int choice_nb)
{
    button_t *button;
    sfVector2f scale;

    scale.x = 0.0004 * window_size.x;
    scale.y = scale.x;
    button = malloc(sizeof(button_t));
    button->texture = sfTexture_createFromFile(texture_path, NULL);
    button->sprite = sfSprite_create();
    pos.x -= 250 * scale.x;
    button->pos = pos;
    button->choice = choice_nb;
    sfSprite_setTexture(button->sprite ,button->texture, sfFalse);
    sfSprite_setScale(button->sprite, scale);
    sfSprite_setPosition(button->sprite, pos);
    return (button);
}

button_t **init_menu_buttons(sfRenderWindow *window)
{
    button_t **buttons;
    sfVector2f button_pos;
    sfVector2u window_size = sfRenderWindow_getSize(window);

    buttons = malloc(sizeof(button_t *) * 2);
    button_pos.x = window_size.x / 2;
    button_pos.y = window_size.y / 2;
    buttons[0] = create_button(button_pos, "../ressources/Play_button.png", window_size, 1);
    button_pos.y += window_size.y / 2 * 0.5;
    buttons[1] = create_button(button_pos, "../ressources/Exit_button.png", window_size, 2);
    return (buttons);
}

button_t **init_end_buttons(sfRenderWindow *window)
{
    button_t **buttons;
    sfVector2f button_pos;
    sfVector2u window_size = sfRenderWindow_getSize(window);

    buttons = malloc(sizeof(button_t *) * 2);
    button_pos.x = window_size.x / 2;
    button_pos.y = window_size.y / 2;
    buttons[0] = create_button(button_pos, "../ressources/retry_button.png", window_size, 1);
    button_pos.y += window_size.y / 2 * 0.5;
    buttons[1] = create_button(button_pos, "../ressources/Exit_button.png", window_size, 2);
    return (buttons);
}

void destroy_buttons(button_t **buttons)
{
    for (int i = 0; i < 2; i++) {
        sfSprite_destroy(buttons[i]->sprite);
        sfTexture_destroy(buttons[i]->texture);
        free(buttons[i]);
    }
    free(buttons);
}