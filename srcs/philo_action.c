/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:24:20 by tnedel            #+#    #+#             */
/*   Updated: 2024/11/05 18:13:35 by tnedel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *tphilo, t_data *master, long *time_elapsed)
{
	master->start_time = master->start_time;
	*time_elapsed += 1;
	printf("my fork\t\t: %i\n", tphilo->num);
	printf("next fork\t: %i\n", master->tphilo[1].num);
}
