NAME = pipex

SRCS =		main.c \
			./sources/ft_split.c \
			./sources/check_args.c \
			./sources/execcmd.c \
			./sources/exitwitherror.c \
			./sources/find_path.c \
			./sources/ft_freestr.c \
			./sources/ft_putstr_fd.c \
			./sources/ft_strjoin.c \
			./sources/ft_strlen.c \
			./sources/ft_strnstr.c \

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

CC = gcc

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(BUFFER) $(SRCS) -Iincludes -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "Cleaning .o files"

fclean: clean
	@rm -rf $(NAME)
	@echo "Cleaning residues"

re: fclean all

bonus: $(NAME)