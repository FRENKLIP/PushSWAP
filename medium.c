/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:46:16 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/03 21:14:05 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	chunk_pos(t_list *a, int start, int end)
{
	t_node	*node;
	int		i;

	node = a->top;
	i = 0;
	while (node)
	{
		if (node->index >= start && node->index <= end)
			return (i);
		i++;
		node = node->next;
	}
	return (-1);
}

static int	max_pos(t_list *b)
{
	t_node	*node;
	int		max;
	int		i;
	int		pos;

	node = b->top;
	max = node->index;
	i = 0;
	pos = 0;
	while (node)
	{
		if (node->index > max)
		{
			max = node->index;
			pos = i;
		}
		i++;
		node = node->next;
	}
	return (pos);
}

static void	push_chunk(t_wrapper *wrapper, int *start, int *end, int size)
{
	int	pos;

	while (wrapper->a->size)
	{
		pos = chunk_pos(wrapper->a, *start, *end);
		if (pos == -1)
		{
			*start += size;
			*end += size;
		}
		else
		{
			rotate_a_to(wrapper, pos);
			pb(wrapper);
		}
	}
}

static void	push_back(t_wrapper *wrapper)
{
	int	pos;

	while (wrapper->b->size)
	{
		pos = max_pos(wrapper->b);
		rotate_b_to(wrapper, pos);
		pa(wrapper);
	}
}

void	medium(t_wrapper *wrapper)
{
	int	chunk_size;
	int	start;
	int	end;

	chunk_size = 22;
	if (wrapper->a->size <= 100)
		chunk_size = 10;
	start = 0;
	end = chunk_size - 1;
	push_chunk(wrapper, &start, &end, chunk_size);
	push_back(wrapper);
}
