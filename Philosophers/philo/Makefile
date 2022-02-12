NAME = philo

RESIDUES =	a.out \
			philo.dSYM \
			./sources/*.o \

SRCS =	main.c \
		./sources/init_var.c \
		./sources/ft_atoi.c \
		./sources/ft_calloc.c \
		./sources/freeandreturn.c \
		./sources/elapsed_time.c \
		./sources/philosopher.c \
		./sources/mysleep.c \
		./sources/activities/may_die.c \
		./sources/activities/waiting_to_eat.c \
		./sources/activities/eating.c \
		./sources/activities/sleeping_and_thinking.c \

FLAGS = -Wall -Wextra -Werror -pthread

OBJS = $(SRCS:.c=.o)

CC = gcc -g

%.o: %.c
	$(CC) $(FLAGS) -g -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -Iincludes -o $(NAME)

all: $(NAME)

clean:
	@rm -rf *.o
	@rm -rf ./sources/ft/*.o
	@rm -rf ./sources/activities/*.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME) $(RESIDUES)

re: fclean all