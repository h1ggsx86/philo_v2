/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:01:55 by tnedel            #+#    #+#             */
/*   Updated: 2024/11/06 14:43:25 by tnedel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_up_master(t_data *new, char **args)
{
	struct timeval	start;

	new->nb_philo = ft_atol(args[1]);
	if (gettimeofday(&start, NULL))
		return (EXIT_FAILURE);
	new->start_time = convert_msec(start);
	if (new->start_time < 0)
		return (EXIT_FAILURE);
	new->time_to_die = ft_atol(args[2]);
	new->time_to_eat = ft_atol(args[3]);
	new->time_to_sleep = ft_atol(args[4]);
	new->tphilo = NULL;
	pthread_mutex_init(&new->pmutex, NULL);
	pthread_mutex_init(&new->tmutex, NULL);
	set_fork(new, new->nb_philo);
	return (EXIT_SUCCESS);
}

void	set_tphilo(t_data *master)
{
	int	i;
	t_philo	*tmp;

	i = 0;
	while (i < master->nb_philo)
	{
		tmp = &master->tphilo[i];
		tmp->num = i + 1;
		tmp->id = 0;
		tmp->master = master;
		i++;
	}
}

void	set_fork(t_data *master, int nb_philo)
{
	int		i;
	t_fork	*forks;

	forks = malloc(sizeof(*forks) * nb_philo);
	i = 0;
	while (i < nb_philo)
	{
		forks[i].id = i + 1;
		pthread_mutex_init(&forks[i].fmutex, NULL);
		i++;
	}
	master->forks = forks;
}
