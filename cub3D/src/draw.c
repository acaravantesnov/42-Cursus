/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:11:31 by acaravan          #+#    #+#             */
/*   Updated: 2022/12/02 01:28:27 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	draw
 *	@abstract	Draws entire buffer, mnimap, and player (on top of each other).
 *	@param		file	t_file struct containing all necessary data.
*	@param		screen	t_data struct which will be later put into window.
*/
void	draw(t_file *file, t_data *screen)
{
	draw_buffer(file, screen);
	draw_minimap(file, screen);
	draw_player(file, screen);
}
