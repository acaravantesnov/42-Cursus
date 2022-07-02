/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:22:36 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/24 19:27:19 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	find_var
 *	@param		var		Variable to look for in envp.
 *	@param		envp	Environment variables.
 *	@return		Index of variable found in envp. -1 otherwise.
*/
size_t	find_var(char *var, char **envp)
{
	size_t	i;

	i = 0;
	var = ft_strjoin(var, "=");
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], var, ft_strlen(var)) == 0)
			break ;
		else if ((ft_strncmp(envp[i], var, ft_strlen(var) - 1) == 0) && \
		(ft_strlen(envp[i]) == (ft_strlen(var) - 1)))
			break ;
		i++;
	}
	free(var);
	if (i == ft_2strlen(envp))
		return (-1);
	return (i);
}
