/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:12:36 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 08:24:44 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sb(int *stackB, int ndigitsB)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int));
	if (ndigitsB > 1)
	{
		temp[0] = stackB[ndigitsB - 1];
		stackB[ndigitsB - 1] = stackB[ndigitsB - 2];
		stackB[ndigitsB - 2] = temp[0];
	}
	free(temp);
}
