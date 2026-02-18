/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:42:09 by monana            #+#    #+#             */
/*   Updated: 2026/02/18 11:59:49 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_space(char c)
{
	return ((c == ' ') || (c >= 9 && c <= 13));
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(const char *str, long *out)
{
	long	res;

	if (!str || !out)
		return (0);
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			return (0);
	if (!is_digit(*str))
		return (0);
	res = 0;
	while (is_digit(*str))
	{
		res = res * 10 + (*str++ - '0');
		if (res > INT_MAX)
			return (0);
	}
	while (is_space(*str))
		str++;
	if (*str)
		return (0);
	return (*out = (res), 1);
}

int	ft_atoi(const char *str, int *out)
{
	int	res;

	if (!str || !out)
		return (0);
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			return (0);
	if (!is_digit(*str))
		return (0);
	res = 0;
	while (is_digit(*str))
	{
		res = res * 10 + (*str++ - '0');
		if (res > INT_MAX)
			return (0);
	}
	while (is_space(*str))
		str++;
	if (*str)
		return (0);
	return (*out = (res), 1);
}
