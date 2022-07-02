/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:24:02 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/22 12:31:24 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *str)
{
	int		i;
	size_t	elementos;

	i = 0;
	elementos = 0;
	while (str && str[i] != '\0')
	{
		i++;
		elementos++;
	}
	return (elementos);
}

size_t	ft_2strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

size_t	ft_3strlen(char ***str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}
