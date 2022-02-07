/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elapsed_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:23:57 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/07 00:40:02 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
**	opt == 0 -> Have not eaten yet
**	opt == 1 -> Already eaten
*/

suseconds_t	elapsed_time(struct s_rules *rules, struct timeval *last_time_i_ate, int opt)
{
	suseconds_t	elapsed_time;

	elapsed_time = 0;
	pthread_mutex_lock(rules->mutex_general);
	if (gettimeofday(&(rules->t), NULL) != 0)
		return (0);
	pthread_mutex_unlock(rules->mutex_general);
	if (opt == 0)
	{
		if ((rules->sim_start.tv_sec <= rules->t.tv_sec) && (rules->sim_start.tv_usec <= rules->t.tv_usec))
			elapsed_time = ((rules->t.tv_sec - rules->sim_start.tv_sec) * 1000000) + (rules->t.tv_usec - rules->sim_start.tv_usec);
		else if ((rules->sim_start.tv_sec <= rules->t.tv_sec) && (rules->sim_start.tv_usec > rules->t.tv_usec))
			elapsed_time = ((rules->t.tv_sec - rules->sim_start.tv_sec) * 1000000) - (rules->sim_start.tv_usec - rules->t.tv_usec);
	}
	else if (opt == 1)
	{
		if ((last_time_i_ate->tv_sec <= rules->t.tv_sec) && (last_time_i_ate->tv_usec <= rules->t.tv_usec))
			elapsed_time = ((rules->t.tv_sec - last_time_i_ate->tv_sec) * 1000000) + (rules->t.tv_usec - last_time_i_ate->tv_usec);
		else if ((last_time_i_ate->tv_sec <= rules->t.tv_sec) && (last_time_i_ate->tv_usec > rules->t.tv_usec))
			elapsed_time = ((rules->t.tv_sec - last_time_i_ate->tv_sec) * 1000000) - (last_time_i_ate->tv_usec - rules->t.tv_usec);
	}
	return (elapsed_time);
}
