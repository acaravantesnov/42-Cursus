/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 02:29:49 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/25 04:29:17 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

const static int	g_fsm[30][11 + 3] = {{1, 0, 3, 9, 12, 16, 20, 23,
	25, 23, 28, 0, 0, 0},
{1, 2, 3, 9, 2, 2, 2, 2, 25, 2, 26, 0, 1, 0},
{ERR, 0, ERR, ERR, 12, 16, 20, 23, ERR, 23, 30, 1, 0, 0},
{4, 4, 5, 4, 4, 4, 4, 4, 6, 4, 27, 0, 0, 0},
{4, 4, 5, 4, 4, 4, 4, 4, 6, 4, 27, 0, 1, 0},
{1, 2, 3, 9, 2, 2, 2, 2, 25, 23, 26, 0, 0, 0},
{8, 8, 7, 8, 8, 8, 8, 30, 7, 8, 7, 0, 1, 0},
{4, 4, 5, 4, 4, 4, 4, 4, 6, 4, 4, 0, 1, 1},
{4, 4, 5, 4, 4, 4, 4, 4, 6, 4, 4, 0, 1, 0},
{10, 10, 10, 11, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0},
{10, 10, 10, 11, 10, 10, 10, 10, 10, 10, 10, 0, 1, 0},
{1, 2, 3, 9, 2, 2, 2, 2, 25, 23, 26, 0, 0, 0},
{13, 13, 13, 13, 14, ERR, ERR, ERR, 13, 13, 13, 0, 1, 0},
{1, 0, 3, 9, ERR, ERR, ERR, ERR, 25, 23, 26, 1, 0, 0},
{15, 15, 15, 15, ERR, ERR, ERR, ERR, 15, 15, 15, 0, 1, 0},
{1, 0, 3, 9, ERR, ERR, ERR, ERR, 25, 23, 26, 1, 0, 0},
{17, 17, 17, 17, ERR, 18, ERR, ERR, 17, 17, 17, 0, 1, 0},
{1, 0, 3, 9, ERR, ERR, ERR, ERR, 25, 23, 26, 1, 0, 0},
{19, 19, 19, 19, ERR, ERR, ERR, ERR, 19, 19, 19, 0, 1, 0},
{1, 0, 3, 9, ERR, ERR, ERR, ERR, 25, 23, 26, 1, 0, 0},
{21, 21, 21, 21, 21, 21, ERR, 21, 21, ERR, 21, 0, 1, 0},
{1, 22, 3, 9, 12, 16, ERR, 22, 25, ERR, 26, 1, 0, 0},
{1, 22, 3, 9, 12, 16, ERR, 22, 22, ERR, 26, 0, 0, 0},
{24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 1, 1, 0},
{1, 0, 3, 9, 12, 16, 20, 24, 25, 24, 26, 0, 0, 0},
{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0},
{ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, 0, 0, 0},
{ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, 0, 0, 0},
{ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, 0, 0, 0},
{1, 0, 3, 9, 12, 16, 20, 23, 25, 23, 28, 1, 1, 0}};

const static char	*g_inputf = "111111111171111111111111111111111120:003000000\
00000000000009405000000000000000000000000000008000000000000000000000000000000060:\
000000000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000";

/*
**																end-put-unput->
**
**							l	sp	"	'	<	>	|	\n	\	;	$	  e p u
**	
** starting State	0)		1	0	3	9	12	16	20	23	25	23	28	  0 0 0
** in argument		1)		1	2	3	9	2	2	2	2	25	2	26    0 1 0
** end ARGUMENT		2)		ERR	0	ERR	ERR	12	16	20	23	ERR	23	ERR	  1 0 0
** start "			3)		4	4	5	4	4	4	4	4	6	4	27	  0 0 0
** in "				4)		4	4	5	4	4	4	4	4	6	4	27	  0 1 0
** end "			5)		1	2	3	9	2	2	2	2	25	23	26	  0 0 0
** / in "			6)		8	8	7	8	8	8	8	30	7	8	7	  0 1 0
** / to spec in "	7)		4	4	5	4	4	4	4	4	6	4	4 	  0 1 1
** / to norm in "	8)		4	4	5	4	4	4	4	4	6	4	4 	  0 1 0
** start '			9)		10	10	10	11	10	10	10	10	10	10	10 	  0 0 0
** in '				10)		10	10	10	11	10	10	10	10	10	10	10 	  0 1 0
** end '			11)		1	2	3	9	2	2	2	2	25	23	26	  0 0 0
** first <			12)		13	13	13	13	14	ERR	ERR	ERR	13	13	13	  0 1 0
** end LEFT			13)		1	0	3	9	ERR	ERR	ERR	ERR	25	23	26	  1 0 0
** second <			14)		15	15	15	15	ERR	ERR	ERR	ERR	15	15	15	  0 1 0
** end D_LEFT		15)		1	0	3	9	ERR	ERR	ERR	ERR	25	23	26	  1 0 0
** first >			16)		17	17	17	17	ERR	18	ERR	ERR	17	17	17	  0 1 0
** end RIGTH		17)		1	0	3	9	ERR	ERR	ERR	ERR	25	23	26	  1 0 0
** second >			18)		19	19	19	19	ERR	ERR	ERR	ERR	19	19	19	  0 1 0
** end	D_RIGHT		19)		1	0	3	9	ERR	ERR	ERR	ERR	25	23	26	  1 0 0
** first |			20)		21	21	21	21	21	21	ERR	21	21	ERR	21	  0 1 0
** end PIPE			21)		1	22	3	9	12	16	ERR	22	25	ERR	26	  1 0 0
** wait after pipe	22)		1	22	3	9	12	16	ERR	22	22	ERR	26 	  0 0 0
** end END			23)		24	24	24	24	24	24	24	24	24	24	24	  1 1 0
** aux end			24)		1	0	3	9	12	16	20	24	25	24	26	  0 0 0
** \ in start		25)		1	1	1	1	1	1	1	1	0	1	1	  0 0 0
** 
**
*/

/*
**	The method is known as a finite state machine.
**
**	The program follow the table tokenizing the input:
**	It starts at state 0, and given the input it goes to the next state
**	given as new_state = table[current_state][input]
**	going though states it will be parsing the input, adding each char
**	to the token with push_c.
**	When the state machine reaches an 'end' it will return the state number
**	Here is an example with the imput: 
**	"echo hola | cat -e > o"
**	
**	State: 0,	buff: e	->1
**	State: 1,	buff: c	->1
**	State: 1,	buff: h	->1
**	State: 1,	buff: o	->1
**	State: 1,	buff:  	->2
**	-->RETURN: 2, |echo|
**	State: 2,	buff:  	->0
**	State: 0,	buff: h	->1
**	State: 1,	buff: o	->1
**	State: 1,	buff: l	->1
**	State: 1,	buff: a	->1
**	State: 1,	buff:  	->2
**	-->RETURN: 2, |hola|
**	State: 2,	buff:  	->0
**	State: 0,	buff: |	->20
**	State: 20,	buff:  	->21
**	-->RETURN: 21, |||
**	State: 21,	buff:  	->22
**	State: 22,	buff: c	->1
**	State: 1,	buff: a	->1
**	State: 1,	buff: t	->1
**	State: 1,	buff:  	->2
**	-->RETURN: 2, |cat|
**	State: 2,	buff:  	->0
**	State: 0,	buff: -	->1
**	State: 1,	buff: e	->1
**	State: 1,	buff:  	->2
**	-->RETURN: 2, |-e|
**	State: 2,	buff:  	->0
**	State: 0,	buff: >	->16
**	State: 16,	buff:  	->17
**	-->RETURN: 17, |>|
**	State: 17,	buff:  	->0
**	State: 0,	buff: o	->1
**	State: 1,	buff:\n	->2
**	-->RETURN: 2, |o|
**	State: 2,	buff:\n	->23
**	-->RETURN: 23, |\n|
**	State: 23,	buff:\n	->24
*/

void	push_c(char **str, char c)
{
	char	*new_str;
	int		i;

	i = 0;
	while (*str && ((*str)[i]))
		i++;
	new_str = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (*str && (*str)[i])
	{
		new_str[i] = (*str)[i];
		i++;
	}
	new_str[i++] = c;
	new_str[i] = '\0';
	if (*str)
		free (*str);
	*str = new_str;
}

void	un_push_c(char **str)
{
	char	*new_str;
	int		i;

	i = 0;
	while (*str && ((*str)[i]))
		i++;
	new_str = malloc(sizeof(char) * (i));
	i = 0;
	while (*str && (*str)[i])
	{
		new_str[i] = (*str)[i];
		i++;
	}
	new_str[i - 1] = '\0';
	if (*str)
		free (*str);
	*str = new_str;
}

int	read_readline(char *buff, int state, char **env)
{
	static char	*l = NULL;
	static char	*prev_l = NULL;
	static int	pos = 0;

	if (l == NULL || l[pos - 1] == 0)
	{
		if (l && *l != 0 && (!prev_l || ft_strcmps(prev_l, l)) && state == 24)
			add_history(l);
		if (prev_l != NULL)
			free(prev_l);
		prev_l = l;
		if (state == 24 || l == NULL)
			l = readline(get_prompt(env));
		else
			l = readline("> ");
		if (l == NULL)
			exit(0);
		if (state == 24 || prev_l == NULL)
			pos = 0;
		else
			l = ft_strjoinf(ft_strjoinf(prev_l, "\n", 0, 0), l, 1, 1);
	}
	pos++;
	return (*buff = (l[pos - 1] == 0) * '\n' + l[pos - 1]);
}

int	get_token(char **token, char **env, char **argv, short res)
{
	static char	buff = ' ';
	static int	state = 0;

	if (*token)
		free(*token);
	*token = ft_strdup("");
	state = !res * state;
	while (1)
	{
		state = g_fsm[state][g_inputf[(unsigned char) buff] - '0'];
		if (g_fsm[state][UN_PUSH_C])
			un_push_c(token);
		if (g_fsm[state][PUSH_C])
			push_c(token, buff);
		if (g_fsm[state][END])
			return (state);
		if (state == 26 || state == 27 || state == 28)
			*token = ft_strjoinf(*token, get_variable(&state,
						&buff, env, argv), 1, 1);
		else
			read_readline(&buff, state, env);
	}
}

int	is_token(int target_id, char **token, char **env, char **argv)
{
	static int	id = -1;
	static char	*tok = NULL;

	if (!env && !argv)
	{
		if (tok)
			free(tok);
		tok = NULL;
		id = -1;
		return (1);
	}
	if (id == -1)
		id = get_token(&tok, env, argv, 0);
	*token = tok;
	if (id != target_id)
		return (0);
	id = -1;
	return (1);
}
