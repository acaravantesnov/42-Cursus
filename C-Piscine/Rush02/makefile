# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juanmart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 21:43:30 by juanmart          #+#    #+#              #
#    Updated: 2020/12/13 22:11:38 by juanmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
SRCS = main.c ft_slicer.c ft_gerror.c ft_dict.c ft_cooldict.c
FLAGS = -Wall -Wextra -Werror
CLEAN = rm -f
CC = cc

all:	
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
		$(CLEAN) $(NAME)
fclean:
		$(CLEAN) *.o *.gch .DS_Store
norma:
		norminette
re::	
		fclean all
