/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:29:12 by monana            #+#    #+#             */
/*   Updated: 2026/02/16 18:32:52 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dead_routine(t_data *data, int i)
{
	long	cur_time;

	cur_time = get_time_in_ms() - data->top_start;
	pthread_mutex_lock(&data->dead_lock);
	data->dead_flag = 1;
	pthread_mutex_unlock(&data->dead_lock);
	pthread_mutex_lock(&data->write_lock);
	printf("%ld %d died\n", cur_time, data->philos[i].p_id);
	pthread_mutex_unlock(&data->write_lock);
	pthread_mutex_unlock(&data->philos[i].meal_lock);
	return ;
}

void	check_monitor(t_data *data)
{
	int		i;
	int		philo_feeded;
	long	time_since_eat;

	while (1)
	{
		i = 0;
		philo_feeded = 0;
		while (i < data->nb_philos)
		{
			pthread_mutex_lock(&data->philos[i].meal_lock);
			time_since_eat = get_time_in_ms() - data->philos[i].last_meal_time;
			if (time_since_eat >= data->time_for_die)
				return (dead_routine(data, i));
			if (data->max_meals != -1 && data->philos[i].meals_eaten >= data->max_meals)
				philo_feeded += 1;
			pthread_mutex_unlock(&data->philos[i].meal_lock);
			i++;
		}
		if (philo_feeded == data->nb_philos)
			return (print_end(data));
	}
}
