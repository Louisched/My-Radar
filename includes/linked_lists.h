/*
** EPITECH PROJECT, 2022
** Linked lists
** File description:
** Jeader for linked lists
*/

#include "../includes/my.h"
#include "functions.h"
#include <SFML/Graphics.h>

#ifndef LINKED_LISTS_H_
    #define LINKED_LISTS_H_

    typedef struct node {
        plane_t *data;
        int index;
        struct node *next;
        struct node *prev;
    } pnode_t;

    typedef struct plist {
        int length;
        pnode_t *head;
        pnode_t *tail;
    } plist_t;

    typedef struct tnode {
        tower_t *data;
        int index;
        struct tnode *next;
        struct tnode *prev;
    } tnode_t;

    typedef struct tlist {
        int length;
        tnode_t *head;
        tnode_t *tail;
    } tlist_t;

    plist_t *plist_create(void);
    void plist_pushlast(plist_t *list, plane_t *to_add);
    void plist_display(plist_t *list, char *separator);
    pnode_t *plist_pop(plist_t **list, int index);
    pnode_t *plist_getnode(plist_t *list, unsigned int index);
    void plist_nodecpy(pnode_t *to_copy, pnode_t *dest);
    void plist_cpy(plist_t *src, plist_t *dest);
    void plist_empty(plist_t **list);
    void plist_pushfirst(plist_t *list, plane_t *to_add);
    void plist_pushmid(plist_t *list, plane_t *to_add, unsigned int index);

    tlist_t *tlist_create(void);
    void tlist_pushlast(tlist_t *list, tower_t *to_add);
    void tlist_display(tlist_t *list, char *separator);
    tnode_t *tlist_pop(tlist_t **list, int index);
    tnode_t *tlist_getnode(tlist_t *list, unsigned int index);
    void tlist_nodecpy(tnode_t *to_copy, tnode_t *dest);
    void tlist_cpy(tlist_t *src, tlist_t *dest);
    void tlist_empty(tlist_t **list);
    void tlist_pushfirst(tlist_t *list, tower_t *to_add);
    void tlist_pushmid(tlist_t *list, tower_t *to_add, unsigned int index);


#endif /* !LINKED_LISTS_H_ */
