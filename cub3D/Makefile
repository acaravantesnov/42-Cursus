# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 14:50:36 by airodrig          #+#    #+#              #
#    Updated: 2022/12/10 17:43:48 by airodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

S			=	src/

P			=	parser/

R			=	raycaster/

O			=	obj/

H			=	-I inc/ -I lib/libft/inc -Imlx

LIBS		=	-L lib/libft -lft

PARS_FILES	=	initial_input_checking.c \
				parse_textures.c \
				parse_map.c \
				map_checker.c \
				parse_texture_utils.c \
				parse_map_utils.c \
				parser.c

PARSER		=	$(addprefix $P, $(PARS_FILES))

RAYCASTER_FILES	=	cast_rays.c \
					cast_rays_utils_1.c \
					cast_rays_utils_2.c

RAYCASTER	=	$(addprefix $R, $(RAYCASTER_FILES))

FILES		=	$(PARSER) \
				$(RAYCASTER) \
				print_error.c \
				list_utils.c \
				free_utils.c \
				tester_utils.c \
				calc_tile_size.c \
				draw.c \
				draw_utils.c \
				my_mlx_pixel_put.c \
				key_hook.c \
				key_hook_utils_1.c \
				key_hook_utils_2.c \
				find_player.c \
				intro.c \
				prepare_textures.c \
				create_file_data_struct.c \
				build_buffer.c \
				close_window.c \
				main.c

SRCS		=	$(addprefix $S, $(FILES))

OBJS		=	$(SRCS:$S%.c=$O%.o)

CC			=	gcc

RM			=	rm -rf

CFLAGS		=	-Wall -Werror -Wextra -g3 #-fsanitize=address -o3

UNAME		=	$(shell uname -s)
ifeq ($(UNAME),Linux)
	H += -I lib/mlx_linux
	LIBS += -L lib/mlx_linux -l mlx -lXext -lX11 -lm -lz -D LINUX_KEYS
endif
ifeq ($(UNAME),Darwin)
	H += -I lib/mlx_mac
	LIBS += -L lib/mlx_mac -l mlx -framework OpenGL -framework AppKit -D \
	MAC_KEYS
endif

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
	@printf "\r$(GRN) cub3D compiled                                                \
	                                                            $(NOCOL)\n"
	@printf "\t$(PUR)- All libft objs done$(NOCOL)\n"
	@printf "\t$(BLU)- All cub3D objs done$(NOCOL)\n"
	@printf "\t\t$(YEL)- cub3D up todate and ready to run$(NOCOL)\n"

$O%.o: $S%.c
	@[ -d $O ] || mkdir $O
	@[ -d $O$P ] || mkdir $O$P
	@[ -d $O$R ] || mkdir $O$R
	@printf "$(BLU)#$(NOCOL)"
	@$(CC) $(CFLAGS) $H -c $< -o $@

$(NAME): $(OBJS)
	@make -s -C lib/libft
	@$(CC) $(CFLAGS) $H $(SRCS) $(LIBS) -o $(NAME)
	@[ -e $(NAME) ]

bonus: all

clean:
	@make clean -s -C lib/libft
	@${RM} $O

fclean: clean
	@rm -f lib/libft/libft.a > /dev/null
	@${RM} ${NAME}
	@echo "$(CYN) 🧼🧼🧼 All clean! 🧼🧼🧼 $(NOCOL)"

re: fclean all

normi:
	@echo "$(PUR) 🔍🔍 Checking Norminette 🔎🔎$(NOCOL)"
	@norminette $S

.PHONY: all clean fclean re normi bonus
