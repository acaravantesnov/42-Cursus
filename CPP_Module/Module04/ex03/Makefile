# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 14:41:22 by acaravan          #+#    #+#              #
#    Updated: 2022/07/21 13:54:03 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Interface

SRCS			=	main.cpp \
					AMateria.cpp \
					Character.cpp \
					Cure.cpp \
					Ice.cpp \
					MateriaSource.cpp

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