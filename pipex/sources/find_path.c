/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:23:43 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/19 20:28:13 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char *cmd, char *env[])
{
	char	*path;
	char	**vent;
	int i;

	i = 0;
	while ((ft_strnstr(env[i], "PATH", 4) == NULL) || env[i] == NULL)
		i++;
	if (env[i] == NULL)
		exitwitherror("Path not found");
	vent = ft_split(env[i] + 5, ':');
	i = 0;
	while (vent[i])
	{
		path = ft_strjoin(vent[i], "/"); //Memory leak
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (NULL);
}