# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 14:41:22 by acaravan          #+#    #+#              #
#    Updated: 2022/07/10 02:06:38 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Some_functions

SRCS			=	main.cpp

OBJS			=	$(SRCS:.cpp=.o)

GCC				=	clang++
RM				=	rm -f
FLAGS			=	-Wall -Wextra -Werror -std=c++98 -pedantic

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