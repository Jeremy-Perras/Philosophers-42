/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:01:25 by jperras           #+#    #+#             */
/*   Updated: 2022/03/29 17:40:56 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_philosophers
{
	struct timeval begin;
	struct timeval end;
	float	elapsed;

}	t_philosophers;

typedef struct s_rules
{
	struct timeval start;
	int		nb_philo;
	float	time_to_die;
	float	time_to_eat;
	float	time_to_sleep;
	float	number_of_times_each_philosopher_must_eat;
	t_philosophers	philo;
	pthread_mutex_t	*mutex;



}	t_rules;

int		ft_atoi(const char *str);
void	ft_init_mutex(t_rules *rules);
#endif

