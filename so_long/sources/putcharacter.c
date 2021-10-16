/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putCharacter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:30:31 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/18 03:03:30 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	putcharacter(t_sprite	*cDown, char **map_2d)
{
	int	i;
	int	j;

	cDown->img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/caracterDown.xpm",
			&cDown->img_width, &cDown->img_height);
	cDown->addr = mlx_get_data_addr(cDown->img, &cDown->bits_per_pixel,
			&cDown->line_length, &cDown->endian);
	i = 0;
	while (i < m.y_size)
	{
		j = 0;
		while (j < m.x_size)
		{
			if (map_2d[i][j] == 'P')
			{
				m.p_x = j;
				m.p_y = i;
				mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, cDown->img,
					j * PS, i * PS);
			}
			j++;
		}
		i++;
	}
}

void	caracterleft(t_sprite	*cLeft, int x, int y)
{
	t_sprite	floor;
	int			img_width;
	int			img_height;

	floor.img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/dirt.xpm", &img_width,
			&img_height);
	if (floor.img == NULL)
		exit(0);
	floor.addr = mlx_get_data_addr(floor.img, &floor.bits_per_pixel,
			&floor.line_length, &floor.endian);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, floor.img, (m.p_x + 1) * PS,
		m.p_y * PS);
	cLeft->img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/caracterLeft.xpm",
			&cLeft->img_width, &cLeft->img_height);
	if (cLeft->img == NULL)
		exit(0);
	cLeft->addr = mlx_get_data_addr(cLeft->img, &cLeft->bits_per_pixel,
			&cLeft->line_length, &cLeft->endian);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, cLeft->img, x * PS,
		y * PS);
}

void	caracterright(t_sprite	*cRight, int x, int y)
{
	t_sprite	floor;
	int			img_width;
	int			img_height;

	floor.img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/dirt.xpm", &img_width,
			&img_height);
	if (floor.img == NULL)
		exit(0);
	floor.addr = mlx_get_data_addr(floor.img, &floor.bits_per_pixel,
			&floor.line_length, &floor.endian);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, floor.img, (m.p_x - 1) * PS,
		m.p_y * PS);
	cRight->img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/caracterRight.xpm",
			&cRight->img_width, &cRight->img_height);
	if (cRight->img == NULL)
		exit(0);
	cRight->addr = mlx_get_data_addr(cRight->img, &cRight->bits_per_pixel,
			&cRight->line_length, &cRight->endian);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, cRight->img, x * PS,
		y * PS);
}

void	caracterdown(t_sprite	*cDown, int x, int y)
{
	t_sprite	floor;
	int			img_width;
	int			img_height;

	floor.img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/dirt.xpm", &img_width,
			&img_height);
	if (floor.img == NULL)
		exit(0);
	floor.addr = mlx_get_data_addr(floor.img, &floor.bits_per_pixel,
			&floor.line_length, &floor.endian);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, floor.img, m.p_x * PS,
		(m.p_y - 1) * PS);
	cDown->img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/caracterDown.xpm",
			&cDown->img_width, &cDown->img_height);
	if (cDown->img == NULL)
		exit(0);
	cDown->addr = mlx_get_data_addr(cDown->img, &cDown->bits_per_pixel,
			&cDown->line_length, &cDown->endian);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, cDown->img, x * PS,
		y * PS);
}

void	caracterup(t_sprite	*cUp, int x, int y)
{
	t_sprite	floor;
	int			img_width;
	int			img_height;

	floor.img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/dirt.xpm", &img_width,
			&img_height);
	if (floor.img == NULL)
		exit(0);
	floor.addr = mlx_get_data_addr(floor.img, &floor.bits_per_pixel,
			&floor.line_length, &floor.endian);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, floor.img, m.p_x * PS,
		(m.p_y + 1) * PS);
	cUp->img = mlx_xpm_file_to_image(mlx.mlx, "./imgs/caracterUp.xpm",
			&cUp->img_width, &cUp->img_height);
	if (cUp->img == NULL)
		exit(0);
	cUp->addr = mlx_get_data_addr(cUp->img, &cUp->bits_per_pixel,
			&cUp->line_length, &cUp->endian);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, cUp->img, x * PS,
		y * PS);
}
