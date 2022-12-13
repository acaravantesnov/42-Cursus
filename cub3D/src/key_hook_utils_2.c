/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:02:32 by acaravan          #+#    #+#             */
/*   Updated: 2022/12/10 16:33:43 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	rotate_90_ccw
 *	@discussion	Saves initial x-direction, and changes direction based on it
 *				(rotates 90 degrees (PI/2 rad) counterclockwise).
 *				Does the same with previous and new plane.
 *	@param		file		t_file struct containing all necessary data.
 *	@param		olddirx		Old x-direction.
 *	@param		oldplanex	Old x-plane.
*/
void	rotate_90_ccw(t_file *file, double *olddirx, double *oldplanex)
{
	*olddirx = file->mlx->player->dir_x;
	file->mlx->player->dir_x = file->mlx->player->dir_x * cos(-PI / 8) - \
	file->mlx->player->dir_y * sin(-PI / 8);
	file->mlx->player->dir_y = *olddirx * sin(-PI / 8) + \
	file->mlx->player->dir_y * cos(-PI / 8);
	*oldplanex = file->mlx->player->plane_x;
	file->mlx->player->plane_x = file->mlx->player->plane_x * cos(-PI / 8) \
	- file->mlx->player->plane_y * sin(-PI / 8);
	file->mlx->player->plane_y = *oldplanex * sin(-PI / 8) \
	+ file->mlx->player->plane_y * cos(-PI / 8);
}

/*!
 *	@function	rotate_90_cw
 *	@discussion	Saves initial x-direction, and changes direction based on it
 *				(rotates 90 degrees (PI/2 rad) clockwise).
 *				Does the same with previous and new plane.
 *	@param		file		t_file struct containing all necessary data.
 *	@param		olddirx		Old x-direction.
 *	@param		oldplanex	Old x-plane.
*/
void	rotate_90_cw(t_file *file, double *olddirx, double *oldplanex)
{
	*olddirx = file->mlx->player->dir_x;
	file->mlx->player->dir_x = file->mlx->player->dir_x * cos(PI / 8) - \
	file->mlx->player->dir_y * sin(PI / 8);
	file->mlx->player->dir_y = *olddirx * sin(PI / 8) + \
	file->mlx->player->dir_y * cos(PI / 8);
	*oldplanex = file->mlx->player->plane_x;
	file->mlx->player->plane_x = file->mlx->player->plane_x * cos(PI / 8) \
	- file->mlx->player->plane_y * sin(PI / 8);
	file->mlx->player->plane_y = *oldplanex * sin(PI / 8) \
	+ file->mlx->player->plane_y * cos(PI / 8);
}
