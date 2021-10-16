/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:03:17 by acaravan          #+#    #+#             */
/*   Updated: 2020/11/30 20:27:26 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	digits[10];
	int		i;
	int		x;

	i = 0;
	x = 48;
	while (i < 10)
	{
		digits[i] = x;
		i++;
		x++;
	}
	i = 0;
	while (i < 10)
	{
		write(1, &digits[i], 1);
		i++;
	}
}
