# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 14:41:22 by acaravan          #+#    #+#              #
#    Updated: 2023/08/16 17:35:10 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	PmergeMe

SRCS			=	main.cpp \
					PmergeMe.cpp

OBJS			=	$(SRCS:.cpp=.o)

CXX				=	c++
RM				=	rm -f
CXXFLAGS		=	-Wall -Wextra -Werror -g 

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