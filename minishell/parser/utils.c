/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:43:49 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/28 03:51:41 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	push_arr(void ***arr, void *element)
{
	int		len;
	void	**new_arr;

	len = 0;
	while ((*arr)[len])
		len++;
	new_arr = malloc(sizeof(void *) * (len + 2));
	len = -1;
	while ((*arr)[++len])
		new_arr[len] = (*arr)[len];
	new_arr[len++] = element;
	new_arr[len] = NULL;
	free(*arr);
	*arr = new_arr;
}

short	serror(char *str, char **env, char **argv)
{
	char	*token;

	token = NULL;
	ft_putstr_fd("syntax error near unexpected token: \'", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\'\n", 2);
	while ((get_token(&token, env, argv, 1)) != END_TOKEN
		|| !ft_strcmps(token, ";"))
		;
	if (token)
		free (token);
	is_token(0, NULL, NULL, NULL);
	return (0);
}

void	free_middle(t_command **line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line && line[i])
	{
		if (line[i]->in_fd >= 0)
			close(line[i]->in_fd);
		j = 0;
		while (line[i]->argv[j])
		{
			free(line[i]->argv[j]);
			j++;
		}
		free(line[i]->argv);
		if (line[i]->out_fd >= 0)
			close(line[i]->out_fd);
		free(line[i]);
		i++;
	}
	if (line)
		free(line);
}

char	*ft_strjoinf(char *s1, char *s2, short f1, short f2)
{
	int		len1;
	int		len2;
	char	*new_str;

	len1 = 0;
	len2 = 0;
	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;
	if (len1 + len2 < 0)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	len1 = -1 * (s1 != 0);
	while (s1 && s1[++len1])
		new_str[len1] = s1[len1];
	len2 = -1 * (s2 != 0);
	while (s2 && s2[++len2])
		new_str[len1 + len2] = s2[len2];
	new_str[len1 + len2] = '\0';
	if (s1 && f1)
		free(s1);
	if (s2 && f2)
		free(s2);
	return (new_str);
}

char	*get_prompt(char **env)
{
	static char	*prmt = NULL;

	if (prmt)
		free(prmt);
	prmt = ft_strjoinf(get_value("USER", env), " $ ", 0, 0);
	return (prmt);
}
