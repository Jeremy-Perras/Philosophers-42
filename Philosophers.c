/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:40:33 by jperras           #+#    #+#             */
/*   Updated: 2022/03/29 17:41:05 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Philosophers.h>

void	*routine(void *void_args)
{
	t_rules *rules;

	rules = (t_rules *) void_args;
	//void	ft_eat();
	//void	ft_sleep();
	//void	ft_think();
	
	pthread_mutex_lock(&rules->mutex[0]);
	printf("start\n");
	sleep(3);
	pthread_mutex_unlock(&rules->mutex[0]);
	printf("end\n");
	return(0);
}

int	main(int argc ,char **argv)
{
	t_rules	rules;
	pthread_t	*thread;
	int	i;

	i = 0;
	thread = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	rules.nb_philo = ft_atoi(argv[1]);
	ft_init_mutex(&rules);
	while (i < ft_atoi(argv[1]))
	{
		if (pthread_create(&thread[i], NULL, &routine, &rules) != 0)
				return(1);
		i++;
	}
	i = 0; 
	while (i < ft_atoi(argv[1]))
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	return (1);
}
