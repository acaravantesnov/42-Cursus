/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:12:36 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/28 18:13:26 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sb(long *stackB, int *ndigitsB)
{
	long	*temp;

	temp = (long *)malloc(sizeof(long));
	if (*ndigitsB > 1)
	{
		temp[0] = stackB[0];
		stackB[0] = stackB[1];
		stackB[1] = temp[0];
	}
	free(temp);
	write(1, "sb\n", 3);
}
