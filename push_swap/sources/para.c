/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   para.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:15:42 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/30 21:16:28 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	para(long *sA, long *sB, int *ndigitsA, int *ndigitsB)
{
	pa(sA, sB, ndigitsA, ndigitsB);
	ra(sA, ndigitsA);
}
