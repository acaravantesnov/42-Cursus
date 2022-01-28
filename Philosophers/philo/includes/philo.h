#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

/*
 * -- Rules --
*/
struct	Rules
{
	int			*iter;
	int			i;
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	pthread_t	*ph;
	int			*forks;
	int			**manos;
};

/*
 * -- Utils --
*/
int	ft_atoi(char *str);

#endif
