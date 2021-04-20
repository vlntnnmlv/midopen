CC = clang++
FLAGS = -Wall -Werror -Wextra -std=c++98 -O3
NAME = mindopen
SRC = main.cpp Memory.cpp Compiler.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): ${OBJ}
	${CC} ${FLAGS} ${SRC} -o ${NAME}

re: fclean all
	
clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}