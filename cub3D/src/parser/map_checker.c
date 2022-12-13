/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:11:13 by airodrig          #+#    #+#             */
/*   Updated: 2022/12/10 16:10:23 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	has_spawn(char *line, t_file *file)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (line[++i])
	{
		if (is_spawn(line[i]))
		{
			cnt++;
			file->player_pos = (t_vector){i, file->height};
			if (line[i] == C_NORTH)
				file->player_dir = (t_vector){0, 1};
			else if (line[i] == C_SOUTH)
				file->player_dir = (t_vector){0, -1};
			else if (line[i] == C_EAST)
				file->player_dir = (t_vector){1, 0};
			else if (line[i] == C_WEST)
				file->player_dir = (t_vector){-1, 0};
		}
	}
	return (cnt);
}

static void	fill_with_spaces(char **line, int aux_len, int max_len)
{
	int		i;
	char	*aux_line;

	i = -1;
	aux_line = ft_calloc(max_len + 1, sizeof(char));
	while (++i < aux_len)
		aux_line[i] = (*line)[i];
	while (i < max_len)
		aux_line[i++] = C_RANDOM;
	free(*line);
	*line = aux_line;
}

void	check_map(t_file *file)
{
	bool	spawns;

	spawns = false;
	while (file->map[++(file->height)])
	{
		if (has_spawn(file->map[file->height], file) > 1
			|| (has_spawn(file->map[file->height], file) == 1 && spawns))
			print_error("Too many spawns", false);
		else if (has_spawn(file->map[file->height], file) == 1 && !spawns)
			spawns = true;
		if ((int)ft_strlen(file->map[file->height]) > file->width)
			file->width = ft_strlen(file->map[file->height]);
	}
	if (!spawns)
		print_error("No spawn detected", false);
	file->height = -1;
	while (file->map[++(file->height)])
	{
		if ((int)ft_strlen(file->map[file->height]) < file->width)
			fill_with_spaces(&file->map[file->height],
				ft_strlen(file->map[file->height]), file->width);
	}
	if (file->height * file->width > 38400)
		print_error("Map is too big", false);
}

static int	floodfill(t_file *file, int y, int x, char **map)
{
	if (y < 0 || x < 0 || y >= file->height || x >= file->width
		|| map[y][x] == C_RANDOM)
		return (1);
	if (map[y][x] == C_WALL)
		return (0);
	map[y][x] = C_WALL;
	return (floodfill(file, y + 1, x, map)
		+ floodfill(file, y, x + 1, map)
		+ floodfill(file, y - 1, x, map)
		+ floodfill(file, y, x - 1, map)
		+ floodfill(file, y + 1, x + 1, map)
		+ floodfill(file, y + 1, x - 1, map)
		+ floodfill(file, y - 1, x + 1, map)
		+ floodfill(file, y - 1, x - 1, map));
}

void	check_walls(t_file file)
{
	int		i;
	char	**aux_map;

	i = -1;
	aux_map = ft_calloc((file.height + 1), sizeof(char *));
	if (!aux_map)
		print_error("Malloc error", false);
	while (file.map[++i])
		aux_map[i] = ft_strdup(file.map[i]);
	aux_map[i] = NULL;
	if (file.player_pos.y <= 0 || file.player_pos.y >= file.height - 1
		|| file.player_pos.x <= 0 || file.player_pos.x >= file.width - 1)
		print_error("Player is outside the map", false);
	if (floodfill(&file, file.player_pos.y, file.player_pos.x, aux_map))
		print_error("Map is not closed", false);
	free_double_chr_ptr(aux_map);
}
