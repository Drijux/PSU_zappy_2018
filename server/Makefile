##
## EPITECH PROJECT, 2019
## PSU_zappy
## File description:
## makefile
##

NAME			=	zappy_server

SRC 			=	src/main.c

# source of handle error
SRC 			+= 	src/handle_error/handle_err.c 		\
					src/handle_error/init_struct.c  	\
					src/handle_error/check_arg_nb.c 	\
					src/handle_error/check_arg_str.c

# source of initiation server
SRC 			+= 	src/init_serv/init_serv.c 	\
					src/init_serv/server.c

OBJ				=	$(SRC:.c=.o)

CPPFLAGS		+=	-I./include/

CFLAGS			+=	-Wextra -Wall


all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)
# 			mv $(NAME) ..

clean:
			$(RM) $(OBJ)

fclean:		clean
# 			$(RM) ../$(NAME)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
