NAME = btc

SRC = main.cpp\
	BitcoinExchange.cpp\

OBJ = $(SRC:.cpp=.o)

CXX = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror -g3

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

