##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	=	my_sokoban.c					\
		map.c							\
		map_display.c					\
		check_map.c 					\
		player.c						\
		crate.c							\
		get_objects.c					\
		game.c							\
		free.c							\
		usage.c							\
		sources/my_strlen.c				\
		sources/my_strdup.c				\
		sources/my_char_is_in_str.c 	\
		sources/my_putchar.c			\
		sources/my_putstr.c				\
		str_to_word_array.c 			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -Wall -Wextra

CPPFLAGS = -I include

NCURSES	=	-lncurses

NAME	=	my_sokoban

all:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(NCURSES)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	re all fclean clean
