/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:31:02 by tnedel            #+#    #+#             */
/*   Updated: 2024/10/24 11:38:07 by tnedel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	usage_mess(void)
{
	printf("Usage: ./philo nb_philosophers ");
	printf("t_to_die ");
	printf("t_to_eat ");
	printf("t_to_sleep ");
	printf("[nb_philosopher_eat]\n");
}