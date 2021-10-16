/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:42:52 by mmunoz-f          #+#    #+#             */
/*   Updated: 2020/12/15 20:24:24 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		count_h(char *arr, int init)
{
	int i;
	int c;

	i = 0;
	c = init + 1;
	while (arr[c])
	{
		if (arr[c] == '\n')
			i++;
		c++;
	}
	return (i);
}

int		count_wh(char *arr, int init, int *n)
{
	int c;
	int w;
	int i;

	w = 0;
	i = count_h(arr, init);
	c = init + 1;
	while (arr[c])
	{
		if (arr[c] != '\n')
		{
			w++;
		}
		else if (arr[c] == '\n')
			break ;
		c++;
	}
	if (n[0] != i)
		w = 0;
	return (w);
}

int		**ft_integerarray(int lines, int cols)
{
	int i;
	int **array;

	i = 0;
	if (!(array = (int **)malloc(sizeof(int *) * lines)))
	{
		write(1, "Memory allocation error", 22);
		exit(-1);
	}
	while (i < lines)
	{
		if (!(array[i] = (int *)malloc(sizeof(int) * cols)))
		{
			write(1, "Memory allocation error", 22);
			exit(-1);
		}
		i++;
	}
	return (array);
}

int		**ft_zerone(char **table, char *keys, int *dim)
{
	int i;
	int j;
	int **array;

	i = 0;
	j = 0;
	array = ft_integerarray(dim[0], dim[1]);
	while (i < dim[0])
	{
		if (j == dim[1])
		{
			i++;
			j = 0;
			continue;
		}
		else if (table[i][j] == keys[0])
			array[i][j] = 1;
		else if (table[i][j] == keys[1])
			array[i][j] = 0;
		j++;
	}
	return (array);
}
