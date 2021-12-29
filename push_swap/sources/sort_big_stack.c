/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:24:01 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/29 04:26:36 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	selectionsort(long *array, int *size)
{
	long	i;
	long	j;
	long	count;
	long	temp;

	i = 0;
	j = 0;
	while (i < size[0])
	{
		j = i + 1;
		while (j < size[0])
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sort_big_stack(long *sA, long *sB, int *ndigitsA, int *ndigitsB)
{
	int		max_num;
	int		max_bits;
	int		i;
	int		j;
	int		num;
	long	*copy;
	long	*copy_sa;

	copy = (long *)malloc(ndigitsA[0] * sizeof(long));
	copy_sa = (long *)malloc(ndigitsA[0] * sizeof(long));
	i = 0;
	while (i < ndigitsA[0])
	{
		copy[i] = sA[i];
		copy_sa[i] = sA[i];
		i++;
	}
	selectionsort(copy, ndigitsA);
	i = 0;
	j = 0;
	while (i < ndigitsA[1])
	{
		j = 0;
		while (j < ndigitsA[0])
		{
			if (copy_sa[i] == copy[j])
				sA[i] = j;
			++j;
		}
		++i;
	}
	max_num = ndigitsA[1] - 1;
	max_bits = 0;
	i = 0;
	j = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		j = 0;
		while (j < ndigitsA[0])
		{
			num = sA[0];
			if (((num >> i) & 1) == 1)
				ra(sA, ndigitsA);
			else
				pb(sA, sB, ndigitsA, ndigitsB);
			++j;
		}
		while (*ndigitsB != 0)
			pa(sA, sB, ndigitsA, ndigitsB);
		++i;
	}
}
