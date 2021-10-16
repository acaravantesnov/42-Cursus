/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 23:10:23 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 04:41:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PS 32

# include "./get_next_line.h"
# include "./libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int			g_ncollec;
int			g_n1;
int			g_collected;
int			g_nmov;
int			g_exit_;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct sprites {
	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_sprite;
t_sprite	g_wall;
t_sprite	g_cdown;
t_sprite	g_collec;
t_sprite	g_vexit;
t_sprite	g_cleft;
t_sprite	g_cright;
t_sprite	g_cup;

struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
}	mlx;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

struct s_map
{
	int	x_size;
	int	y_size;
	int	p_x;
	int	p_y;
}	m;

struct s_pos
{
	int	x;
	int	y;
}	one[1000], collecc[1000], E[1];

int			check_map(char **map);
void		check_map2(int nExit, int nPosInic);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			my_ft_strcmp(char *s1, char *s2);
char		*my_ft_strchr(char *s, int c);
int			check_args(int argc, char **argv);
int			file_descriptor(char **argv);
char		*save_map(int fd);
int			map_size(char *map);
char		**make2dmap(char *map);
void		print2dmap(char **map_2d);
void		initialization(t_data *floor);
void		putcharacter(t_sprite	*g_cdown, char **map_2d);
void		putwalls(t_sprite	*g_wall, char **map_2d);
int			putcollec(t_sprite *g_collec, char **map_2d);
void		putvexit(t_sprite *g_vexit, char **map_2d);
int			close_window(int keycode);
void		caracterleft(t_sprite	*g_cleft, int x, int y);
void		caracterright(t_sprite	*g_cright, int x, int y);
void		caracterdown(t_sprite	*g_cdown, int x, int y);
void		caracterup(t_sprite	*g_cup, int x, int y);
int			key_hook(int keycode);

#endif
