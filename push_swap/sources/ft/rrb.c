/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 07:21:36 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 08:24:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrb(int *stackB, int ndigitsB)
{
	int	i;
	int	*temp;

	i = ndigitsB - 1;
	temp = (int *)malloc(sizeof(int));
	*temp = stackB[ndigitsB - 1];
	while (i > 0)
	{
		stackB[i] = stackB[i - 1];
		i--;
	}
	stackB[0] = *temp;
	free(temp);
}
