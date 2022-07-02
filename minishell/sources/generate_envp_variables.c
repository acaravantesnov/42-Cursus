/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_envp_variables.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:38:01 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/24 19:20:03 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	generate_envp_variables
 *	@param		envp	Environment variables.
 *	@return		Array of environment variables without its values.
*/
char	**generate_envp_variables(char **envp)
{
	size_t	i;
	size_t	size;
	char	**variables;
	char	**var;

	i = 0;
	size = ft_2strlen(envp);
	variables = (char **)malloc((size + 1) * sizeof(char *));
	while (i < size)
	{
		var = ft_split(envp[i], "=");
		if (ft_strncmp(var[0], envp[i], ft_strlen(envp[i])) == 0)
		{
			variables[i] = malloc((ft_strlen(var[0]) + 1) * sizeof(char));
			ft_strcpy(variables[i], var[0]);
			variables[i][ft_strlen(var[0])] = '\0';
		}
		else
			variables[i] = ft_strjoin(var[0], "=\0");
		free_2pointer(var);
		i++;
	}
	variables[size] = NULL;
	return (variables);
}
