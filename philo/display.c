/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:19:42 by monana            #+#    #+#             */
/*   Updated: 2026/02/18 12:39:32 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char status)
{
	long	cur_time;

	pthread_mutex_lock(&philo->data->write_lock);
	cur_time = (get_time_in_ms() - philo->data->top_start);
	if (check_death(philo))
	{
		pthread_mutex_unlock(&philo->data->write_lock);
		return ;
	}
	if (status == 'E')
		printf("%ldms %d is eating\n", cur_time, philo->p_id);
	else if (status == 'T')
		printf("%ldms %d is thinking\n", cur_time, philo->p_id);
	else if (status == 'S')
		printf("%ldms %d is sleeping\n", cur_time, philo->p_id);
	else if (status == 'F')
		printf("%ldms %d has taken a fork\n", cur_time, philo->p_id);
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	print_end(t_data *data)
{
	long	cur_time;

	pthread_mutex_lock(&data->write_lock);
	cur_time = (get_time_in_ms() - data->top_start);
	printf("%ldms All the philosophers are feeded\n", cur_time);
	pthread_mutex_unlock(&data->write_lock);
	pthread_mutex_lock(&data->dead_lock);
	data->dead_flag = 1;
	pthread_mutex_unlock(&data->dead_lock);
}
