/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Initialize the infos_t structure
*/
#include <stdlib.h>
#include "my_hunter.h"

infos_t *init_game(int nb_ducks)
{
    infos_t *game_values;

    game_values = malloc(sizeof(infos_t));
    game_values->lives = 3;
    game_values->score = 0;
    game_values->nb_ducks = nb_ducks;
    return (game_values);
}

void destroy_game_info(infos_t *game_inf)
{
    free(game_inf);
}