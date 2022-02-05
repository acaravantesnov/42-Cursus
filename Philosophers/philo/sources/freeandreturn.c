/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeandreturn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:05:59 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/05 16:15:20 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	freeandreturn(struct s_rules *rules)
{
	free(rules->ph);
	free(rules->forks);
	free(rules);
	return (0);
}
