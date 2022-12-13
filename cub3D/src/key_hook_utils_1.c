/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:51:54 by acaravan          #+#    #+#             */
/*   Updated: 2022/12/10 14:46:51 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	set_screen
 *	@abstract	Creates img and address pointers.
 *	@param		file	t_file struct containing all necessary data.
 *	@param		screen	t_data struct which will be later put into window.
*/
void	set_screen(t_file *file, t_data *screen)
{
	screen->img = mlx_new_image(file->mlx->mlx, WIDTH, HEIGHT);
	screen->addr = mlx_get_data_addr(screen->img, &(screen->bits_per_pixel), \
	&(screen->line_length), &(screen->endian));
}

/*!
 *	@function	rotate_left
 *	@discussion	Saves initial x-direction, and changes direction based on it
 *				(rotates to the left).
 *				Does the same with previous and new plane.
 *	@param		file		t_file struct containing all necessary data.
 *	@param		olddirx		Old x-direction.
 *	@param		oldplanex	Old x-plane.
*/
void	rotate_left(t_file *file, double *olddirx, double *oldplanex)
{
	*olddirx = file->mlx->player->dir_x;
	file->mlx->player->dir_x = file->mlx->player->dir_x * cos(ROTSPEED) - \
	file->mlx->player->dir_y * sin(ROTSPEED);
	file->mlx->player->dir_y = *olddirx * sin(ROTSPEED) + \
	file->mlx->player->dir_y * cos(ROTSPEED);
	*oldplanex = file->mlx->player->plane_x;
	file->mlx->player->plane_x = file->mlx->player->plane_x * cos(ROTSPEED) \
	- file->mlx->player->plane_y * sin(ROTSPEED);
	file->mlx->player->plane_y = *oldplanex * sin(ROTSPEED) \
	+ file->mlx->player->plane_y * cos(ROTSPEED);
}

/*!
 *	@function	rotate_right
 *	@discussion	Saves initial x-direction, and changes direction based on it
 *				(rotates to the right).
 *				Does the same with previous and new plane.
 *	@param		file		t_file struct containing all necessary data.
 *	@param		olddirx		Old x-direction.
 *	@param		oldplanex	Old x-plane.
*/
void	rotate_right(t_file *file, double *olddirx, double *oldplanex)
{
	*olddirx = file->mlx->player->dir_x;
	file->mlx->player->dir_x = file->mlx->player->dir_x * cos(-ROTSPEED) - \
	file->mlx->player->dir_y * sin(-ROTSPEED);
	file->mlx->player->dir_y = *olddirx * sin(-ROTSPEED) + \
	file->mlx->player->dir_y * cos(-ROTSPEED);
	*oldplanex = file->mlx->player->plane_x;
	file->mlx->player->plane_x = file->mlx->player->plane_x * cos(-ROTSPEED) \
	- file->mlx->player->plane_y * sin(-ROTSPEED);
	file->mlx->player->plane_y = *oldplanex * sin(-ROTSPEED) \
	+ file->mlx->player->plane_y * cos(-ROTSPEED);
}

/*!
 *	@function	move_forward
 *	@discussion	Saves in xy the possible new values for player pposition.
 *				It checks this new position in the map matrix, and if it is not
 *				a wall, it will change the players position (in pixels and map).
 *	@param		file	t_file struct containing all necessary data.
 *	@param		xy		x and y new viable positions.
*/
void	move_forward(t_file *file, double xy[2])
{
	xy[0] = file->mlx->player->pos_x + 1 * file->mlx->player->dir_y;
	xy[1] = file->mlx->player->pos_y + 1 * file->mlx->player->dir_x;
	if ((xy[0] >= 0) && (xy[0] < file->width) && (xy[1] >= 0) && \
	(xy[1] < file->height))
	{
		if (file->map[(int)(xy[1])][(int)(xy[0])] != '1')
		{
			file->mlx->player->pos_ypx += \
			file->mlx->player->dir_x * SPEED;
			file->mlx->player->pos_y += \
			(file->mlx->player->dir_x * SPEED) / file->tile_size;
			file->mlx->player->pos_xpx += \
			file->mlx->player->dir_y * SPEED;
			file->mlx->player->pos_x += \
			(file->mlx->player->dir_y * SPEED) / file->tile_size;
		}
	}
}

/*!
 *	@function	move_forward
 *	@discussion	Saves in xy the possible new values for player pposition.
 *				It checks this new position in the map matrix, and if it is not
 *				a wall, it will change the players position (in pixels and map).
 *	@param		file	t_file struct containing all necessary data.
 *	@param		xy		x and y new viable positions.
*/
void	move_backward(t_file *file, double xy[2])
{
	xy[0] = file->mlx->player->pos_x - 1 * file->mlx->player->dir_y;
	xy[1] = file->mlx->player->pos_y - 1 * file->mlx->player->dir_x;
	if ((xy[0] >= 0) && (xy[0] < file->width) && (xy[1] >= 0) && \
	(xy[1] < file->height))
	{
		if (file->map[(int)(xy[1])][(int)(xy[0])] != '1')
		{
			file->mlx->player->pos_ypx -= \
			file->mlx->player->dir_x * SPEED;
			file->mlx->player->pos_y -= \
			(file->mlx->player->dir_x * SPEED) / file->tile_size;
			file->mlx->player->pos_xpx -= \
			file->mlx->player->dir_y * SPEED;
			file->mlx->player->pos_x -= \
			(file->mlx->player->dir_y * SPEED) / file->tile_size;
		}
	}
}
