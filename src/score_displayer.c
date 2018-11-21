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
    my_revstr(str);
    return (str);
}

sfText *init_text(void)
{
    sfFont *font = sfFont_createFromFile("../ressources/main_font.otf");
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setColor(text, sfRed);
    return (text);
}

char *concat_str(char *str1, char *str2)
{
    int str_len1 = my_strlen(str1);
    int str_len2 = my_strlen(str2);
    char *result_str;

    result_str = malloc(sizeof(char) * (str_len1 + str_len2 + 1));
    for (int i = 0; i < str_len1; i++)
        result_str[i] = str1[i];
    for (int i = 0; i < str_len2; i++)
        result_str[str_len1 + i] = str2[i];
    return (result_str);
}

void display_score(sfText *text, int score)
{
    char *str_score = convert_to_string(score);
    char str_begin[8] = "Score : ";
    char *new_str = concat_str(str_begin, str_score);
    
    sfText_setString(text, new_str);
}
