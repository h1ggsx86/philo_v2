/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:37:12 by tnedel            #+#    #+#             */
/*   Updated: 2024/11/06 15:47:21 by tnedel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*survive(void *arg)
{
	long	time_elapsed;
	t_philo	*tphilo;

	tphilo = arg;
	time_elapsed = 0;
	while (time_elapsed != 1000)
		eat(tphilo, tphilo->master, &time_elapsed);
//	pthread_mutex_lock(&tphilo->master->pmutex);
//	if (ft_gettime(&time_elapsed, tphilo->master->start_time))
//		return ((void *)EXIT_FAILURE);
//	pthread_mutex_unlock(&tphilo->master->pmutex);
//	print_mess(" died\n", time_elapsed, tphilo);
	return (NULL);
}

void	*monitoring(void *arg)
{
	t_data	*master;

	master = arg;
	sync_threads(master);
	return (NULL);
}

int	init_philo(t_data *master, char *av[])
{
	int		i;
	t_philo	*tphilo;

	set_up_master(master, av);
	tphilo = malloc(sizeof(*tphilo) * master->nb_philo);
	if (!tphilo)
		return (EXIT_FAILURE);
	master->tphilo = tphilo;
	set_tphilo(master);
	pthread_create(&master->id, NULL, &monitoring, master);
	i = 0;
	while (i < master->nb_philo)
	{
		if(pthread_create(&master->tphilo[i].id, NULL, \
										&survive, \
										&master->tphilo[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	join_philo(t_data *master)
{
	int		i;
	void	*res;

	res = NULL;
	i = 0;
	while (i < master->nb_philo)
	{
		if (pthread_join(master->tphilo[i].id, &res))
			return (EXIT_FAILURE);
//		printf("philo %i joined and succeeded\n", master->tphilo[i].num);
		i++;
	}
	pthread_join(master->id, NULL);
	return (EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{
	t_data	master;

	if (ac < 2)
		return (usage_mess(), EXIT_FAILURE);
	if (init_philo(&master, av))
		return (EXIT_FAILURE);
	if (join_philo(&master))
		return (EXIT_FAILURE);
	pthread_mutex_destroy(&master.pmutex);
	pthread_mutex_destroy(&master.tmutex);
	destroy_mutex(&master);
	return (EXIT_SUCCESS);
}
