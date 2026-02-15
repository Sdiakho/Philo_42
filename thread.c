/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:21:43 by monana            #+#    #+#             */
/*   Updated: 2026/02/15 18:37:48 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	int is_dead;

	pthread_mutex_lock(&philo->data->dead_lock);
	is_dead = philo->data->dead_flag;
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (is_dead);
}

void	*philo_routine(void *p_data)
{
	t_philo	*philo;

	philo = (t_philo *)p_data;
	if (philo->p_id % 2 == 0)
		ft_usleep(2, philo);
	while (!check_death(philo))
	{
		eat_routine(philo);
		print_status(philo, 'S');
		ft_usleep(philo->data->time_for_slp, philo);
		print_status(philo, 'T');	
	}
	return (NULL);
}

void	init_thread(t_data *data, t_philo *philos, int nb_philos)
{
	int i;

	i = 0;
	while (i < nb_philos)
	{
		if (pthread_create(&philos[i].t_id, NULL, philo_routine, &philos[i])
			!= 0)
			error_exit_msg(data, "Create Thread error", 1);
		i++;
	}
	i = 0;
	while (i < nb_philos)
	{
		if (pthread_join(&philos[i].t_id, NULL) != 0)
			error_exit_msg(data, "Join Thread error", 1);
		i++;
	}
}
