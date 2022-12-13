/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:48:57 by acaravan          #+#    #+#             */
/*   Updated: 2022/12/02 01:28:51 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	set_directions_1
 *	@discussion	Sets direction and plane of player depending on whether its set as
 *				West, or East.
 *	@param		file	t_file struct containing all necessary data.
 *	@param		save_i	x-position of player in file->map
 *	@param		save_j	y-position of player in file->map
*/
void	set_directions_1(t_file *file, int save_i, int save_j)
{
	if (file->map[save_j][save_i] == 'W')
	{
		file->mlx->player->dir_x = 0;
		file->mlx->player->dir_y = -1;
		file->mlx->player->plane_x = -0.66;
		file->mlx->player->plane_y = 0;
	}
	if (file->map[save_j][save_i] == 'E')
	{
		file->mlx->player->dir_x = 0;
		file->mlx->player->dir_y = 1;
		file->mlx->player->plane_x = 0.66;
		file->mlx->player->plane_y = 0;
	}
}

/*!
 *	@function	set_directions_2
 *	@discussion	Sets direction and plane of player depending on whether its set as
 *				South, or North.
 *	@param		file	t_file struct containing all necessary data.
 *	@param		save_i	x-position of player in file->map
 *	@param		save_j	y-position of player in file->map
*/
void	set_directions_2(t_file *file, int save_i, int save_j)
{
	if (file->map[save_j][save_i] == 'S')
	{
		file->mlx->player->dir_x = 1;
		file->mlx->player->dir_y = 0;
		file->mlx->player->plane_x = 0;
		file->mlx->player->plane_y = -0.66;
	}
	if (file->map[save_j][save_i] == 'N')
	{
		file->mlx->player->dir_x = -1;
		file->mlx->player->dir_y = 0;
		file->mlx->player->plane_x = 0;
		file->mlx->player->plane_y = 0.66;
	}
}

/*!
 *	@function	find_player
 *	@abstract	Draws player (square and direction ray) for minimap into screen.
 *	@param		file	t_file struct containing all necessary data.
 *	@param		i		Auxiliary param to avoid norminette. Used to iterate in
 *						while loop.
 *	@param		j		Auxiliary param to avoid norminette. Used to iterate in
 *						while loop.
 *	@param		save_ij Auxiliary param to avoid norminette. Used to save i and
 *						j variables values to save player's position in map.
*/
void	find_player(t_file *file, int i, int j, int save_ij[2])
{
	file->mlx->player = (t_player *)malloc (sizeof(t_player));
	while (file->map[j])
	{
		i = 0;
		while (file->map[j][i])
		{
			if ((file->map[j][i] == 'N') || (file->map[j][i] == 'S') || \
			(file->map[j][i] == 'E') || (file->map[j][i] == 'W'))
			{
				file->mlx->player->pos_x = i + 0.5;
				file->mlx->player->pos_y = j + 0.5;
				file->mlx->player->pos_xpx = (i * file->tile_size) + \
				(file->tile_size / 2);
				file->mlx->player->pos_ypx = (j * file->tile_size) + \
				(file->tile_size / 2);
				save_ij[0] = i;
				save_ij[1] = j;
			}
			i++;
		}
		j++;
	}
	set_directions_1(file, save_ij[0], save_ij[1]);
	set_directions_2(file, save_ij[0], save_ij[1]);
}
