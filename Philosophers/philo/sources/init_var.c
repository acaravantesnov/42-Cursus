/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:03:20 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/09 22:34:56 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*init_var(struct s_rules *rules, char **argv)
{
	rules->number_of_philosophers = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (gettimeofday(&(rules->t), NULL) == 0)
	{
		rules->sim_start.tv_sec = rules->t.tv_sec;
		rules->sim_start.tv_usec = rules->t.tv_usec;
	}
	else
		return (NULL);
	rules->ph = malloc(rules->number_of_philosophers * sizeof(pthread_t));
	rules->forks = ft_calloc(rules->number_of_philosophers);
	rules->mutex_general = (pthread_mutex_t *)malloc (sizeof(pthread_mutex_t));
	rules->mutex = (pthread_mutex_t *)malloc (rules->number_of_philosophers * \
	sizeof(pthread_mutex_t));
	rules->sb_has_died = (int *)malloc (sizeof(int));
	*(rules->sb_has_died) = 0;
	rules->sb_has_died_mutex = (pthread_mutex_t *) \
	malloc (sizeof(pthread_mutex_t));
	return (rules);
}
