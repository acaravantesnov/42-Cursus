/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 07:23:17 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 08:24:42 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrr(int *stackA, int *stackB, int ndigitsA, int ndigitsB)
{
	rra(stackA, ndigitsA);
	rrb(stackB, ndigitsB);
}
