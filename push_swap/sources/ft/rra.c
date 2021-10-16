/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 07:14:56 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 08:24:41 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(int *stackA, int ndigitsA)
{
	int	i;
	int	*temp;

	i = ndigitsA - 1;
	temp = (int *)malloc(sizeof(int));
	*temp = stackA[ndigitsA - 1];
	while (i > 0)
	{
		stackA[i] = stackA[i - 1];
		i--;
	}
	stackA[0] = *temp;
	free(temp);
}
