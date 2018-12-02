/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Main function of the my_hunter project
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_hunter.h"

void run_game(sfRenderWindow *window, int nb_ducks);
void run_menu(sfRenderWindow *window);
int run_end_menu(sfRenderWindow *window);

sfRenderWindow *create_window(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "MyHunter", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

int check_arg(char *av)
{
    if (av[0] == '-' && av[1] == 'h') {
        write(1, "My_Hunter project 2018\n", 23);
        write(1, "Shoot at the duck to win points\n", 32);
        write(1, "Press escape to use the menu\n", 29);
        return (-1);
    }
    else if (av[0] >= '0' && av[0] <= '9')
        return (my_getnbr(av));
    return(3);
}

int main(int ac, char **av)
{
    sfRenderWindow *window;
    int nb_ducks = 3;
    int i = 0;
    int retried = 0;

    if (ac == 2 && check_arg(av[1]) == -1)
        return (0);
    else if (ac == 2 && check_arg(av[1]) != -1)
        nb_ducks = check_arg(av[1]);
    window = create_window(1920, 1080);
    while (sfRenderWindow_isOpen(window)) {
        if (retried == 0) {
            run_menu(window);
        }
        run_game(window, nb_ducks);
        retried = 0;
        retried = run_end_menu(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
