/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:39:29 by airodrig          #+#    #+#             */
/*   Updated: 2022/11/27 23:03:19 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_name(const char *filename, const char *ext)
{
	char	*namecpy;
	int		i;

	i = ft_strlen(filename);
	namecpy = (char *)filename;
	while (i > 0 && namecpy[--i] != '.')
		;
	if (!ft_strncmp(&namecpy[i], ext, ft_strlen(ext) + 1))
		return (true);
	return (false);
}

void	parse_file(int map_fd, t_file *file)
{
	char		*line;
	char		*aux;

	line = get_next_line(map_fd);
	while (line && line[0])
	{
		aux = ft_strtrim(line, "\n");
		free(line);
		line = aux;
		if (line[0])
		{
			if (is_map(line))
				break ;
			get_texture(line, &file->textures, file);
		}
		free(line);
		line = get_next_line(map_fd);
	}
	check_textures(file->textures);
	if (line && line[0])
		parse_map(&line, map_fd, file);
	if (!file->map)
		print_error("Map missing in the file", false);
}
