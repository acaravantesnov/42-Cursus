/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:41:07 by airodrig          #+#    #+#             */
/*   Updated: 2022/12/07 21:26:50 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_char(char name)
{
	int					i;
	const char			chars[7] = {'0', '1', 'N', 'S', 'E', 'W', ' '};
	const enum e_valid	names[7] = {C_VOID, C_WALL, C_NORTH, C_SOUTH, C_EAST,
		C_WEST, C_RANDOM};

	i = -1;
	while (++i < 7)
		if (name == chars[i])
			return (names[i]);
	return (-1);
}

bool	is_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (get_char(line[i]) == -1)
			return (false);
	}
	return (true);
}

bool	is_spawn(char c)
{
	return (c == C_NORTH || c == C_SOUTH || c == C_EAST || c == C_WEST);
}
