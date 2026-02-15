/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:42:09 by monana            #+#    #+#             */
/*   Updated: 2026/02/15 12:59:47 by monana           ###   ########.fr       */
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

long	ft_atol(const char *str, int *out)
{
	long	res;
	int		sign;

	if (!str || !out)
		return (0);
	while (is_space(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	if (!is_digit(*str))
		return (0);
	res = 0;
	while (is_digit(*str))
		res = res * 10 + (*str++ - '0');
	while (is_space(*str))
		str++;
	if (*str)
		return (0);
	return (*out = (res * sign), 1);
}

int		ft_atoi(const char *str, int *out)
{
	int	res;
	int	sign;

	if (!str || !out)
		return (0);
	while (is_space(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	if (!is_digit(*str))
		return (0);
	res = 0;
	while (is_digit(*str))
		res = res * 10 + (*str++ - '0');
	while (is_space(*str))
		str++;
	if (*str)
		return (0);
	return (*out = (res *sign), 1);
}
