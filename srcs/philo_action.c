/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:24:20 by tnedel            #+#    #+#             */
/*   Updated: 2024/11/06 15:51:28 by tnedel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *tphilo, t_data *master, long *time_elapsed)
{
	int	left_fork;
	int	right_fork;

	left_fork = tphilo->num - 1;
	if (tphilo->num == master->nb_philo)
		right_fork = 0;
	else
		right_fork = tphilo->num;
	pthread_mutex_lock(&master->forks[left_fork].fmutex);
	print_mess(" has taken a fork\n", ft_gettime(time_elapsed, \
			master->start_time), tphilo);
	pthread_mutex_lock(&master->forks[right_fork].fmutex);
	print_mess(" has taken a fork\n", ft_gettime(time_elapsed, \
			master->start_time), tphilo);
	print_mess(" is eating\n", ft_gettime(time_elapsed, \
			master->start_time), tphilo);
	usleep(master->time_to_eat * 1000);
	pthread_mutex_unlock(&master->forks[left_fork].fmutex);
	pthread_mutex_unlock(&master->forks[right_fork].fmutex);
}
