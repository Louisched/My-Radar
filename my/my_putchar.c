/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** My_putchar
*/

#include "../includes/my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
