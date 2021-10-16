/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slicer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:39:12 by manmarti          #+#    #+#             */
/*   Updated: 2020/12/13 19:35:53 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slicer.h"
#include <stdlib.h>

char	**ft_slicer(char *argv)
{
	int		ar[5];
	char	**tab;

	ar[0] = 0;
	ar[1] = 0;
	ar[4] = 1;
	if (ft_strlen(argv) % 3 == 0)
		ar[4]--;
	ar[3] = (ft_strlen(argv));
	tab = malloc(sizeof(char *) * ((ar[3] / 3) + ar[4]));
	while (ar[0] < ((ar[3] / 3) + ar[4]))
	{
		tab[ar[0]] = malloc(sizeof(char) * 3);
		ar[0]++;
	}
	ar[0] = 0;
	return (ft_tab(ar, tab, argv));
}

char	**ft_tab(int *ar, char **tab, char *argv)
{
	while (ar[0] < ((ar[3] / 3) + ar[4]))
	{
		ar[2] = 0;
		if (ar[3] % 3 != 0 && ar[0] == 0)
		{
			ar[1] = ft_zero_adder(tab, argv);
			ar[0]++;
		}
		while (ar[2] < 3 && ar[1] < ar[3])
		{
			tab[ar[0]][ar[2]] = argv[ar[1]];
			ar[2]++;
			ar[1]++;
		}
		ar[0]++;
	}
	return (tab);
}

int		ft_zero_adder(char **tab, char *argv)
{
	int k;
	int r;

	r = 0;
	k = 0;
	if (ft_strlen(argv) % 3 == 1)
	{
		tab[0][r] = '0';
		tab[0][r + 1] = '0';
		tab[0][r + 2] = argv[0];
		k++;
	}
	if (ft_strlen(argv) % 3 == 2)
	{
		tab[0][r] = '0';
		tab[0][r + 1] = argv[0];
		tab[0][r + 2] = argv[1];
		k = k + 2;
	}
	return (k);
}

int		ft_strlen(char *argv)
{
	int i;

	i = 0;
	while (argv[i] != '\0')
	{
		i++;
	}
	return (i);
}
