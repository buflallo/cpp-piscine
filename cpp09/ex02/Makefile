# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 01:37:33 by hlachkar          #+#    #+#              #
#    Updated: 2023/05/31 01:37:34 by hlachkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=PmergeMe
SRC=main.cpp PmergeMe.cpp
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
