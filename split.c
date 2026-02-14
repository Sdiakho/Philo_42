/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monana <monana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:48:11 by monana            #+#    #+#             */
/*   Updated: 2026/02/14 15:01:08 by monana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_split(char **tab, int n)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	count_words(const char *str, const char sep)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
	while (str[i] && str[i] == sep)
		i++;
	if (str[i])
		count++;
	while (str[i] && str[i] != sep)
		i++;
	}
	return (count);
}

char	*word(const char *str, int start, int end)
{
	int		i;
	int		len_wrd;
	char	*wrd;

	i = 0;
	len_wrd = end - start;
	wrd = (char *)malloc(sizeof(char) * (len_wrd + 1));
	if (!wrd)
		return (NULL);
	ft_strlcpy(wrd, &str[start], len_wrd + 1);
	return (wrd);
}

char	**split(const char *str, const char sep)
{
	int		i;
	int		j;
	int		start;
	char	**words;

	words = (char **)malloc(sizeof(char *) * (count_words(str, ' ') + 1));
	if (!words)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(str, ' '))
	{
		while (str[i] && str[i] == sep)
			i++;
		start = i;
		while (str[i] && str[i] != sep)
			i++;
		words[j] = word(str, start, i);
		if (!words[j])
			return (free_split(words, j), NULL);
		j++;
	}
	words[j] = NULL;
	return (words);
}
