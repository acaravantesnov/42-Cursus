#include "./includes/philo.h"

int*	ft_calloc(int size)
{
	int x;
	int *ptr;
	
	x = 0;
	ptr = malloc(sizeof(int) * size);
	while (x < size)
	{
		ptr[x] = 0;
		x++;
	}
	return (ptr);
}

int		freephandexit(pthread_t *ph)
{
	free(ph);
	return (1);
}

void*	philosopher(void* arg)
{
	struct Rules *rules = arg;
	//int	N;
	/*
		+ activity = 0 -> Taking a fork
		+ activity = 1 -> Eating
		+ activity = 2 -> Sleeping
		+ activity = 3 -> Thinking
		+ activity = 4 -> Died
	*/
	int	activity = 0;
	//N = *(rules->iter) + 1;
	while (activity != 4)
	{
		if (*(rules->iter) < rules->number_of_philosophers - 1)
		{
			if (rules->forks[*(rules->iter)] == 0)
			{
				printf("%d took a fork.\n", *(rules->iter));
				pthread_mutex_lock(&(rules->mutex));
				rules->manos[*(rules->iter)][0] = 1;
				rules->forks[*(rules->iter)] = 1;
				pthread_mutex_unlock(&(rules->mutex));
			}
			if (rules->forks[*(rules->iter) + 1] == 0)
			{
				printf("%d took a fork.\n", *(rules->iter));
				pthread_mutex_lock(&(rules->mutex));
				rules->manos[*(rules->iter)][1] = 1;
				rules->forks[*(rules->iter) + 1] = 1;
				pthread_mutex_unlock(&(rules->mutex));
			}
		}
		else if (*(rules->iter) == (rules->number_of_philosophers - 1))
		{
			if (rules->forks[*(rules->iter)] == 0)
			{
				printf("%d took a fork.\n", *(rules->iter));
				pthread_mutex_lock(&(rules->mutex));
				rules->manos[*(rules->iter)][0] = 1;
				rules->forks[*(rules->iter)] = 1;
				pthread_mutex_unlock(&(rules->mutex));
			}
			if (rules->forks[0] == 0)
			{
				printf("%d took a fork.\n", *(rules->iter));
				pthread_mutex_lock(&(rules->mutex));
				rules->manos[*(rules->iter)][1] = 1;
				rules->forks[0] = 1;
				pthread_mutex_unlock(&(rules->mutex));
			}
		}
		//printf("%i", N);
		activity++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	struct Rules *rules = malloc(sizeof(struct Rules));
	pthread_mutex_init(&(rules->mutex), NULL);
	
	int i = 0;
	int j;
	rules->iter = &i;
	if ((argc != 5) && (argc != 6))
		return (1);
	if (argc == 6)
		rules->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);

	rules->number_of_philosophers = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);

	rules->ph = malloc(sizeof(pthread_t) * rules->number_of_philosophers);
	rules->forks = ft_calloc(rules->number_of_philosophers);

	rules->manos = (int**)malloc(sizeof(int*) * rules->number_of_philosophers);
	while (i < rules->number_of_philosophers)
	{
		rules->manos[i] = ft_calloc(2);
		i++;
	}

	printf("%d %d %d %d %d\n", rules->number_of_philosophers, rules->time_to_die, \
	rules->time_to_eat, rules->time_to_sleep, \
	rules->number_of_times_each_philosopher_must_eat);
	for (int i = 0; i < rules->number_of_philosophers; i++)
	{
		for (int j = 0; j < 2; j++)
			ft_printf("%d", rules->manos[i][j]);
		write(1, "\n", 1);
	}

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (pthread_create(&rules->ph[i], NULL, &philosopher, rules) != 0)
			return (freephandexit(rules->ph));
		i++;
	}

	j = 0;
	while (j < rules->number_of_philosophers)
	{
		if (pthread_join(rules->ph[j], NULL) != 0)
			return (freephandexit(rules->ph));
		j++;
	}
	for (int j = 0; j < rules->number_of_philosophers; j++)
	{
		for (int k = 0; k < 2; k++)
			ft_printf("%d", rules->manos[j][k]);
		write(1, "\n", 1);
	}
	pthread_mutex_destroy(&(rules->mutex));
	return (0);
}
