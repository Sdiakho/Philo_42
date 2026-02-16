/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:01:10 by monana            #+#    #+#             */
/*   Updated: 2026/02/16 17:14:18 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

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

int		check_death(t_philo *philo);

/* Utils*/
int		ft_atoi(const char *str, int *out);
int		ft_strlen(const char *str);
char	*ft_strlcpy(char *dst, const char *src, int n);
long	ft_atol(const char *str, long *out);
char	**split(const char *str, const char sep);
void	free_split(char **tab, int n);

/*  Display  */
void	ft_putstr_fd(char *str, int fd);
void	print_status(t_philo *philo, char *status);

/*  Error  */
void	error_exit_msg(t_data *data, char *msg, int status);

/*  Time  */
long	get_time_in_ms(void);
void	ft_usleep(long time_in_ms, t_philo *philo);

#endif