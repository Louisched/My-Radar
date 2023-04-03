/*
** EPITECH PROJECT, 2023
** functions
** File description:
** Some functions
*/

#include "../includes/my.h"
#include "../includes/functions.h"
#include "../includes/linked_lists.h"
#include <stdio.h>
#include <stdlib.h>

int power(int n, int p)
{
    int n_copy = n;
    int i = 0;
    if (p == 0)
        return (1);
    for (i ; i < p - 1 ; i++) {
        n *= n_copy;
    }
    return (n);
}

int get_nbr_begginig_ind(char *line, int ind)
{
    int i = 0;
    while (!(BETW(line[i], 48, 58))) i++;
    for (int j = 0 ; j < ind ; j++) {
        while (BETW(line[i], 48, 58)) i++;
        while (!(BETW(line[i], 48, 58))) i++;
    }
    return i;
}

int get_nbr_len(char *line, int ind)
{
    int start = get_nbr_begginig_ind(line, ind);
    int count = start;
    while (BETW(line[count], 48, 58)) count++;
    return count - start;
}
