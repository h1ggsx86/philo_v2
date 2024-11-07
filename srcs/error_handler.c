/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:31:02 by tnedel            #+#    #+#             */
/*   Updated: 2024/11/07 11:28:31 by tnedel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	usage_mess(void)
{
	ft_putstr_fd("Usage: ./philo nb_philosophers ", 1);
	ft_putstr_fd("t_to_die ", 1);
	ft_putstr_fd("t_to_eat ", 1);
	ft_putstr_fd("t_to_sleep ", 1);
	ft_putstr_fd("[nb_philosopher_eat]\n", 1);
}