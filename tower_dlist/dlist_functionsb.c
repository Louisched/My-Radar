/*
** EPITECH PROJECT, 2022
** tlist functions
** File description:
** File B for tlist functions
*/

#include <stdlib.h>
#include "../includes/functions.h"
#include "../includes/linked_lists.h"

tnode_t *tlist_getnode(tlist_t *list, unsigned int index)
{
    if (index >= list->length) return NULL;
    if (index == 0) return list->head;
    tnode_t *current = list->head;
    while (current->next->index < index) current = current->next;
    return current->next;
}

void tlist_cpy(tlist_t *src, tlist_t *dest)
{
    tnode_t *current = src->head;
    while (current != NULL) {
        tlist_pushlast(dest, current->data);
        current = current->next;
    }
}

void tlist_empty(tlist_t **list)
{
    if ((* list)->length == 0) return;
    if ((* list)->length == 1) {
        free((* list)->head);
        free((* list)->tail);
        (* list)->length = 0;
        (* list)->head = NULL;
        (* list)->tail = NULL;
        return;
    }
    tnode_t *current = (* list)->head;
    current = current->next;
    while (current != NULL) {
        free(current->prev);
        current = current->next;
    }
    (* list)->length = 0;
    free((* list)->tail);
    (* list)->head = NULL;
    (* list)->tail = NULL;
}

void tlist_pushfirst(tlist_t *list, tower_t *to_add)
{
    tnode_t *new_node = malloc(sizeof(tnode_t));
    new_node->data = to_add;
    new_node->index = 0;
    list->length++;
    if (list->head == NULL && list->tail == NULL) {
        new_node->next = NULL;
        new_node->prev = NULL;
        list->head = new_node;
        list->tail = new_node;
        return;
    }
    new_node->next = list->head;
    new_node->prev = NULL;
    list->head->prev = new_node;
    list->head = new_node;
    tnode_t *current = list->head->next;
    while (current != NULL) {
        current->index++;
        current = current->next;
    }
}

void tlist_pushmid(tlist_t *list, tower_t *to_add, unsigned int index)
{
    if (index > list->length) return;
    if (index == list->length) return tlist_pushlast(list, to_add);
    if (index == 0) return tlist_pushfirst(list, to_add);
    tnode_t *new_node = malloc(sizeof(tnode_t));
    new_node->data = to_add;
    new_node->index = index;
    tnode_t *current = list->head;
    while (current->next->index < index) current = current->next;
    new_node->next = current->next;
    new_node->prev = tlist_getnode(list, current->index);
    current->next = new_node;
    current = new_node;
    while (current->next != NULL) {
        current->next->index++;
        current = current->next;
    }
    list->length++;
}
