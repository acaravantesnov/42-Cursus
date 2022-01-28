#include "./includes/philo.h"

int*	ft_calloc(int size)
{
	int i;
	int *ptr;
	
	i = 0;
	ptr = malloc(sizeof(int) * size);
	while (i < size)
	{
		ptr[i] = 0;
		i++;
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
	int	N;
	/*
		+ activity = 0 -> Taking a fork
		+ activity = 1 -> Eating
		+ activity = 2 -> Sleeping
		+ activity = 3 -> Thinking
		+ activity = 4 -> Died
	*/
	int	activity = 0;
	N = *(rules->iter) + 1;
	while (activity != 4)
	{
		if (*(rules->iter) < rules->number_of_philosophers - 1)
		{
			if (rules->forks[*(rules->iter)] == 0)
			{
				printf("I took a fork.\n");
				rules->manos[*(rules->iter)][0] = 1;
				rules->forks[*(rules->iter)] = 1;
			}
			if (rules->forks[*(rules->iter) + 1] == 0)
			{
				printf("I took a fork.\n");
				rules->manos[*(rules->iter)][1] = 1;
				rules->forks[*(rules->iter) + 1] = 1;
			}
		}
		else if (*(rules->iter) == (rules->number_of_philosophers - 1))
		{
			if (rules->forks[*(rules->iter)] == 0)
			{
				printf("I took a fork.\n");
				rules->manos[*(rules->iter)][0] = 1;
				rules->forks[*(rules->iter)] = 1;
			}
			if (rules->forks[0] == 0)
			{
				printf("I took a fork.\n");
				rules->manos[*(rules->iter)][1] = 1;
				rules->forks[0] = 1;
			}
		}
		activity = 4;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	struct Rules *rules = malloc(sizeof(struct Rules));
	pthread_mutex_t	mutex;
	pthread_mutex_init(&mutex, NULL);
	
	int i = 0;
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
		{
			printf("%i", rules->manos[i][j]);
		}
		printf("\n");
	}

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (pthread_create(&rules->ph[i], NULL, &philosopher, rules) != 0)
			return (freephandexit(rules->ph));
		i++;
	}

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (pthread_join(rules->ph[i], NULL) != 0)
			return (freephandexit(rules->ph));
		i++;
	}
	for (int i = 0; i < rules->number_of_philosophers; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%i", rules->manos[i][j]);
		}
		printf("\n");
	}
	pthread_mutex_destroy(&mutex);
	return (0);
}
