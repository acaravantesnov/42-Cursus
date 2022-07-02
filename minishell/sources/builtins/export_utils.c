/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 04:11:10 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/27 05:10:27 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_equal(char *argv)
{
	int	i;
	int	size;
	int	nequals;

	i = 0;
	size = ft_strlen(argv);
	nequals = 0;
	while (i < size)
	{
		if (argv[i] == '=')
			nequals++;
		i++;
	}
	if (nequals == size)
	{
		ft_putstr_fd("minishell: export: \'", 2);
		ft_putstr_fd(argv, 2);
		ft_putstr_fd("\': not  valid identifier\n", 2);
		return (1);
	}
	return (0);
}

int	check_non_valid_syntax(char *argv)
{
	char		**var;
	size_t		i;

	var = ft_split(argv, "=");
	i = 0;
	while (i < ft_strlen(var[0]))
	{
		if ((ft_cinstr(var[0][i], "*+-[]¨{}:.,?¿@ñçÑÇ") == 1) || \
		(var[0][i] < 0))
		{
			ft_putstr_fd("minishell: export: \'", 2);
			ft_putstr_fd(var[0], 2);
			ft_putstr_fd("\': not  valid identifier\n", 2);
			free_2pointer(var);
			return (1);
		}
		i++;
	}
	free_2pointer(var);
	return (0);
}

void	print_line(char **srtd_vars, char ***envp, int i, int j)
{
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(srtd_vars[i], 1);
	if (ft_strchr(srtd_vars[i], '=') != NULL)
	{
		ft_putchar_fd(34, 1);
		ft_putstr_fd((*envp)[j] + ft_strlen(srtd_vars[i]), 1);
		ft_putstr_fd("\"\n", 1);
	}
	else
		ft_putchar_fd(10, 1);
}

/*!
 *	@function	print_export
 *	@abstract	Prints export looking for each sorted_var in envp.
 *	@param		envp		Environment variables.
 *	@param		srtd_vars	Return of function generate_sorted_envp_variables.
*/
void	print_export(char ***envp, char **srtd_vars)
{
	int		i;
	int		j;

	i = 0;
	while (srtd_vars[i] != NULL)
	{
		j = 0;
		while ((*envp)[j] != NULL)
		{
			if ((ft_strncmp((*envp)[j], srtd_vars[i], \
			ft_strlen(srtd_vars[i])) == 0) && \
			(ft_strncmp((*envp)[j], "_=", 2) != 0))
			{
				print_line(srtd_vars, envp, i, j);
				break ;
			}
			j++;
		}
		i++;
	}
	free_2pointer(srtd_vars);
}
