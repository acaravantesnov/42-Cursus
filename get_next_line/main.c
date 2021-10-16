/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:47:55 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/05 09:41:53 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*linea;
	int		fd;

	fd = open("test", O_RDONLY);
	close(fd);
	for (int i = 1; i <= 3; i++)
	{
		linea = get_next_line(fd);
		printf("Linea %d: %s\n", i, linea);
		free(linea);
	}
	system("leaks a.out");
	close(fd);
	return (0);
}