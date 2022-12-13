# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 10:58:45 by airodrig          #+#    #+#              #
#    Updated: 2022/11/30 15:31:26 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S		=		src/

O		=		obj/

H		=		-I inc/

SRCS	=		$Sft_memset.c \
				$Sft_strlen.c \
				$Sft_strchr.c \
				$Sft_strrchr.c \
				$Sft_atoi.c \
				$Sft_isalpha.c \
				$Sft_isdigit.c \
				$Sft_isalnum.c \
				$Sft_isascii.c \
				$Sft_isprint.c \
				$Sft_toupper.c \
				$Sft_tolower.c \
				$Sft_substr.c \
				$Sft_strjoin.c \
				$Sft_strjoin_chr.c \
				$Sft_putchar_fd.c \
				$Sft_putstr_fd.c \
				$Sft_putendl_fd.c \
				$Sft_putnbr_fd.c \
				$Sft_bzero.c \
				$Sft_memcpy.c \
				$Sft_memmove.c \
				$Sft_memchr.c \
				$Sft_memcmp.c \
				$Sft_strlcpy.c \
				$Sft_strlcat.c \
				$Sft_strcmp.c \
				$Sft_strncmp.c \
				$Sft_strnstr.c \
				$Sft_calloc.c \
				$Sft_strdup.c \
				$Sft_itoa.c \
				$Sft_strtrim.c \
				$Sft_strmapi.c \
				$Sft_striteri.c \
				$Sft_split.c \
				$Sft_memccpy.c \
				$Sget_next_line.c \
				$Sfree_double_ptrs.c \
				$Sft_lstnew.c \
				$Sft_lstadd_front.c \
				$Sft_lstsize.c \
				$Sft_lstlast.c \
				$Sft_lstadd_back.c \
				$Sft_lstdelone.c \
				$Sft_lstclear.c \
				$Sft_lstiter.c \
				$Sft_lstmap.c \
				$Sft_atoi_base.c

OBJS	=		$(SRCS:$S%.c=$O%.o)

CC		=		gcc

RM		=		rm -rf

AR		=		ar rcs

CFLAGS	=		-Wall -Werror -Wextra -g3 #-fsanitize=address

NAME	=		libft.a

NOCOL		=	\033[0m
RED			=	\033[1;31m
ORG			=	\033[0;33m
YEL			=	\033[1;33m
GRN			=	\033[1;32m
BLU			=	\033[0;34m
CYN			=	\033[0;36m
PUR			=	\033[0;35m

#Black        0;30     Dark Gray     1;30
#Red          0;31     Light Red     1;31
#Green        0;32     Light Green   1;32
#Brown/Orange 0;33     Yellow        1;33
#Blue         0;34     Light Blue    1;34
#Purple       0;35     Light Purple  1;35
#Cyan         0;36     Light Cyan    1;36
#Light Gray   0;37     White         1;37

all: $(NAME)

$O%.o: $S%.c
	@[ -d $O ] || mkdir $O
	@$(CC) $(CFLAGS) $H -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@[ -e $(NAME) ] && echo "$(GRN) ✅✅✅ Compilation Succeeded! ✅✅✅ $(NOCOL)"

clean:
	@${RM} $O

fclean: clean
	@${RM} ${NAME}
	@echo "$(CYN) 🧼🧼🧼 All clean! 🧼🧼🧼 $(NOCOL)"

normi:
	@echo "$(PUR) 🔍🔍 Checking Norminette 🔎🔎$(NOCOL)"
	@norminette $S inc

re: fclean all

.PHONY: all clean fclean re normi
