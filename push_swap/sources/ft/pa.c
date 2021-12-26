/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:18:48 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 23:19:47 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(long	*stackA, long *stackB, int *ndigitsA, int *ndigitsB)
{
	long	*temp;
	long	save;
	int		i;

	temp = ft_realloc(stackA, *ndigitsA, *ndigitsA + 1);
	(*ndigitsA)++;
	i = 1;
	if (*ndigitsA > 1)
	{
		save = stackA[2];
		while (i < *ndigitsA)
		{
			stackA[i] = stackA[i - 1];
			
			i++;
		}
	}
	stackA[0] = stackB[0];
	temp = ft_realloc(stackB, *ndigitsB, *ndigitsB - 1);
	(*ndigitsB)--;
	i = 0;
	while (i < *ndigitsB)
	{
		stackB[i] = stackB[i + 1];
		i++;
	}
	if (*ndigitsB == 0)
		stackB = NULL;
	write(1, "pa\n", 3);
}
