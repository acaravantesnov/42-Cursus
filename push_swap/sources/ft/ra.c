/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 05:51:25 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 08:24:39 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(int	*stackA, int ndigitsA)
{
	int	i;
	int	*temp;

	i = 0;
	temp = (int *)malloc(sizeof(int));
	*temp = stackA[0];
	while (i < ndigitsA)
	{
		stackA[i] = stackA[i + 1];
		i++;
	}
	stackA[ndigitsA - 1] = *temp;
	free(temp);
}
