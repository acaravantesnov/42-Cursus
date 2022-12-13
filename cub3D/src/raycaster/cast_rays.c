/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:57:06 by acaravan          #+#    #+#             */
/*   Updated: 2022/12/09 23:18:48 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	cast_rays
 *	@discussion	First of all, it saves the floor and sky into the buffer.
 *				Then, for every x-coordinate in the window, it will cast the
 *				corresponding ray, calculate its perpendicular distance from the
 *				camera plane to the hit point throught the use of an algorithm,
 *				and calculate the length of the vertical stripe to be drawn for
 *				that ray.
 *				For that stripe, it will iterate through the texture in the
 *				y-direction and save the corresponding colors into the buffer.
 *	@param		file	t_file struct containing all necessary data.
*/
void	cast_rays(t_file *file)
{
	t_cast	cast;

	set_floor_sky_and_vars(file, &cast);
	while (cast.x < WIDTH)
	{
		ray_initial_pos_and_dir(file, &cast);
		ray_deltadist(&cast);
		ray_step_and_initial_sidedist(&cast, file);
		cast.side = dda_algorithm(&cast, file, 0, 0);
		calc_draw_start_draw_end(&cast);
		calc_tex_x(file, &cast);
		cast.step = TEXTURE_HEIGHT / cast.line_height;
		cast.tex_pos = \
		(cast.draw_start - HEIGHT / 2 + cast.line_height / 2) * cast.step;
		save_vline_into_buffer(file, &cast);
		cast.x++;
	}
}
