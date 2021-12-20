/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:25:59 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/19 20:29:06 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_args(int argc, char *argv[])
{
	if (argc != 5)
	{
		ft_putstr_fd("Arguments Error\n", 2);
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}

	if ((access(argv[1], F_OK) == -1) || (access(argv[4], F_OK) == -1))
	{
		ft_putstr_fd("Arguments Error\nEither of the files not existing\n", 2);
		exit(EXIT_FAILURE);
	}
}