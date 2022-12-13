/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:34:26 by acaravan          #+#    #+#             */
/*   Updated: 2022/11/30 15:30:10 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	build_buffer
 *	@discussion	Allocates memory for a matrix of integer values. It will contain
 *				as many elements as pixels in the window.
 *				It is initially filled with hex values 0x000000 (black).
 *	@param		file	t_file struct containing all necessary data.
*/
void	build_buffer(t_file *file)
{
	int	i;
	int	j;

	file->buffer = (int **)malloc(HEIGHT * sizeof(int *));
	i = 0;
	while (i < HEIGHT)
	{
		file->buffer[i] = (int *)malloc(WIDTH * sizeof(int));
		i++;
	}
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			file->buffer[i][j] = 0x000000;
			j++;
		}
		i++;
	}
}
