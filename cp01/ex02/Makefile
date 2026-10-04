NAME = brain

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

cxxflags = -Wall -Wextra -Werror -std=c++98

cxx = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(cxx) $(cxxflags) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.phony: all clean fclean re