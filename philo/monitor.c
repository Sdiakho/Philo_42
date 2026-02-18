/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:29:12 by monana            #+#    #+#             */
/*   Updated: 2026/02/18 11:22:39 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	int	is_dead;

	pthread_mutex_lock(&philo->data->dead_lock);
	is_dead = philo->data->dead_flag;
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (is_dead);
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
