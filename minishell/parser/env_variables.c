/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:43:22 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/25 02:31:50 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	state_logic(int curr_state, char *value)
{
	if (curr_state == 26)
		return (1);
	if (curr_state == 27)
		return (4);
	if (curr_state == 28 && value)
		return (1);
	if (curr_state == 28 && !value)
		return (0);
	return (ERR);
}

char	*get_value(char *var, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i] && var && env[i][j] == var[j])
			j++;
		if (env[i] && var && env[i][j] == '=' && !var[j])
			return (&(env[i][j + 1]));
		i++;
	}
	return (NULL);
}

char	*get_tilde(char *buff, char **env)
{
	read_readline(buff, 0, env);
	if (*buff == '-')
	{
		read_readline(buff, 0, env);
		if (ft_cinstr(*buff, " \n/") && get_value("OLDPWD", env))
			return (ft_strdup(get_value("OLDPWD", env)));
		else
			return (ft_strdup("~-"));
	}
	if (*buff == '+')
	{
		read_readline(buff, 0, env);
		if (ft_cinstr(*buff, " \n/") && get_value("PWD", env))
			return (ft_strdup(get_value("PWD", env)));
		else
			return (ft_strdup("~+"));
	}
	if (ft_cinstr(*buff, " \n/") && get_value("HOME", env))
		return (ft_strdup(get_value("HOME", env)));
	else
		return (ft_strdup("~"));
}

char	*get_env_variable(char *buff, char **env, char **argv)
{
	int		ret;
	char	*var;
	char	*value;

	var = NULL;
	ret = read_readline(buff, 0, env);
	if (*buff >= '0' && *buff <= '9')
	{
		while (((*buff)--) - '0' && *(argv) && argv++)
			;
		read_readline(buff, 0, env);
		return (ft_strdup(*(argv)));
	}
	if (*buff == '?' && read_readline(buff, 0, env))
		return (ft_itoa(g_lastexit));
	while (ret && !ft_cinstr(*buff, " \"\'\n;$/?\\|<>"))
	{
		push_c(&var, *buff);
		ret = read_readline(buff, 0, env);
	}
	if (var == NULL)
		return (ft_strdup("$"));
	value = get_value(var, env);
	free(var);
	return (ft_strdup(value));
}

char	*get_variable(int *state, char *buff, char **env, char **argv)
{
	char	*value;

	if (*buff == '$')
		value = get_env_variable(buff, env, argv);
	else if (*buff == '~')
		value = get_tilde(buff, env);
	else
		value = NULL;
	*state = state_logic(*state, value);
	return (value);
}
