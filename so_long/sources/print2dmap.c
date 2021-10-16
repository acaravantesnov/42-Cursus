/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2dmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:11:04 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/18 02:44:39 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print2dmap(char **map_2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < m.y_size)
	{
		j = 0;
		while (j < m.x_size + 1)
		{
			write(1, &map_2d[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
