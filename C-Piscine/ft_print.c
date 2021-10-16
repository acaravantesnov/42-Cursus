/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmirayo- <mmirayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:04:16 by mmirayo-          #+#    #+#             */
/*   Updated: 2020/12/15 20:30:36 by mmirayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char *keys)
{
	write(1, &keys[2], 1);
}

char		ft_print(int *solution, char *keys, char **table)
{
	int tam;
	int x;
	int y;
	int y1;
	int x1;

	tam = solution[0];
	x = solution[1];
	y = solution[2];
	x1 = x - solution[0];
	y1 = y - solution[0];

	while (y1 < y)
	{
		ft_putchar(&keys[2]);
		y1++;
		while (x1 < x)
		{
			ft_putchar(&keys[2]);
			x++;
		}
	}
	x = solution[1];
	y = solution[2];
	return(0);
}

int		main(void)
{
	int *solution;
	char *keys;
	char **table;

	solution[3]={3,3,5}
	key[2]="ax"
	table[7][7];
	ft_print(*solution, *keys, **table);
	return (0);
}