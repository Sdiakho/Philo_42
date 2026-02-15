/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:02:32 by monana            #+#    #+#             */
/*   Updated: 2026/02/15 18:37:34 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, char **args)
{
	data->nb_philos = -1;
	data->top_start = get_time_in_ms();
	data->time_for_die = -1;
	data->time_for_eat = -1;
	data->time_for_slp = -1;
	data->max_meals = -1;
	data->philos = NULL;
	data->forks = NULL;
	data->dead_flag = 0;
	if (pthread_mutex_init((&data->dead_lock), NULL) != 0)
		error_exit_msg(data, "Mutex error", 1);
	if (pthread_mutex_init((&data->write_lock), NULL) != 0)
		error_exit_msg(data, "Mutex error", 1);
}
void	alloc_data(t_data *data)
{
	int i;

	if (!data)
		error_exit_msg(data, "Missing datas", 1);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philos)
		error_exit_msg(data, "Malloc error", 1);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		error_exit_msg(data, "Malloc error", 1);
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			error_exit_msg(data, "Mutex error", 1);
		i++;
	}
}

void	fill_philo(t_data *data, t_philo *philo, int i)
{
	philo->p_id = i + 1;
	philo->meals_eaten = 0;
	philo->data = data;
	philo->left_fork = &data->forks[i];
	philo->right_fork = &data->forks[philo->p_id % data->nb_philos];
	philo->last_meal_time = data->top_start;
	if (pthread_mutex_init((&philo->meal_lock), NULL) != 0)
		error_exit_msg(data, "Mutex error", 1);
}

void	init_philo(t_data *data)
{
	int i;

	i = 0;
	if (!data)
		error_exit_msg(data, "Missing datas", 1);
	while (i < data->nb_philos)
	{
		fill_philo(data, &data->philos[i], i);
		i++;
	}
}
