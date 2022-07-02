/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:34:56 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/25 03:36:50 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	update_oldpwd_pwd
 *	@discussion	It updates the value of OLDPWD and PWD environment variables.
 *	@param		mvars		Pointer to struct containing variables used in 
 							manager.
 *	@param		envp		Environment variables.
 *	@param		oldpwd_m	ie. export OLDPWD=x
 *	@param		pwd_m		ie. export PWD=x
*/
void	update_oldpwd_pwd(char ***envp, char **oldpwd_m, char **pwd_m)
{
	export(pwd_m, envp);
	export(oldpwd_m, envp);
}

void	free_change_directory(char **oldpwd_m, char **pwd_m, char **pwd)
{
	free_2pointer(pwd);
	free_2pointer(oldpwd_m);
	free_2pointer(pwd_m);
}

/*!
 *	@function	change_directory
 *	@discussion	Given the fact that path is accesible, it will chdir to it.
				This will update PWD and OLDPWD when necessary.
 *	@param		path	String of directory to follow.
 *	@param		envp	Environment variables.
*/
void	change_directory(char *path, char ***envp)
{
	char	**pwd;
	char	*aux;
	char	**oldpwd_m;
	char	**pwd_m;
	char	cwd[256];

	pwd = (char **) malloc(3 * sizeof(char *));
	pwd[2] = NULL;
	getcwd(cwd, sizeof(cwd));
	pwd[0] = malloc((14 + ft_strlen(cwd)) * sizeof(char));
	ft_strcpy(pwd[0], "export OLDPWD=");
	aux = pwd[0];
	pwd[0] = ft_strjoin(aux, cwd);
	free(aux);
	chdir(path);
	getcwd(cwd, sizeof(cwd));
	pwd[1] = malloc((11 + ft_strlen(cwd)) * sizeof(char));
	ft_strcpy(pwd[1], "export PWD=");
	aux = pwd[1];
	pwd[1] = ft_strjoin(aux, cwd);
	free(aux);
	pwd_m = ft_split(pwd[1], " ");
	oldpwd_m = ft_split(pwd[0], " ");
	update_oldpwd_pwd(envp, oldpwd_m, pwd_m);
	free_change_directory(oldpwd_m, pwd_m, pwd);
}
