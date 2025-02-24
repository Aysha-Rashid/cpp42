NAME = PmergeMe
SRC = main.cpp\
	PmergeMe.cpp\

OBJ = $(SRC:.cpp=.o)

CXX = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror -O2

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

