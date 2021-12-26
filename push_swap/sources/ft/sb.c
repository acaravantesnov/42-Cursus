/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:12:36 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 12:11:40 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sb(long *stackB, int ndigitsB)
{
	long	*temp;

	temp = (long *)malloc(sizeof(long));
	if (ndigitsB > 1)
	{
		temp[0] = stackB[ndigitsB - 1];
		stackB[ndigitsB - 1] = stackB[ndigitsB - 2];
		stackB[ndigitsB - 2] = temp[0];
	}
	free(temp);
}
