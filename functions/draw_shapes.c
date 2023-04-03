/*
** EPITECH PROJECT, 2022
** draw shapes
** File description:
** draw shapes
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <math.h>
#include "../includes/functions.h"
#include "../includes/my.h"

sfCircleShape *create_circle (sfVector2f position, float radius)
{
    sfCircleShape *circle;
    circle = sfCircleShape_create();
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineThickness(circle, 5.00);
    return (circle);
}

int is_intersecting_circles(plane_t *c1, plane_t *c2)
{
    int Cr = 10;
    int Dr = 10;
    int Cx = sfRectangleShape_getPosition(c1->circle).x + Cr;
    int Cy = sfRectangleShape_getPosition(c1->circle).y + Cr;
    int Dx = sfRectangleShape_getPosition(c2->circle).x + Dr;
    int Dy = sfRectangleShape_getPosition(c2->circle).y + Dr;
    if (pow(Cx - Dx, 2) + pow(Cy - Dy, 2) <= pow(Cr + Dr, 2))
        return (1);
    return (0);
}

int is_plane_in_controll_area(plane_t *c1, tower_t *c2)
{
    int Cr = 10;
    int Dr = sfCircleShape_getRadius(c2->control_area);
    int Cx = sfRectangleShape_getPosition(c1->circle).x + Cr;
    int Cy = sfRectangleShape_getPosition(c1->circle).y + Cr;
    int Dx = sfCircleShape_getPosition(c2->control_area).x + Dr;
    int Dy = sfCircleShape_getPosition(c2->control_area).y + Dr;
    if (pow(Cx - Dx, 2) + pow(Cy - Dy, 2) <= pow(Cr + Dr, 2))
        return (1);
    return (0);
}
