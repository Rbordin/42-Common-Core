NAME			= RPN

SRCS			= main.cpp \
					RPN.cpp\
			
OBJS			= $(SRCS:.cpp=.o)

CC				= c++
RM				= rm -f
FLAG			= -Wall -Wextra -Werror  -std=c++98


all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(FLAG) -o $(NAME) $(OBJS)


clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)