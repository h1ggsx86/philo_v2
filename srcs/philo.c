/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:37:12 by tnedel            #+#    #+#             */
/*   Updated: 2024/11/07 14:49:23 by tnedel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*survive(void *arg)
{
	long	time_elapsed;
	t_philo	*tphilo;

	tphilo = arg;
	time_elapsed = 0;
	while (time_elapsed != 15)
	{
		philo_eat(tphilo, tphilo->master);
		philo_sleep(tphilo->num, tphilo->master);
		philo_think(tphilo->num, tphilo->master);
		time_elapsed++;
	}
	return (NULL);
}

void	*monitoring(void *arg)
{
	int	i;
	t_data	*master;

	master = arg;
	sync_threads(master);
	i = 0;
	while (i < 50)
		i++;
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
	destroy_mutex(&master);
	free(master.tphilo);
	free(master.forks);
	return (EXIT_SUCCESS);
}
