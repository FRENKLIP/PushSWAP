/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:20:47 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/03 23:38:57 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	lowest(t_list *a)
{
	int		i;
	int		lowest_pos;
	int		lowest_value;
	t_node	*node;

	i = 0;
	lowest_pos = 0;
	node = a->top;
	if (!node)
		return (-1);
	lowest_value = node->data;
	while (node)
	{
		if (node->data < lowest_value)
		{
			lowest_value = node->data;
			lowest_pos = i;
		}
		node = node->next;
		i++;
	}
	return (lowest_pos);
}

void	n2(t_wrapper *wrapper)
{
	int	i;
	int	lowest1;

	while (wrapper->a->size)
	{
		lowest1 = lowest(wrapper->a);
		if (lowest1 <= wrapper->a->size / 2)
		{
			i = 0;
			while (i++ < lowest1)
				ra(wrapper);
		}
		else
		{
			i = wrapper->a->size;
			while (i-- > lowest1)
				rra(wrapper);
		}
		pb(wrapper);
	}
	while (wrapper->b->size)
		pa(wrapper);
}
