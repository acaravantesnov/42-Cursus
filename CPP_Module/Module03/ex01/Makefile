# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 18:03:32 by acaravan          #+#    #+#              #
#    Updated: 2022/07/09 18:04:18 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ScavTrap

SRCS			=	main.cpp \
					ClapTrap.cpp \
					ScavTrap.cpp

OBJS			= $(SRCS:.cpp=.o)

GCC				= clang++
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -std=c++98 -pedantic

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