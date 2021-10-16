/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:13:21 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 08:24:45 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ss(int *stackA, int *stackB, int ndigitsA, int ndigitsB)
{
	sa(stackA, ndigitsA);
	sb(stackB, ndigitsB);
}
