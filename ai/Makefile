##
## EPITECH PROJECT, 2019
## zappy_ai
## File description:
## Makefile of zappy_ai project
##

NAME			=	zappy_ai

SRC_DIR			=	./src/

CLASS_DIR		=	./src/class/

SRC_FILES		=	argument.cpp	\
					main.cpp

CLASS_FILES		=	client.cpp	\
					mybot.cpp

SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))

CLASS			=	$(addprefix $(CLASS_DIR), $(CLASS_FILES))

OBJ				=	$(SRC:.cpp=.o)	\
					$(CLASS:.cpp=.o)

CPPFLAGS		+=	-I./include/ -I./include/class/

CXXFLAGS		+=	-Wall -Wextra -Werror


all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) -o ../$(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) ../$(NAME)

re:			fclean all

.PHONY:		all clean fclean re