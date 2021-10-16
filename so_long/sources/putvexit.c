/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putvExit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 03:06:32 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/18 03:27:34 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	putvexit_2(t_sprite *vexit, int i, int j)
{
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, vexit->img,
		j * PS, i * PS);
}

void	putvexit(t_sprite *vexit, char **map_2d)
{
	int	i;
	int	j;

	vexit->img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/vexit.xpm",
			&vexit->img_width, &vexit->img_height);
	if (vexit->img == NULL)
		exit(0);
	vexit->addr = mlx_get_data_addr(vexit->img, &vexit->bits_per_pixel,
			&vexit->line_length, &vexit->endian);
	i = 0;
	while (i < m.y_size)
	{
		j = 0;
		while (j < m.x_size)
		{
			if (map_2d[i][j] == 'E')
			{
				E[0].x = j;
				E[0].y = i;
				putvexit_2(vexit, i, j);
			}
			j++;
		}
		i++;
	}
}
