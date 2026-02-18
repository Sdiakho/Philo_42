/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:09:41 by monana            #+#    #+#             */
/*   Updated: 2026/02/15 18:22:49 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_in_ms(void)
{
	struct timeval	tv;
	long			usec_ms;
	long			sec_ms;
	long			time_ms;

	gettimeofday(&tv, NULL);
	usec_ms = tv.tv_usec / 1000;
	sec_ms = tv.tv_sec * 1000;
	time_ms = usec_ms + sec_ms;
	return (time_ms);
}

void	ft_usleep(long time_in_ms, t_philo *philo)
{
	long	start;

	start = get_time_in_ms();
	while ((get_time_in_ms() - start) < time_in_ms)
	{
		if (check_death(philo))
			break ;
		usleep(500);
	}
}
