/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:24:20 by tnedel            #+#    #+#             */
/*   Updated: 2024/11/07 14:47:40 by tnedel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *tphilo, t_data *master)
{
	int	left_fork;
	int	right_fork;

	left_fork = tphilo->num - 1;
	if (tphilo->num == master->nb_philo)
		right_fork = 0;
	else
		right_fork = tphilo->num;
	take_forks(&master->forks[left_fork], &master->forks[right_fork], tphilo->num, master);
	print_mess(" is eating\n", tphilo->num, tphilo->master);
	usleep(master->time_to_eat * 1000);
	pthread_mutex_unlock(&master->forks[left_fork]);
	pthread_mutex_unlock(&master->forks[right_fork]);
}

void	philo_sleep(int philo, t_data *master)
{
	print_mess(" is sleeping\n", philo, master);
	usleep(master->time_to_sleep * 1000);
}

void	philo_think(int philo, t_data *master)
{
	print_mess(" is thinking\n", philo, master);
}

void	take_forks(t_mutex *l_fork, t_mutex *r_fork, int philo, t_data *master)
{
//	if (master->nb_philo % 2 == 0)
//	{
		if (pthread_mutex_lock(l_fork) == 0)
		{
			print_mess(" has taken a fork\n", philo, master);
			if (pthread_mutex_lock(r_fork) == 0)
				print_mess(" has taken a fork\n", philo, master);
		}
//	}
//	else
//	{
//		if (pthread_mutex_lock(r_fork) == 0)
//		{
//			print_mess(" has taken a fork\n", philo, master);
//			if (pthread_mutex_lock(l_fork) == 0)
//				print_mess(" has taken a fork\n", philo, master);
//		}
//	}
}