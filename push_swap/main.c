/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 04:40:45 by acaravan          #+#    #+#             */
/*   Updated: 2022/01/08 19:11:31 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	freeandexit(int *ndigitsA, int *ndigitsB)
{
	free(ndigitsA);
	free(ndigitsB);
	exit(0);
}

void	freeandexitwitherror(int *ndigitsA, int *ndigitsB)
{
	free(ndigitsA);
	free(ndigitsB);
	write(1, "Error\n", 6);
	exit(0);
}

void	check_params(int argc, char **argv, int *ndigitsA, int *ndigitsB)
{
	int		i;
	size_t	j;

	i = 1;
	j = 0;
	if (argc < 2)
		freeandexit(ndigitsA, ndigitsB);
	while (i < argc)
	{
		if ((argv[i][ft_strlen(argv[i]) - 1] == ' ') || (argv[i][0] == ' '))
			freeandexitwitherror(ndigitsA, ndigitsB);
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (((argv[i][j] < 48) || (argv[i][j] > 57)) && (argv[i][j] != 32))
			{
				if (argv[i][j] != 45)
					freeandexitwitherror(ndigitsA, ndigitsB);
			}
			if ((argv[i][j] == 32) && (argv[i][j + 1] == 32))
				freeandexitwitherror(ndigitsA, ndigitsB);
			j++;
		}
		i++;
	}
}

void	setndigits(int *ndigitsA, int *ndigitsB, int argc)
{
	ndigitsA[0] = argc - 1;
	ndigitsA[1] = ndigitsA[0];
	*ndigitsB = 0;
}

int	main(int argc, char **argv)
{
	long	*stcka;
	long	*stckb;
	int		*ndgtsa;
	int		*ndgtsb;

	ndgtsa = (int *)malloc(2 * sizeof(int));
	ndgtsb = (int *)malloc(sizeof(int));
	check_params(argc, argv, ndgtsa, ndgtsb);
	setndigits(ndgtsa, ndgtsb, argc);
	stcka = (long *)malloc(sizeof(long) * size(argc, argv));
	stckb = (long *)malloc(sizeof(long) * size(argc, argv));
	if ((parsing(stcka, ndgtsa, argv) == -1) || (issorted(stcka, ndgtsa) == 0))
		freeall(stcka, stckb, ndgtsa, ndgtsb);
	if ((ndgtsa[1] == 2) && (stcka[0] > stcka[1]))
		ra(stcka, ndgtsa);
	else if (ndgtsa[1] == 3)
		sort_3digits(stcka, ndgtsa);
	else if (ndgtsa[1] == 5)
		sort_5digits(stcka, stckb, ndgtsa, ndgtsb);
	else
		sort_big_stack(stcka, stckb, ndgtsa, ndgtsb);
	freeall(stcka, stckb, ndgtsa, ndgtsb);
	return (0);
}
