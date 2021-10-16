NAME = a.out

SRCS =		main.cpp \
			Zombie.cpp \
			newZombie.cpp \
			randomChump.cpp \

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)

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