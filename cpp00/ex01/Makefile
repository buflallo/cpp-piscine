SRC=Contact.cpp PhoneBook.cpp main.cpp
OBJ=Contact.o PhoneBook.o main.o
FLAGS=-Wall -Wextra -Werror
NAME=oldphonebook
STD=-std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(FLAGS) $(STD) $(OBJ) -o $(NAME)

%.o: %.cpp
	g++ $(FLAGS) $(STD) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all