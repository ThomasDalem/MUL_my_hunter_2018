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

char *convert_to_string(int number)
{
    char *str;
    int num = number;
    int num2 = number;
    int nb_char = 0;
    int i = 0;

    while (num > 0) {
        num /= 10;
        nb_char++;
    }
    str = malloc(sizeof(char) * nb_char + 1);
    while (i < nb_char) {
        str[i] = num2 % 10 + '0';
        num2 /= 10;
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}

sfText *init_text(void)
{
    sfFont *font = sfFont_createFromFile("../ressources/BebasNeue_Regular.otf");
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setColor(text, sfRed);
    return (text);
}

char *concat_str(char const *str1, char const *str2)
{
    char *str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));

    my_strcpy(str, str1);
    my_strcat(str, str2);
    return (str);
}

void display_score(sfText *text, infos_t *game_infos, sfSprite *health, sfRenderWindow *window)
{
    char *str_score = convert_to_string(game_infos->score);
    char *str_begin = "Score:";
    char *new_str = concat_str(str_begin, str_score);
    
    display_heatlh(window, health, game_infos->lives);
    sfText_setString(text, new_str);
}
