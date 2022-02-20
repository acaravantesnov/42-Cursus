/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:43:26 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/19 17:05:45 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	ft_strlen(char *s)
{
	int len;

	len = 0;
	while(s[len])
		len++;
	return (len);
}

char	ft_toupper(char c)
{
	if ((c >= 97) && (c <= 122))
		c -= 32;
	return (c);
}

int	main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (i < argc)
		{
			j = 0;
			while (j < ft_strlen(argv[i]))
			{
				std::cout << ft_toupper(argv[i][j]);
				j++;
			}
			i++; 
		}
	}
	std::cout << std::endl;
	return (0);
}
