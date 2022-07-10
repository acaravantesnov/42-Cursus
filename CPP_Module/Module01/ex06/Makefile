# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 15:54:24 by acaravan          #+#    #+#              #
#    Updated: 2022/07/04 15:54:49 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Karen

SRCS			=	main.cpp \
					Karen.cpp

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