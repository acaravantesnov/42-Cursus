/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:43:50 by acaravan          #+#    #+#             */
/*   Updated: 2022/01/31 22:32:45 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

suseconds_t	elapsed_time(struct Rules *rules)
{
	suseconds_t	elapsed_time;
	
	if (gettimeofday(&(rules->t), NULL) != 0)
		return (0);
	if ((rules->sim_start.tv_sec <= rules->t.tv_sec) && (rules->sim_start.tv_usec <= rules->t.tv_usec))
		elapsed_time = ((rules->t.tv_sec - rules->sim_start.tv_sec) * 1000000) + (rules->t.tv_usec - rules->sim_start.tv_usec);
	else if ((rules->sim_start.tv_sec <= rules->t.tv_sec) && (rules->sim_start.tv_usec > rules->t.tv_usec))
		elapsed_time = ((rules->t.tv_sec - rules->sim_start.tv_sec) * 1000000) - (rules->sim_start.tv_usec - rules->t.tv_usec);
	return (elapsed_time);
}

void*	philosopher(void *arg)
{
	struct	Rules	*rules;
	suseconds_t		time;

	rules = arg;
	pthread_mutex_lock(&(rules->mutex));
	int n = *(rules->iter);
	pthread_mutex_unlock(&rules->mutex);
	int activity = 0; // Esperando a comer
	// if (activity == 1) --> Comiendo
	// if (activity == 2) --> Durmiendo
	// if (activity == 3) --> Pensando
	while (1)
	{
		pthread_mutex_lock(&(rules->mutex));
		time = elapsed_time(rules);
		if (time > (rules->time_to_die))
		{
			printf("%d has died\n", *(rules->iter) + 1);
			pthread_detach(rules->ph[*(rules->iter)]);
			return (NULL);	
		}
		pthread_mutex_unlock(&rules->mutex);
		if (activity == 0) //Waiting to eat
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

				printf("%d has taken a fork\n", n + 1);
				printf("%d has taken a fork\n", n + 1);
			}
			else if ((rules->forks[n] == 0) && (rules->forks[0] == 0) \
			&& (n == (rules->number_of_philosophers - 1)))
			{
				rules->forks[n] = 1;
				rules->forks[0] = 1;
				rules->manos[n][0] = 1;
				rules->manos[n][1] = 1;
				activity = 1;

				printf("%d has taken a fork\n", n + 1);
				printf("%d has taken a fork\n", n + 1);
			}
			pthread_mutex_unlock(&(rules->mutex));
		}
		if (activity == 1) //Eating
		{
			printf("%d is eating\n", n + 1);
			usleep(rules->time_to_eat);
			pthread_mutex_lock(&(rules->mutex));
			gettimeofday(&(rules->t), NULL);
			rules->sim_start.tv_sec = rules->t.tv_sec;
			rules->sim_start.tv_usec = rules->t.tv_usec;
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
		if (activity == 2) //Sleeping
		{
			printf("%d is sleeping\n", n + 1);
			usleep(rules->time_to_sleep);
			activity = 3;
		}
		if (activity == 3) //Thinking
		{
			printf("%d is thinking\n", n + 1);
			activity = 0;
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int	*i;
	i = malloc(sizeof(int));
	*i = 0;
	struct	Rules *rules = malloc(sizeof(struct Rules));
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
