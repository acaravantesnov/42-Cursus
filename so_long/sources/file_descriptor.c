/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_descriptor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:05:01 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/18 00:23:42 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	file_descriptor(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if ((fd < 0) || (fd > 256))
	{
		write(1, "Error\nNon existing .ber file or in wrong path", 45);
		exit(0);
	}
	return (fd);
}
