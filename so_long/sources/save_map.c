/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:06:27 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/23 04:18:36 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*save_map(int fd)
{
	char	map[144444];
	char	*ptr;
	char	*ptr_m;
	char	*extra;

	extra = NULL;
	ft_bzero(map, 1444);
	if (read(fd, extra, 1) == 0)
		return (NULL);
	ptr = get_next_line(fd);
	while (ptr != NULL)
	{
		ft_strlcat(map, ptr);
		free(ptr);
		ptr = get_next_line(fd);
	}
	free(ptr);
	ptr_m = malloc(sizeof(char) * ft_strlen(map) + 2);
	ft_strcpy(ptr_m, map);
	return (ptr_m);
}
