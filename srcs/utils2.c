/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:38:07 by tnedel            #+#    #+#             */
/*   Updated: 2024/11/04 13:48:14 by tnedel           ###   ########.fr       */
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

void	set_up_master(t_data *new, char **args)
{
	struct timeval	start;

	new->nb_philo = ft_atol(args[1]);
	gettimeofday(&start, NULL);
	new->start_time = convert_msec(start);
	new->time_elapsed = 0;
	new->time_to_die = ft_atol(args[2]);
	new->time_to_eat = ft_atol(args[3]);
	new->time_to_sleep = ft_atol(args[4]);
	new->tphilo = NULL;
	pthread_mutex_init(&new->pmutex, NULL);
}

void	destroy_mutex(t_data *master)
{
	int	i;

	i = 0;
	while (i < master->nb_philo)
		pthread_mutex_destroy(&master->tphilo[i++].fmutex);
}

//void	sync_threads(t_data *master)
//{
	
//}
