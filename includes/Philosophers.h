/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:01:25 by jperras           #+#    #+#             */
/*   Updated: 2022/04/01 17:08:53 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
typedef struct s_rules
{
	struct timeval start;
	struct timeval begin;
	int		nb_philo;
	float	time_to_die;
	float	time_to_eat;
	float	time_to_sleep;
	float	number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	*mutex;
	int		Error;
	int		id_thread;
	int		death;
	int		*id_int;
	int 	win;
}	t_rules;

typedef struct s_philosophers
{
	int		id;
	int		leftid;
	int		rightid;
	int		number_of_eat;
	struct timeval begin;
	struct timeval life;
	struct timeval start;
	struct timeval end;
	t_rules *rules;
}	t_philosophers;


int		ft_atoi(const char *str);
void	ft_init_mutex(t_rules *rules);
void	*ft_init_pthread(t_philosophers *philo);
t_philosophers	*ft_init_philo(t_rules *rules,t_philosophers *philo);
void	*routine(void *void_args);
void	ft_eat(t_philosophers *philo);
void	ft_dead(t_philosophers *philo);
void	ft_sleep(t_philosophers *philo);
void	ft_think(t_philosophers *philo);
long double ft_time(struct timeval end, struct timeval begin);
int		ft_check(int argc, char **argv);
void	*ft_fork(t_philosophers *philo);
void	*ft_right_fork(t_philosophers *philo);
void	ft_destroy(t_philosophers *philo, pthread_t *thread);
#endif

