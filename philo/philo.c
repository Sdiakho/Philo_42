/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:33:03 by monana            #+#    #+#             */
/*   Updated: 2026/02/18 12:50:15 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
	{
		printf("Numbers of aguments invalid");
		return (1);
	}
	init_data(&data);
	parser(&data, ac, av);
	alloc_data(&data);
	init_philo(&data);
	init_thread(&data, data.philos, data.nb_philos);
	clean_all(&data, -1);
	return (0);
}
