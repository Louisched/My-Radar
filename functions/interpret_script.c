/*
** EPITECH PROJECT, 2023
** interpret script
** File description:
** interpret script
*/

#include "../includes/my.h"
#include "../includes/functions.h"
#include "../includes/linked_lists.h"
#include <stdio.h>
#include <stdlib.h>

int my_getnbr(char *str)
{
    int n = 0;
    int res = 0;
    int j = 0;
    for (int i = my_strlen(str) - 1 ; i >= 0 ; i--) {
        if (str[i] != '-') {
            n = str[i] - 48;
            n *= power(10, j);
            res += n;
            j++;
        } else
            res *= -1;
    }
    return (res);
}

int *get_nbrs_from_line(char *line, int at)
{
    char **str_nbrs = malloc(at * sizeof(char *));
    int *nbrs = malloc(at * sizeof(int));
    int nb_index;
    int nb_len;
    int count = 0;
    for (int i = 0 ; i < at ; i++) {
        str_nbrs[i] = malloc(get_nbr_len(line, i) * sizeof(char));
        nb_index = get_nbr_begginig_ind(line, i);
        nb_len = get_nbr_len(line, i);
        count = 0;
        for (int j = nb_index ; count < nb_len; j++) {
            str_nbrs[i][count] = line[j];
            count++;
        }
        str_nbrs[i][count] = '\0';
    }
    for (int k = 0 ; k < at ; k++) nbrs[k] = my_getnbr(str_nbrs[k]);
    for (int l = at - 1 ; l >= 0 ; l--) free(str_nbrs[l]);
    free(str_nbrs);
    return nbrs;
}

plane_t *new_plane(char *line, game_t *game)
{
    int *data = get_nbrs_from_line(line, 6);
    plane_t *plane = malloc(sizeof(plane_t));
    plane->dparture.x = data[0];  plane->dparture.y = data[1];
    plane->arrival.x = data[2]; plane->arrival.y = data[3];
    plane->speed = data[4]; plane->t = data[5];
    sfVector2f size; size.x = 20; size.y = 20;
    plane->direc_x = (plane->dparture.x < 960) ? RIGHT : LEFT;
    plane->direc_y = (plane->dparture.y < 540) ? DOWN : UP;
    plane->circle = sfRectangleShape_create();
    sfRectangleShape_setPosition(plane->circle, plane->dparture);
    sfRectangleShape_setSize(plane->circle, size);
    sfRectangleShape_setFillColor(plane->circle, sfTransparent);
    sfRectangleShape_setOutlineColor(plane->circle, sfWhite);
    sfRectangleShape_setOutlineThickness(plane->circle, 1.00);
    plane->sprite = sfSprite_create();
    sfSprite_setTexture(plane->sprite, game->plane_textire, sfTrue);
    sfSprite_setPosition(plane->sprite, plane->dparture);
    plane->clock = sfClock_create();
    return plane;
}

tower_t *new_tower(char *line, game_t *game)
{
    int *data = get_nbrs_from_line(line, 3);
    tower_t *tower = malloc(sizeof(tower_t));
    tower->position.x = data[0];
    tower->position.y = data[1];
    tower->control_area = create_circle(tower->position, data[2]);
    sfVector2f circle_vector;
    circle_vector.x = tower->position.x - CIRCRAD(tower->control_area);
    circle_vector.y = tower->position.y - CIRCRAD(tower->control_area);
    sfCircleShape_setPosition(tower->control_area, circle_vector);
    tower->sprite = sfSprite_create();
    sfSprite_setTexture(tower->sprite, game->tower_texture, sfTrue);
    sfSprite_setPosition(tower->sprite, tower->position);
    return tower;
}

pla_tow_t *create_plane_list_from_script(char *path, game_t *game)
{
    FILE *sc = fopen(path, "r");
    if (!sc) return NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    plist_t *aircrafts = plist_create();
    tlist_t *towers = tlist_create();
    pla_tow_t *pla_tow = malloc(sizeof(pla_tow_t));
    while (nread = getline(&line, &len, sc) != -1) {
        if (line[0] == 'A')
            plist_pushfirst(aircrafts, new_plane(line, game));
        if (line[0] == 'T')
            tlist_pushfirst(towers, new_tower(line, game));
    }
    fclose(sc);
    pla_tow->planes = aircrafts;
    pla_tow->towers = towers;
    return pla_tow;
}
