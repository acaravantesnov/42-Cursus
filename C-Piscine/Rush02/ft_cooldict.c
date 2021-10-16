/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cooldict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:06:50 by acrucesp          #+#    #+#             */
/*   Updated: 2020/12/13 20:51:37 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_dictlen(char *dict)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 1;
	while (dict[i])
	{
		if (dict[i] == '\n')
		{
			if (k == 0)
				j++;
			k = 1;
		}
		if (dict[i] != '\n')
			k = 0;
		i++;
	}
	return (j);
}

char	**ft_takemem(int dictlen)
{
	char	**array;
	int		i;

	i = 0;
	if (!(array = (char **)malloc(sizeof(char *) * dictlen)))
		return (0);
	while (i < dictlen)
	{
		if (!(array[i] = (char *)malloc(sizeof(char) * 256)))
			return (0);
		i++;
	}
	return (array);
}

char	**ft_cooldict(char *dict)
{
	char	**array;
	int		dictlen;
	int		i;
	int		j;
	int		k;

	dictlen = ft_dictlen(dict);
	array = ft_takemem(dictlen);
	if (array == NULL)
		write(1, "Allocation Error\n", 17);
	i = 0;
	k = 0;
	while (i < dictlen)
	{
		j = 0;
		while (dict[k] != 10)
		{
			array[i][j] = dict[k];
			k++;
			j++;
		}
		i++;
		k++;
	}
	return (array);
}
