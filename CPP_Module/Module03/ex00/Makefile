SRCS			=	main.cpp \
					ClapTrap.cpp

OBJS			= $(SRCS:.cpp=.o)

GCC				= clang++
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -std=c++98 -pedantic

NAME			= ClapTrap

all:			$(NAME)

$(NAME):		$(OBJS)
				$(GCC) $(FLAGS) -g -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			$(NAME)

.PHONY:			all clean fclean re test