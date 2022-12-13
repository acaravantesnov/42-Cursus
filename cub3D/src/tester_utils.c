/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:32:19 by airodrig          #+#    #+#             */
/*   Updated: 2022/11/28 23:31:01 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

const char	*print_place(int place)
{
	const char	*id[6] = {"NO", "SO", "EA", "WE", "F", "C"};

	return (id[place]);
}

void	print_textures(t_texture *list)
{
	t_texture	*aux;

	aux = list;
	while (aux)
	{
		printf("The place is %s\n", print_place(aux->place));
		if (aux->path)
			printf("The path to the texture is %s\n", aux->path);
		else
			printf("The color is %d\n", aux->color);
		aux = aux->next;
	}
}

void	print_map(char **matrix)
{
	int	i;

	i = -1;
	while (matrix && matrix[++i] && matrix[i][0])
		printf("%s\n", matrix[i]);
}
