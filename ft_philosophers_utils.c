/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:15:34 by jperras           #+#    #+#             */
/*   Updated: 2022/03/29 17:30:13 by jperras          ###   ########.fr       */
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
