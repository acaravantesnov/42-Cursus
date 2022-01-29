NAME = philo

RESIDUES =	a.out \
			philo.dSYM \
			./sources/*.o \

SRCS =	main.c \
		./sources/ft_atoi.c \

LIB = ./sources/ft_printf/*.c

FLAGS = -Wall -Wextra -Werror -pthread

OBJS = $(SRCS:.c=.o)

CC = gcc -g

%.o: %.c
	$(CC) $(FLAGS) -g -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) $(LIB) -Iincludes -o $(NAME)

all: $(NAME)

clean:
	@rm -rf *.o
	@rm -rf ./sources/ft/*.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME) $(RESIDUES)

re: fclean all
