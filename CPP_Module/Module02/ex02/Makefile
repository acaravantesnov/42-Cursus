# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 18:52:02 by acaravan          #+#    #+#              #
#    Updated: 2022/07/16 22:55:27 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Fixed

SRCS			=	main.cpp \
					Fixed.cpp

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