# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 21:39:40 by acaravan          #+#    #+#              #
#    Updated: 2022/08/02 00:33:36 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

SRCS			=	main.c

LIBFT			=	./includes/libft/libft.a

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

%.o:			%.C
				$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@


all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

$(LIBFT):		make -C ./includes/libft

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			$(NAME)

.PHONY:			all clean fclean re test