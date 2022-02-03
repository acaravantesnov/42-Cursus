/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:03:20 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/03 22:14:19 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*init_var(struct s_rules *rules, char **argv)
{
	int	k;

	k = 0;
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
	rules->manos = (int **) malloc(rules->number_of_philosophers * sizeof(int *));
	while (k < rules->number_of_philosophers)
	{
		rules->manos[k] = ft_calloc(2);
		k++;
	}
	return (rules);
}
