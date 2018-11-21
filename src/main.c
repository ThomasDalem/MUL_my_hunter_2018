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

void run_game(sfRenderWindow *window, int nb_ducks);
int analyse_menu_events(sfRenderWindow *window, sfEvent event);

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

int main(int ac, char **av)
{
    sfRenderWindow *window;
    int width = 1920;
    int height = 1080;
    int nb_ducks = 3;
    int choice = 0;
    sfEvent event;

    window = create_window(width, height);
    while (sfRenderWindow_isOpen(window)) {
//        while (sfRenderWindow_pollEvent(window, &event) && choice == 0)
//            choice = analyse_menu_events();
        run_game(window, nb_ducks);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
