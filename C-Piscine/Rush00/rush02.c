/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:23:19 by acaravan          #+#    #+#             */
/*   Updated: 2020/11/29 15:51:14 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int rw;
	int cl;

	rw = 1;
	cl = 1;
	while (rw <= y)
	{
		while (cl <= x)
		{
			if ((rw == 1 && cl == 1) || (rw == 1 && cl == x))
				ft_putchar(65);
			else if ((rw == y && cl == 1) || (rw == y && cl == x))
				ft_putchar(67);
			else if (((rw == 1 || rw == y) && cl > 1 && cl < x) ||
			((cl == 1 || cl == x) && rw > 1 && rw < y))
				ft_putchar(66);
			else
				ft_putchar(32);
			cl++;
		}
		ft_putchar('\n');
		cl = 1;
		rw++;
	}
}
