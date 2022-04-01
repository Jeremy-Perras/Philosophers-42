/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:07:49 by jperras           #+#    #+#             */
/*   Updated: 2022/04/01 17:27:56 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <Philosophers.h>


long double	ft_time(struct timeval end, struct timeval begin)
{	
	long double elapsed;

	elapsed = (end.tv_sec - begin.tv_sec) * 1000.0 + (end.tv_usec - begin.tv_usec) / 1000.0; 
	return(elapsed);
}

void	ft_eat(t_philosophers *philo)
{
	if (philo->rules->death != 1 && philo->id % 2)
	{
		usleep(2000);
		ft_fork(philo);
	}
	else if (philo->rules->death != 1)
		ft_right_fork(philo);
}

void	ft_dead(t_philosophers *philo)
{
	struct timeval elapsed;
	int				i;
	int				flag;
	int 			j;

	i = 0;
	flag = 0;
	usleep(philo[i].rules->nb_philo * 50);
	j = philo[i].rules->nb_philo;
	while (flag == 0 && philo[i].rules->win != 1)
	{
		while(i < j && flag == 0 && philo[i].rules->win != 1)
		{
			gettimeofday(&elapsed, NULL);
			if(ft_time(elapsed, philo[i].life) >= philo[i].rules->time_to_die)
			{
				philo[i].rules->death = 1;
				printf("%Lf %d died \n",ft_time(elapsed, philo->start), i);
				flag = 1;
			}
			i++;
		}
		i = 0;
	}
}

void	ft_sleep(t_philosophers *philo)
{
	struct timeval begin;
	struct timeval end;
	int				flag;

	gettimeofday(&begin, NULL);
	printf("%Lf %d is sleeping\n",ft_time(begin, philo->start), philo->id);
	flag = 0;
	while (flag != 1)
	{
		gettimeofday(&end, NULL);
		if(ft_time(end, begin) >= philo->rules->time_to_sleep)
			flag = 1;
	}
}

void	ft_think(t_philosophers *philo)
{
	struct timeval begin;

	gettimeofday(&begin, NULL);
	printf("%Lf %d is thinking\n",ft_time(begin, philo->start), philo->id);
}
