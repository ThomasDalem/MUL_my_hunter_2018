/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Displays the scor on the screen
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Color.h>
#include "my_hunter.h"

void display_score(sfRenderWindow *window, int score)
{
    sfFont *font = sfFont_createFromFile("../ressources/main_font.otf");
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setString(text, "BONJOUR");
    sfText_setColor(text, sfRed);
}
