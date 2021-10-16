/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:07:19 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/07 12:58:24 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	str2[ft_strlen(str)];

	i = 0;
	while (str[i] != '\0')
	{
		if (((i == 0) || (str[i - 1] == 32) || ((str[i - 1] < 48) ||
		(str[i - 1] > 122) || ((str[i - 1] > 90) && (str[i - 1] < 97)) ||
		((str[i - 1] > 57) && (str[i - 1] < 65)))) && ((str[i] > 96) &&
		(str[i] < 123)))
		{
			str2[i] = str[i] - 32;
			str[i] = str2[i];
		}
		else if (((str[i] > 64) && (str[i] < 91)) && ((str[i - 1] > 96) &&
		(str[i - 1] < 123)))
		{
			str2[i] = str[i] + 32;
			str[i] = str2[i];
		}
		i++;
	}
	return (str);
}

int		ft_strlen(char *str)
{
	int i;
	int elementos;

	i = 0;
	elementos = 0;
	while (str[i] != '\0')
	{
		i++;
		elementos++;
	}
	return (elementos);
}
