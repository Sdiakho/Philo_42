/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:21:43 by monana            #+#    #+#             */
/*   Updated: 2026/02/18 12:09:01 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_thread(t_data *data, t_philo *philos, int nb_philos)
{
	int	i;

	i = 0;
	while (i < nb_philos)
	{
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
