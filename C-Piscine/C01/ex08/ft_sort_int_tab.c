/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:56:27 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/10 16:10:58 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;
	int minPos;

	i = 0;
	while (i < size - 1)
	{
		minPos = i;
		while (j < size)
		{
			j = i + 1;
			if (tab[j] < tab[minPos])
				minPos = j;
			j++;
		}
		temp = tab[i];
		tab[i] = tab[minPos];
		tab[minPos] = temp;
		i++;
	}
}
