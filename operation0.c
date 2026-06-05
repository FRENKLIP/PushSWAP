/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 22:18:32 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/04 17:12:29 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_list *src, t_list *dst)
{
	t_node	*node;
	t_node	*temp;

	if (!src || !dst || !src->top)
		return ;
	node = src->top;
	src->size -= 1;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	temp = dst->top;
	if (temp)
		temp->prev = node;
	else
		dst->bottom = node;
	dst->top = node;
	dst->top->next = temp;
	dst->top->prev = NULL;
	dst->size += 1;
}

void	pa(t_wrapper *wrapper)
{
	if (!wrapper->b || wrapper->b->size == 0)
		return ;
	push(wrapper->b, wrapper->a);
	print_op(wrapper, "pa\n", 3, OP_PA);
}

void	pb(t_wrapper *wrapper)
{
	if (!wrapper->a || wrapper->a->size == 0)
		return ;
	push(wrapper->a, wrapper->b);
	print_op(wrapper, "pb\n", 3, OP_PB);
}
