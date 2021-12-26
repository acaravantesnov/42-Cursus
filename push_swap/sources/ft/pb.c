/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 05:47:42 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 23:00:44 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(long	*stackA, long *stackB, int *ndigitsA, int *ndigitsB)
{
	long	*temp;
	int		i;

	temp = ft_realloc(stackB, *ndigitsB, *ndigitsB + 1);
	(*ndigitsB)++;
	i = 1;
	if (*ndigitsB > 1)
	{
		while (i < *ndigitsB)
		{
			stackB[i] = stackB[i - 1];
			i++;
		}
	}
	stackB[0] = stackA[0];
	temp = ft_realloc(stackA, *ndigitsA, *ndigitsA - 1);
	(*ndigitsA)--;
	i = 0;
	while (i < *ndigitsA)
	{
		stackA[i] = stackA[i + 1];
		i++;
	}
	if (*ndigitsA == 0)
		stackA = NULL;
	write(1, "pb\n", 3);
}
