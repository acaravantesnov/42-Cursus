/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:53:57 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 21:40:34 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void parsing(long *stackA, int *ndigitsA, char **argv)
{
	int i;

	i = 0;
	while (i < *ndigitsA)
	{
		if (ft_isnumber(argv[i + 1]) == 1)
			stackA[i] = ft_atoi(argv[i + 1]);
		else
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	check_repeated_numbers(stackA, *ndigitsA);
	check_numeric_limits(stackA, *ndigitsA);
}
