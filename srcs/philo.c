/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:37:12 by tnedel            #+#    #+#             */
/*   Updated: 2024/11/04 15:15:10 by tnedel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*survive(void *arg)
{
	t_philo	*tphilo;

	tphilo = arg;
//	sync_threads(tphilo->master);
//	printf("i'm %i and my id : %i\n", tphilo->num, (int)tphilo->id);
	usleep(200000);
	pthread_mutex_lock(&tphilo->master->pmutex);
	if (ft_gettime(&tphilo->master->time_elapsed, tphilo->master->start_time))
		return ((void *)EXIT_FAILURE);
	pthread_mutex_unlock(&tphilo->master->pmutex);
	print_mess(" died\n", tphilo->master->time_elapsed, tphilo);
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
	i = 0;
	while (i < master->nb_philo)
	{
		master->tphilo[i].master = master;
		master->tphilo[i].num = i + 1;
		pthread_mutex_init(&master->tphilo[i].fmutex, NULL);
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
	return (EXIT_SUCCESS);
}
