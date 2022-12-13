/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:14:13 by acaravan          #+#    #+#             */
/*   Updated: 2022/12/10 16:35:13 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	draw_buffer
 *	@discussion	Iterates through the file->buffer matrix and puts into screen
 *				each individual element (pixel).
 *	@param		file	t_file struct containing all necessary data.
 *	@param		screen	t_data struct which will be later put into window.
*/
void	draw_buffer(t_file *file, t_data *screen)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_mlx_pixel_put(screen, j, i, file->buffer[i][j]);
			j++;
		}
		i++;
	}
}

/*!
 *	@function	draw_floor_square
 *	@abstract	Draws a single tile (floor square) for the minimap into screen.
 *	@param		tile_size	Size in px of each tile.
 *	@param		posxy		Position in x and y for the tile to be placed.
 *	@param		screen		t_data struct which will be later put into
 *							window.
 *	@param		color		Color of the tile to be drawn.
*/
void	draw_floor_square(int tile_size, int posxy[2], t_data *screen, \
int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tile_size)
	{
		j = 0;
		while (j < tile_size)
		{
			my_mlx_pixel_put(screen, posxy[0] + i, posxy[1] + j, color);
			j++;
		}
		i++;
	}
}

/*!
 *	@function	draw_minimap
 *	@abstract	Draws the entire minimap (without player) into screen.
 *	@param		file	t_file struct containing all necessary data.
 *	@param		screen	screen	t_data struct which will be later put into
 *						window.
*/
void	draw_minimap(t_file *file, t_data *screen)
{
	int	i;
	int	j;
	int	posxy[2];

	i = 0;
	j = 0;
	while (file->map[j])
	{
		i = 0;
		while (file->map[j][i])
		{
			posxy[0] = (i * file->tile_size) + WIDTH - \
			(file->width * file->tile_size);
			posxy[1] = j * file->tile_size;
			if (file->map[j][i] == '1')
				draw_floor_square(file->tile_size, posxy, screen, \
				(file->floor >> 1) & 8355711);
			else if ((file->map[j][i] == '0') || (file->map[j][i] == 'N') || \
			(file->map[j][i] == 'S') || (file->map[j][i] == 'E') || \
			(file->map[j][i] == 'W'))
				draw_floor_square(file->tile_size, posxy, screen, file->floor);
			i++;
		}
		j++;
	}
}

/*!
 *	@function	draw_square
 *	@abstract	Draws a single red square (player) for the minimap into screen.
 *	@param		screen	screen	t_data struct which will be later put into
 *						window.
 *	@param		posx	X-position in which to draw the square.
 *	@param		posy	Y-position in which to draw the square.
*/
void	draw_square(t_data *screen, double posx, double posy, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			if ((posx + j < WIDTH) && (posy + i > 0))
				my_mlx_pixel_put(screen, posx + j, posy + i, color);
			j++;
		}
		i++;
	}
}

/*!
 *	@function	draw_player
 *	@abstract	Draws player (square and direction ray) for minimap into screen.
 *	@param		file	t_file struct containing all necessary data.
 *	@param		screen	t_data struct which will be later put into window.
*/
void	draw_player(t_file *file, t_data *screen)
{
	double	posx;
	double	posy;
	double	k;

	posx = file->mlx->player->pos_xpx - 2 + WIDTH - \
	(file->width * file->tile_size);
	posy = file->mlx->player->pos_ypx - 2;
	draw_square(screen, posx, posy, (file->floor >> 1) & 8355711);
	k = 0;
	while (k < 15)
	{
		if ((posy + (k * file->mlx->player->dir_x) + 2 > 0)
			&& (posx + (k * file->mlx->player->dir_y) + 2 <= WIDTH))
			my_mlx_pixel_put(screen, posx + (k * file->mlx->player->dir_y) + 2, \
			posy + (k * file->mlx->player->dir_x) + 2, \
			(file->floor >> 1) & 8355711);
		k++;
	}
}
