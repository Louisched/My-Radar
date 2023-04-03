/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <time.h>
#include "includes/my.h"
#include "includes/functions.h"
#include "includes/linked_lists.h"

game_t init(char *name, sfVideoMode mode)
{
    game_t game;
    game.mode = mode;
    game.window = sfRenderWindow_create(mode, name, PARAM, NULL);
    game.clock = sfClock_create();
    game.plane_textire = sfTexture_createFromFile("plane.png", NULL);
    game.tower_texture = sfTexture_createFromFile("tower.png", NULL);
    game.background = sfTexture_createFromFile("worldmap.jpg", NULL);
    game.background_sprite = sfSprite_create();
    sfSprite_setTexture(game.background_sprite, game.background, sfTrue);
    return (game);
}

/* plist_t *create_list(int nb)
{
    plist_t *list = plist_create();
    sfVector2f vector;
    for (int i = 0 ; i < nb ; i++) {
        vector.x = rand() % 795;
        vector.y = rand() % 595;
        plist_pushfirst(list, create_circle(vector, 20.00));
    }
    return list;
}
 */
void display_entities(pla_tow_t *pt, game_t *game)
{
    pnode_t *current = pt->planes->head;
    for (current ; current ; current = current->next) {
        DRAW_RECT(game->window, current->data->circle, NULL);
        sfRenderWindow_drawSprite(game->window, current->data->sprite, NULL);
    }
    tnode_t *current2 = pt->towers->head;
    for (current2 ; current2 ; current2 = current2->next) {
        DRAW_CRICLE(game->window, current2->data->control_area, NULL);
        sfRenderWindow_drawSprite(game->window, current2->data->sprite, NULL);
    }
}

void analyse_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

void destroy_game(game_t *game, pla_tow_t *pt)
{
    pnode_t *current = pt->planes->head;
    for (current ; current ; current = current->next) {
        sfSprite_destroy(current->data->sprite);
        sfRectangleShape_destroy(current->data->circle);
    }
    tnode_t *current2 = pt->towers->head;
    for (current2 ; current2 ; current2 = current2->next) {
        sfSprite_destroy(current2->data->sprite);
        sfCircleShape_destroy(current2->data->control_area);
    }
    sfSprite_destroy(game->background_sprite);
    sfTexture_destroy(game->background);
    sfClock_destroy(game->clock);
    sfTexture_destroy(game->plane_textire);
    sfTexture_destroy(game->tower_texture);
    sfRenderWindow_destroy(game->window);
}

int main(int argc, char *argv[])
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') return help();
    if (!is_script_valid(argv[1])) return 84;
    sfVideoMode mode = {1920, 1080, 32};
    game_t game = init("My Radar", mode);
    if (!game.window) return EXIT_FAILURE;
    pla_tow_t *pt = create_plane_list_from_script(argv[1], &game);
    sfRenderWindow_setFramerateLimit(game.window, 30);
    while (sfRenderWindow_isOpen(game.window)) {
        print_framerate();
        analyse_events(&game);
        sfRenderWindow_clear(game.window, sfBlack);
        sfRenderWindow_drawSprite(game.window, game.background_sprite, NULL);
        move_planes(pt);
        calculate_colisions(pt);
        display_entities(pt, &game);
        sfRenderWindow_display(game.window);
    }
    destroy_game(&game, pt);
    return (0);
}
