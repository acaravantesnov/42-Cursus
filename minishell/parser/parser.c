/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:04:46 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/30 18:19:44 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	in_file -> [RIGHT | D_RIGHT] ARGUMENT
*/
short	parse_in_file(int *fd, char **env, char **argv, char **token)
{
	if (is_token(LEFT, token, env, argv))
	{
		if (is_token(ARGUMENT, token, env, argv))
		{
			*fd = open(*token, O_RDONLY);
			if (*fd == -1)
				perror("bash: in");
			return (TRUE);
		}
		return (serror(*token, env, argv));
	}
	else if (is_token(D_LEFT, token, env, argv))
	{
		if (is_token(ARGUMENT, token, env, argv))
		{
			*fd = heredoc(*token);
			if (*fd == -1)
				perror("bash: in");
			return (TRUE);
		}
		return (serror(*token, env, argv));
	}
	return (FALSE);
}

/*
**	out_file -> [LEFT | D_LEFT] ARGUMENT
*/
short	parse_out_file(int *fd, char **env, char **argv, char **token)
{
	if (is_token(RIGHT, token, env, argv))
	{
		if (is_token(ARGUMENT, token, env, argv))
		{
			*fd = open(*token, O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (*fd == -1)
				perror("bash: out");
			return (TRUE);
		}
		return (serror(*token, env, argv));
	}
	else if (is_token(D_RIGHT, token, env, argv))
	{
		if (is_token(ARGUMENT, token, env, argv))
		{
			*fd = open(*token, O_WRONLY | O_CREAT | O_APPEND, 0777);
			if (*fd == -1)
				perror("bash: out");
			return (TRUE);
		}
		return (serror(*token, env, argv));
	}
	return (FALSE);
}

/*
**	argument -> ARGUMENT
*/
short	parse_argument(char ***argv, char **env, char **origin_argv,
	char **token)
{
	if (!is_token(ARGUMENT, token, env, origin_argv))
		return (FALSE);
	push_arr((void ***)argv, ft_strdup(*token));
	return (TRUE);
}

/*
** command -> [argument | in_file | out_file]+
*/
short	parse_command(t_command ***line, char **env, char **argv, char **token)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	cmd->argv = (char **)malloc(sizeof(char *));
	cmd->argv[0] = NULL;
	cmd->in_fd = -2;
	cmd->out_fd = -2;
	if (!(parse_in_file(&(cmd->in_fd), env, argv, token) > 0
			|| parse_out_file(&(cmd->out_fd), env, argv, token) > 0
			|| parse_argument(&(cmd->argv), env, argv, token) > 0))
	{
		free(cmd->argv);
		free(cmd);
		return (FALSE);
	}
	while (parse_in_file(&(cmd->in_fd), env, argv, token) > 0
		|| parse_out_file(&(cmd->out_fd), env, argv, token) > 0
		|| parse_argument(&(cmd->argv), env, argv, token) > 0)
		;
	push_arr((void ***)line, cmd);
	return (TRUE);
}

/*
** line -> END | command+ [PIPE command]* END
*/
short	parse_line(char ***env, char **argv, t_command ***line)
{
	char		*token;
	int			i;

	token = NULL;
	if (is_token(END_TOKEN, &token, *env, argv))
		return (TRUE);
	if (!parse_command(line, *env, argv, &token))
		return (serror(token, *env, argv));
	while (is_token(PIPE, &token, *env, argv))
		if (!parse_command(line, *env, argv, &token))
			return (serror(token, *env, argv));
	if (!is_token(END_TOKEN, &token, *env, argv))
		return (serror(token, *env, argv));
	i = 0;
	while (line && (*line)[i] && (*line)[i]->in_fd != -3)
		i++;
	if (line && !(*line)[i])
		manager(*line, env);
	return (TRUE);
}
