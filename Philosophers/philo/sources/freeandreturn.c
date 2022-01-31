/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeandreturn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:05:59 by acaravan          #+#    #+#             */
/*   Updated: 2022/01/31 17:09:07 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	freeandreturn(struct Rules *rules)
{
	int	f;

	f = 0;
	free(rules->ph);
	free(rules->forks);
	while (f < rules->number_of_philosophers)
	{
		free(rules->manos[f]);
		f++;
	}
	free(rules->manos);
	free(rules);
	return (0);
}
