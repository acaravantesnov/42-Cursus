/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 05:47:42 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 08:24:39 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(int	*stackA, int *stackB, int ndigitsA, int ndigitsB)
{
	int	*temp;

	temp = ft_realloc(stackB, ndigitsB, ndigitsB + 1);
	temp[ndigitsB + 1] = stackB[ndigitsA];
	if (ndigitsA == 0)
		stackA = NULL;
	free(temp);
}
