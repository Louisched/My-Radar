/*
** EPITECH PROJECT, 2022
** functions
** File description:
** functions
*/

#ifndef FUNCTIONS_H_
    #define FUNCTIONS_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include "my.h"

    typedef enum {RIGHT, LEFT} direc_x_t;
    typedef enum {UP, DOWN} direc_y_t;

    typedef struct game_tools {
        sfVideoMode mode;
        sfRenderWindow *window;
        sfEvent event;
        sfClock *clock;
        sfTime time;
        sfTexture *plane_textire;
        sfTexture *tower_texture;
        sfTexture *background;
        sfSprite *background_sprite;
    } game_t;

    typedef struct sprite_data {
        sfRectangleShape *circle;
        bool_t destroy;
        sfVector2f dparture;
        sfVector2f arrival;
        int speed;
        int t;
        sfSprite *sprite;
        direc_x_t direc_x;
        direc_y_t direc_y;
        sfClock *clock;
    } plane_t;

    typedef struct tower_data {
        sfCircleShape *control_area;
        sfVector2f position;
        sfSprite *sprite;
    } tower_t;

    #include "linked_lists.h"

    typedef struct towers_and_planes {
        plist_t *planes;
        tlist_t *towers;
    } pla_tow_t;

    #define PARAM sfClose | sfResize
    #define DRAW_CRICLE sfRenderWindow_drawCircleShape
    #define BETW(x, min, max) x >= min && x < max
    #define CIRCRAD sfCircleShape_getRadius
    #define DRAW_RECT sfRenderWindow_drawRectangleShape
    #define DDATA current->data

    sfCircleShape *create_circle (sfVector2f position, float radius);
    int is_intersecting_circles(plane_t *c1, plane_t *c2);
    void calculate_colisions(pla_tow_t *list);
    void move_circles(plist_t *list);
    void print_framerate(void);
    int get_nbr_len(char *line, int ind);
    int *get_nbrs_from_line(char *line, int at);
    pla_tow_t *create_plane_list_from_script(char *path, game_t *game);
    int power(int n, int p);
    int get_nbr_begginig_ind(char *line, int ind);
    int get_nbr_len(char *line, int ind);
    bool_t is_script_valid(char *path);
    void move_planes(pla_tow_t *pt);
    int is_plane_in_controll_area(plane_t *c1, tower_t *c2);
    int help(void);

#endif /* !FUNCTIONS_H_ */
