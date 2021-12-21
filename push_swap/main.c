/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 04:40:45 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/21 15:43:41 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

// ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG

int	check_params(int argc)
{
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
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

void	parsing(int *stackA, int ndigitsA, char **argv)
{
	int i;

	i = 0;
	while (i < ndigitsA)
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

int	check_stackA(int *stackA, int ndigitsA)
{
	int i;

	i = 0;
	while (i < ndigitsA)
	{
		if ((stackA[i] > 2147483647) || (stackA[i] < -2147483648))
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int i;
	int *stackA;
	int *stackB;
	int ndigitsA;
	int ndigitsB;

	i = 0;
	if (check_params(argc) == -1)
		return (0);
	ndigitsA = argc - 1;
	ndigitsB = 0;
	stackA = (int *)malloc(sizeof(int) * ndigitsA);
	stackB = NULL;
	parsing(stackA, ndigitsA, argv);
	if (check_stackA(stackA, ndigitsA) == -1)
		return (0);
	if (check_sorted(stackA, ndigitsA) == 0)
		return (0);
	build_stacks(stackA, stackB, ndigitsA);
	return (0);
}
