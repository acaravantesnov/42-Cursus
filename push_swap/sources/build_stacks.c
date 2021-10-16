/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 06:11:00 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 07:27:04 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	build_stacks(int *stackA, int *stackB, int ndigitsA)
{
	int	i;

	i = 0;
	printf("---------------------\n");
	printf("| stackA  |  stackB |\n");
	printf("---------------------\n");
	while (i < ndigitsA)
	{
		if (stackA && stackB)
			printf("| %i\t  |  %i\t    |\n", stackA[i], stackB[i]);
		else if (stackA && (stackB == NULL))
			printf("| %i\t  |  \t    |\n", stackA[i]);
		else if (ndigitsA == 0)
			printf("| \t  |  %i\t    |\n", stackB[i]);
		i++;
	}
	printf("---------------------\n");
}
