/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:34:37 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/08 16:32:34 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
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

int	while1(char *s1, char *s2)
{
	int i;

	i = 0;
	while (i < ft_strlen(s1))
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
		{
			return (1);
			i = ft_strlen(s1);
		}
		else if ((unsigned char)s2[i] > (unsigned char)s1[i])
		{
			return (-1);
			i = ft_strlen(s1);
		}
		else if ((unsigned char)s1[i] == (unsigned char)s2[i])
		{
			i++;
		}
	}
	return (0);
}

int	while2(char *s1, char *s2)
{
	int i;

	i = 0;
	while (i < ft_strlen(s2))
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
		{
			return (1);
			i = ft_strlen(s2);
		}
		else if ((unsigned char)s2[i] > (unsigned char)s1[i])
		{
			return (-1);
			i = ft_strlen(s2);
		}
		else if ((unsigned char)s1[i] == (unsigned char)s2[i])
		{
			i++;
		}
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int x;
	int y;

	if (ft_strlen(s1) > ft_strlen(s2))
	{
		x = while1(s1, s2);
		return (x);
	}
	else
	{
		y = while2(s1, s2);
		return (y);
	}
	return (0);
}
