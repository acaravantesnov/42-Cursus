/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 22:55:15 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/23 04:46:11 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	master_hook(char **map_2d)
{
	while (g_exit_ != 1)
	{
		mlx_hook(mlx.mlx_win, 2, 1L << 0, key_hook, &map_2d);
		mlx_hook(mlx.mlx_win, 17, 1L << 17, close_window, &mlx);
		mlx_loop(mlx.mlx);
	}
}

void	freemap_2d(char **map_2d)
{
	int	i;

	i = 0;
	while (i < m.y_size)
	{
		free(map_2d[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	*map;
	char	**map_2d;
	t_data	floor;

	g_exit_ = 0;
	g_nmov = 0;
	g_collected = 0;
	check_args(argc, argv);
	map = save_map(file_descriptor(argv));
	map_size(map);
	map_2d = make2dmap(map);
	free(map);
	check_map(map_2d);
	initialization(&floor);
	putcharacter(&g_cdown, map_2d);
	putwalls(&g_wall, map_2d);
	g_ncollec = putcollec(&g_collec, map_2d);
	putvexit(&g_vexit, map_2d);
	master_hook(map_2d);
	freemap_2d(map_2d);
	return (0);
}
