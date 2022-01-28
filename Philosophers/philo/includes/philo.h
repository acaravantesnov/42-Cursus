#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

/*
 * -- Philosophers --
*/ 
struct	Philosopher
{
	int	N;
	int	activity;
};

/*
 * -- Rules --
*/
struct	Rules
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	pthread_t	*ph;
} rules;

/*
 * -- Utils --
*/
int	ft_atoi(char *str);

#endif
