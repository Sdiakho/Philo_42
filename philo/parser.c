/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:01:21 by monana            #+#    #+#             */
/*   Updated: 2026/02/18 11:18:44 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static int	is_valid(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	check_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!(is_valid(args[i])))
			return (0);
		i++;
	}
	return (1);
}

void	parser(t_data *data, int ac, char **av)
{
	if ((check_args(&av[1])) != 1)
		error_exit_msg(data, "check args", 1);
	if (!(ft_atoi(av[1], &data->nb_philos)))
		error_exit_msg(data, "check args", 1);
	if (!(ft_atol(av[2], &data->time_for_die)))
		error_exit_msg(data, "check args", 1);
	if (!(ft_atol(av[3], &data->time_for_eat)))
		error_exit_msg(data, "check args", 1);
	if (!(ft_atol(av[4], &data->time_for_slp)))
		error_exit_msg(data, "check args", 1);
	if (ac == 6)
		if (!(ft_atoi(av[5], &data->max_meals)))
			error_exit_msg(data, "check args", 1);
}
