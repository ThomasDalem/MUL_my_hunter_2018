/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Displays the scor on the screen
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Color.h>
#include <stdlib.h>
#include "my_hunter.h"

sfText *init_text(void)
{
    sfFont *font = sfFont_createFromFile("./assets/BebasNeue_Regular.otf");
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setColor(text, sfRed);
    return (text);
}

void add_text_beginning(char *str)
{
    str[0] = 'M';
    str[1] = 'o';
    str[2] = 'n';
    str[3] = 'e';
    str[4] = 'y';
    str[5] = ':';
    str[6] = ' ';
    str[7] = '\0';
}

void display_score(sfText *text, infos_t *game_infos, sfSprite *health, sfRenderWindow *window)
{
    char *str_score = my_int_to_str(game_infos->score);
    int score_size = my_strlen(str_score);
    char *str = malloc(sizeof(char) * (7 + score_size + 1));

    add_text_beginning(str);
    my_strcat(str, str_score);
    display_heatlh(window, health, game_infos->lives);
    sfText_setString(text, str);
}
