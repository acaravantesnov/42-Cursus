/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:13:21 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 14:18:46 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ss(long *stackA, long *stackB, int ndigitsA, int ndigitsB)
{
	long	*temp;

	temp = (long *)malloc(sizeof(long));
	if (ndigitsA > 1)
	{
		temp[0] = stackA[ndigitsA - 1];
		stackA[ndigitsA - 1] = stackA[ndigitsA - 2];
		stackA[ndigitsA - 2] = temp[0];
	}
	if (ndigitsB > 1)
	{
		temp[0] = stackB[ndigitsB - 1];
		stackB[ndigitsB - 1] = stackB[ndigitsB - 2];
		stackB[ndigitsB - 2] = temp[0];
	}
	free(temp);
	write(1, "ss\n", 3);
}
