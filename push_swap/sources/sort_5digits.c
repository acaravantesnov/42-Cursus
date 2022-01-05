/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:03:00 by acaravan          #+#    #+#             */
/*   Updated: 2022/01/05 14:20:20 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	first(long *sA, long *sB, int *ndigitsA, int *ndigitsB)
{
	if (sB[0] < sA[0])
		pa(sA, sB, ndigitsA, ndigitsB);
	else if ((sB[0] > sA[0]) && (sB[0] < sA[1]))
	{
		ra(sA, ndigitsA);
		pa(sA, sB, ndigitsA, ndigitsB);
		rra(sA, ndigitsA);
	}
	else if ((sB[0] > sA[1]) && (sB[0] < sA[2]))
	{
		rra(sA, ndigitsA);
		pa(sA, sB, ndigitsA, ndigitsB);
		rra(sA, ndigitsA);
		rra(sA, ndigitsA);
	}
	else if (sB[0] > sA[2])
	{
		pa(sA, sB, ndigitsA, ndigitsB);
		ra(sA, ndigitsA);
	}
}

void	rax2(long *sA, int *ndigitsA)
{
	ra(sA, ndigitsA);
	ra(sA, ndigitsA);
}

void	rrax2(long *sA, int *ndigitsA)
{
	rra(sA, ndigitsA);
	rra(sA, ndigitsA);
}

void	second(long *sA, long *sB, int *ndigitsA, int *ndigitsB)
{
	if (sB[0] < sA[0])
		pa(sA, sB, ndigitsA, ndigitsB);
	else if ((sB[0] > sA[0]) && (sB[0] < sA[1]))
	{
		ra(sA, ndigitsA);
		pa(sA, sB, ndigitsA, ndigitsB);
		rra(sA, ndigitsA);
	}
	else if ((sB[0] > sA[1]) && (sB[0] < sA[2]))
	{
		ra(sA, ndigitsA);
		pa(sA, sB, ndigitsA, ndigitsB);
		sa(sA, ndigitsA);
		rra(sA, ndigitsA);
	}
	else if ((sB[0] > sA[2]) && (sB[0] < sA[3]))
	{
		rra(sA, ndigitsA);
		pa(sA, sB, ndigitsA, ndigitsB);
		rax2(sA, ndigitsA);
	}
	else if (sB[0] > sA[3])
		para(sA, sB, ndigitsA, ndigitsB);
}

void	sort_5digits(long *sA, long *sB, int *ndigitsA, int *ndigitsB)
{
	pb(sA, sB, ndigitsA, ndigitsB);
	pb(sA, sB, ndigitsA, ndigitsB);
	sort_3digits(sA, ndigitsA);
	while (*ndigitsB != 0)
	{
		if (ndigitsA[1] == 3)
			first(sA, sB, ndigitsA, ndigitsB);
		else if (ndigitsA[1] == 4)
			second(sA, sB, ndigitsA, ndigitsB);
	}
}
