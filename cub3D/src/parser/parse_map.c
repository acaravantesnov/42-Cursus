/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:00:57 by airodrig          #+#    #+#             */
/*   Updated: 2022/08/08 19:35:15 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_map(char *line, t_file *file)
{
	int			i;
	char		**aux_matrix;
	const int	matrix_lines = getsize(file->map);

	i = -1;
	if (!matrix_lines || !file->map)
	{
		file->map = ft_calloc(2, sizeof(char *));
		file->map[++i] = ft_strdup(line);
	}
	else
	{
		aux_matrix = ft_calloc((matrix_lines + 2), sizeof(char *));
		while (++i < matrix_lines)
			aux_matrix[i] = ft_strdup(file->map[i]);
		aux_matrix[i] = ft_strdup(line);
		free_double_chr_ptr(file->map);
		file->map = aux_matrix;
	}
		file->map[++i] = NULL;
}

void	parse_map(char **line, int map_fd, t_file *file)
{
	char	*aux;

	file->map = NULL;
	while (*line && *line[0])
	{
		aux = ft_strtrim(*line, "\n");
		free(*line);
		*line = aux;
		if (!(*line[0]))
			break ;
		if (!is_map(*line))
			print_error("Error encountered while reading the map", false);
		copy_map(*line, file);
		free(*line);
		*line = get_next_line(map_fd);
	}
	aux = get_next_line(map_fd);
	if (aux)
		print_error("Error encountered while reading the map", false);
	else
		free(aux);
	free(*line);
	check_map(file);
	check_walls(*file);
}
