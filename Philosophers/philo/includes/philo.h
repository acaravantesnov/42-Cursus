/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:07:02 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/09 22:13:36 by acaravan         ###   ########.fr       */
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
	pthread_mutex_t		*sb_has_died_mutex;
	struct timeval		t;
	struct timeval		sim_start;
};

int			parsing(int argc, char **argv, struct s_rules *rules, int *i);
void		*init_var(struct s_rules *rules, char **argv);
long		ft_atoi(char *str);
int			freeandreturn(struct s_rules *rules, int *i);
int			*ft_calloc(int size);
suseconds_t	elapsed_time(struct s_rules *rules, \
struct timeval *last_time_i_ate, int opt);
void		*philosopher(void *arg);
void		mysleep(suseconds_t	time, struct s_rules *rules);
int			may_die1(suseconds_t *t_snc_sim_start, \
struct s_rules *rules, int *i);
int			may_die2(struct timeval *last_t_i_ate, \
suseconds_t *t_snc_last_t_i_ate, struct s_rules *rules, int *i);
int			waiting_to_eat(struct s_rules *rules, int *i);
int			eating(struct timeval *last_t_i_ate, suseconds_t *t_snc_sim_start, \
struct s_rules *rules, int *i);
int			sleeping_and_thinking(struct s_rules *rules, int *i);

#endif