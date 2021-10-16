/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:08:12 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/23 04:49:15 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_nl(char *map)
{
	if (ft_strchr(map, '\n') == NULL)
	{
		printf("Error\nInvalid map");
		exit (0);
	}
}

void	check_map_length(char *map)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		k = 0;
		while ((map[i + k] != '\n') && (map[i + k] != '\0'))
			k++;
		if ((k != m.x_size) && (k != 0))
		{
			printf("Error\nInvalid map.");
			exit(0);
		}
		i = i + m.x_size + 1;
	}
}

void	check_last_char(int i, int y, char *map)
{
	if (map[i - 1] == '\n')
		m.y_size = y;
	else
		m.y_size = y + 1;
}

int	map_size(char *map)
{
	int	x;
	int	y;
	int	i;

	if (map == NULL)
	{
		printf("Error\nInvalid map");
		exit (0);
	}
	check_nl(map);
	x = 0;
	while (map[x] != '\n')
		x++;
	m.x_size = x;
	i = 0;
	y = 0;
	while (map[i] != '\0')
	{
		if ((map[i] == '\n') && (map[i - 1] == '1'))
			y++;
		i++;
	}
	check_last_char(i, y, map);
	check_map_length(map);
	return (0);
}
