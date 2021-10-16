/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putWalls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 05:33:42 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/18 03:37:01 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	putwalls_3(t_sprite *wall, int i, int j)
{
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, wall->img,
		j * PS, i * PS);
}

void	putwalls_2(t_sprite *wall, int pexit, int obstac, char **map_2d)
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
				if (map_2d[i][j] == '1')
				{
					one[obstac].x = j;
					one[obstac].y = i;
					putwalls_3(wall, i, j);
					obstac++;
					g_n1++;
				}
				j++;
			}
			i++;
		}
		pexit = 1;
	}
}

void	putwalls(t_sprite *wall, char **map_2d)
{
	int	obstac;
	int	pexit;

	pexit = 0;
	obstac = 0;
	wall->img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/wall.xpm",
			&wall->img_width, &wall->img_height);
	if (wall->img == NULL)
		exit(0);
	wall->addr = mlx_get_data_addr(wall->img, &wall->bits_per_pixel,
			&wall->line_length, &wall->endian);
	putwalls_2(wall, pexit, obstac, map_2d);
}
