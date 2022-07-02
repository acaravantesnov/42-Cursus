/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:34:22 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/27 05:13:49 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*!
 *	@function	export_var
 *	@abstract	Adds variable to envp.
 *	@param		envp	Environment variables.
 *	@param		argv	VAR, VAR=var.
 *	@param		i		Iterator to go through each argument in exxport.
*/
void	export_var(char ***envp, char **argv, int i)
{
	int		envp_size;
	int		index;
	char	**var;

	envp_size = ft_2strlen(*envp);
	var = ft_split(argv[i], "=");
	index = find_var(var[0], *envp);
	free_2pointer(var);
	if (index == -1)
	{
		(*envp) = (char **)ft_realloc(*envp, (envp_size + 2) \
		* sizeof(char *));
		(*envp)[envp_size] = (char *)ft_realloc((*envp)[envp_size], \
		ft_strlen(argv[i]) * sizeof(char));
		ft_strcpy((*envp)[envp_size], argv[i]);
		(*envp)[envp_size + 1] = NULL;
	}
	else
	{
		(*envp)[index] = ft_realloc((*envp)[index], ft_strlen(argv[i]) \
		* sizeof(char));
		ft_strcpy((*envp)[index], argv[i]);
	}
}

/*!
 *	@function	export
 *	@discussion	"export VAR=var"-> Adds VAR to env if it does not already exist.
 *				"export VAR"	-> Adds VAR to env (only visible in export).
 *				"export"		-> Prints env vars in alpabetical order.
 *	@param		argv			VAR, VAR=var, or NULL.
 *	@param		envp			Environment variables.
 *	@return		0 if no error.
*/
size_t	export(char **argv, char ***envp)
{
	char	**envp_vars;
	char	**sorted_envp_vars;
	int		i;

	envp_vars = generate_envp_variables(*envp);
	sorted_envp_vars = generate_sorted_envp_variables(envp_vars);
	if (argv[1] == NULL)
		print_export(envp, sorted_envp_vars);
	else
	{
		i = 1;
		while (argv[i] != NULL)
		{
			if ((check_equal(argv[i]) == 1) || \
			(check_non_valid_syntax(argv[i]) == 1))
			{
				free_2pointer(sorted_envp_vars);
				return (1);
			}
			export_var(envp, argv, i);
			i++;
		}
		free_2pointer(sorted_envp_vars);
	}
	return (0);
}
