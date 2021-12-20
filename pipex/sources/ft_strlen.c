/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:23:49 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/19 20:27:18 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

size_t	ft_strlen(char *str)
{
	int		i;
	size_t	elementos;

	i = 0;
	elementos = 0;
	while (str[i] != '\0')
	{
		i++;
		elementos++;
	}
	return (elementos);
}