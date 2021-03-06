/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:11:18 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/28 18:13:12 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(long *stackA, int *ndigitsA)
{
	long	*temp;

	temp = (long *)malloc(sizeof(long));
	if (ndigitsA[1] > 1)
	{
		temp[0] = stackA[0];
		stackA[0] = stackA[1];
		stackA[1] = temp[0];
	}
	free(temp);
	write(1, "sa\n", 3);
}
