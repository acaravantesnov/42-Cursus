/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:37:13 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/02 00:57:53 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;

	if (argc != 3)
		write (1, "\n", 1);
	else
	{
		while (argv[1][i] != '\0')
		{
			j = 0;
			while (argv[2][j] != '\0')
			{
				if (argv[1][i] == argv[2][j])
				{
					k = 0;
					count = 0;
					while (k <= i)
					{
						if (argv[1][i] == argv[1][k])
							count++;
						k++;
					}
					if (count == 1)
						write(1, &argv[1][i], 1);
					break;
				}
				j++;
			}
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}