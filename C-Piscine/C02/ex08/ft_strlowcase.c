/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:00:10 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/02 21:06:13 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strlowcase(char *str)
{
	int		i;
	char	str2[ft_strlen(str)];

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 64) && (str[i] < 91))
		{
			str2[i] = str[i] + 32;
			str[i] = str2[i];
		}
		i++;
	}
	return (str);
}
