/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:35:08 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/25 02:15:25 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shift_vars(char ***envp, size_t find_var_rt, size_t size)
{
	size_t	i;

	i = 0;
	while (find_var_rt + i < size - 1)
	{
		(*envp)[find_var_rt + i] = \
		(char *)ft_realloc((*envp)[find_var_rt + i], \
		(ft_strlen((*envp)[find_var_rt + i + 1]) + 1) * sizeof(char));
		ft_strcpy((*envp)[find_var_rt + i], \
		(*envp)[find_var_rt + i + 1]);
		(*envp)[find_var_rt + i][ft_strlen((*envp)[find_var_rt + i + 1])] = \
		'\0';
		i++;
	}
	(*envp) = (char **)ft_realloc(*envp, \
	size * sizeof(char *));
	free((*envp)[size - 1]);
	(*envp)[size - 1] = NULL;
}

/*!
 *	@function	unset
 *	@discussion	Removes variables if they already exist.
 *	@param		argv	Single command.
 *	@param		envp	Environment variables.
 *	@return		0.
*/
size_t	unset(char **argv, char ***envp)
{
	int		i;
	int		find_var_rt;
	size_t	size;

	if (argv[1] == NULL)
		return (0);
	size = ft_2strlen(*envp);
	i = 1;
	while (argv[i] != NULL)
	{
		size = ft_2strlen(*envp);
		find_var_rt = find_var(argv[i], *envp);
		if (find_var_rt != -1)
			shift_vars(envp, find_var_rt, size);
		i++;
	}
	return (0);
}
