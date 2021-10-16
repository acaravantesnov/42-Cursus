/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:35:58 by manmarti          #+#    #+#             */
/*   Updated: 2020/12/15 20:33:08 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_merror.h"

int		error_wh(char *arr, int *n, int init)
{
	int i;
	int c;

	c = init + 1;
	i = 0;
	n[1] = count_wh(arr, init, n);
	while (arr[c])
	{
		if (arr[c] != '\n')
			i++;
		if (arr[c] == '\n')
		{
			if (i != n[1])
			{
				n[1] = 0;
				break ;
			}
			else
				i = 0;
		}
		c++;
	}
	return (n[1]);
}

int			ft_divide(char **table, char *buff, int *var, int *dim)
{
	while (buff[var[0]] != '\0' && table)
	{
		if (!(table[var[1]] = malloc(dim[1] * sizeof(char *))))
		{
			write(1, "Memory allocation error", 22);
			exit(-1);
		}
		while (buff[var[0]] != '\n' && buff[var[0]] && table[var[1]])
		{
			table[var[1]][var[2]] = buff[var[0]];
			var[2]++;
			var[0]++;
		}
		var[2] = 0;
		var[1]++;
		var[0]++;
	}
}

int		ft_compr_table(char **table, int *keys, char *dim)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < dim[0])
	{
		while (j < dim[1])
		{
			if (table[i][j] != keys[1] && table[i][j] != keys[0])
			{
				write(1, "map error\n", 10);
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

char	**ft_divide_text(char *buff, char *keys, int *dim)
{
	char	**table;
	int		var[3];

	var[0] = dim[2];
	var[1] = 0;
	var[2] = 0;
	if (!(table = malloc(dim[0] * sizeof(char *))))
	{
		write(1, "Memory allocation error", 22);
		exit(-1);
	}
	if ((dim[1] = error_wh(buff, dim, dim[2])))
		ft_divide(table, buff, var, dim);
	else
	{
		write(1, "map error\n", 10);
		return (0);
	}
	if (ft_compr_table(table, keys, dim))
		return (ft_zerone(table, keys, dim));
	return (0);
}

int		ft_indraw(char *buff, char *keys, int *dim)
{
	int i;

	i = 0;
	while (buff[i] != '\n')
		i++;
	keys[0] = buff[i - 3];
	keys[1] = buff[i - 2];
	keys[2] = buff[i - 1];
	if (keys[0] == keys[1] || keys[0] == keys[2] || keys[1] == keys[2])
		return (0);
	dim[2] = i + 1;
	i = 0;
	dim[0] = 0;
	while (i != keys[0]) //error (mala comparación y falta caracteres imprimibles)
	{
		if (buff[i] >= '0' && buff[i] <= '9')
			dim[0] = (dim[0] * 10) + (int)(buff[i] - '0');
		i++;
	}
	if (dim[0] == 0)
		return (0);
	return (1);
}

int		**ft_gestmp(char *buff, char *keys, int *dim)
{
	int **table;

	if (!(ft_indraw(buff, keys, dim)))
	{
		write(1, "map error\n", 10);
		return (0);
	}
	if ((table = ft_divide_text(buff, keys, dim)))
		free(buff);
	return (0);
}
