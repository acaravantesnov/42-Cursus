/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 07:23:17 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/28 18:13:03 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrr(long *stackA, long *stackB, int *ndigitsA, int *ndigitsB)
{
	int	i;
	long	*temp;

	i = ndigitsA[1] - 1;
	temp = (long *)malloc(sizeof(long));
	*temp = stackA[ndigitsA[1] - 1];
	while (i > 0)
	{
		stackA[i] = stackA[i - 1];
		i--;
	}
	stackA[0] = *temp;
	i = 0;
	*temp = stackB[0];
	while (i < *ndigitsB)
	{
		stackB[i] = stackB[i + 1];
		i++;
	}
	stackB[*ndigitsB - 1] = *temp;
	free(temp);
	write(1, "rrr\n", 4);
}
