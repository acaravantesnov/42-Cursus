/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 05:47:42 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/29 14:14:16 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(long	*stackA, long *stackB, int *ndigitsA, int *ndigitsB)
{
	int		i;

	ft_realloc(stackB, *ndigitsB, *ndigitsB + 1);
	(*ndigitsB)++;
	i = *ndigitsB - 1;
	while (i > 0)
	{
		stackB[i] = stackB[i - 1];
		i--;
	}
	stackB[0] = stackA[0];
	ft_realloc(stackA, ndigitsA[1], ndigitsA[1] - 1);
	(ndigitsA[1])--;
	i = 0;
	while (i < ndigitsA[1])
	{
		stackA[i] = stackA[i + 1];
		i++;
	}
	if (ndigitsA[1] == 0)
		stackA = NULL;
	write(1, "pb\n", 3);
}
