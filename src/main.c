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

sfRenderWindow *create_window(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "MyHunter", sfDefaultStyle, NULL);
    return (window);
}

int main(void)
{
    sfRenderWindow *window;
    int width = 800;
    int height = 600;
    int nb_ducks = 3;

    window = create_window(width, height);
    while (sfRenderWindow_isOpen(window)) {
        run_game(window, nb_ducks);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
