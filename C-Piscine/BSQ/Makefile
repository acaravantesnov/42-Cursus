# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/15 16:14:34 by acaravan          #+#    #+#              #
#    Updated: 2020/12/15 16:15:01 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BSQ
SRCS = main.c
FLAGS = -Wall -Wextra -Werror
CLEAN = rm -f
CC = cc

all:	
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)
clean:
		$(CLEAN) $(NAME)
fclean:	clean
		$(CLEAN) *.o .DS_Store
norma:
		norminette -R CheckForbiddenSourceHeader