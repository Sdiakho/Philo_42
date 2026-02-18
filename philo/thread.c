/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:21:43 by monana            #+#    #+#             */
/*   Updated: 2026/02/18 15:19:18 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_thread(t_data *data, t_philo *philos, int nb_philos)
{
	int	i;

	i = 0;
	data->top_start = get_time_in_ms();
	while (i < nb_philos)
	{
		data->philos[i].last_meal_time = data->top_start;
		if (pthread_create(&philos[i].t_id, NULL, philo_routine, &philos[i])
			!= 0)
			error_exit_msg(data, "Create Thread error", 1);
		i++;
	}
	check_monitor(data);
	i = 0;
	while (i < nb_philos)
	{
		if (pthread_join(philos[i].t_id, NULL) != 0)
			error_exit_msg(data, "Join Thread error", 1);
		i++;
	}
}
