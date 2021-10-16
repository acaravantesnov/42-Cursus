/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:16:08 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/18 03:11:05 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	grass(t_data *floor)
{
	int	i;
	int	j;
	int	img_width;
	int	img_height;

	floor->img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/grass.xpm", &img_width,
			&img_height);
	if (floor->img == NULL)
		exit(0);
	floor->addr = mlx_get_data_addr(floor->img, &floor->bits_per_pixel,
			&floor->line_length, &floor->endian);
	i = 0;
	while (i < m.y_size)
	{
		j = 0;
		while (j < m.x_size)
		{
			mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, floor->img, j * PS,
				i * PS);
			j++;
		}
		i++;
	}
}

void	dirt(t_data *floor)
{
	int	i;
	int	j;
	int	img_width;
	int	img_height;

	floor->img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/dirt.xpm", &img_width,
			&img_height);
	if (floor->img == NULL)
		exit(0);
	floor->addr = mlx_get_data_addr(floor->img, &floor->bits_per_pixel,
			&floor->line_length, &floor->endian);
	i = 1;
	j = 1;
	while (i < m.y_size - 1)
	{
		j = 1;
		while (j < m.x_size - 1)
		{
			mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, floor->img, j * PS,
				i * PS);
			j++;
		}
		i++;
	}
}

void	initialization(t_data	*floor)
{
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, m.x_size * PS, m.y_size * PS,
			"./so_long");
	grass(floor);
	dirt(floor);
}
