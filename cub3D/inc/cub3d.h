/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:39:54 by airodrig          #+#    #+#             */
/*   Updated: 2022/12/10 18:30:44 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <sys/time.h>
# include <math.h>
# include <stdbool.h>

# if defined(__APPLE__)
#  include "keycodes_mac.h"
# else
#  include "key_linux.h"
# endif

/*! @define	WIDTH 	Screen width (in pixels) */
# define WIDTH 1200

/*! @define	HEIGHT	Screen height (in pixels) */
# define HEIGHT 800

/*! @define	TEXTURE_WIDTH	Texture width (in pixels) */
# define TEXTURE_WIDTH 64

/*! @define TEXTURE_HEIGHT	Texture height (in pixels) */
# define TEXTURE_HEIGHT 64

/*! @define SPEED	Speed factor for forward and backward movement of player. */
# define SPEED 2

/*!
 *	@define ROTSPEED	Rotation Speed factor for right and left rotation of
 *						player.
*/
# define ROTSPEED 0.05

/*! @define PI	Value of PI constant. Used for rotation in radians. */
# define PI 3.14159265358979323

enum e_valid {
	C_VOID = '0',
	C_WALL = '1',
	C_NORTH = 'N',
	C_SOUTH = 'S',
	C_EAST = 'E',
	C_WEST = 'W',
	C_RANDOM = ' ',
	C_CHECK = 'x'
};

enum e_textures{
	T_NORTH,
	T_SOUTH,
	T_EAST,
	T_WEST,
	T_FLOOR,
	T_CEILING
};

/*!
 * @typedef		t_data
 *				Data necessary for putting an image into screen.
 * @field		img				Image instance.
 * @field		addr			Data address of the current image.
 * @field		img_width		Width of the image to be created.
 * @field		img_height		Height of the image to be created.
 * @field		bits_per_pixel	Pointer to where the bpp is written.
 * @field		line_length		Pointer to where the line is written.
 * @field		endian			Pointer to where the endian is written.
*/
typedef struct s_data {
	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/*!
 * @typedef		t_texture
 *				Data for each texture.
 * @field		place	0-North, 1-South, 2-East, 3-West, 4-Floor, 5-Sky
 * @field		path	Relative path to the xpm texture file.
 * @field		color	Color in hex
 * @field		data	t_data struct containing all necessary data for drawing
 *						the texture.
 * @field		next	Pointer to next texture.
*/
typedef struct s_textures
{
	int					place;
	char				*path;
	int					color;
	t_data				data;
	struct s_textures	*next;
}	t_texture;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

/*!
 * @typedef		t_player
 *				Data for player.
 * @field		pos_x	Current x-position of player in file->map.
 * @field		pos_y	Current y-position of player in file->map.
 * @field		pos_xpx	Current x-position of player in pixels.
 * @field		pos_ypx	Current y-position of player in pixels.
 * @field		dir_x	Current x-direction of player.
 * @field		dir_y	Current y-direction of player.
 * @field		plane_x	Current x-coordinate of view plane of player.
 * @field		plane_y	Current y-coordinate of view plane of player.
*/
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	pos_xpx;
	double	pos_ypx;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

/*!
 * @typedef		t_mlx
 *				Minilibx data.
 * @field		mlx		Mlx instance.
 * @field		mlx_win	Window instance.
 * @field		player	Pointer to a t_player.
*/
typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_player	*player;
}	t_mlx;

typedef struct s_tex
{
	int		width;
	int		height;
	int		*addr;
}	t_tex;

/*!
 * @typedef		t_file
 *				Most variables apart from the used in Raycasting.
 * @field		width		Width of screen.
 * @field		height		Height of screen.
 * @field		player_pos	Vector of current player position.
 * @field		player_dir	Vector of current player direction.
 * @field		map			Character matrix of map saved from .cub file.
 * @field		tile_size	Size in pixels of each tile (square).
 * @field		textures	List of textures.
 * @field		buffer		Matrix of the whole screen to be rendered.
 * 							Each element in the matrix represents each pixel in
 * 							the screen.
 * 							Therefore, it has a size of HEIGHT x WIDTH
 * @field		mlx			Pointer to t_mlx struct.
 * @field		n			Array of integer values (colors in hex) of all the
 * 							pixels in the North texture.
 * @field		s			Array of integer values (colors in hex) of all the
 * 							pixels in the South texture.
 * @field		e			Array of integer values (colors in hex) of all the
 * 							pixels in the East texture.
 * @field		w			Array of integer values (colors in hex) of all the
 * 							pixels in the West texture.
 * @field		sky			Color in hex of sky.
 * @field		floor		Color in hex of floor.
*/
typedef struct s_file
{
	int			width;
	int			height;
	t_vector	player_pos;
	t_vector	player_dir;
	char		**map;
	int			tile_size;
	t_texture	*textures;
	int			**buffer;
	t_mlx		*mlx;
	t_tex		n;
	t_tex		s;
	t_tex		e;
	t_tex		w;
	int			sky;
	int			floor;
}	t_file;

/*!
 * @typedef		t_cast
 *				Most variables used in Raycasting.
 * @field		x				Used for iterating for every x-coordinate of the
 * 								window.
 * @field		i				Aux variable for iterations.
 * @field		j				Aux variable for iterations.
 * @field		perpwalldist	Perpendicular distance to the wall.
 * @field		camera_x		x-coordinate of camera.
 * @field		raydir_xy		Direction coordinates of the ray.
 * @field		map_xy			Tile in the map the ray is being checked.
 * @field		sidedist_xy		Length of ray from curretn position to next x or
 * 								y side.
 * @field		deltadist_xy	Length of ray from one x or y side to next x or
 * 								y side.
 * @field		step_xy			Direction in which to step in. +1 or -1.
 * @field		side			side == 1	--> W	side == 2	--> E
 *								side == 3	--> N	side == 4	--> S
 * @field		line_height		Height of single vertical line for a single ray.
 * @field		color			Used to save color to be put to screen.
 * @field		draw_start		y-coordinate (top of window being 0, bottom
 * 								being HEIGHT) of the top part of the single line
 * 								to be drawn.
 * @field		draw_end		y-coordinate (top of window being 0, bottom
 * 								being HEIGHT) of the bottom part of the single
 * 								line to be drawn.
 * @field		wall_x			Where exactly the wall was hit.
 * @field		tex_x			x-coordinate in texture.
 * @field		step			Amount to increase in tex_x per window px (x).
 * @field		tex_pos			Used to iterate through the vertical stripe.
 * @field		y				Aux variable to iterate vertically through all
 * 								pixels in a single vertical stripe.
 * @field		tex_y			Used to iterate through the vertical stripe.
*/
typedef struct s_cast
{
	int		x;
	int		i;
	int		j;
	double	perpwalldist;
	double	camera_x;
	double	raydir_xy[2];
	double	map_xy[2];
	double	sidedist_xy[2];
	double	deltadist_xy[2];
	int		step_xy[2];
	int		side;
	double	line_height;
	int		color;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;
}	t_cast;

////////////////////////////////////////////////////////////////////////////////
// General
////////////////////////////////////////////////////////////////////////////////
void		create_file_data_struct(t_file *file);
int			calc_tile_size(t_file *file);
int			close_window(int keycode, t_file *file);
void		find_player(t_file *file, int i, int j, int save_ij[2]);
int			close_window(int keycode, t_file *file);
void		parse_textures(t_texture *textures);
void		intro(t_file *file);
int			quit_intro_hook(int keycode, t_file *file);
void		prepare_textures(t_file *file);
void		build_buffer(t_file *file);
void		set_screen(t_file *file, t_data *screen);

////////////////////////////////////////////////////////////////////////////////
// Movement
////////////////////////////////////////////////////////////////////////////////
int			key_hook(int keycode, t_file *file);
void		rotate_left(t_file *file, double *olddirx, double *oldplanex);
void		rotate_right(t_file *file, double *olddirx, double *oldplanex);
void		move_forward(t_file *file, double xy[2]);
void		move_backward(t_file *file, double xy[2]);
void		rotate_90_ccw(t_file *file, double *olddirx, double *oldplanex);
void		rotate_90_cw(t_file *file, double *olddirx, double *oldplanex);

////////////////////////////////////////////////////////////////////////////////
// RayCasting
////////////////////////////////////////////////////////////////////////////////
void		cast_rays(t_file *file);
void		set_floor_sky_and_vars(t_file *file, t_cast *cast);
void		ray_deltadist(t_cast *cast);
void		ray_initial_pos_and_dir(t_file *file, t_cast *cast);
void		ray_step_and_initial_sidedist(t_cast *cast, t_file *file);
int			dda_algorithm(t_cast *cast, t_file *file, int hit, int side);
void		calc_draw_start_draw_end(t_cast *cast);
void		calc_tex_x(t_file *file, t_cast *cast);
void		color_assignment(t_file *file, t_cast *cast);
void		save_vline_into_buffer(t_file *file, t_cast *cast);
void		savedir_xy_and_perpwalldist(t_cast *cast);

////////////////////////////////////////////////////////////////////////////////
// Drawing pixels
////////////////////////////////////////////////////////////////////////////////
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw(t_file *file, t_data *screen);
void		draw_buffer(t_file *file, t_data *screen);
void		draw_minimap(t_file *file, t_data *map_data);
void		draw_player(t_file *file, t_data *screen);

////////////////////////////////////////////////////////////////////////////////
// Lists
////////////////////////////////////////////////////////////////////////////////
t_texture	*ft_newel(int place, int color, char *path);
void		ft_lstaddback_check(t_texture **list, t_texture *newel);
void		free_file(t_file *lst);

////////////////////////////////////////////////////////////////////////////////
// Parser
////////////////////////////////////////////////////////////////////////////////
void		initial_input_checking(int argc, const char **argv, int *map_fd);
bool		check_name(const char *filename, const char *ext);
void		get_texture(char *line, t_texture **list, t_file *file);
void		parse_file(int map_fd, t_file *file);
int			getsize(char **ptr);
int			atoi_cub(const char *str);
int			getrgb(int r, int g, int b);
void		check_textures(t_texture *textures);
bool		is_map(char *line);
bool		is_spawn(char c);
void		check_map(t_file *file);
void		check_walls(t_file file);
void		parse_map(char **line, int map_fd, t_file *file);

////////////////////////////////////////////////////////////////////////////////
// Print
////////////////////////////////////////////////////////////////////////////////
void		print_error(char *str, bool print_usage);
void		print_textures(t_texture *list);
const char	*print_place(int place);
void		print_map(char **map);

#endif
