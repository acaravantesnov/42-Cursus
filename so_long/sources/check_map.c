/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:55:40 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/23 04:46:22 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_2(void)
{
	if (m.x_size == m.y_size)
	{
		write(1, "Error\nMap should be rectangular", 31);
		exit(0);
	}
}

void	check_map_3(char **map)
{
	int	j;

	j = 0;
	while (j < m.x_size)
	{
		if ((map[0][j] != '1') || (map[m.y_size - 1][j] != '1'))
		{
			write(1, "Error\nMap should be surrounded by 1", 35);
			exit(0);
		}
		j++;
	}
}

void	check_map_4(char **map)
{
	int	i;

	i = 0;
	while (i < m.y_size)
	{
		if ((map[i][0] != '1') || (map[i][m.x_size - 1] != '1'))
		{
			write(1, "Error\nMap should be surrounded by 1", 35);
			exit(0);
		}
		i++;
	}
}

void	check_map_5(int i, char **map, int nExit, int nPosInic)
{
	int	j;

	while (i < m.y_size)
	{
		j = 0;
		while (j < m.x_size)
		{
			if ((map[i][j] != '1') && (map[i][j] != '0') &&
			(map[i][j] != 'E') && (map[i][j] != 'C') && (map[i][j] != 'P'))
			{
				write(1, "Error\nInvalid character in the .ber map.", 40);
				exit(0);
			}
			if (map[i][j] == 'E')
				nExit++;
			else if (map[i][j] == 'P')
				nPosInic++;
			else if (map[i][j] == 'C')
				g_ncollec++;
			j++;
		}
		i++;
	}
	check_map2(nExit, nPosInic);
}

int	check_map(char **map)
{
	int	i;
	int	nexit;
	int	nposinic;

	i = 0;
	nexit = 0;
	nposinic = 0;
	check_map_2();
	check_map_3(map);
	check_map_4(map);
	check_map_5(i, map, nexit, nposinic);
	return (0);
}
