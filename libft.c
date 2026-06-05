/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:56:29 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/02 11:56:34 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(const char *str)
{
	return ((int)ft_atol(str));
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!is_sep(*s, c) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (is_sep(*s, c))
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(char const *s, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		start;
	int		word;

	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i])
	{
		while (is_sep(s[i], c))
			i++;
		start = i;
		while (s[i] && !is_sep(s[i], c))
			i++;
		if (i > start)
			arr[word++] = word_dup(s + start, i - start);
	}
	arr[word] = NULL;
	return (arr);
}
