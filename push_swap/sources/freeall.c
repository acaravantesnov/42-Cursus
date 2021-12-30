/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:58:40 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/30 22:37:27 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	freeall(long *stackA, long *stackB, int *ndigitsA, int *ndigitsB)
{
	free(stackA);
	free(stackB);
	free(ndigitsA);
	free(ndigitsB);
	exit(0);
}
