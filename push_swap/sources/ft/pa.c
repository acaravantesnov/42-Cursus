/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:18:48 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/30 17:53:49 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(long	*stackA, long *stackB, int *ndigitsA, int *ndigitsB)
{
	long	save;
	int		i;

	(ndigitsA[1])++;
	i = ndigitsA[1] - 1;
	while (i > 0)
	{
		stackA[i] = stackA[i - 1];
		i--;
	}
	stackA[0] = stackB[0];
	i = 0;
	while (i < *ndigitsB)
	{
		stackB[i] = stackB[i + 1];
		i++;
	}
	(*ndigitsB)--;
	if (*ndigitsB == 0)
		stackB = NULL;
	write(1, "pa\n", 3);
}
