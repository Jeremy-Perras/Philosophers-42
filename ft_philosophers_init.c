/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:15:34 by jperras           #+#    #+#             */
/*   Updated: 2022/03/31 17:52:37 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <Philosophers.h>

void	ft_init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	rules->mutex = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
	while (i < rules->nb_philo)
	{
		pthread_mutex_init(&rules->mutex[i], NULL);
		i++;
	}
}

void	ft_init_pthread(t_philosophers *philo)
{
	pthread_t *thread;
	int			i;

	i = 0;
	thread = malloc(sizeof(pthread_t) * philo[0].rules->nb_philo);
	while (i < philo[0].rules->nb_philo)
	{
		usleep(50);
		philo[i].died = 0;
		if(pthread_create(&thread[i], NULL, &routine, &(philo[i])) != 0)
			;
			//rules->Error = 1;
		i++;
	}
	i = 0;
	//ft_dead(philo);
	while (i < philo[0].rules->nb_philo)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}

t_philosophers	*ft_init_philo(t_rules *rules, t_philosophers *philo)
{
	int				i;

	i = 0;
	philo = malloc(sizeof(t_philosophers) * rules->nb_philo);
	while ( i < rules->nb_philo)
	{
		if (i == 0)
		{
			philo[i].rightid = rules->nb_philo - 1;
			philo[i].leftid = i + 1;
		}
		else if (i == rules->nb_philo - 1)
		{
			philo[i].leftid = 0;
			philo[i].rightid = i - 1;
		}
		else
		{
			philo[i].leftid = i + 1;
			philo[i].rightid = i - 1;
		}
		philo[i].id = i;
		i++;
	}
	return (philo);
}
