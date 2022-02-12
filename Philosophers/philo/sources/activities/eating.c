/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:18:15 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/12 19:38:16 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	anyfilo_eating(struct s_rules *rules, int *i)
{
	rules->forks[i[0]] = 0;
	pthread_mutex_unlock(&(rules->mutex[i[0]]));
	rules->forks[i[0] + 1] = 0;
	pthread_mutex_unlock(&(rules->mutex[i[0] + 1]));
}

void	lastfilo_eating(struct s_rules *rules, int *i)
{
	rules->forks[i[0]] = 0;
	pthread_mutex_unlock(&(rules->mutex[i[0]]));
	rules->forks[0] = 0;
	pthread_mutex_unlock(&(rules->mutex[0]));
}

int	eating(struct timeval *last_t_i_ate, suseconds_t *t_snc_sim_start, \
struct s_rules *rules, int *i)
{
	if (i[1] == 1)
	{
		if (*(rules->sb_has_died) == 1)
			return (1);
		pthread_mutex_lock(rules->mutex_general);
		gettimeofday(&(rules->t), NULL);
		pthread_mutex_unlock(rules->mutex_general);
		last_t_i_ate->tv_sec = rules->t.tv_sec;
		last_t_i_ate->tv_usec = rules->t.tv_usec;
		*t_snc_sim_start = 0;
		printf("%d %d is eating\n", \
		elapsed_time(rules, &(rules->sim_start), 0) / 1000, i[0] + 1);
		mysleep(rules->time_to_eat * 1000);
		i[2]++;
		if (i[0] != (rules->number_of_philosophers - 1))
			anyfilo_eating(rules, i);
		else
			lastfilo_eating(rules, i);
		i[1] = 2;
	}
	return (0);
}
