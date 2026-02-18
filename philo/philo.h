/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:01:10 by monana            #+#    #+#             */
/*   Updated: 2026/02/18 11:57:58 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define INT_MAX 2147483647

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				p_id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		t_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_lock;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
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
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
}					t_data;

/*  Init  */
void	init_data(t_data *data);
void	alloc_data(t_data *data);
void	init_philo(t_data *data);
void	init_thread(t_data *data, t_philo *philos, int nb_philos);

/*  Parser  */
void	parser(t_data *data, int ac, char **av);

/*  Monitor  */
void	check_monitor(t_data *data);
int		check_death(t_philo *philo);

/*  Routine  */
void	eat_routine(t_philo *philo);
void	*philo_routine(void *p_data);
void	dead_routine(t_data *data, int i);

/*  Display  */
void	print_end(t_data *data);
void	print_status(t_philo *philo, char status);

/*  Time  */
long	get_time_in_ms(void);
void	ft_usleep(long time_in_ms, t_philo *philo);

/*  Clean  */
void	clean_forks(t_data *data, int n);
void	clean_all(t_data *data, int fork_flag);

/*  Error  */
void	error_fork(t_data *data, char *msg, int fork_flag);
void	error_exit_msg(t_data *data, char *msg, int status);

/*  Utils  */
int		ft_strlen(const char *str);
int		ft_atoi(const char *str, int *out);
long	ft_atol(const char *str, long *out);
char	*ft_strlcpy(char *dst, const char *src, int n);

#endif