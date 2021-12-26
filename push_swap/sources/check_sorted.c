/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:54:39 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 21:39:53 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_sorted(long *stackA, int *ndigitsA)
{
	int i;
	int j;
	long max;

	i = 1;
	j = 0;
	max = stackA[0];
	while (i < *ndigitsA)
	{
		if (stackA[i] > max)
		{
			max = stackA[i];
			j++;
		}
		i++;
	}
	if (j == *ndigitsA - 1)
		return (0);
	return (-1);
}
