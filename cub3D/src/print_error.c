/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:27:34 by airodrig          #+#    #+#             */
/*   Updated: 2022/11/29 16:07:24 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *str, bool print_usage)
{
	printf("\033[1;31mError\033[0m\n%s\n", str);
	if (print_usage)
		printf("\033[1;32mUsage: ./cub3D mapname.cub\n\033[0m");
	exit(errno);
}
