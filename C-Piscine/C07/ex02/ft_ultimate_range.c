/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 11:28:34 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/13 11:55:13 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

    range = malloc(sizeof(int *) * 4);
    while(i < 4)
    {
        range[i] = malloc(sizeof(int *) * 4);
        i++;
    }
}

int main()
{
	int **x;
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			x[i][j] = i + j;
			j++;
		}
		i++;
	}
	int y = ft_ultimate_range(x,1,1);
	printf("%i", y);
}
