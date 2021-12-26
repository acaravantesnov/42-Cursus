/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 05:51:25 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 18:19:13 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void ra(long *stackA, int ndigitsA)
{
	int i;
	long *temp;

	i = 0;
	temp = (long *)malloc(sizeof(long));
	*temp = stackA[0];
	while (i < ndigitsA)
	{
		stackA[i] = stackA[i + 1];
		i++;
	}
	stackA[ndigitsA - 1] = *temp;
	free(temp);
	write(1, "ra\n", 3);
}
