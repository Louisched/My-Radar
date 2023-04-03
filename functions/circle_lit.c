/*
** EPITECH PROJECT, 2022
** circle list
** File description:
** Functions for circle lists
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/functions.h"
#include "../includes/linked_lists.h"

void detect(pnode_t *c1, pnode_t *c2, pla_tow_t *list)
{
    tnode_t *current = list->towers->head;
    for (current ; current ; current = current->next) {
        if (is_plane_in_controll_area(c1->data, current->data)) return;
        if (is_plane_in_controll_area(c2->data, current->data)) return;
    }
    if (c1->index == c2->index) return;
    if (is_intersecting_circles(c1->data, c2->data) == 1) {
        sfRectangleShape_destroy(c1->data->circle);
        sfSprite_destroy(c1->data->sprite);
        sfRectangleShape_destroy(c2->data->circle);
        sfSprite_destroy(c2->data->sprite);
        plist_pop(&list->planes, c1->index);
        plist_pop(&list->planes, c2->index);
    }
}

void calculate_colisions(pla_tow_t *list)
{
    pnode_t *current = list->planes->head;
    pnode_t *current2 = list->planes->head->next;
    for (current ; current ; current = current->next) {
        for (current2 ; current2 ; current2 = current2->next) {
            detect(current, current2, list);
        }
        current2 = current->next;
    }
}

void move_circles(plist_t *list)
{
    pnode_t *current = list->head;
    int mvrand;
    sfVector2f vector;
    for (current ; current ; current = current->next) {
        mvrand = rand() % 5;
        vector.x = sfRectangleShape_getPosition(current->data->circle).x;
        vector.y = sfRectangleShape_getPosition(current->data->circle).y;
        if (mvrand == 1 && vector.x < 800) vector.x++;
        if (mvrand == 2 && vector.x > 0) vector.x--;
        if (mvrand == 3 && vector.y < 600) vector.y++;
        if (mvrand == 4 && vector.y > 0) vector.y--;
        sfRectangleShape_setPosition(current->data->circle, vector);
    }
}

void move_planes(pla_tow_t *pt)
{
    sfVector2f vector;
    pnode_t *current = pt->planes->head;
    for (current ; current ; current = current->next) {
        vector.x = DDATA->speed * (current->data->direc_x == RIGHT) ? 1 : -1;
        vector.y = DDATA->speed * (current->data->direc_y == DOWN) ? 1 : -1;
        sfVector2f pos = sfRectangleShape_getPosition(current->data->circle);
        if (pos.x <= 20) current->data->direc_x = RIGHT;
        if (pos.x >= 1900) current->data->direc_x = LEFT;
        if (pos.y <= 20) current->data->direc_y = DOWN;
        if (pos.y >= 1000) current->data->direc_y = UP;
        sfRectangleShape_move(current->data->circle, vector);
        sfSprite_move(current->data->sprite, vector);
    }
}

void print_framerate(void)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    sfTime elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        my_put_nbr(fps);
        my_putstr(" FPS\n");
        fps = 0;
        sfClock_restart(clock);
    } else
        fps++;
}

/*
plist_t *put_circles_into_sublists(plist_t *src, int height, int width)
{
    plist_t **list_arr = malloc(sizeof(plist_t *) * 16);
    plane_t *to_add;
    for (int i = 0 ; i < 16 ; i++)
        list_arr[i] = plist_create();
    float x;
    float y;
    while (src->head) {
        to_add = plist_pop(src, 0);
        x = sfCircleShape_getPosition(to_add->circle).x;
        y = sfCircleShape_getPosition(to_add->circle).y;
        if (BETW(x, 0, width / 16) && BETW(y, 0, height / 16))

    }
}*/
