/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:53:57 by acaravan          #+#    #+#             */
/*   Updated: 2022/01/08 19:50:42 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stringimput(long *stackA, int *ndigitsA, char **argv, char **numbersinc)
{
	int	i;
	int	digits;

	i = 0;
	digits = 0;
	numbersinc = ft_split(argv[1], 32);
	while (numbersinc[i])
	{
		digits++;
		i++;
	}
	ndigitsA[0] = digits;
	ndigitsA[1] = ndigitsA[0];
	i = 0;
	while (i < ndigitsA[0])
	{
		stackA[i] = ft_atoi(numbersinc[i]);
		i++;
	}
	ft_freestr(numbersinc);
	free(numbersinc);
	return (0);
}

int	normalimput(long *stackA, int *ndigitsA, char **argv)
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
			return (-1);
		}
		i++;
	}
	return (0);
}

int	parsing(long *stackA, int *ndigitsA, char **argv)
{
	char	**numbersinc;

	numbersinc = NULL;
	if (ndigitsA[0] == 1)
	{
		if (stringimput(stackA, ndigitsA, argv, numbersinc) == -1)
			return (-1);
	}
	else
	{
		if (normalimput(stackA, ndigitsA, argv) == -1)
			return (-1);
	}
	if (check_repeated_numbers(stackA, ndigitsA[1]) == -1)
		return (-1);
	if (check_numeric_limits(stackA, ndigitsA[1]) == -1)
		return (-1);
	return (0);
}
