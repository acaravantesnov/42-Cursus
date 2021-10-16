NAME = so_long

RESIDUES =	.vscode \
			a.out.dSYM \
			a.out \
			./includes/so_long.h.gch \
			./includes/get_next_line.h.gch \
			./includes/libft.h.gch \
			./sources/*.o \
			so_long.dSYM \

SRCS =		so_long_bonus.c \
			./sources/check_map.c \
			./sources/check_map2.c \
			./sources/my_mlx_pixel_put.c \
			./sources/my_ft_strcmp.c \
			./sources/my_ft_strchr.c \
			./sources/check_args.c \
			./sources/file_descriptor.c \
			./sources/save_map.c \
			./sources/map_size.c \
			./sources/make2dmap.c \
			./sources/print2dmap.c \
			./sources/initialization.c \
			./sources/putcharacter.c \
			./sources/close_window.c \
			./sources/putwalls.c \
			./sources/putvexit.c \
			./sources/putcollec.c \
			./sources/key_hook.c \

LIB = ./sources/get_next_line/get_next_line.c ./sources/libft/*.c

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

CC = gcc -g

BUFFER = -D BUFFER_SIZE=1

%.o: %.c
	$(CC) $(FLAGS) $(BUFFER) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(BUFFER) $(SRCS) $(LIB) -Iincludes -Lmlx -lmlx -framework OpenGL -framework AppKit -lz -o $(NAME)

all: $(NAME)

clean:
	@rm -rf *.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME) $(RESIDUES)

re: fclean all

debug: $(OBJS)
	$(CC) $(BUFFER) $(SRCS) $(LIB) -fsanitize=address -Iincludes -Lmlx -lmlx -framework OpenGL -framework AppKit -lz -o $(NAME)

bonus: $(NAME)
