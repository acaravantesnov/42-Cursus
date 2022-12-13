/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:11:35 by airodrig          #+#    #+#             */
/*   Updated: 2022/05/05 18:28:11 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_strings(char **string)
{
	int	i;

	i = -1;
	while (string[++i] && string[i][0])
		printf("%s\n", string[i]);
}
