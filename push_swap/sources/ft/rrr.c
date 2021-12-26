/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 07:23:17 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 12:11:45 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrr(long *stackA, long *stackB, int ndigitsA, int ndigitsB)
{
	rra(stackA, ndigitsA);
	rrb(stackB, ndigitsB);
}
