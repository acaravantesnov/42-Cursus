/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 00:31:03 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/24 19:17:16 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	get_env
 *	@param		env_var	String of environment variable to look for.
 *	@param		envp	Environment variables.
 *	@return		Value of environment value if existing. NULL otherwise.
*/
char	*get_env(char *env_var, char **envp)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	env_var = ft_strjoin(env_var, "=");
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], env_var, ft_strlen(env_var)) == 0)
			str = envp[i] + ft_strlen(env_var);
		i++;
	}
	free(env_var);
	return (str);
}
