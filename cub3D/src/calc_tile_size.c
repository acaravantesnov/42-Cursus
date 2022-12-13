/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_tile_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:03:18 by acaravan          #+#    #+#             */
/*   Updated: 2022/11/29 15:25:26 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	calc_tile_size
 *	@discussion	Calculates the size of each tile based on maximum size of
 *				minimap and even size.
 *	@param		file	t_file struct containing all necessary data.
 *	@return		Size in px of each individual tile (square) in the map.
*/
int	calc_tile_size(t_file *file)
{
	int	tile_size;
	int	max;

	max = WIDTH / 4;
	tile_size = 1;
	while (((tile_size * file->height < max) && \
	(tile_size * file->width < max)) || (tile_size % 2 != 0))
		tile_size++;
	return (tile_size);
}
