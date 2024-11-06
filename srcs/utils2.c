/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:38:07 by tnedel            #+#    #+#             */
/*   Updated: 2024/11/06 14:41:04 by tnedel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mess(char *s, int curtime, t_philo *tphilo)
{ 
//	printf("\n[DEBUG] ------- pmutex : %p\n", &tphilo->watcher->pmutex);
//	printf("[DEBUG] ------- watcher : %p\n", tphilo->watcher);
	pthread_mutex_lock(&tphilo->master->pmutex);
	ft_putnbr_fd(curtime, 1);
	ft_putstr_fd("\t", 1);
	ft_putnbr_fd(tphilo->num, 1);
	ft_putstr_fd(s, 1);
	pthread_mutex_unlock(&tphilo->master->pmutex);
}

void	destroy_mutex(t_data *master)
{
	int	i;

	i = 0;
	while (i < master->nb_philo)
		pthread_mutex_destroy(&master->forks[i++].fmutex);
}

void	sync_threads(t_data *master)
{
	int	i;

	i = 0;
	while (i < master->nb_philo)
	{
		if (master->tphilo[i].id != 0)
			i++;
		usleep(1);
	}
}
