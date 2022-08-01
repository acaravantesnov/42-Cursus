/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:38:14 by acaravan          #+#    #+#             */
/*   Updated: 2022/08/02 01:08:13 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/utils.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_mlx *mlx)
{
	t_data	img;

	if (keycode == 53)
		exit(0);
	if (keycode == 0) // A
		(mlx->player->px) -= 10;
	else if (keycode == 13) // W
		(mlx->player->py) -= 10;
	else if (keycode == 2) // D
		(mlx->player->px) += 10;
	else if (keycode == 1) // S
		(mlx->player->py) += 10;

	img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	//img.img = mlx_xpm_file_to_image(mlx, ) <- To create sprites from xpm
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
	my_mlx_pixel_put(&img, mlx->player->px, mlx->player->py, 0xFF5733);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.img, 0, 0);
	return (0);
}

int	close_window(int keycode, t_mlx *mlx)
{
	(void)keycode;
	(void)mlx;
	exit (0);
}


int	main ( void )
{
	t_data		data;
	t_mlx		mlx;
	int			*window_size;

	(void)data;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, \
	"./cub3D");
	mlx.player = malloc (sizeof(t_player));
	mlx.player->px = 0;
	mlx.player->py = 0;
	while (1)
	{
		mlx_hook(mlx.mlx_win, 2, 1L << 17, key_hook, &mlx);
		mlx_hook(mlx.mlx_win, 17, 1L << 17, close_window, &mlx);
		mlx_loop(mlx.mlx);
	}

	free(mlx.player);
	free(window_size);
	return (0);
}


