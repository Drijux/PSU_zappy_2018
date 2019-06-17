##
## EPITECH PROJECT, 2019
## zappy_ai
## File description:
## Makefile of zappy_ai project
##

NAME			=	zappy_ai

SRC_DIR			=	./src/

SRC_FILES		=	main.cpp

SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ				=	$(SRC:.cpp=.o)

CPPFLAGS		+=	-I./include/

CXXFLAGS		+=	-Wall -Wextra -Werror


all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) -o $(NAME) $(OBJ)
			mv $(NAME) ..

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) ../$(NAME)

re:			fclean all

.PHONY:		all clean fclean re