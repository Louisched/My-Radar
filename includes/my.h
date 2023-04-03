/*
** EPITECH PROJECT, 2022
** My
** File description:
** My header
*/

#ifndef MY_H_
    #define MY_H_

int my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char *str);
int my_strcmp(const char *s1, const char *s2);

    #define debug my_putstr("debug\n");
    #define ENT my_putchar('\n')

    #define True 1
    #define False 0
    typedef int bool_t;

#endif /* !MY_H_ */
