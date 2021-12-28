/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 04:40:45 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/28 08:08:48 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	print_stacks(long *stackA, long *stackB, int *ndigitsA, int *ndigitsB)
{
	printf("\nStackA: ");
	for (int i = 0; i < *ndigitsA; i++)
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
	int *size;

	ndigitsA = (int*)malloc(sizeof(int));
	ndigitsB = (int*)malloc(sizeof(int));
	size = (int*)malloc(sizeof(int));
	if (check_params(argc) == -1)
		return (0);
	*size = argc - 1;
	*ndigitsA = *size;
	*ndigitsB = 0;
	stackA = (long *)malloc(sizeof(long) * (*ndigitsA));
	stackB = (long *)malloc(sizeof(long) * (*ndigitsB));
	parsing(stackA, ndigitsA, argv);
	if (check_sorted(stackA, ndigitsA) == 0)
		return (0);
	//print_stacks(stackA, stackB, ndigitsA, ndigitsB);
	if (*ndigitsA == 3)
		sort_3digits(stackA, stackB, ndigitsA);
	else if (*ndigitsA == 5)
		sort_5digits(stackA, stackB, ndigitsA, ndigitsB);
	else
		sort_big_stack(stackA, stackB, ndigitsA, ndigitsB, size);
	//print_stacks(stackA, stackB, ndigitsA, ndigitsB);
	free(stackA);
	free(stackB);
	return (0);
}
