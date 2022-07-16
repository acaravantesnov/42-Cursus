# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 18:52:02 by acaravan          #+#    #+#              #
#    Updated: 2022/07/15 18:52:04 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed

SRCS =	main.cpp \
		Fixed.cpp \

RESIDUES =	./a.out.dSYM \

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)

CC = clang++ -g

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS)

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME) $(RESIDUES)

re: fclean all