/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:35:36 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/25 02:24:57 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*!
 *	@function	env
 *	@abstract	Prints environment variables.
 *	@param		envp	Pointer to environment variables.
 *	@return		0 if no error. 1 if envp does not exist.
*/
size_t	env(char ***envp)
{
	int	i;

	i = 0;
	if ((*envp) == NULL)
		return (1);
	while ((*envp)[i] != NULL)
	{
		if (ft_strchr((*envp)[i], '=') != NULL)
		{
			ft_putstr_fd((*envp)[i], 1);
			ft_putchar_fd(10, 1);
		}
		i++;
	}
	return (0);
}
