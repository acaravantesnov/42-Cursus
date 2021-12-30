/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:24:01 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/30 21:12:17 by acaravan         ###   ########.fr       */
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

void	while1(long *copy, long *copy_sa, long *sA, int *ndigitsA)
{
	int	i;

	i = 0;
	while (i < ndigitsA[0])
	{
		copy[i] = sA[i];
		copy_sa[i] = sA[i];
		i++;
	}
}

void	while2(long *copy, long *copy_sa, long *sA, int *ndigitsA)
{
	int	i;
	int	j;

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
}

void	while3(long *sA, long *sB, int *ndigitsA, int *ndigitsB)
{
	int	max_num;
	int	max_bits;
	int	iterator[2];

	max_num = ndigitsA[1] - 1;
	max_bits = 0;
	iterator[0] = 0;
	iterator[1] = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	while (iterator[0] < max_bits)
	{
		iterator[1] = 0;
		while (iterator[1] < ndigitsA[0])
		{
			if (((sA[0] >> iterator[0]) & 1) == 1)
				ra(sA, ndigitsA);
			else
				pb(sA, sB, ndigitsA, ndigitsB);
			++iterator[1];
		}
		while (*ndigitsB != 0)
			pa(sA, sB, ndigitsA, ndigitsB);
		++iterator[0];
	}
}

void	sort_big_stack(long *sA, long *sB, int *ndigitsA, int *ndigitsB)
{
	long	*copy;
	long	*copy_sa;

	copy = (long *)malloc(ndigitsA[0] * sizeof(long));
	copy_sa = (long *)malloc(ndigitsA[0] * sizeof(long));
	while1(copy, copy_sa, sA, ndigitsA);
	selectionsort(copy, ndigitsA);
	while2(copy, copy_sa, sA, ndigitsA);
	free(copy);
	free(copy_sa);
	while3(sA, sB, ndigitsA, ndigitsB);
}
