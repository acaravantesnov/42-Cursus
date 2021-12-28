/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:03:00 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/28 18:49:41 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	max(long *sA, int *ndigitsA)
{
	int i;
	long maximum;

	i = 1;
	if (sA[0])
		maximum = sA[0];
	while (i < ndigitsA[1])
	{
		if (sA[i] > maximum)
			maximum = sA[i];
		i++;
	}
	return (maximum);
}

void	sort_5digits(long *sA, long *sB, int *ndigitsA, int *ndigitsB)
{
	pb(sA, sB, ndigitsA, ndigitsB);
	pb(sA, sB, ndigitsA, ndigitsB);
	sort_3digits(sA, sB, ndigitsA);
	long	max_in_A;
	max_in_A = max(sA, ndigitsA);
	while (*ndigitsB != 0)
	{
		if (sB[0] < sA[0])
		{
			pa(sA, sB, ndigitsA, ndigitsB);
			rra(sA, ndigitsA);	
		}
		else if ((sB[0] > sA[0]) && (sB[0] > max_in_A) && (sA[ndigitsA[1] - 1] == max_in_A))
		{
			pa(sA, sB, ndigitsA, ndigitsB);
			ra(sA, ndigitsA);
		}
		else
			ra(sA, ndigitsA);
	}
	while (sA[0] > sA[ndigitsA[1] - 1])
		ra(sA, ndigitsA);
}
