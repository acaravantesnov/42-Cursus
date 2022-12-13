/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:04:13 by airodrig          #+#    #+#             */
/*   Updated: 2022/11/29 14:01:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	getsize(char **ptr)
{
	int	i;

	i = -1;
	while (ptr && ptr[++i] && ptr[i][0])
		;
	return (i);
}

int	atoi_cub(const char *str)
{
	unsigned long long	nb;
	int					cnt;

	nb = 0;
	cnt = 0;
	if (str[cnt] == '-')
		print_error("No negative numbers allowed in colors", false);
	if (str[cnt] == '+')
		cnt++;
	while (str[cnt] && str[cnt] >= '0' && str[cnt] <= '9')
		nb = nb * 10 + str[cnt++] - '0';
	if (str[cnt] && (str[cnt] <= '0' || str[cnt] >= '9'))
		print_error("Invalid color", false);
	if (nb > 255)
		print_error("Number is too big", false);
	return (nb);
}

int	getrgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	check_textures(t_texture *textures)
{
	int			i;
	t_texture	*aux;

	i = 0;
	aux = textures;
	while (aux)
	{
		i++;
		if (aux->path && !check_name(aux->path, ".xpm"))
			print_error("Invalid texture", false);
		aux = aux->next;
	}
	if (i != 6)
		print_error("Invalid number of textures", false);
}
