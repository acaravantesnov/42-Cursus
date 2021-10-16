/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putCollec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 03:08:40 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/18 03:25:05 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	putcollec_3(t_sprite *collec, int i, int j)
{
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win,
		collec->img, j * PS, i * PS);
}

void	putcollec_2(t_sprite *collec, int pexit, int elem, char **map_2d)
{
	int	i;
	int	j;

	i = 0;
	while (pexit != 1)
	{
		while (i < m.y_size)
		{
			j = 0;
			while (j < m.x_size)
			{
				if (map_2d[i][j] == 'C')
				{
					collecc[elem].x = j;
					collecc[elem].y = i;
					putcollec_3(collec, i, j);
					g_ncollec++;
					elem++;
				}
				j++;
			}
			i++;
		}
		pexit = 1;
	}
}

int	putcollec(t_sprite *collec, char **map_2d)
{
	int	elem;
	int	pexit;

	pexit = 0;
	g_ncollec = 0;
	elem = 0;
	collec->img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/collec.xpm",
			&collec->img_width, &collec->img_height);
	if (collec->img == NULL)
		exit(0);
	collec->addr = mlx_get_data_addr(collec->img, &collec->bits_per_pixel,
			&collec->line_length, &collec->endian);
	putcollec_2(collec, pexit, elem, map_2d);
	return (g_ncollec);
}
