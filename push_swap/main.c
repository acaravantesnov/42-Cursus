/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 04:40:45 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 11:44:33 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

// ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG

/*	COSAS POR HACER

	#	Numeric integer limits

*/

int	check_params(int argc)
{
	if (argc < 2)
		return (-1);
	return (0);
}

int	ft_isnumber(char *num)
{
	int i;
	int minus;

	i = 0;
	minus = 0;
	while (num[i])
	{
		if (num[i] == 45)
			minus++;
		if (ft_isdigit(num[i]) == 0)
			return (0);
		i++;
	}
	if (minus > 1)
		return (0);
	return (1);
}

void	check_repeated_numbers(int *stackA, int ndigitsA)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < ndigitsA)
	{
		j = 0;
		while (j < ndigitsA)
		{
			if ((stackA[i] == stackA[j]) && (i != j))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	parsing(int *stackA, int ndigitsA, char **argv)
{
	int i;

	i = 0;
	while (i < ndigitsA)
	{
		if ((ft_isnumber(argv[i + 1]) == 1) && (ft_atoi(argv[i + 1]) > -2147483648) &&
		(ft_atoi(argv[i + 1]) < 2147483647))
			stackA[i] = ft_atoi(argv[i + 1]);
		else
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	check_repeated_numbers(stackA, ndigitsA);
}

int check_sorted(int *stackA, int ndigitsA)
{
	int i;
	int j;
	int max;

	i = 1;
	j = 0;
	max = stackA[0];
	while (i < ndigitsA)
	{
		if (stackA[i] > max)
		{
			max = stackA[i];
			j++;
		}
		i++;
	}
	if (j == ndigitsA - 1)
		return (0);
	return (-1);
}

int	main(int argc, char **argv)
{
	int *stackA;
	int *stackB;
	int ndigitsA;

	if (check_params(argc) == -1)
		return (0);
	ndigitsA = argc - 1;
	stackA = (int *)malloc(sizeof(int) * ndigitsA);
	stackB = (int *)malloc(sizeof(int) * ndigitsA);
	parsing(stackA, ndigitsA, argv);
	if (check_sorted(stackA, ndigitsA) == 0)
		return (0);
	build_stacks(stackA, stackB, ndigitsA);
	return (0);
}
