/*
** EPITECH PROJECT, 2022
** str append
** File description:
** Append data to a str linked list
*/

#include <stdlib.h>
#include "../includes/linked_lists.h"

tlist_t *tlist_create(void)
{
    tlist_t *list = malloc(sizeof(tlist_t));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void tlist_pushlast(tlist_t *list, tower_t *to_add)
{
    tnode_t *new_node = malloc(sizeof(tnode_t));
    new_node->data = to_add;
    if (list->head == NULL && list->tail == NULL) {
        new_node->prev = NULL;
        new_node->next = NULL;
        new_node->index = 0;
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->index = list->tail->index + 1;
        list->tail->next = new_node;
        new_node->prev = list->tail;
        new_node->next = NULL;
        list->tail = new_node;
    }
    list->length++;
}

void tlist_display(tlist_t *list, char *separator)
{
    tnode_t *current = list->head;
    while (current != NULL) {
        my_put_nbr(current->index);
        if (current->index < list->length - 1) my_putstr(separator);
        current = current->next;
    }
    my_putchar('\n');
}

void tlist_nodecpy(tnode_t *to_copy, tnode_t *dest)
{
    dest->data = to_copy->data;
    dest->index = to_copy->index;
    dest->prev = NULL;
    dest->next = NULL;
}

tnode_t *tlist_pop(tlist_t **list, int index)
{
    if (index >= (* list)->length) return NULL;
    tnode_t *current = (* list)->head;
    tnode_t *to_return = malloc(sizeof(tnode_t));
    if (index == 0) {
        tlist_nodecpy(current, to_return);
        (* list)->head = current->next;
    }
    if (index > 0) {
        while (current->next->index < index) current = current->next;
        tlist_nodecpy(current, to_return);
        current->next = current->next->next;
    }
    while (current->next != NULL) {
        current->next->index--;
        current = current->next;
    }
    (* list)->length--;
    if ((* list)->length == 0) (* list)->head = NULL;
    if ((* list)->length == 0) (* list)->tail = NULL;
    return to_return;
}
