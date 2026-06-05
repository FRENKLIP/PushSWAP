/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 22:37:50 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/04 17:23:02 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

double	mistakes(t_list *a)
{
	double	mis;
	double	all;
	t_node	*i;
	t_node	*j;

	mis = 0;
	all = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->data > j->data)
				mis++;
			j = j->next;
			all++;
		}
		i = i->next;
	}
	if (all == 0)
		return (0);
	return (mis / all);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	print_op(t_wrapper *wrapper, char *op, int len, int id)
{
	wrapper->total_ops++;
	wrapper->ops[id]++;
	write(1, op, len);
}

int	is_sorted(t_list *a)
{
	t_node	*node;

	node = a->top;
	while (node && node->next)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}
