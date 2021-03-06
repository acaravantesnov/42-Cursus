/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:01:54 by acaravan          #+#    #+#             */
/*   Updated: 2022/01/05 14:19:46 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3digits(long *sA, int *ndigitsA)
{
	if ((sA[0] > sA[1]) && (sA[1] < sA[2]) && (sA[0] < sA[2]))
		sa(sA, ndigitsA);
	if ((sA[0] > sA[1]) && (sA[1] > sA[2]) && (sA[0] > sA[2]))
	{
		sa(sA, ndigitsA);
		rra(sA, ndigitsA);
	}
	if ((sA[0] > sA[1]) && (sA[1] < sA[2]) && (sA[0] > sA[2]))
		ra(sA, ndigitsA);
	if ((sA[0] < sA[1]) && (sA[1] > sA[2]) && (sA[0] < sA[2]))
	{
		sa(sA, ndigitsA);
		ra(sA, ndigitsA);
	}
	if ((sA[0] < sA[1]) && (sA[1] > sA[2]) && (sA[0] > sA[2]))
		rra(sA, ndigitsA);
}
