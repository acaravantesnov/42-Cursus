/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:48:06 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/14 15:25:27 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int		count;

	if (nb == 0)
		return (0);
	else if (nb == 1)
		return (1);
	count = 1;
	while (count < 46341)
	{
		if ((count * count) == nb)
			return (count);
		else
			count++;
	}
	return (0);
}
