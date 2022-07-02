/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fcts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:55:11 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/25 02:20:48 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_2pointer(char **x)
{
	int	i;

	i = 0;
	while (x[i] != NULL)
	{
		free(x[i]);
		i++;
	}
	free(x);
}

void	free_3pointer(char ***x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (x[i] != NULL)
	{
		j = 0;
		while (x[i][j] != NULL)
		{
			free(x[i][j]);
			j++;
		}
		free(x[i]);
		i++;
	}
	free(x);
}

void	free_all(t_managervars *mvars, t_command **line)
{
	free(mvars);
	free_middle(line);
}
