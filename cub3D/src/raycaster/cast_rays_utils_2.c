/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:49:57 by acaravan          #+#    #+#             */
/*   Updated: 2022/12/10 18:30:21 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	calc_draw_start_draw_end
 *	@discussion	perpwalldist is set based on the last sidedist which was
 *				incremented by deltadist. Thats why by substracting deltadist,
 *				the actual length of the ray is obtained.
 *				Perpendicular distance is taken instead of Euclidean distance in
 *				order to avoid fisheye effect.
 *				Once value of perpwalldist is set, the actual length of the
 *				vertical stripe is set, and drawstart and drawend are also set.
 *	@param		cast	t_cast struct cointaining most variables used in the
 *						raycaster.
*/
void	calc_draw_start_draw_end(t_cast *cast)
{
	if ((cast->side == 1) || (cast->side == 2))
		cast->perpwalldist = cast->sidedist_xy[0] - cast->deltadist_xy[0];
	else
		cast->perpwalldist = cast->sidedist_xy[1] - cast->deltadist_xy[1];
	cast->line_height = (HEIGHT / cast->perpwalldist);
	cast->draw_start = (HEIGHT / 2) - (cast->line_height / 2);
	if (cast->draw_start < 0)
		cast->draw_start = 0;
	cast->draw_end = (HEIGHT / 2) + (cast->line_height / 2);
	if (cast->draw_end >= HEIGHT)
		cast->draw_end = HEIGHT;
}

/*!
 *	@function	calc_tex_x
 *	@discussion	For every vertical stripe (one ray), it will be necessary to
 *				iterate through it and save it into the buffer.
 *				For doing so, it is first necessary to know the exact possition
 *				where the wall was hit (wall_x), and look for the position in
 *				the texture to be used for that stripe.
 *	@param		file	t_file struct containing all necessary data.
 *	@param		cast	t_cast struct cointaining most variables used in the
 *						raycaster.
*/
void	calc_tex_x(t_file *file, t_cast *cast)
{
	if ((cast->side == 1) || (cast->side == 2))
		cast->wall_x = file->mlx->player->pos_y + cast->perpwalldist * \
		cast->raydir_xy[1];
	else
		cast->wall_x = file->mlx->player->pos_x + cast->perpwalldist * \
		cast->raydir_xy[0];
	cast->wall_x -= floor(cast->wall_x);
	cast->tex_x = (int)(cast->wall_x * (double)(TEXTURE_WIDTH - 1));
}

/*!
 *	@function	color_assignment
 *	@discussion	To know which color has the pixel to be evaluated, it is
 *				necessary to get it from the integer array saved.
 *	@param		file	t_file struct containing all necessary data.
 *	@param		cast	t_cast struct cointaining most variables used in the
 *						raycaster.
*/
void	color_assignment(t_file *file, t_cast *cast)
{
	if (cast->side == 3)
		cast->color
			= (file->n.addr)[file->n.height * cast->tex_y + cast->tex_x];
	else if (cast->side == 4)
		cast->color
			= (file->s.addr)[file->s.height * cast->tex_y + cast->tex_x];
	else if (cast->side == 2)
		cast->color
			= (file->e.addr)[file->e.height * cast->tex_y + cast->tex_x];
	else if (cast->side == 1)
		cast->color
			= (file->w.addr)[file->w.height * cast->tex_y + cast->tex_x];
	file->buffer[cast->y][cast->x] = cast->color;
}

/*!
 *	@function	save_vline_into_buffer
 *	@discussion	Iterates through the vertical line from draw_start to draw_end,
 *				saving the colors in the buffer.
 *	@param		cast	t_cast struct cointaining most variables used in the
 *						raycaster.
 *	@param		file	t_file struct containing all necessary data.
*/
void	save_vline_into_buffer(t_file *file, t_cast *cast)
{
	cast->y = cast->draw_start;
	while (cast->y < cast->draw_end)
	{
		cast->tex_y = (int)cast->tex_pos & (TEXTURE_HEIGHT - 1);
		cast->tex_pos += cast->step;
		color_assignment(file, cast);
		cast->y++;
	}
}
