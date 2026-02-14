/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:01:10 by monana            #+#    #+#             */
/*   Updated: 2026/02/14 13:14:45 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>

typedef struct	s_philo
{
	int				p_id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		t_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct	s_data
{
	int				nb_philos;
	int				max_meals;
	int				dead_flag;
	long			top_start;
	long			time_for_eat;
	long			time_for_die;
	long			time_for_slp;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*write_lock;
}	t_data;

#endif