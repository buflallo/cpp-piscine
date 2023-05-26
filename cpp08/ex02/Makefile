NAME	= MutantStack
CC		= c++
FLAGS	= -Wall -Werror -Wextra
SRCS 	= main.cpp

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all