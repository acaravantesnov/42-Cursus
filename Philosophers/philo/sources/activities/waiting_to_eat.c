/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_to_eat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:18:32 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/12 19:38:17 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	anyfilo_waiting_to_eat(struct s_rules *rules, int *i)
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
	return (0);
}

int	lastfilo_waiting_to_eat(struct s_rules *rules, int *i)
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
	return (0);
}

int	waiting_to_eat(struct s_rules *rules, int *i)
{
	if (i[1] == 0)
	{
		if ((rules->forks[i[0]] == 0) && (rules->forks[i[0] + 1] == 0) \
		&& (i[0] != (rules->number_of_philosophers - 1)))
		{
			if (anyfilo_waiting_to_eat(rules, i) == 1)
				return (1);
		}
		else if ((rules->forks[i[0]] == 0) && (rules->forks[0] == 0) \
		&& (i[0] == (rules->number_of_philosophers - 1)))
		{
			if (lastfilo_waiting_to_eat(rules, i) == 1)
				return (1);
		}
	}
	return (0);
}
