/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:58:43 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/03 23:21:29 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	max_bits(t_list *a)
{
	int		max;
	t_node	*node;
	int		bits;

	max = a->top->index;
	bits = 0;
	node = a->top;
	while (node)
	{
		if (max < node->index)
			max = node->index;
		node = node->next;
	}
	while (max)
	{
		bits++;
		max = max / 2;
	}
	return (bits);
}

void	complex(t_wrapper *wrapper)
{
	int	max;
	int	bit;
	int	i;
	int	size;

	max = max_bits(wrapper->a);
	bit = 0;
	while (bit < max)
	{
		i = 0;
		size = wrapper->a->size;
		while (i < size)
		{
			if (((wrapper->a->top->index >> bit) & 1) == 1)
				ra(wrapper);
			else
				pb(wrapper);
			i++;
		}
		while (wrapper->b->size)
			pa(wrapper);
		bit++;
	}
}
