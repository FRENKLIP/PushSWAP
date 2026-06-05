/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 19:27:15 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/04 17:18:11 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_num(char *str)
{
	int	i;

	i = 1;
	if (!str)
		return (0);
	if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
		return (0);
	if (!(str[0] == '-' || str[0] == '+'
			|| (str[0] >= '0' && str[0] <= '9')))
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	valid_int(char *str)
{
	long	n;

	n = ft_atol(str);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}

int	dupes(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!is_num(argv[i]) || !valid_int(argv[i]))
			return (0);
		i++;
	}
	if (dupes(argc, argv))
		return (0);
	return (1);
}
