# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 14:41:22 by acaravan          #+#    #+#              #
#    Updated: 2023/08/17 17:41:31 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	PmergeMe

SRCS			=	main.cpp \
					PmergeMe.cpp

OBJS			=	$(SRCS:.cpp=.o)

CXX				=	c++
RM				=	rm -f
CXXFLAGS		=	-Wall -Wextra -Werror -g -std=c++98 -pedantic

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -g -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			$(NAME)

.PHONY:			all clean fclean re test