/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:38:07 by tnedel            #+#    #+#             */
/*   Updated: 2024/11/07 14:30:15 by tnedel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mess(char *s, int philo, t_data *master)
{ 
	long	time_elapsed;

	time_elapsed = 0;
	pthread_mutex_lock(&master->pmutex);
	ft_gettime(&time_elapsed, master->start_time);
	ft_putnbr_fd(time_elapsed, 1);
	ft_putstr_fd("\t", 1);
	ft_putnbr_fd(philo, 1);
	ft_putstr_fd(s, 1);
	pthread_mutex_unlock(&master->pmutex);
}

void	destroy_mutex(t_data *master)
{
	int	i;

	i = 0;
	while (i < master->nb_philo)
		pthread_mutex_destroy(&master->forks[i++]);
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
