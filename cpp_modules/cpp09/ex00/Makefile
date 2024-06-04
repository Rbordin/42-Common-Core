# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 17:41:41 by riccardobor       #+#    #+#              #
#    Updated: 2023/12/03 14:26:08 by riccardobor      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

SRC = *.cpp

CFLAGS = -Werror -Wextra -Wall -std=c++98

OBJS = $(SRC:.cpp=.o)

NAME = btc

MAKEFLAGS += --silent

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[32mBitcoin exchanger calculator is ready!\033[0m"

%.o:%.cpp
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f *.o

fclean: clean
	rm $(NAME)
	@echo "\033[35mBitcoin exchanger calculator is now off!\033[0m"

re:
	clean fclean make
