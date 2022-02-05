/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:43:50 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/05 16:54:53 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

/*
**	opt == 0 -> Have not eaten yet
**	opt == 1 -> Already eaten
*/

suseconds_t	elapsed_time(struct s_rules *rules, struct timeval *last_time_i_ate, int opt)
{
	suseconds_t	elapsed_time;

	elapsed_time = 0;
	if (gettimeofday(&(rules->t), NULL) != 0)
		return (0);
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

/*
**	activity == 0 -> Waiting to eat
**	activity == 1 -> Eating
**	activity == 2 -> Sleeping
**	activity == 3 -> Thinking
*/

void	*philosopher(void *arg)
{
	int				n;
	int				activity;
	int				has_eaten;
	struct s_rules	*rules;
	struct timeval	last_time_i_ate;
	suseconds_t		time_since_sim_start;
	suseconds_t		time_since_last_time_i_ate;

	rules = arg;
	n = *(rules->iter);
	activity = 0;
	has_eaten = 0;
	time_since_sim_start = elapsed_time(rules, &(rules->sim_start), 0);
	time_since_last_time_i_ate = 0;
	rules->number_of_times_each_philosopher_must_eat = 1000000;
	while (1)
	{
		if ((time_since_sim_start > (rules->time_to_die * 1000)) && (time_since_sim_start != 0))
		{
			
			printf("%d %d has died\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
			printf("Muerto = %d\n", *(rules->sb_has_died));
			pthread_mutex_lock(rules->mutex_general);
			*(rules->sb_has_died) = 1;
			pthread_mutex_unlock(rules->mutex_general);
			return (NULL);
		}
		if (has_eaten > 0)
		{
			time_since_last_time_i_ate = elapsed_time (rules, &(last_time_i_ate), 1);
			if ((time_since_last_time_i_ate > (rules->time_to_die * 1000)) && (time_since_last_time_i_ate != 0))
			{
				printf("%d %d has died\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
				printf("Muerto = %d\n", *(rules->sb_has_died));
				pthread_mutex_lock(rules->mutex_general);
				*(rules->sb_has_died) = 1;
				pthread_mutex_unlock(rules->mutex_general);
				return (NULL);
			}
			if (has_eaten >= rules->number_of_times_each_philosopher_must_eat)
				return (NULL);
		}
		if (activity == 0)
		{
			if ((rules->forks[n] == 0) && (rules->forks[n + 1] == 0) \
			&& (n != (rules->number_of_philosophers - 1)))
			{
				pthread_mutex_lock(&(rules->mutex[n]));
				rules->forks[n] = 1;
				pthread_mutex_lock(&(rules->mutex[n + 1]));
				rules->forks[n + 1] = 1;
				activity = 1;
				if (*(rules->sb_has_died) == 1)
					return (NULL);
				printf("%d %d has taken a fork\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
				printf("%d %d has taken a fork\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
			}
			else if ((rules->forks[n] == 0) && (rules->forks[0] == 0) \
			&& (n == (rules->number_of_philosophers - 1)))
			{
				pthread_mutex_lock(&(rules->mutex[n]));
				rules->forks[n] = 1;
				pthread_mutex_lock(&(rules->mutex[0]));
				rules->forks[0] = 1;
				activity = 1;
				if (*(rules->sb_has_died) == 1)
					return (NULL);
				printf("%d %d has taken a fork\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
				printf("%d %d has taken a fork\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
			}
		}
		if (activity == 1)
		{
			if (*(rules->sb_has_died) == 1)
					return (NULL);
			printf("%d %d is eating\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
			usleep(rules->time_to_eat * 1000);
			pthread_mutex_lock(rules->mutex_general);
			gettimeofday(&(rules->t), NULL);
			pthread_mutex_unlock(rules->mutex_general);
			last_time_i_ate.tv_sec = rules->t.tv_sec;
			last_time_i_ate.tv_usec = rules->t.tv_usec;
			time_since_sim_start = 0;
			has_eaten++;
			if (n != (rules->number_of_philosophers - 1))
			{
				rules->forks[n] = 0;
				pthread_mutex_unlock(&(rules->mutex[n]));
				rules->forks[n + 1] = 0;
				pthread_mutex_unlock(&(rules->mutex[n + 1]));
			}
			else
			{
				rules->forks[n] = 0;
				pthread_mutex_unlock(&(rules->mutex[n]));
				rules->forks[0] = 0;
				pthread_mutex_unlock(&(rules->mutex[0]));
			}
			activity = 2;
		}
		if (activity == 2)
		{
			if (*(rules->sb_has_died) == 1)
					return (NULL);
			printf("%d %d is sleeping\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
			usleep(rules->time_to_sleep * 1000);
			activity = 3;
		}
		if (activity == 3)
		{
			if (*(rules->sb_has_died) == 1)
					return (NULL);
			printf("%d %d is thinking\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
			activity = 0;
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int				*i;
	int				j;
	struct s_rules	*rules;

	i = malloc(sizeof(int));
	*i = 0;
	rules = malloc(sizeof(struct s_rules));
	rules->mutex = (pthread_mutex_t*)malloc (rules->number_of_philosophers * sizeof(pthread_mutex_t));
	rules->mutex_general = (pthread_mutex_t*)malloc (sizeof(pthread_mutex_t));
	rules->sb_has_died = (int*)malloc (sizeof(int));
	*(rules->sb_has_died) = 0;
	if ((argc >= 5) && (argc <= 6))
	{
		init_var(rules, argv);
		if (argc == 6)
			rules->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
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
			return (freeandreturn(rules));
		usleep(100);
		(*i)++;
	}
	*i = 0;
	while (*i < rules->number_of_philosophers)
	{
		if (pthread_join(rules->ph[*i], NULL) != 0)
			return (freeandreturn(rules));
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
	return (freeandreturn(rules));
}
