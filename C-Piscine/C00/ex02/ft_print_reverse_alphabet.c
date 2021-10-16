/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:57:01 by acaravan          #+#    #+#             */
/*   Updated: 2020/11/30 20:53:14 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	reverse_alphabet[26];
	int		i;
	int		x;

	i = 0;
	x = 122;
	while (i < 26)
	{
		reverse_alphabet[i] = x;
		i++;
		x--;
	}
	i = 0;
	while (i < 26)
	{
		write(1, &reverse_alphabet[i], 1);
		i++;
	}
}
