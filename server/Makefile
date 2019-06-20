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
					src/init_serv/init_server.c

# source to launch server
SRC 			+= 	src/server/server.c 		\
					src/server/send_recv.c 		\
					src/server/handle_poll.c 	\
					src/server/my_poll.c

SRC 			+= 	src/action/forward.c 		\
					src/action/broadcast.c 		\
					src/action/right.c 			\
					src/action/incantation.c 	\
					src/action/inventory.c 		\
					src/action/look.c 			\
					src/action/my_eject.c 		\
					src/action/my_fork.c 		\
					src/action/set_object.c 	\
					src/action/take_object.c 	\
					src/action/left.c 			\
					src/action/connect_nbr.c 	\

OBJ				=	$(SRC:.c=.o)

CPPFLAGS		+=	-I./include/

CFLAGS			+=	-Wextra -Wall


all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)
			cp $(NAME) ..

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) ../$(NAME)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
