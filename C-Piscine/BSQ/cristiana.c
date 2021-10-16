/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cristiana.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:01:14 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/15 16:14:03 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_min(int j, int k, int n)
{
	int min;

	if (j <= k)
	{
		min = j;
	}
	else
	{
		min = k;
	}
	if (min <= n)
	{
		return (min);
	}
	else 
	{
		return (n);
	}
}


void    cristiana(int ml[50][50], int alto, int largo)
{
    int i;
    int j;
    int min;

    i = 1;
    j = 1;
    while(i < alto)
    {
        j = 1;
        while(j < largo)
        {
            if (ml[i][j] != 0)
            {
                min = get_min(ml[i - 1][j], ml[i][j - 1], ml[i - 1][j - 1]);
                ml[i][j] = min + 1;
            }
            else
                ml[i][j] = 0;
            j++;
        }
        i++;
    }

}

int main(void)
{
    int ml[50][50];
	int i,j;
	i = 0;
	j = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			ml[i][j] = 1;
			j++;
		}
		i++;
	}
    cristiana(ml, 50, 50);
	i = 0;
	j = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			printf("%i", ml[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
