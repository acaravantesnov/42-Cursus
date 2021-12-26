/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:18:48 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 14:19:23 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(long	*stackA, long *stackB, int ndigitsA, int ndigitsB)
{
	long	*temp;

	temp = ft_realloc(stackA, ndigitsA, ndigitsA + 1);
	temp[ndigitsA + 1] = stackB[ndigitsB];
	if (ndigitsB == 0)
		stackB = NULL;
	free(temp);
	write(1, "pa\n", 3);
}
