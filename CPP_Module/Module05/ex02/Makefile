# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 14:41:22 by acaravan          #+#    #+#              #
#    Updated: 2022/07/09 23:50:57 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	No,_you_need_form_28B,_not_28C...

SRCS			=	main.cpp \
					Bureaucrat.cpp \
					Form.cpp \
					ShrubberyCreationForm.cpp \
					RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp

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