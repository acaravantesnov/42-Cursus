/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 04:15:03 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/27 04:23:38 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	error1(char *str, t_managervars *mvars)
{
	close(mvars->fdout);
	if (access(str, F_OK) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	return (1);
}

size_t	error2(t_managervars *mvars, int opt)
{
	close(mvars->fdout);
	ft_putstr_fd("minishell: cd: ", 2);
	if (opt == 1)
		ft_putstr_fd("HOME", 2);
	else if (opt == 2)
		ft_putstr_fd("OLDPWD", 2);
	ft_putstr_fd(" not set\n", 2);
	return (1);
}
