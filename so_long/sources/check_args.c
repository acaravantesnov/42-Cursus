/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:03:38 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/23 02:40:36 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\nWrong number of arguments", 31);
		exit(0);
	}
	if (ft_strchr(argv[1], '.') == NULL)
	{
		write(1, "Error\nWrong file extension.", 27);
		exit(0);
	}
	else if (my_ft_strcmp(my_ft_strchr(argv[1], '.'), ".ber") != 0)
	{
		write(1, "Error\nWrong file extension.", 27);
		exit(0);
	}
	return (0);
}
