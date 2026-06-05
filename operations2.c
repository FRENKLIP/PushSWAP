/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:48:55 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/04 17:17:33 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_list *list)
{
	t_node	*top;
	t_node	*bot;

	if (!list || list->size < 2)
		return ;
	top = list->top;
	bot = list->bottom;
	bot->next = top;
	list->top = list->top->next;
	list->top->prev = NULL;
	list->bottom = top;
	list->bottom->next = NULL;
	list->bottom->prev = bot;
}

void	ra(t_wrapper *wrapper)
{
	if (!wrapper->a || wrapper->a->size < 2)
		return ;
	rotate(wrapper->a);
	print_op(wrapper, "ra\n", 3, OP_RA);
}

void	rb(t_wrapper *wrapper)
{
	if (!wrapper->b || wrapper->b->size < 2)
		return ;
	rotate(wrapper->b);
	print_op(wrapper, "rb\n", 3, OP_RB);
}

void	rr(t_wrapper *wrapper)
{
	if ((!wrapper->a || wrapper->a->size < 2)
		&& (!wrapper->b || wrapper->b->size < 2))
		return ;
	rotate(wrapper->a);
	rotate(wrapper->b);
	print_op(wrapper, "rr\n", 3, OP_RR);
}
