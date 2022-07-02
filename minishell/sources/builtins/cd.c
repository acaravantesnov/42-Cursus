/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:33:31 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/28 04:32:14 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*!
 *	@function	cd_without_argument
 *	@discussion	It will try to chdir to HOME variable value if it exists and is
 *				accessible.
 *	@param		envp	Environment variables.
 *	@param		mvars	Pointer to struct containing variables used in manager.
 *	@return		0 if no error. 1 otherwise.
*/
size_t	cd_without_argument(char ***envp, t_managervars *mvars)
{
	char	*home;

	home = get_env("HOME", *envp);
	if (home != NULL)
	{
		if (get_env("PWD", *envp) != NULL)
		{
			if ((access(home, X_OK) != -1) && \
			(ft_strncmp(home, get_env("PWD", *envp), ft_strlen(home) + 1) != 0))
				change_directory(home, envp);
			return (0);
		}
		else
		{
			change_directory(home, envp);
			return (0);
		}
		return (error1(home, mvars));
	}
	else
		return (error2(mvars, 1));
	return (0);
}

/*!
 *	@function	cd_with_hyphen_2
 *	@abstract	Prints and chdir's to OLDPWD given user is not in OLDPWD direct.
 *	@param		oldpwdstr	String of OLDPWD variable value.
 *	@param		envp		Environment variables.
*/
void	cd_with_hypen_2(char *oldpwdstr, char ***envp)
{
	ft_putstr_fd(oldpwdstr, 1);
	ft_putchar_fd(10, 1);
	change_directory(oldpwdstr, envp);
}

/*!
 *	@function	cd_with_hyphen
 *	@discussion	It will print and try to chdir to the OLDPWD value if it exists
 *				and is accessible.
 *	@param		envp	Environment variables.
 *	@param		mvars	Pointer to struct containing variables used in manager.
 *	@return		0 if no error. 1 otherwise.
*/
size_t	cd_with_hyphen(char ***envp, t_managervars *mvars)
{
	char	*pwdstr;
	char	*oldpwdstr;
	int		maxlen;

	pwdstr = get_env("PWD", *envp);
	oldpwdstr = get_env("OLDPWD", *envp);
	if (oldpwdstr != NULL)
	{
		if (access(oldpwdstr, X_OK) != -1)
		{
			maxlen = ft_strlen(oldpwdstr);
			if (pwdstr != NULL)
			{
				if (ft_strlen(pwdstr) > ft_strlen(oldpwdstr))
					maxlen = ft_strlen(pwdstr);
				if (ft_strncmp(pwdstr, oldpwdstr, maxlen) != 0)
					cd_with_hypen_2(oldpwdstr, envp);
			}
			return (0);
		}
		return (error1(oldpwdstr, mvars));
	}
	return (error2(mvars, 2));
}

/*!
 *	@function	cd
 *	@discussion	"cd"		-> Changes directory to HOME variable if accessible.
 *				"cd path"	-> Changes directory to path if accessible.
 *				"cd -"		-> Prints OLDPWD variable and cd's to it.
 *	@param		path	String of path to follow. NULL otherwise.
 *	@param		envp	Environment variables.
 *	@param		mvars	Pointer to struct containing variables used in manager.
 *	@return		0 if no error. 1 otherwise.
*/
size_t	cd(char *path, char ***envp, t_managervars *mvars)
{
	if (path != NULL)
	{
		if (ft_strlen(path) == 0)
			return (0);
	}
	else if (path == NULL)
		return (cd_without_argument(envp, mvars));
	if (ft_strncmp(path, "-", ft_strlen(path)) == 0)
		return (cd_with_hyphen(envp, mvars));
	if ((access(path, F_OK) == -1) || (access(path, X_OK) == -1))
	{
		close(mvars->fdout);
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		if (access(path, F_OK) == -1)
			ft_putstr_fd(": No such file or directory\n", 2);
		else
			ft_putstr_fd(": Permission denied\n", 2);
		return (1);
	}
	else
		change_directory(path, envp);
	return (0);
}
