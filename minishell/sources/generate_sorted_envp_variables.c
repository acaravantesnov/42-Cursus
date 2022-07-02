/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_sorted_envp_variables.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:39:28 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/27 05:05:17 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	swap_with_min
 *	@discussion	Using a temporal string, it swaps envp_vars[min_index] with
 *				envp_vars[i].
 *	@param		envp_vars	Return of function generate_envp_variables.
 *	@param		i			Iterator to go through envp_vars.
 *	@param		min_index	Saves index of minimum string.
*/
void	swap_with_min(char **envp_vars, int i, int min_index)
{
	char	*temp;

	temp = malloc((ft_strlen(envp_vars[min_index]) + 1) * sizeof(char));
	ft_strcpy(temp, envp_vars[min_index]);
	temp[ft_strlen(envp_vars[min_index])] = '\0';
	envp_vars[min_index] = ft_realloc(envp_vars[min_index], \
	(ft_strlen(envp_vars[i]) + 1) * sizeof(char));
	ft_strcpy(envp_vars[min_index], envp_vars[i]);
	envp_vars[min_index][ft_strlen(envp_vars[i])] = '\0';
	envp_vars[i] = ft_realloc(envp_vars[i], \
	(ft_strlen(temp) + 1) * sizeof(char));
	ft_strcpy(envp_vars[i], temp);
	envp_vars[i][ft_strlen(temp)] = '\0';
	free(temp);
}

/*!
 *	@function	generate_sorted_envp_variables
 *	@param		envp_vars	Return of function generate_envp_variables.
 *	@return		Array of sorted environment variables without its values.
*/
char	**generate_sorted_envp_variables(char **envp_vars)
{
	int		i;
	int		j;
	int		min_index;
	int		size;

	i = 0;
	size = ft_2strlen(envp_vars);
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (ft_strncmp(envp_vars[j], envp_vars[min_index], \
			ft_strlen(envp_vars[j])) <= 0)
				min_index = j;
			j++;
		}
		swap_with_min(envp_vars, i, min_index);
		i++;
	}
	return (envp_vars);
}
