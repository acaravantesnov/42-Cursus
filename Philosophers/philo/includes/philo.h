/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:07:02 by acaravan          #+#    #+#             */
/*   Updated: 2022/01/31 22:09:50 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

struct	Rules
{
	int			number_of_philosophers;
	suseconds_t	time_to_die;
	suseconds_t	time_to_eat;
	suseconds_t	time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	pthread_t	*ph;
	int			*forks;
	int			*iter;
	int			**manos;
	pthread_mutex_t	mutex; //Uno o varios mutex?
	struct		timeval t;
	struct		timeval	sim_start;
};

void*	init_var(struct Rules *rules, char **argv);
long	ft_atoi(char *str);
int		freeandreturn(struct Rules *rules);
int*	ft_calloc(int size);
void	info(struct Rules *rules);

#endif