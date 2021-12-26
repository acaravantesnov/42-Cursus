/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:18:48 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 15:04:54 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(long	*stackA, long *stackB, int ndigitsA, int ndigitsB)
{
	long	*temp;
	int		i;

	temp = ft_realloc(stackA, ndigitsA, ndigitsA + 1);
	i = 1;
	while (i < ndigitsA)
	{
		stackA[i] = stackA[i - 1];
		i++;
	}
	stackA[0] = stackB[0];
	if (ndigitsB == 0)
		stackB = NULL;
	free(temp);
	write(1, "pa\n", 3);
}
