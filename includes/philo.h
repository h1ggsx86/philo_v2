/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:37:30 by tnedel            #+#    #+#             */
/*   Updated: 2024/11/07 14:24:29 by tnedel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define LONG_MAX 2147483647

typedef pthread_mutex_t t_mutex;

typedef	struct s_data
{
	int				nb_philo;
	long			start_time;
	long			time_to_eat;
	long			time_to_die;
	long			time_to_sleep;
	t_mutex			pmutex;
	t_mutex			*forks;
	pthread_t		id;
	struct s_philo 	*tphilo;
}					t_data;


typedef struct	s_philo
{
	int				num;
	pthread_t		id;
	t_data			*master;
}					t_philo;

int		ft_strlen(char *s);
int		ft_gettime(long *time_elapsed, long start);
long	ft_atol(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
long	convert_msec(struct timeval time);

void	print_mess(char *s, int philo, t_data *master);
void	usage_mess(void);
void	destroy_mutex(t_data *master);
void	sync_threads(t_data *master);
void	take_forks(t_mutex *l_fork, t_mutex *r_fork, int philo, t_data *master);

int		set_up_master(t_data *new, char **args);
void	set_tphilo(t_data *master);
void	set_fork(t_data *master, int nb_philo);

void	philo_sleep(int philo, t_data *master);
void	philo_eat(t_philo *tphilo, t_data *master);
void	philo_think(int philo, t_data *master);

#endif
