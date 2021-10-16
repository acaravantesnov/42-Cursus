/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:18:48 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 08:24:37 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(int	*stackA, int *stackB, int ndigitsA, int ndigitsB)
{
	int	*temp;

	temp = ft_realloc(stackA, ndigitsA, ndigitsA + 1);
	temp[ndigitsA + 1] = stackB[ndigitsB];
	if (ndigitsB == 0)
		stackB = NULL;
	free(temp);
}
