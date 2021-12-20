/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitwitherror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:25:01 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/19 20:26:24 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exitwitherror(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}
