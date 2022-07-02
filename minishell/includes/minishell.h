/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 22:36:37 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/28 04:48:46 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define ARGUMENT 2
# define LEFT 13
# define D_LEFT 15
# define RIGHT 17
# define D_RIGHT 19
# define PIPE 21
# define END_TOKEN 23

# define END 11
# define PUSH_C 12
# define UN_PUSH_C 13
# define ERR 29

# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <dirent.h>
# include <limits.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include "../sources/libft/libft.h"

int	g_lastexit;

/*!
 *	@typedef	t_command
 *				One struct per single command.
 *	@field		in_fd	Input fd for this command.
 *	@field		argv	Single command.
 *	@field		out_fd	Output fd for this command.
*/
typedef struct s_command
{
	int		in_fd;
	char	**argv;
	int		out_fd;
}	t_command;

typedef struct s_managervars
{
	int		i;
	int		ncmds;
	char	*path;
	char	*seekbinreturn;
	int		tempin;
	int		tempout;
	int		fdin;
	int		fdout;
	int		fdpipe[2];
	int		wstatus;
	int		error;
	pid_t	pids[100];
	int		pid_index;
}	t_managervars;

/*
	tokenizer.h
*/
int		is_token(int target_id, char **token, char **env, char **argv);
char	*get_variable(int *state, char *buff, char **env, char **argv);
void	push_c(char **str, char c);
int		read_readline(char *buff, int state, char **env);
char	*ft_strjoinf(char *s1, char *s2, short f1, short f2);
char	*get_value(char *var, char **env);
int		get_token(char **token, char **env, char **argv, short res);
char	*get_prompt(char **env);

/*
	parser.h
*/
void	push_arr(void ***arr, void *element);
short	serror(char *str, char **env, char **argv);
int		heredoc(char *end);
short	parse_line(char ***env, char **argv, t_command ***line);

/*
	signals.h
*/
void	sighandler(int signum);

/*
	Print parsing
*/
void	print_middle(t_command **line);
void	free_middle(t_command **line);

/*
	Builtins
*/
size_t	echo(char **argv, int opt);
size_t	cd(char *path, char ***envp, t_managervars *mvars);
size_t	pwd(void);
size_t	export(char **argv, char ***envp);
size_t	unset(char **argv, char ***envp);
size_t	env(char ***envp);
void	exit_builtin(t_command **line, t_managervars *mvars);

/*
	Builtins utils
*/
size_t	error1(char *str, t_managervars *mvars);
size_t	error2(t_managervars *mvars, int opt);
int		check_equal(char *argv);
int		check_non_valid_syntax(char *argv);
void	print_line(char **srtd_vars, char ***envp, int i, int j);
void	print_export(char ***envp, char **srtd_vars);

/*
	Functions
*/
void	manager(t_command **line, char ***envp);
char	*seek_builtin(char **argv);
size_t	execbuiltin(t_managervars *mvars, t_command **line, char ***envp);
void	process(t_command **line, t_managervars *mvars, char **envp);
char	*find_path(char *cmd, char *env[]);
char	**ft_envp_copy(char ***envp);
void	change_directory(char *path, char ***envp);
char	*get_env(char *env_var, char **envp);
size_t	find_var(char *var, char **envp);
char	**generate_envp_variables(char **envp);
char	**generate_sorted_envp_variables(char **envp_vars);
char	***generate_export(char **envp, char **sorted_envp_variables);
void	free_all(t_managervars *mvars, t_command **line);
void	free_2pointer(char **x);
void	free_3pointer(char ***x);
size_t	number_of_cmds(t_command **line);
void	free_mvars(t_managervars *mvars);
void	setmvars(t_managervars *mvars, t_command **line);
void	setfds(t_managervars *mvars, t_command **line);
void	command_not_found(t_managervars *mvars, t_command **line);
void	not_builtin(t_managervars *mvars, t_command **line, char ***envp, \
char *aux);
void	command_exists(t_managervars *mvars, t_command **line, char ***envp, \
char *aux);
void	whilefct(t_managervars *mvars, t_command **line, char ***envp);
void	last_command_ended(t_managervars *mvars);
void	save_exceptions(void);

#endif
