/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 00:06:49 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/09 23:02:46 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	freeall(struct s_rules *rules, int *i)
{
	free(rules->ph);
	free(rules->forks);
	free(rules->mutex_general);
	free(rules->mutex);
	free(rules->sb_has_died);
	free(rules->sb_has_died_mutex);
	free(i);
	free(rules);
	return (1);
}

int	just_one_filo(struct s_rules *rules, int *i)
{
	if (rules->number_of_philosophers == 1)
	{
		printf("%d %d has died\n", rules->time_to_die, 1);
		return (freeall(rules, i));
	}
	return (0);
}

int	wrong_parameters(struct s_rules *rules, int *i)
{
	printf("Error.\nUsage: ./philo n_of_philo time_to_die ");
	printf("time_to_eat time_to_sleep n_of_times_each_philo_must_eat\n");
	printf("Also, all parameters should be positive\n");
	free(i);
	free(rules);
	return (1);
}

int	parsing(int argc, char **argv, struct s_rules *rules, int *i)
{
	if ((argc >= 5) && (argc <= 6) && (ft_atoi(argv[1]) > 0) && \
	(ft_atoi(argv[2]) > 0) && (ft_atoi(argv[3]) > 0) && (ft_atoi(argv[4]) > 0))
	{
		init_var(rules, argv);
		if (argc == 6)
		{
			if (ft_atoi(argv[5]) <= 0)
			{
				printf("All parameters should be positive\n");
				return (freeall(rules, i));
			}
			rules->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		}
		else
			rules->number_of_times_each_philosopher_must_eat = 2147483647;
	}
	else
		return (wrong_parameters(rules, i));
	return (just_one_filo(rules, i));
}
