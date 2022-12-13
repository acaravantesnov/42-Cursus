/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:12:46 by airodrig          #+#    #+#             */
/*   Updated: 2022/12/10 16:31:20 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_place(char *name)
{
	int						i;
	const char				*id[6] = {"NO", "SO", "EA", "WE", "F", "C"};
	const enum e_textures	names[6] = {T_NORTH, T_SOUTH, T_EAST, T_WEST,
		T_FLOOR, T_CEILING};

	i = -1;
	while (++i < 6)
		if (!ft_strcmp(id[i], name))
			return (names[i]);
	print_error("Textures identifiers wrong", false);
	return (-1);
}

static void	space_comma(char **colors)
{
	int		i;
	char	*aux;

	i = -1;
	while (++i < 3)
	{
		aux = ft_strtrim(colors[i], ",");
		free(colors[i]);
		colors[i] = aux;
	}
}

static char	**copy_colors(char **aux_split)
{
	int		i;
	char	**colors;

	i = -1;
	colors = (char **)ft_calloc(sizeof(char *), 4);
	while (++i < 3)
		colors[i] = ft_strdup(aux_split[i]);
	colors[i] = NULL;
	return (colors);
}

static void	parse_color(char **aux_split, t_texture **list, t_file *file)
{
	char	**colors;
	int		color;

	if (getsize(aux_split) == 2)
		colors = ft_split(aux_split[1], ',');
	else if (getsize(aux_split) == 4)
	{
		colors = copy_colors(&aux_split[1]);
		space_comma(colors);
	}
	else
		colors = NULL;
	if ((getsize(aux_split) != 2 && getsize(aux_split) != 4)
		|| getsize(colors) != 3)
		print_error("Colors are wrong", false);
	color = getrgb(atoi_cub(colors[0]), atoi_cub(colors[1]),
			atoi_cub(colors[2]));
	if (colors)
		free_double_chr_ptr(colors);
	ft_lstaddback_check(list, ft_newel(get_place(aux_split[0]), color, NULL));
	if (get_place(aux_split[0]) == T_FLOOR)
		file->floor = color;
	else if (get_place(aux_split[0]) == T_CEILING)
		file->sky = color;
}

void	get_texture(char *line, t_texture **list, t_file *file)
{
	char	**aux_split;
	int		aux_fd;

	aux_split = ft_split(line, ' ');
	if (getsize(aux_split) != 2 && getsize(aux_split) != 4)
		print_error("Textures are wrong", false);
	aux_fd = open(aux_split[1], O_RDONLY);
	if (aux_fd == -1)
		parse_color(aux_split, list, file);
	else
	{
		close(aux_fd);
		ft_lstaddback_check(list,
			ft_newel(get_place(aux_split[0]), -1, aux_split[1]));
	}
	free_double_chr_ptr(aux_split);
}
