/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:42:52 by mmunoz-f          #+#    #+#             */
/*   Updated: 2020/12/14 20:10:33 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		**ft_integerarray(int lines, int cols)
{
	int i;
	int **array;

	i = 0;
	if(!(array = (int **)malloc(sizeof(int *) * lines)))
	{
		write(1, "Memory allocation error", 22);
		exit(-1);
	}
	while (i < lines)
	{
		if(!(array[i] = (int *)malloc(sizeof(int) * col)))
		{
			write(1, "Memory allocation error", 22);
			exit(-1);
		}
		i++;
	}
	return (array);
}

int		**ft_zerone(char **table, char *key, int *dim)
{
	int i;
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
