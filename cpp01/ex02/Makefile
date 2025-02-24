NAME= Zombie


SRC= main.cpp\

OBJ = $(SRC:.cpp=.o)

CPP = c++

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

$(NAME): $(OBJ)
	@ $(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@rm $(OBJ)
	@echo "Cleaned all 'o' files successfully"

fclean: clean
	@rm $(NAME)
	@echo "Cleaned Program name successfully"

re: fclean all