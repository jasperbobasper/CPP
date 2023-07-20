NAME	= brain
SRCS	= main.cpp

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

all:		${NAME}

${NAME}:
			${CC} ${SRCS} ${FLAGS} -o ${NAME} 

fclean:	
			rm -f ${NAME}

re:			fclean all

.PHONY:		re fclean all