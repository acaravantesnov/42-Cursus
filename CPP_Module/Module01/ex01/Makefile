NAME = Moar_brainz!

RESIDUES =	*.dSYM \
			a.out

SRCS =	main.cpp \
		Zombie.cpp \
		ZombieHorde.cpp \

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

OBJS =	$(SRCS:.cpp=.o) \

CC = clang++ -g

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME) $(RESIDUES)

re: fclean all