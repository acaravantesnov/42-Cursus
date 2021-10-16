/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make2dmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:09:47 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/23 04:18:37 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**make2dmap(char *map)
{
	int		i;
	char	**map_2d;

	i = 0;
	map_2d = (char **)malloc(m.y_size * sizeof(char *));
	while (i < m.y_size)
	{
		map_2d[i] = (char *)malloc((m.x_size + 2) * sizeof(char));
		i++;
	}
	i = 0;
	while (i < m.y_size)
	{
		ft_strlcpy(map_2d[i], map, m.x_size + 1);
		map += m.x_size + 1;
		i++;
	}
	return (map_2d);
}
