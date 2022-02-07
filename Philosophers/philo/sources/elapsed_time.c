/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elapsed_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:23:57 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/07 22:05:56 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
**	opt == 0 -> Have not eaten yet
**	opt == 1 -> Already eaten
*/

void	opt1(struct s_rules *rules, suseconds_t *t)
{
	if ((rules->sim_start.tv_sec <= rules->t.tv_sec) && \
	(rules->sim_start.tv_usec <= rules->t.tv_usec))
		*t = ((rules->t.tv_sec - rules->sim_start.tv_sec) * 1000000) + \
		(rules->t.tv_usec - rules->sim_start.tv_usec);
	else if ((rules->sim_start.tv_sec <= rules->t.tv_sec) && \
	(rules->sim_start.tv_usec > rules->t.tv_usec))
		*t = ((rules->t.tv_sec - rules->sim_start.tv_sec) * 1000000) - \
		(rules->sim_start.tv_usec - rules->t.tv_usec);
}

void	opt2(struct s_rules *rules, struct timeval *last_t_i_ate, \
suseconds_t *t)
{
	if ((last_t_i_ate->tv_sec <= rules->t.tv_sec) && \
	(last_t_i_ate->tv_usec <= rules->t.tv_usec))
		*t = ((rules->t.tv_sec - last_t_i_ate->tv_sec) * 1000000) + \
		(rules->t.tv_usec - last_t_i_ate->tv_usec);
	else if ((last_t_i_ate->tv_sec <= rules->t.tv_sec) && \
	(last_t_i_ate->tv_usec > rules->t.tv_usec))
		*t = ((rules->t.tv_sec - last_t_i_ate->tv_sec) * 1000000) - \
		(last_t_i_ate->tv_usec - rules->t.tv_usec);
}

suseconds_t	elapsed_time(struct s_rules *rules, struct timeval *last_t_i_ate, \
int opt)
{
	suseconds_t	t;

	t = 0;
	pthread_mutex_lock(rules->mutex_general);
	if (gettimeofday(&(rules->t), NULL) != 0)
		return (0);
	pthread_mutex_unlock(rules->mutex_general);
	if (opt == 0)
		opt1(rules, &t);
	else if (opt == 1)
		opt2(rules, last_t_i_ate, &t);
	return (t);
}
