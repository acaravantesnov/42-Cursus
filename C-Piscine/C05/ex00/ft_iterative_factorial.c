/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:34:01 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/13 13:24:46 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int result;

	i = 0;
	result = 1;
	if (nb < 0)
		return (0);
	while (i < nb)
	{
		result = result * (nb - i);
		i++;
	}
	return (result);
}
