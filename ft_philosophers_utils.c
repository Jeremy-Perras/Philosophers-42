/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:07:49 by jperras           #+#    #+#             */
/*   Updated: 2022/03/31 16:30:31 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <Philosophers.h>


double	ft_time(struct timeval end, struct timeval begin)
{	
	double elapsed;
	elapsed = (end.tv_sec - begin.tv_sec) + (end.tv_usec - begin.tv_usec)/1000000.0;
	return(elapsed);
}

void	ft_eat(t_philosophers *philo)
{
	sleep(2);
	if (philo->id % 2)
		usleep(20000);
	gettimeofday(&philo->begin, NULL);
	pthread_mutex_lock(&(philo->rules->mutex[philo->rightid]));
	printf("%lf %d has taken a fork\n",ft_time(philo->begin, philo->start), philo->id);
	pthread_mutex_lock(&(philo->rules->mutex[philo->id]));
	printf("%lf %d has taken a fork\n",ft_time(philo->begin, philo->start), philo->id);
	printf("%lf %d is eating\n",ft_time(philo->begin, philo->start), philo->id);
	pthread_mutex_unlock(&(philo->rules->mutex[philo->id]));
	pthread_mutex_unlock(&(philo->rules->mutex[philo->rightid]));
}


void	ft_dead(t_philosophers *philo)
{
	(void) philo;	
	
	
}
