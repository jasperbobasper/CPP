NAME	= phonebook

CC = c++

FLAGS = -Wall -Werror -Wextra

RM = rm -f

SRC = main.cpp phonebook.cpp contact.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
