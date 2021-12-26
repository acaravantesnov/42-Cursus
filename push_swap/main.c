/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 04:40:45 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 19:00:13 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

// ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG

/*	COSAS POR HACER

	#pa		*
	#pb		*
	#ra
	#rb
	#rr
	#rra
	#rrb
	#rrr
	#sa		*
	#sb		*
	#ss		*

	#Comprobar sort_3digits()
	#sort_5digits()
	#sort_100digits()
	#sort_500digits()
*/

int main(int argc, char **argv)
{
	long *stackA;
	long *stackB;
	int ndigitsA;

	if (check_params(argc) == -1)
		return (0);
	ndigitsA = argc - 1;
	stackA = (long *)malloc(sizeof(long) * ndigitsA);
	stackB = (long *)malloc(sizeof(long) * ndigitsA);
	parsing(stackA, ndigitsA, argv);
	if (check_sorted(stackA, ndigitsA) == 0)
		return (0);
	build_stacks(stackA, stackB, ndigitsA);
	if (ndigitsA == 3)
		sort_3digits(stackA, stackB);
	else if (ndigitsA == 5)
		sort_5digits(stackA, stackB);
	else if (ndigitsA == 100)
		sort_100digits(stackA, stackB);
	else if (ndigitsA == 500)
		sort_500digits(stackA, stackB);
	build_stacks(stackA, stackB, ndigitsA);
	free(stackA);
	free(stackB);
	return (0);
}
