/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:32:51 by acaravan          #+#    #+#             */
/*   Updated: 2022/12/10 12:09:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	set_floor_sky_and_vars
 *	@discussion	Gives values to buffer pixels in order to set floor and sky.
 *				It also initializes i, j and x variables to zero.
 *	@param		file	t_file struct containing all necessary data.
 *	@param		cast	t_cast struct containing most variables used in cast
 *						function.
*/
void	set_floor_sky_and_vars(t_file *file, t_cast *cast)
{
	cast->i = 0;
	cast->j = 0;
	while (cast->i < HEIGHT)
	{
		cast->j = 0;
		while (cast->j < WIDTH)
		{
			if (cast->i < HEIGHT / 2)
				file->buffer[cast->i][cast->j] = file->sky;
			else
				file->buffer[cast->i][cast->j] = file->floor;
			(cast->j)++;
		}
		(cast->i)++;
	}
	cast->i = 0;
	cast->j = 0;
	cast->x = 0;
}

/*!
 *	@function	ray_initial_pos_and_dir
 *	@discussion	Sets camera_x value. Goes from -1 (left edge of the window) to
 *				+1 (right edge of the window), 0 for the center.
 *				It also sets x and y ray directions, and actual position of the
 *				ray to be evaluated.
 *	@param		file	t_file struct containing all necessary data.
 *	@param		cast	t_cast struct containing most variables used in cast
 *						function.
*/
void	ray_initial_pos_and_dir(t_file *file, t_cast *cast)
{
	cast->camera_x = 2 * cast->x / (double)WIDTH - 1;
	cast->raydir_xy[1] = file->mlx->player->dir_x + file->mlx->player->plane_x \
	* cast->camera_x;
	cast->raydir_xy[0] = file->mlx->player->dir_y + file->mlx->player->plane_y \
	* cast->camera_x;
	cast->map_xy[0] = (int)file->mlx->player->pos_x;
	cast->map_xy[1] = (int)file->mlx->player->pos_y;
}

/*!
 *	@function	ray_deltadist
 *	@discussion	Sets deltadist x and y values.
 *				Deltadist is set to INT32_MAX value if raydir is 0. Dividing by
 *				0 is technically infinity, and it would not be able to be
 *				computed. That is why deltadist is assigned the highest value
 *				possible.
 *	@param		cast	t_cast struct containing most variables used in cast
 *						function.
*/
void	ray_deltadist(t_cast *cast)
{
	cast->deltadist_xy[0] = fabs(1 / cast->raydir_xy[0]);
	cast->deltadist_xy[1] = fabs(1 / cast->raydir_xy[1]);
}

/*!
 *	@function	ray_step_and_initial_sidedist
 *	@discussion	Depending on the direction of the ray, the step in x and
 *				y-directions are +1 or -1. It also sets the sidedist.
 *	@param		cast	t_cast struct cointaining most variables used in the
 *						raycaster.
 *	@param		file	t_file struct containing all necessary data.
*/
void	ray_step_and_initial_sidedist(t_cast *cast, t_file *file)
{
	if (cast->raydir_xy[0] < 0)
	{
		cast->step_xy[0] = -1;
		cast->sidedist_xy[0] = (file->mlx->player->pos_x - cast->map_xy[0]) * \
		(cast->deltadist_xy[0]);
	}
	else
	{
		cast->step_xy[0] = 1;
		cast->sidedist_xy[0] = (cast->map_xy[0] + 1 - \
		file->mlx->player->pos_x) * (cast->deltadist_xy[0]);
	}
	if (cast->raydir_xy[1] < 0)
	{
		cast->step_xy[1] = -1;
		cast->sidedist_xy[1] = (file->mlx->player->pos_y - \
		cast->map_xy[1]) * (cast->deltadist_xy[1]);
	}
	else
	{
		cast->step_xy[1] = 1;
		cast->sidedist_xy[1] = (cast->map_xy[1] + 1 - \
		file->mlx->player->pos_y) * (cast->deltadist_xy[1]);
	}
}

/*!
 *	@function	dda_algorithm
 *	@discussion	DDA stands for Digital Differential Analyzer.
 *				Loop that increments the ray 1 tile at a time, until a wall is
 *				hit. It jumps a tile in the x or y direction (through step_xy[0]
 *				or step_xy[1]).
 *				Sidedist gets incremented with deltadist and map_xy[0] or [1]
 *				gets incremented with step_xy[0] or [1] respectively.
 *				Once the wall is hit, the loop ends (hit is set to 1), and the
 *				last saved value in side will represent the orientation of the
 *				wall which was hit (N, S, E or W).
 *	@param		cast	t_cast struct cointaining most variables used in the
 *						raycaster.
 *	@param		file	t_file struct containing all necessary data.
 *	@param		hit		Was the wall hit? (hit == 1) Or not? (hit == 0).
 *	@param		side	side == 1	--> W	side == 2	--> E
 *						side == 3	--> N	side == 4	--> S
 *	@return		Side value to be saved in cast.side.
*/
int	dda_algorithm(t_cast *cast, t_file *file, int hit, int side)
{
	while (hit == 0)
	{
		if (cast->sidedist_xy[0] < cast->sidedist_xy[1])
		{
			cast->sidedist_xy[0] += cast->deltadist_xy[0];
			cast->map_xy[0] += cast->step_xy[0];
			side = 2;
			if (cast->map_xy[0] < file->mlx->player->pos_x)
				side = 1;
		}
		else
		{
			cast->sidedist_xy[1] += cast->deltadist_xy[1];
			cast->map_xy[1] += cast->step_xy[1];
			side = 4;
			if (cast->map_xy[1] > file->mlx->player->pos_y)
				side = 3;
		}
		if ((cast->map_xy[0] < 0) || (cast->map_xy[0] >= (file->width)) || \
		(cast->map_xy[1] < 0) || (cast->map_xy[1] >= (file->height)))
			break ;
		if (file->map[(int)cast->map_xy[1]][(int)cast->map_xy[0]] == '1')
			hit = 1;
	}
	return (side);
}
