/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:43:16 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/03 14:51:31 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int i = 0, j = 0, k = 0, count1 = 0, count2 = 0;
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		j = 0;
		count1 = 0;
		while (j < i)
		{
			if (argv[1][i] == argv[1][j])
				count1++;
			j++;
		}
		if (count1 == 0)
			write(1, &argv[1][i], 1);
		i++;
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		j = 0;
		k = 0;
		count1 = 0;
		count2 = 0;
		while(argv[1][j] != '\0')
		{
			if (argv[1][j] == argv[2][i])
				count1++;
			j++;
		}
		while (k < i)
		{
			if (argv[2][i] == argv[2][k])
				count2++;
			k++;
		}
		if ((count1 == 0) && (count2 == 0))
			write(1, &argv[2][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}