/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:43:50 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/03 17:14:24 by acaravan         ###   ########.fr       */
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
	pthread_mutex_lock(&(rules->mutex));
	n = *(rules->iter);
	pthread_mutex_unlock(&rules->mutex);
	activity = 0;
	has_eaten = 0;
	time_since_sim_start = elapsed_time(rules, &(rules->sim_start), 0);
	time_since_last_time_i_ate = 0;
	while (1)
	{
		pthread_mutex_lock(&(rules->mutex));
		if ((time_since_sim_start > (rules->time_to_die)) && (time_since_sim_start != 0))
		{
			printf("%d %d has died\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, *(rules->iter) + 1);
			return (NULL);
		}
		if (has_eaten > 0)
		{
			time_since_last_time_i_ate = elapsed_time (rules, &(last_time_i_ate), 1);
			if ((time_since_last_time_i_ate > (rules->time_to_die)) && (time_since_last_time_i_ate != 0))
			{
				printf("%d %d has died\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, *(rules->iter) + 1);
				return (NULL);
			}
			if (has_eaten >= rules->number_of_times_each_philosopher_must_eat)
				return (NULL);
		}
		pthread_mutex_unlock(&rules->mutex);
		if (activity == 0)
		{
			pthread_mutex_lock(&(rules->mutex));
			if ((rules->forks[n] == 0) && (rules->forks[n + 1] == 0) \
			&& (n != (rules->number_of_philosophers - 1)))
			{
				rules->forks[n] = 1;
				rules->forks[n + 1] = 1;
				rules->manos[n][0] = 1;
				rules->manos[n][1] = 1;
				activity = 1;
				printf("%d %d has taken a fork\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
				printf("%d %d has taken a fork\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
			}
			else if ((rules->forks[n] == 0) && (rules->forks[0] == 0) \
			&& (n == (rules->number_of_philosophers - 1)))
			{
				rules->forks[n] = 1;
				rules->forks[0] = 1;
				rules->manos[n][0] = 1;
				rules->manos[n][1] = 1;
				activity = 1;
				printf("%d %d has taken a fork\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
				printf("%d %d has taken a fork\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
			}
			pthread_mutex_unlock(&(rules->mutex));
		}
		if (activity == 1)
		{
			printf("%d %d is eating\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
			usleep(rules->time_to_eat);
			pthread_mutex_lock(&(rules->mutex));
			gettimeofday(&(rules->t), NULL);
			last_time_i_ate.tv_sec = rules->t.tv_sec;
			last_time_i_ate.tv_usec = rules->t.tv_usec;
			time_since_sim_start = 0;
			has_eaten++;
			if (n != (rules->number_of_philosophers - 1))
			{
				rules->forks[n] = 0;
				rules->forks[n + 1] = 0;
				rules->manos[n][0] = 0;
				rules->manos[n][1] = 0;
			}
			else
			{
				rules->forks[n] = 0;
				rules->forks[0] = 0;
				rules->manos[n][0] = 0;
				rules->manos[n][1] = 0;
			}
			pthread_mutex_unlock(&(rules->mutex));
			activity = 2;
		}
		if (activity == 2)
		{
			printf("%d %d is sleeping\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
			usleep(rules->time_to_sleep);
			activity = 3;
		}
		if (activity == 3)
		{
			printf("%d %d is thinking\n", elapsed_time(rules, &(rules->sim_start), 0) / 1000, n + 1);
			activity = 0;
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int				*i;
	struct s_rules	*rules;

	i = malloc(sizeof(int));
	*i = 0;
	rules = malloc(sizeof(struct s_rules));
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
	pthread_mutex_init(&(rules->mutex), NULL);
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
	pthread_mutex_destroy(&(rules->mutex));
	return (freeandreturn(rules));
}
