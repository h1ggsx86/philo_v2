/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:40:17 by tnedel            #+#    #+#             */
/*   Updated: 2024/11/04 15:15:11 by tnedel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return len;
}

long	ft_atol(const char *nptr)
{
	int			n;
	long		res;
	char		*p;

	n = 1;
	res = 0;
	p = (char *)nptr;
	while (*p == 32 || (*p >= 9 && *p <= 13))
		p++;
	if (*p == '-' || *p == '+')
	{
		if (*p++ == '-')
		n = -n;
	}
	while (*p >= 48 && *p <= 57)
		res = (res * 10) + (*p++ - '0');
	return (res * n);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	slen;

	slen = ft_strlen(s);
	write(fd, s, slen);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	nb;
	
	nb = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	c = '0' + (nb % 10);
	write(fd, &c, 1);
}

long	convert_msec(struct timeval time)
{
	long long res;

	res = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (res);
}

int	ft_gettime(long *time_elapsed, long start_time)
{
	long long		res;
	long long		check;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (EXIT_FAILURE);
	res = convert_msec(tv);
	check = res - start_time;
	if (check > LONG_MAX)
		return (EXIT_FAILURE);
	*time_elapsed = *time_elapsed + check;
	return (EXIT_SUCCESS);
}

