NAME= phonebook

SRC= main.cpp\
	SetterGetter.cpp\
	Contact.cpp

OBJ = $(SRC:.cpp=.o)

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

$(NAME): $(OBJ)
	@ $(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJ)
	@echo "Cleaned all 'o' files successfully"

fclean: clean
	@rm -rf $(NAME)
	@echo "Cleaned Program name successfully"

re: fclean all