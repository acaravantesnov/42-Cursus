/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:33:59 by acaravan          #+#    #+#             */
/*   Updated: 2020/11/30 20:52:23 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	alphabet[26];
	int		i;
	int		x;

	i = 0;
	x = 97;
	while (i < 26)
	{
		alphabet[i] = x;
		i++;
		x++;
	}
	i = 0;
	while (i < 26)
	{
		write(1, &alphabet[i], 1);
		i++;
	}
}
