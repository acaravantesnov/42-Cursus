/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:07:02 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/07 00:40:10 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

struct	s_rules
{
	int					number_of_philosophers;
	suseconds_t			time_to_die;
	suseconds_t			time_to_eat;
	suseconds_t			time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	int					*sb_has_died;
	pthread_t			*ph;
	int					*forks;
	int					*iter;
	pthread_mutex_t		*mutex;
	pthread_mutex_t		*mutex_general;
	struct timeval		t;
	struct timeval		sim_start;
};

void		*init_var(struct s_rules *rules, char **argv);
long		ft_atoi(char *str);
int			freeandreturn(struct s_rules *rules, int *i);
int			*ft_calloc(int size);
suseconds_t	elapsed_time(struct s_rules *rules, struct timeval *last_time_i_ate, int opt);
void		*philosopher(void *arg);
void		info(struct s_rules *rules);

#endif