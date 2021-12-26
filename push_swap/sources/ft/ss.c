/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:13:21 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 15:00:03 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ss(long *stackA, long *stackB, int ndigitsA, int ndigitsB)
{
	long	*temp;

	temp = (long *)malloc(sizeof(long));
	if (ndigitsA > 1)
	{
		temp[0] = stackA[0];
		stackA[0] = stackA[1];
		stackA[1] = temp[0];
	}
	if (ndigitsB > 1)
	{
		temp[0] = stackB[0];
		stackB[0] = stackB[1];
		stackB[1] = temp[0];
	}
	free(temp);
	write(1, "ss\n", 3);
}
