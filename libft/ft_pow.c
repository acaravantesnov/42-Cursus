/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 00:48:55 by acaravan          #+#    #+#             */
/*   Updated: 2021/05/04 17:32:46 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int base, int exponent)
{
	int	i;
	int	extra;

	i = 0;
	extra = 1;
	while (i < exponent)
	{
		extra *= base;
		i++;
	}
	return (extra);
}
