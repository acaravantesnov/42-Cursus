/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:43:50 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/09 22:39:48 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	init_mutexes(struct s_rules *rules)
{
	int	j;

	j = 0;
	while (j < rules->number_of_philosophers)
	{
		pthread_mutex_init(&(rules->mutex[j]), NULL);
		j++;
	}
	pthread_mutex_init(rules->mutex_general, NULL);
	pthread_mutex_init(rules->sb_has_died_mutex, NULL);
}

int	threads(struct s_rules *rules, int *i)
{
	rules->iter = i;
	*i = 0;
	while (*i < rules->number_of_philosophers)
	{
		if (pthread_create(&rules->ph[*i], NULL, &philosopher, rules) != 0)
			return (1);
		mysleep(1000, rules);
		(*i)++;
	}
	*i = 0;
	while (*i < rules->number_of_philosophers)
	{
		if (pthread_join(rules->ph[*i], NULL) != 0)
			return (1);
		(*i)++;
	}
	return (0);
}

void	destroy_mutexes(struct s_rules *rules)
{
	int	j;

	j = 0;
	while (j < rules->number_of_philosophers)
	{
		pthread_mutex_destroy(&(rules->mutex[j]));
		j++;
	}
	pthread_mutex_destroy(rules->mutex_general);
	pthread_mutex_destroy(rules->sb_has_died_mutex);
}

void	leaks()
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	int				*i;
	struct s_rules	*rules;

	atexit(leaks);
	i = malloc(sizeof(int));
	*i = 0;
	rules = malloc(sizeof(struct s_rules));
	if (parsing(argc, argv, rules, i) == 1)
		return (0);
	init_mutexes(rules);
	if (threads(rules, i) == 1)
		return (freeandreturn(rules, i));
	destroy_mutexes(rules);
	return (freeandreturn(rules, i));
}
