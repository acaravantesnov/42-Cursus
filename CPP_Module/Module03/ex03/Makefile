# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 20:37:55 by acaravan          #+#    #+#              #
#    Updated: 2022/07/17 20:37:57 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= DiamondTrap

SRCS			=	main.cpp \
					DiamondTrap.cpp \
					ClapTrap.cpp \
					ScavTrap.cpp \
					FragTrap.cpp

OBJS			= $(SRCS:.cpp=.o)

GCC				= clang++
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -std=c++98 -pedantic -Wshadow -Wno-shadow



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