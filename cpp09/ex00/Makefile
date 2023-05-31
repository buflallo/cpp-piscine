# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlachkar <hlachkar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 01:39:55 by hlachkar          #+#    #+#              #
#    Updated: 2023/05/31 01:39:56 by hlachkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=btc
SRC=main.cpp BitcoinExchange.cpp
OBJ=$(SRC:.cpp=.o)
CFLAGS=-Wall -Wextra -Werror
CC=c++ -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
