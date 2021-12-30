/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 06:45:09 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/29 03:40:50 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rr(long *stackA, long *stackB, int *ndigitsA, int *ndigitsB)
{
	int		i;
	long	*temp;

	i = 0;
	temp = (long *)malloc(sizeof(long));
	*temp = stackA[0];
	while (i < ndigitsA[1])
	{
		stackA[i] = stackA[i + 1];
		i++;
	}
	stackA[ndigitsA[1] - 1] = *temp;
	i = 0;
	*temp = stackB[0];
	while (i < *ndigitsB)
	{
		stackB[i] = stackB[i + 1];
		i++;
	}
	stackB[*ndigitsB - 1] = *temp;
	free(temp);
	write(1, "rr\n", 3);
}
