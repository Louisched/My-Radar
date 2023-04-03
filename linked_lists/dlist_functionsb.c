/*
** EPITECH PROJECT, 2022
** plist functions
** File description:
** File B for plist functions
*/

#include <stdlib.h>
#include "../includes/functions.h"
#include "../includes/linked_lists.h"

pnode_t *plist_getnode(plist_t *list, unsigned int index)
{
    if (index >= list->length) return NULL;
    if (index == 0) return list->head;
    pnode_t *current = list->head;
    while (current->next->index < index) current = current->next;
    return current->next;
}

void plist_cpy(plist_t *src, plist_t *dest)
{
    pnode_t *current = src->head;
    while (current != NULL) {
        plist_pushlast(dest, current->data);
        current = current->next;
    }
}

void plist_empty(plist_t **list)
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
    pnode_t *current = (* list)->head;
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

void plist_pushfirst(plist_t *list, plane_t *to_add)
{
    pnode_t *new_node = malloc(sizeof(pnode_t));
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
    pnode_t *current = list->head->next;
    while (current != NULL) {
        current->index++;
        current = current->next;
    }
}

void plist_pushmid(plist_t *list, plane_t *to_add, unsigned int index)
{
    if (index > list->length) return;
    if (index == list->length) return plist_pushlast(list, to_add);
    if (index == 0) return plist_pushfirst(list, to_add);
    pnode_t *new_node = malloc(sizeof(pnode_t));
    new_node->data = to_add;
    new_node->index = index;
    pnode_t *current = list->head;
    while (current->next->index < index) current = current->next;
    new_node->next = current->next;
    new_node->prev = plist_getnode(list, current->index);
    current->next = new_node;
    current = new_node;
    while (current->next != NULL) {
        current->next->index++;
        current = current->next;
    }
    list->length++;
}
