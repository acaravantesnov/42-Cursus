/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeandreturn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:05:59 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/09 22:15:13 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	freeandreturn(struct s_rules *rules, int *i)
{
	free(rules->ph);
	free(rules->forks);
	free(rules->mutex_general);
	free(rules->sb_has_died_mutex);
	free(rules->mutex);
	free(rules->sb_has_died);
	free(i);
	free(rules);
	return (0);
}
