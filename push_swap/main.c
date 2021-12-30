/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 04:40:45 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/30 22:37:33 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	check_params(int argc, int *ndigitsA, int *ndigitsB)
{
	if (argc < 2)
	{
		free(ndigitsA);
		free(ndigitsB);
		exit(0);
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
	check_params(argc, ndgtsa, ndgtsb);
	setndigits(ndgtsa, ndgtsb, argc);
	stcka = (long *)malloc(sizeof(long) * size(argc, argv));
	stckb = (long *)malloc(sizeof(long) * size(argc, argv));
	if ((parsing(stcka, ndgtsa, argv) == -1) || (issorted(stcka, ndgtsa) == 0))
		freeall(stcka, stckb, ndgtsa, ndgtsb);
	if ((ndgtsa[1] == 2) && (stcka[0] > stcka[1]))
		ra(stcka, ndgtsa);
	else if (ndgtsa[1] == 3)
		sort_3digits(stcka, stckb, ndgtsa);
	else if (ndgtsa[1] == 5)
		sort_5digits(stcka, stckb, ndgtsa, ndgtsb);
	else
		sort_big_stack(stcka, stckb, ndgtsa, ndgtsb);
	freeall(stcka, stckb, ndgtsa, ndgtsb);
	return (0);
}
