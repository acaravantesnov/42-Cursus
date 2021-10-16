/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:12:41 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/10 15:07:42 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int i;
	int minus_count;
	int devolveri;

	i = 0;
	minus_count = 0;
	devolveri = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
		(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		devolveri = devolveri * 10;
		devolveri = devolveri + (str[i] - 48);
		i++;
	}
	if (minus_count % 2 != 0)
		devolveri *= (-1);
	return (devolveri);
}
