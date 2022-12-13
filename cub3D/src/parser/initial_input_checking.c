/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_input_checking.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:37:26 by acaravan          #+#    #+#             */
/*   Updated: 2022/11/29 19:40:42 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initial_input_checking(int argc, const char **argv, int *map_fd)
{
	if (argc != 2)
		print_error("Wrong number of arguments!", true);
	if (!check_name(argv[1], ".cub"))
		print_error("File name is wrong", true);
	*map_fd = open(argv[1], O_RDONLY);
	if (*map_fd == -1)
		print_error("Map file doesn't exist or is corrupted", false);
}
