##
## EPITECH PROJECT, 2019
## PSU_zappy
## File description:
## makefile
##

NAME		=	zappy_server

SRC		=	src/main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wextra -Wall -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:			clean all

.PHONY:	all clean fclean re
