##
## EPITECH PROJECT, 2019
## PSU_zappy
## File description:
## makefile
##

NAME			=	zappy_server

SRC_DIR			= 	./src/

SRC_FILES		=	main.c

SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ				=	$(SRC:.c=.o)

CPPFLAGS		+=	-I./include/

CFLAGS			+=	-Wextra -Wall -Werror


all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)
			mv $(NAME) ..

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) ../$(NAME)

re:			fclean all

.PHONY:		all clean fclean re
