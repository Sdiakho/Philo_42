/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:01:21 by monana            #+#    #+#             */
/*   Updated: 2026/02/14 18:49:50 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	is_full_digits(const char *str)
{
	int	i;
	int	len_str;

	i = 0;
	len_str = ft_strlen(str);
	while (i < len_str)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		if (!is_full_digits(args[i]))
			return (0);
		i++;
	}
	return (1);
}

void	parser_one(t_data *data, char **av)
{
	char **args;

	args = split(av[1], ' ');
	if (!args)
	{
		printf("split error\n");
		exit(1);
	}
	if ((check_args(args)) != 1)
	{
		printf("error checks\n");
		exit(1);
	}
	data->nb_philos = ft_atoi(args[0]);
	data->time_for_die = ft_atol(args[1]);
	data->time_for_eat = ft_atol(args[2]);
	data->time_for_slp = ft_atol(args[3]);
	if (args[4])
	{
		data->max_meals = ft_atoi(args[4]);
		free_split(args, 5);
	}
	else
		free_split(args, 4);	
}

void	parser_multi(t_data *data, char **av)
{
	if ((check_args(&av[1])) != 1)
	{
		printf("error checks\n");
		exit(1);
	}
	data->nb_philos = ft_atoi(av[1]);
	data->time_for_die = ft_atol(av[2]);
	data->time_for_eat = ft_atol(av[3]);
	data->time_for_slp = ft_atol(av[4]);
	if (av[4])
	{
		data->max_meals = ft_atoi(av[5]);
	}
}

#include <stdio.h>

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
		parser_one(&data, av);
	else
		parser_multi(&data, av);
	printf("Time for die : %ld ms\n", data.time_for_die);
	printf("Time for eat : %ld ms\n", data.time_for_eat);
	printf("Time for sleep : %ld ms\n", data.time_for_slp);
	printf("nbrs de philo : %d\n", data.nb_philos);
	return (0);
}
