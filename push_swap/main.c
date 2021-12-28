/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 04:40:45 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/28 20:00:31 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	print_stacks(long *stackA, long *stackB, int *ndigitsA, int *ndigitsB)
{
	printf("\nStackA: ");
	for (int i = 0; i < ndigitsA[1]; i++)
		printf("%li ", stackA[i]);
	printf("\nStackB: ");
	for (int i = 0; i < *ndigitsB; i++)
		printf("%li ", stackB[i]);
}

int main(int argc, char **argv)
{
	long *stackA;
	long *stackB;
	int *ndigitsA;
	int	*ndigitsB;

	ndigitsA = (int*)malloc(2 * sizeof(int));
	ndigitsB = (int*)malloc(sizeof(int));
	if (check_params(argc) == -1)
		return (0);
	ndigitsA[0] = argc - 1;
	ndigitsA[1] = ndigitsA[0];
	*ndigitsB = 0;
	stackA = (long *)malloc(sizeof(long) * (ndigitsA[1]));
	parsing(stackA, ndigitsA, argv);
	stackB = (long *)malloc(sizeof(long) * (*ndigitsB));
	if (check_sorted(stackA, ndigitsA) == 0)
		return (0);
	if (ndigitsA[1] == 3)
		sort_3digits(stackA, stackB, ndigitsA);
	else if (ndigitsA[1] == 5)
		sort_5digits(stackA, stackB, ndigitsA, ndigitsB);
	else
		sort_big_stack(stackA, stackB, ndigitsA, ndigitsB);
	free(stackA);
	free(stackB);
	return (0);
}
