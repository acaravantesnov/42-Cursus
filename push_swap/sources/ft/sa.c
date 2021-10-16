/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:11:18 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 08:24:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(int *stackA, int ndigitsA)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int));
	if (ndigitsA > 1)
	{
		temp[0] = stackA[ndigitsA - 1];
		stackA[ndigitsA - 1] = stackA[ndigitsA - 2];
		stackA[ndigitsA - 2] = temp[0];
	}
	free(temp);
}
