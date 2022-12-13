/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:54:04 by acaravan          #+#    #+#             */
/*   Updated: 2022/11/29 15:59:40 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*!
 *	@function	my_mlx_pixel_put
 *	@abstract	Puts pixels into data img. More efficient than mlx_pixel_put.
 *	@param		data	t_data struct which will be later put into window.
 *	@param		x		Pixel's X-position.
 *	@param		y		Pixel's Y-position.
 *	@param		color	Pixel's color.
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
