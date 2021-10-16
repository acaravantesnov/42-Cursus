/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gerror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:14:04 by manmarti          #+#    #+#             */
/*   Updated: 2020/12/13 16:01:15 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_gerror.h"

int		ft_gerror(char **argv, int argc)
{
	if (argc == 2)
	{
		if (ft_arg_error(argv[1]) == 1)
			return (1);
	}
	else if (argc == 3)
	{
		if (ft_arg_error(argv[2]) == 1)
			return (2);
	}
	else
	{
		ft_puterror();
		return (0);
	}
	return (0);
}

int		ft_arg_error(char *str)
{
	int		n;

	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] < '0' || str[n] > '9')
		{
			ft_puterror();
			return (0);
		}
		n++;
		if (n > 10)
		{
			ft_puterror();
			return (0);
		}
	}
	return (ft_conv(str));
}

int		ft_conv(char *str)
{
	long long unsigned int res;

	res = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	if (!(res <= 4294967295))
	{
		ft_puterror();
		return (0);
	}
	return (1);
}

void	ft_puterror(void)
{
	write(1, "Error\n", 6);
}
