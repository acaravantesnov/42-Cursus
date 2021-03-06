/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_repeated_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:52:16 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/30 22:13:13 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_repeated_numbers(long *stackA, int ndigitsA)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ndigitsA)
	{
		j = 0;
		while (j < ndigitsA)
		{
			if ((stackA[i] == stackA[j]) && (i != j))
			{
				write(1, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
