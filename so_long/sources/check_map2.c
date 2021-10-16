/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 03:13:01 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/18 03:14:50 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map2(int nExit, int nPosInic)
{
	if (nExit != 1 || nPosInic != 1 || g_ncollec == 0)
	{
		printf("Error\nMaps should contain 1 and only 1 P and E characters,");
		printf(" and at least one C.");
		exit(0);
	}
}
