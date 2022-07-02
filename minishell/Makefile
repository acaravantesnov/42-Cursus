# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 22:34:43 by acaravan          #+#    #+#              #
#    Updated: 2022/06/30 17:54:08 by acaravan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

HEADER			= ./includes

LIBFT			= ./sources/libft/libft.a

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror -g -I$(HEADER) -I$(RL_INC) #-fsanitize=address

RL_INC			= $(HOME)/.brew/opt/readline/include
RL_LIB			= $(HOME)/.brew/opt/readline/lib

SRCS			=	main.c \
					./sources/builtins/cd.c \
					./sources/builtins/cd_utils.c \
					./sources/builtins/echo.c \
					./sources/builtins/env.c \
					./sources/builtins/exit_builtin.c \
					./sources/builtins/export.c \
					./sources/builtins/export_utils.c \
					./sources/builtins/pwd.c \
					./sources/builtins/unset.c \
					./sources/generate_envp_variables.c \
					./sources/generate_sorted_envp_variables.c \
					./sources/execbuiltin.c \
					./sources/process.c \
					./sources/seek_builtin.c \
					./sources/find_path.c \
					./sources/change_directory.c \
					./sources/get_env.c \
					./sources/find_var.c \
					./sources/ft_envp_copy.c \
					./sources/manager.c \
					./sources/manager_utils_1.c \
					./sources/manager_utils_2.c \
					./sources/free_fcts.c \
					./sources/number_of_cmds.c \
					./parser/parser.c \
					./parser/tokenizer.c \
					./parser/utils.c \
					./parser/files.c \
					./parser/env_variables.c \
					./signals/signals.c

OBJS			= $(SRCS:.c=.o)

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS) 
				$(CC) $(CFLAGS) -lreadline $(OBJS) -L$(RL_LIB) -o $(NAME) $(LIBFT)

$(LIBFT):		make -C ./sources/libft

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			$(NAME)

bonus:			$(NAME)

.PHONY:			all clean fclean re test
