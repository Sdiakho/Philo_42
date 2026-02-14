/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:02:32 by monana            #+#    #+#             */
/*   Updated: 2026/02/14 19:06:59 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **args)
{
	data->nb_philos = -1;
	data->time_for_die = -1;
	data->time_for_eat = -1;
	data->time_for_slp = -1;
	data->max_meals = -1;
	data->philos = NULL;
	data->forks = NULL;
	data->dead_flag = 0;
	if (pthread_mutex_init((&data->dead_lock), NULL) != 0)
		return ;
	;
	pthread_mutex_init((&data->write_lock), NULL);
}

void	init_philo(t_philo *philo)
{
}