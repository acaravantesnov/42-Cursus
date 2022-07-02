# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 20:12:27 by acaravan          #+#    #+#              #
#    Updated: 2022/06/22 12:01:41 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS =	ft_memset.c \
		ft_strlcpy.c \
		ft_strmapi.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_realloc.c \
		ft_strlen.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strlcat.c \
		ft_itoa.c \
		ft_pow.c \
		ft_cifras.c \
		ft_strcpy.c \
		ft_avanzar.c \
		ft_while_itoa.c \
		ft_split.c \
		extra_libft.c \

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

FLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = ${BONUS:.c=.o}
CC = gcc
RM = rm -f
NORME = norminette -R CheckForbiddenSourceHeader $(SRCS)

.c.o:
	$(CC) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) a.out

fclean: clean
	$(RM) $(NAME)

re: fclean all

norma: $(NORME)

bonus: ${BONUS_OBJS} ${OBJS}
	ar rcs ${NAME} ${BONUS_OBJS} ${OBJS}
