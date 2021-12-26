/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numeric_limits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:53:08 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 12:53:22 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void check_numeric_limits(long *stackA, int ndigitsA)
{
	int i;

	i = 0;
	while (i < ndigitsA)
	{
		if ((stackA[i] > 2147483647) || (stackA[i] < -2147483648))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
}
