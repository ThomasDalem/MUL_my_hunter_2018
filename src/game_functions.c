/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Initialize the infos_t structure
*/
#include <stdlib.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include "my_hunter.h"

infos_t *init_game(int nb_ducks)
{
    infos_t *game_values;
    char *shot_path = "./assets/shot.ogg";
    char *duck_sound = "./assets/duck.ogg";

    game_values = malloc(sizeof(infos_t));
    game_values->lives = 3;
    game_values->score = 0;
    game_values->nb_ducks = nb_ducks;
    game_values->sound_buffer = sfSoundBuffer_createFromFile(shot_path);
    game_values->sound = sfSound_create();
    game_values->sound_buffer2 = sfSoundBuffer_createFromFile(duck_sound);
    game_values->duck_sound = sfSound_create();
    sfSound_setBuffer(game_values->sound, game_values->sound_buffer);
    sfSound_setBuffer(game_values->duck_sound, game_values->sound_buffer2);
    sfSound_setLoop(game_values->duck_sound, sfTrue);
    sfSound_play(game_values->duck_sound);
    sfSound_setVolume(game_values->duck_sound, 75.0);
    return (game_values);
}

void destroy_game_info(infos_t *game_inf)
{
    sfSound_destroy(game_inf->sound);
    sfSoundBuffer_destroy(game_inf->sound_buffer);
    sfSound_destroy(game_inf->duck_sound);
    sfSoundBuffer_destroy(game_inf->sound_buffer2);
    free(game_inf);
}