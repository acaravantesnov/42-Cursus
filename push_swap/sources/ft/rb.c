/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 05:58:17 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 08:24:40 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rb(int	*stackB, int ndigitsB)
{
	int	i;
	int	*temp;

	i = 0;
	temp = (int *)malloc(sizeof(int));
	*temp = stackB[0];
	while (i < ndigitsB)
	{
		stackB[i] = stackB[i + 1];
		i++;
	}
	stackB[ndigitsB - 1] = *temp;
	free(temp);
}
