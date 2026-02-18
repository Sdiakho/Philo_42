/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:38:32 by monana            #+#    #+#             */
/*   Updated: 2026/02/18 12:49:31 by monana           ###   ########.fr       */
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

void	eat_mutex(t_philo *philo, pthread_mutex_t *fk_1, pthread_mutex_t *fk_2)
{
	pthread_mutex_lock(fk_1);
	print_status(philo, 'F');
	pthread_mutex_lock(fk_2);
	print_status(philo, 'F');
	print_status(philo, 'E');
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_time_in_ms();
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo->data->time_for_eat, philo);
	pthread_mutex_unlock(fk_1);
	pthread_mutex_unlock(fk_2);
}

void	eat_routine(t_philo *philo)
{
	if (philo->p_id % 2 != 0)
		eat_mutex(philo, philo->right_fork, philo->left_fork);
	else
		eat_mutex(philo, philo->left_fork, philo->right_fork);
}

void	*philo_routine(void *p_data)
{
	t_philo	*philo;

	philo = (t_philo *)p_data;
	if (philo->p_id % 2 == 0)
		ft_usleep(5, philo);
	while (!check_death(philo))
	{
		eat_routine(philo);
		print_status(philo, 'S');
		ft_usleep(philo->data->time_for_slp, philo);
		print_status(philo, 'T');
	}
	return (NULL);
}
