/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 04:14:46 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/25 02:18:27 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	find_path_index
 *	@abstract	Finds PATH var and saves its index into i.
 *	@param		i	Pointer to index to save.
 *	@param		env	Environment variables.
*/
void	find_path_index(size_t *i, char **env)
{
	while (*i < ft_2strlen(env))
	{
		if (ft_strncmp(env[*i], "PATH=", 5) == 0)
			break ;
		(*i)++;
	}
}

/*!
 *	@function	find_path_while
 *	@abstract	Looks for a valid executable matching the command to be used.
 *	@param		path	String were the path will be stored.
 *	@param		aux		Auxiliary string to free path.
 *	@param		cmd		Command to look for.
 *	@param		vent	Path value splitted into vent for each possible path.
 *	@return		Path of binary if exists. NULL otherwise.
*/
char	*find_path_while(char *path, char *aux, char *cmd, char **vent)
{
	int	i;

	i = 0;
	while (vent[i])
	{
		path = ft_strjoin(vent[i], "/");
		aux = path;
		path = ft_strjoin(aux, cmd);
		free(aux);
		if (access(path, F_OK) == 0)
		{
			free_2pointer(vent);
			return (path);
		}
		free(path);
		i++;
	}
	return (NULL);
}

/*!
 *	@function	find_path
 *	@abstract	Checks whether the command is a valid binary executable.
 *	@param		cmd	Single command.
 *	@param		env	Environment variables.
 *	@return		Path of binary if exists. NULL otherwise.
*/
char	*find_path(char *cmd, char **env)
{
	char	*path;
	char	*aux;
	char	**vent;
	char	*ret;
	size_t	i;

	path = NULL;
	aux = NULL;
	if (ft_strncmp(cmd, "/", 1) == 0)
		return (cmd);
	else if (ft_strncmp(cmd, "./", 2) == 0)
		return (cmd + 2);
	i = 0;
	find_path_index(&i, env);
	if (env[i] == NULL)
		return (NULL);
	vent = ft_split(env[i] + 5, ":");
	ret = find_path_while(path, aux, cmd, vent);
	if (ret != NULL)
		return (ret);
	free_2pointer(vent);
	return (NULL);
}
