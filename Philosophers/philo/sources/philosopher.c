/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:26:38 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/07 23:39:26 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
**	i[0] -> n
**	i[1] -> activity
**	i[2] -> has_eaten
**
**	activity == 0 -> Waiting to eat
**	activity == 1 -> Eating
**	activity == 2 -> Sleeping
**	activity == 3 -> Thinking
*/

int	may_die(struct timeval *last_t_i_ate, suseconds_t *t_snc_sim_start, \
suseconds_t *t_snc_last_t_i_ate, struct s_rules *rules, int *i)
{
	if ((*t_snc_sim_start > (rules->time_to_die * 1000)) && \
	(*t_snc_sim_start != 0))
	{
		printf("%d %d has died\n", \
		elapsed_time(rules, &(rules->sim_start), 0) / 1000, i[0] + 1);
		pthread_mutex_lock(rules->mutex_general);
		*(rules->sb_has_died) = 1;
		pthread_mutex_unlock(rules->mutex_general);
		return (1);
	}
	if (i[2] > 0)
	{
		*t_snc_last_t_i_ate = elapsed_time (rules, last_t_i_ate, 1);
		if ((*t_snc_last_t_i_ate > (rules->time_to_die * 1000)) && \
		(*t_snc_last_t_i_ate != 0))
		{
			printf("%d %d has died\n", \
			elapsed_time(rules, &(rules->sim_start), 0) / 1000, i[0] + 1);
			pthread_mutex_lock(rules->mutex_general);
			*(rules->sb_has_died) = 1;
			pthread_mutex_unlock(rules->mutex_general);
			return (1);
		}
		if (i[2] >= rules->number_of_times_each_philosopher_must_eat)
			return (1);
	}
	return (0);
}

int	waiting_to_eat(struct s_rules *rules, int *i)
{
	if (i[1] == 0)
	{
		if ((rules->forks[i[0]] == 0) && (rules->forks[i[0] + 1] == 0) \
		&& (i[0] != (rules->number_of_philosophers - 1)))
		{
			pthread_mutex_lock(&(rules->mutex[i[0]]));
			rules->forks[i[0]] = 1;
			pthread_mutex_lock(&(rules->mutex[i[0] + 1]));
			rules->forks[i[0] + 1] = 1;
			i[1] = 1;
			if (*(rules->sb_has_died) == 1)
				return (1);
			printf("%d %d has taken a fork\n", \
			elapsed_time(rules, &(rules->sim_start), 0) / 1000, i[0] + 1);
			printf("%d %d has taken a fork\n", \
			elapsed_time(rules, &(rules->sim_start), 0) / 1000, i[0] + 1);
		}
		else if ((rules->forks[i[0]] == 0) && (rules->forks[0] == 0) \
		&& (i[0] == (rules->number_of_philosophers - 1)))
		{
			pthread_mutex_lock(&(rules->mutex[i[0]]));
			rules->forks[i[0]] = 1;
			pthread_mutex_lock(&(rules->mutex[0]));
			rules->forks[0] = 1;
			i[1] = 1;
			if (*(rules->sb_has_died) == 1)
				return (1);
			printf("%d %d has taken a fork\n", \
			elapsed_time(rules, &(rules->sim_start), 0) / 1000, i[0] + 1);
			printf("%d %d has taken a fork\n", \
			elapsed_time(rules, &(rules->sim_start), 0) / 1000, i[0] + 1);
		}
	}
	return (0);
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
		usleep(rules->time_to_eat * 1000);
		i[2]++;
		if (i[0] != (rules->number_of_philosophers - 1))
		{
			rules->forks[i[0]] = 0;
			pthread_mutex_unlock(&(rules->mutex[i[0]]));
			rules->forks[i[0] + 1] = 0;
			pthread_mutex_unlock(&(rules->mutex[i[0] + 1]));
		}
		else
		{
			rules->forks[i[0]] = 0;
			pthread_mutex_unlock(&(rules->mutex[i[0]]));
			rules->forks[0] = 0;
			pthread_mutex_unlock(&(rules->mutex[0]));
		}
		i[1] = 2;
	}
	return (0);
}

int	sleeping_and_thinking(struct s_rules *rules, int *i)
{
	if (i[1] == 2)
	{
		if (*(rules->sb_has_died) == 1)
			return (1);
		printf("%d %d is sleeping\n", \
		elapsed_time(rules, &(rules->sim_start), 0) / 1000, i[0] + 1);
		usleep(rules->time_to_sleep * 1000);
		i[1] = 3;
	}
	if (i[1] == 3)
	{
		if (*(rules->sb_has_died) == 1)
			return (1);
		printf("%d %d is thinking\n", \
		elapsed_time(rules, &(rules->sim_start), 0) / 1000, i[0] + 1);
		i[1] = 0;
	}
	return (0);
}

void	*philosopher(void *arg)
{
	int				i[3];
	struct s_rules	*rules;
	struct timeval	last_t_i_ate;
	suseconds_t		t_snc_sim_start;
	suseconds_t		t_snc_last_t_i_ate;

	rules = arg;
	i[0] = *(rules->iter);
	i[1] = 0;
	i[2] = 0;
	t_snc_sim_start = elapsed_time(rules, &(rules->sim_start), 0);
	t_snc_last_t_i_ate = 0;
	rules->number_of_times_each_philosopher_must_eat = 1000000;
	if (i[0] % 2 != 0)
		usleep(100);
	while (1)
	{
		if (may_die(&(last_t_i_ate), &(t_snc_sim_start), \
		&(t_snc_last_t_i_ate), rules, i) == 1)
			return (NULL);
		if (waiting_to_eat(rules, i) == 1)
			return (NULL);
		if (eating(&(last_t_i_ate), &(t_snc_sim_start), rules, i) == 1)
			return (NULL);
		if (sleeping_and_thinking(rules, i) == 1)
			return (NULL);
	}
	return (NULL);
}
