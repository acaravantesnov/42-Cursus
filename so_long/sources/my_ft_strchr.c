/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ft_strchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 02:52:45 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/23 04:02:40 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*freeandreturnaux(char *temp, char *aux)
{
	free(temp);
	return (aux);
}

char	*my_ft_strchr(char *s, int c)
{
	int		i;
	int		j;
	int		k;
	char	*temp;
	char	*aux;

	i = 0;
	j = 0;
	k = 0;
	aux = NULL;
	temp = ft_strdup(s);
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	while ((temp[k] != '\0') && (j < i))
	{
		if (temp[k] == c)
			j++;
		k++;
	}
	aux = temp + k - 1;
	return (freeandreturnaux(temp, aux));
}
