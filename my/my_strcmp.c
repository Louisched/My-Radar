/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** my_strcmp
*/

#include "../includes/functions.h"

int my_strcmp(const char *s1, const char *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return (-1);
    for (int i = 0 ; s1[i] != '\0' ; i++)
        if (s1[i] != s2[i])
            return (-1);
    return (0);
}
