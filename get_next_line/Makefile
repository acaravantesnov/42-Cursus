NAME =	get_next_line.a
SRCS =	get_next_line.c \
		get_next_line_utils.c \

FLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)
CC = gcc
RM = rm -f
NORME = norminette -R CheckForbiddenSourceHeader $(SRCS)

.c.o:
	$(CC) $(FLAGS) -D BUFFER_SIZE=1 -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) a.out

fclean: clean
	$(RM) $(NAME)

re: fclean all

norma: $(NORME)