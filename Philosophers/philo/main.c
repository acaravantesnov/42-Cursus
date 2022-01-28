#include "./includes/philo.h"

int	freephandexit(pthread_t *ph)
{
	free(ph);
	return (1);
}

void*	philosopher(void* arg)
{
	struct Philosopher ph;
	ph.N = *(int*)arg + 1;
	printf("%d", ph.N);
	return (0);
}

int	main(int argc, char **argv)
{
	int i;

	if ((argc != 5) && (argc != 6))
		return (1);

	rules.ph = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	rules.number_of_philosophers = ft_atoi(argv[1]);
	rules.time_to_die = ft_atoi(argv[2]);
	rules.time_to_eat = ft_atoi(argv[3]);
	rules.time_to_sleep = ft_atoi(argv[4]);
	
	if (argc == 6)
		rules.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	printf("%d %d %d %d %d\n", rules.number_of_philosophers, rules.time_to_die, rules.time_to_eat, rules.time_to_sleep, rules.number_of_times_each_philosopher_must_eat);
	
	i = 0;
	while (i < rules.number_of_philosophers)
	{
		int* index;
		index = malloc(sizeof(int));
		*index = i;
		if (pthread_create(&rules.ph[i], NULL, &philosopher, (void*)index) != 0)
			return (freephandexit(rules.ph));
		i++;
	}

	i = 0;
	while (i < rules.number_of_philosophers)
	{
		if (pthread_join(rules.ph[i], NULL) != 0)
			return (freephandexit(rules.ph));
		i++;
	}
	return (0);
}
