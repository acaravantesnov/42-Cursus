/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:53:57 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/28 19:33:31 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void parsing(long *stackA, int *ndigitsA, char **argv)
{
	int i;
	char **numbersinc;

	i = 0;
	if (ndigitsA[0] == 1)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 32)
			{
				(ndigitsA[0])++;
				(ndigitsA[1])++;
			}
			i++;
		}
		ft_realloc(stackA, 1, ndigitsA[0]);
		numbersinc = ft_split(argv[1], 32);
		i = 0;
		while (i < ndigitsA[0])
		{
			stackA[i] = ft_atoi(numbersinc[i]);
			i++;
		}
	}
	else
	{
		while (i < ndigitsA[1])
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
	}
	check_repeated_numbers(stackA, ndigitsA[1]);
	check_numeric_limits(stackA, ndigitsA[1]);
}
