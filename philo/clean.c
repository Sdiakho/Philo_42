/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:51:38 by monana            #+#    #+#             */
/*   Updated: 2026/02/18 11:02:30 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clean_philo(t_philo *philo)
{
	if (!philo)
		return ;
	pthread_mutex_destroy(&philo->meal_lock);
	philo->data = NULL;
}

static void	clean_philos(t_data *data)
{
	int	i;

	i = 0;
	if (!data->philos)
		return ;
	while (i < data->nb_philos)
	{
		clean_philo(&data->philos[i]);
		i++;
	}
	free(data->philos);
}

void	clean_forks(t_data *data, int n)
{
	int	i;

	i = 0;
	if (!data->forks)
		return ;
	while (i < n)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
}

void	clean_all(t_data *data, int fork_flag)
{
	if (!data)
		return ;
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->dead_lock);
	if (data->forks && fork_flag == -1)
		clean_forks(data, data->nb_philos);
	else
		clean_forks(data, fork_flag);
	if (data->philos)
		clean_philos(data);
}
