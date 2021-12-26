/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:03:00 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 19:13:54 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_5digits(long *sA, long *sB)
{
	int *fivedigits;
	int *zerodigits;

	*fivedigits = 5;
	*zerodigits = 0;
	pb(sA, sB, fivedigits, zerodigits);
	pb(sA, sB, fivedigits, zerodigits);
	sort_3digits(sA, sB);
}
