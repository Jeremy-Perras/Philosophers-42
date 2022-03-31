/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:40:33 by jperras           #+#    #+#             */
/*   Updated: 2022/03/31 17:55:02 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Philosophers.h>

void	*routine(void *void_args)
{
	(void) void_args;
	int i;

	t_philosophers *philo;
	i = 0;
	while (i<5)
	{
		philo = (t_philosophers *) void_args;
		gettimeofday(&philo->start, NULL);
		gettimeofday(&philo->rules->start, NULL);

		ft_eat(philo);
		i++;
	}
	return(0);
}

int	main(int argc ,char **argv)
{
	(void) argc;
	
	t_rules	rules;
	t_philosophers *philo;
	int				i;

	philo = NULL;
	i = 0;
	rules.nb_philo = ft_atoi(argv[1]);
	rules.time_to_die = ft_atoi(argv[2])/1000.0;
	rules.time_to_eat = ft_atoi(argv[3])/1000.0;
	rules.time_to_sleep = ft_atoi(argv[4])/1000.0;
	rules.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	ft_init_mutex(&rules);
	philo = ft_init_philo(&rules, philo);
	while (i < rules.nb_philo)
	{
		philo[i].rules = &rules;
		i++;
	}
	ft_init_pthread(philo);
}
