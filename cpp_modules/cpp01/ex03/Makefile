# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 12:12:00 by riccardobor       #+#    #+#              #
#    Updated: 2023/12/03 14:26:08 by riccardobor      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp 

CFLAGS = -Werror -Wextra -Wall -std=c++98

OBJS = $(SRC:.cpp=.o)

NAME = unnecessary_violence

MAKEFLAGS += --silent

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[32mViolence is ready to spread!\033[0m"

%.o:%.cpp
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f *.o

fclean: clean
	rm $(NAME)
	@echo "\033[35mAll fights are settled!\033[0m"

re:
	clean fclean make
