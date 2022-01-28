#include "./includes/philo.h"

void*	philosopher(void *index)
{
	int N;
	//int activity;

	N = *(int*)index + 1;
	printf("%d\n", N);
	free(index);
	return (NULL);
}

int	main(int argc, char **argv)
{
	int i;
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat = 0;
	pthread_t	ph[ft_atoi(argv[1])];

	if ((argc != 5) && (argc != 6))
		return (1);
	number_of_philosophers = ft_atoi(argv[1]);
	time_to_die = ft_atoi(argv[2]);
	time_to_eat = ft_atoi(argv[3]);
	time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	printf("%d %d %d %d %d\n", number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, number_of_times_each_philosopher_must_eat);
	
	i = 0;
	while (i < number_of_philosophers)
	{
		int* ptr = malloc (sizeof(int));
		*ptr = i;
		if (pthread_create(&ph[i], NULL, &philosopher, ptr) != 0)
			return (1);
		i++;
	}

	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_join(ph[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
