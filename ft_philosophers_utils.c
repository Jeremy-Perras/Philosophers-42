/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:07:49 by jperras           #+#    #+#             */
/*   Updated: 2022/03/31 18:13:10 by jperras          ###   ########.fr       */
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
	if (philo->id % 2)
		usleep(20000);
	sleep(1);
	pthread_mutex_lock(&(philo->rules->mutex[philo->rightid]));
	gettimeofday(&philo->begin, NULL);
	printf("%lf %d has taken a fork\n",ft_time(philo->begin, philo->rules->start), philo->id);
	pthread_mutex_lock(&(philo->rules->mutex[philo->id]));
	gettimeofday(&philo->begin, NULL);
	printf("%lf %d has taken a fork\n",ft_time(philo->begin, philo->rules->start), philo->id);
	printf("%lf %d is eating\n",ft_time(philo->begin, philo->rules->start), philo->id);
	gettimeofday(&philo->start, NULL);
	pthread_mutex_unlock(&(philo->rules->mutex[philo->id]));
	pthread_mutex_unlock(&(philo->rules->mutex[philo->rightid]));
}


void	ft_dead(t_philosophers *philo)
{
	struct timeval elapsed;
	int				i;

	i = 0;
	//printf("elapsed %lf",ft_time(elapsed, philo[i].start), philo[i].rules->time_to_die);
	
	while (!philo[i].died)
	{
		while(i<philo[i]->rules->nb_philo)

			{
			gettimeofday(&elapsed, NULL);
			if(ft_time(elapsed, philo[i].start) > philo[i].rules->time_to_die)
			{
				philo[i].died = 1;
				printf("%lf died %d\n",ft_time(elapsed, philo[i].start), i);
			}
			i++;
		}
	}
}
