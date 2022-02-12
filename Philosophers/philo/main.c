/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:43:50 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/12 17:38:16 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	main(int argc, char **argv)
{
	int				*i;
	int				j;
	struct s_rules	*rules;

	i = malloc(sizeof(int));
	*i = 0;
	rules = malloc(sizeof(struct s_rules));
	if ((argc >= 5) && (argc <= 6))
	{
		init_var(rules, argv);
		if (argc == 6)
			rules->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		else
			rules->number_of_times_each_philosopher_must_eat = 2147483647;
	}
	else
	{
		printf("Error.\nUsage: ./philo <n_of_philo> <time_to_die> ");
		printf("<time_to_eat> <time_to_sleep> <n_of_times_each_philo_must_eat>\n");
		free(i);
		free(rules);
		return (0);
	}
	if (rules->number_of_philosophers == 1)
	{
		printf("%d %d has died\n", rules->time_to_die, 1);
		free(i);
		free(rules);
		return (0);
	}
	j = 0;
	while (j < rules->number_of_philosophers)
	{
		pthread_mutex_init(&(rules->mutex[j]), NULL);
		j++;
	}
	pthread_mutex_init(rules->mutex_general, NULL);
	rules->iter = i;
	*i = 0;
	while (*i < rules->number_of_philosophers)
	{
		if (pthread_create(&rules->ph[*i], NULL, &philosopher, rules) != 0)
			return (freeandreturn(rules, i));
		usleep(100);
		(*i)++;
	}
	*i = 0;
	while (*i < rules->number_of_philosophers)
	{
		if (pthread_join(rules->ph[*i], NULL) != 0)
			return (freeandreturn(rules, i));
		(*i)++;
	}
	info(rules);
	j = 0;
	while (j < rules->number_of_philosophers)
	{
		pthread_mutex_destroy(&(rules->mutex[j]));
		j++;
	}
	pthread_mutex_destroy(rules->mutex_general);
	return (freeandreturn(rules, i));
}
