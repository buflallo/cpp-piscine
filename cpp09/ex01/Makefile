NAME=RPN
SRC=main.cpp RPN.cpp
OBJ=$(SRC:.cpp=.o)
CFLAGS=-Wall -Wextra -Werror
CC=c++ -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
