/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:38:14 by acaravan          #+#    #+#             */
/*   Updated: 2022/08/02 00:33:56 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/utils.h"

int	key_hook(int keycode, t_player *player)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 0) // A
		(player->px)--;
	else if (keycode == 13) // W
		(player->py)++;
	else if (keycode == 2) // D
		(player->px)++;
	else if (keycode == 1) // S
		(player->py)--;
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
	t_player	player;

	(void)data;

	window_size = malloc(2 * sizeof(int));
	window_size[0] = 2060;
	window_size[1] = 1220;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, window_size[0], window_size[1], \
	"./cub3D");
	player.px = 0;
	player.py = 0;
	while (1)
	{
		mlx_pixel_put(mlx.mlx, mlx.mlx_win, 100 + player.px , 100 + player.py, \
		0xFF5733);
		mlx_hook(mlx.mlx_win, 2, 1L << 17, key_hook, &player);
		mlx_hook(mlx.mlx_win, 17, 1L << 17, close_window, &mlx);
		mlx_loop(mlx.mlx);
	}
	
	return (0);
}


