NAME	= Span
CC		= c++ -std=c++98
FLAGS	= -Wall -Werror -Wextra
SRCS 	= main.cpp span.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all