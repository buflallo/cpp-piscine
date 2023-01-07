
NAME=UnnecessaryViolence
SRC=main.cpp Weapon.hpp Weapon.cpp HumanA.hpp HumanA.cpp HumanB.hpp HumanB.cpp
OBJ=$(SRC:.cpp=.o)
CFLAGS=-Wall -Wextra -Werror
CC=c++

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