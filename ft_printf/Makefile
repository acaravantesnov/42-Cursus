# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 20:12:27 by acaravan          #+#    #+#              #
#    Updated: 2021/08/14 19:51:28 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
SRCS =	ft_printf.c \
		sources/ft_putstr.c \
		sources/ft_putnbr.c \
		sources/ft_putunbr.c \
		sources/ft_pointer.c \
		sources/ft_putchar.c \
		sources/ft_putnbr_base.c \
		sources/ft_putnbr_base2.c \
		sources/ft_printfext.c \

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)
CC = gcc
RM = rm -f
NORME = norminette -R CheckForbiddenSourceHeader $(SRCS)

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) a.out

fclean: clean
	$(RM) $(NAME)

re: fclean all

norma: $(NORME)
