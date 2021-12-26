/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:50:52 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 12:51:27 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_isnumber(char *num)
{
	int i;
	int minus;

	i = 0;
	minus = 0;
	while (num[i])
	{
		if (num[i] == 45)
			minus++;
		else if (ft_isdigit(num[i]) == 0)
			return (0);
		i++;
	}
	if (minus > 1)
		return (0);
	return (1);
}
