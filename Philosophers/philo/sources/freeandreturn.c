/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeandreturn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:05:59 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/06 16:18:54 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	freeandreturn(struct s_rules *rules, int *i)
{
	free(rules->ph);
	free(rules->forks);
	free(rules->mutex_general);
	free(rules->mutex);
	free(rules->sb_has_died);
	free(i);
	free(rules);
	return (0);
}
