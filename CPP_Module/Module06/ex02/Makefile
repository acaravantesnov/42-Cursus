# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 14:41:22 by acaravan          #+#    #+#              #
#    Updated: 2022/07/22 14:18:17 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Real_type

SRCS			=	main.cpp \
					Real_type.cpp

OBJS			=	$(SRCS:.cpp=.o)

CXX				=	clang++
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