/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:53:57 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/29 04:23:28 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stringimput(long *stackA, int *ndigitsA, char **argv, char **numbersinc)
{
	int	i;

	i = 0;
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

void	normalimput(long *stackA, int *ndigitsA, char **argv)
{
	int	i;

	i = 0;
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

void	parsing(long *stackA, int *ndigitsA, char **argv)
{
	char	**numbersinc;

	if (ndigitsA[0] == 1)
		stringimput(stackA, ndigitsA, argv, numbersinc);
	else
		normalimput(stackA, ndigitsA, argv);
	check_repeated_numbers(stackA, ndigitsA[1]);
	check_numeric_limits(stackA, ndigitsA[1]);
}
