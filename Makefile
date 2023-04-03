##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	main.c \
		my/my_strlen.c \
		my/my_putchar.c \
		my/my_putstr.c \
		my/my_put_nbr.c \
		linked_lists/dlist_functions.c \
        linked_lists/dlist_functionsb.c \
		tower_dlist/dlist_functions.c \
		tower_dlist/dlist_functionsb.c \
		functions/draw_shapes.c \
		functions/circle_lit.c \
		functions/interpret_script.c \
		functions/functions.c \
		functions/error_handler.c

NAME = my_radar


all:
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean
	make
