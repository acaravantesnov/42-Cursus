/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 07:14:56 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 14:19:12 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(long *stackA, int ndigitsA)
{
	int	i;
	long	*temp;

	i = ndigitsA - 1;
	temp = (long *)malloc(sizeof(long));
	*temp = stackA[ndigitsA - 1];
	while (i > 0)
	{
		stackA[i] = stackA[i - 1];
		i--;
	}
	stackA[0] = *temp;
	free(temp);
	write(1, "rra\n", 4);
}
