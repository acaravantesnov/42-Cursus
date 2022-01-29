/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:28:54 by acaravan          #+#    #+#             */
/*   Updated: 2022/01/29 02:46:30 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_printf(const char *input, ...)
{
	int		i;
	int		ret;
	va_list	ap;

	i = 0;
	ret = 0;
	va_start(ap, input);
	ret = ft_printfext(i, ret, input, ap);
	va_end(ap);
	return (ret);
}
