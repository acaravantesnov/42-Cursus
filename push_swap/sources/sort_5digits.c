/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:03:00 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 21:44:08 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_5digits(long *sA, long *sB, int *ndigitsA, int *ndigitsB)
{
	pb(sA, sB, ndigitsA, ndigitsB);
	pb(sA, sB, ndigitsA, ndigitsB);
	sort_3digits(sA, sB);
}
