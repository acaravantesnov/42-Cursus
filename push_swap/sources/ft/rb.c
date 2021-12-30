/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 05:58:17 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/29 03:42:07 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rb(long	*stackB, int *ndigitsB)
{
	int		i;
	long	*temp;

	i = 0;
	temp = (long *)malloc(sizeof(long));
	*temp = stackB[0];
	while (i < *ndigitsB)
	{
		stackB[i] = stackB[i + 1];
		i++;
	}
	stackB[*ndigitsB - 1] = *temp;
	free(temp);
	write(1, "rb\n", 3);
}
