/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 04:40:45 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/29 04:10:02 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	check_params(int argc)
{
	if (argc < 2)
		exit(0);
}

void	setndigits(int *ndigitsA, int *ndigitsB, int argc)
{
	ndigitsA[0] = argc - 1;
	ndigitsA[1] = ndigitsA[0];
	*ndigitsB = 0;
}

void	freeall(long *stackA, long *stackB, int *ndigitsA, int *ndigitsB)
{
	free(stackA);
	free(stackB);
	free(ndigitsA);
	free(ndigitsB);
}

int	main(int argc, char **argv)
{
	long	*stacka;
	long	*stackb;
	int		*ndigitsa;
	int		*ndigitsb;

	ndigitsa = (int *)malloc(2 * sizeof(int));
	ndigitsb = (int *)malloc(sizeof(int));
	check_params(argc);
	setndigits(ndigitsa, ndigitsb, argc);
	stacka = (long *)malloc(sizeof(long) * (ndigitsa[1]));
	parsing(stacka, ndigitsa, argv);
	stackb = (long *)malloc(sizeof(long) * (*ndigitsb));
	if (check_sorted(stacka, ndigitsa) == 0)
		return (0);
	if ((ndigitsa[1] == 2) && (stacka[0] > stacka[1]))
		ra(stacka, ndigitsa);
	else if (ndigitsa[1] == 3)
		sort_3digits(stacka, stackb, ndigitsa);
	else if (ndigitsa[1] == 5)
		sort_5digits(stacka, stackb, ndigitsa, ndigitsb);
	else
		sort_big_stack(stacka, stackb, ndigitsa, ndigitsb);
	freeall(stacka, stackb, ndigitsa, ndigitsb);
	return (0);
}
