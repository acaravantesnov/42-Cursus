/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:01:31 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/24 19:25:52 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	ft_envp_copy
 *	@param		envp	Pointer to environment variables.
 *	@return		Copy of envp.
*/
char	**ft_envp_copy(char ***envp)
{
	char	**envpcpy;
	int		sizeofenvp;
	int		i;

	sizeofenvp = ft_2strlen(*envp);
	envpcpy = (char **) malloc(sizeof(char *) * (sizeofenvp + 1));
	i = 0;
	while (i < sizeofenvp)
	{
		envpcpy[i] = ft_strdup((*envp)[i]);
		i++;
	}
	envpcpy[i] = NULL;
	return (envpcpy);
}
