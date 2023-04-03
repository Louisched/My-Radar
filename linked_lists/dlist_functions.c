/*
** EPITECH PROJECT, 2022
** str append
** File description:
** Append data to a str linked list
*/

#include <stdlib.h>
#include "../includes/linked_lists.h"

plist_t *plist_create(void)
{
    plist_t *list = malloc(sizeof(plist_t));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void plist_pushlast(plist_t *list, plane_t *to_add)
{
    pnode_t *new_node = malloc(sizeof(pnode_t));
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

void plist_display(plist_t *list, char *separator)
{
    pnode_t *current = list->head;
    while (current != NULL) {
        my_put_nbr(current->index);
        if (current->index < list->length - 1) my_putstr(separator);
        current = current->next;
    }
    my_putchar('\n');
}

void plist_nodecpy(pnode_t *to_copy, pnode_t *dest)
{
    dest->data = to_copy->data;
    dest->index = to_copy->index;
    dest->prev = NULL;
    dest->next = NULL;
}

pnode_t *plist_pop(plist_t **list, int index)
{
    if (index >= (* list)->length) return NULL;
    pnode_t *current = (* list)->head;
    pnode_t *to_return = malloc(sizeof(pnode_t));
    if (index == 0) {
        plist_nodecpy(current, to_return);
        (* list)->head = current->next;
    }
    if (index > 0) {
        while (current->next->index < index) current = current->next;
        plist_nodecpy(current, to_return);
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
