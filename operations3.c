/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 22:07:57 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/04 17:17:39 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rev_rot(t_list *list)
{
	t_node	*top;
	t_node	*bot;
	t_node	*temp;

	if (!list || list->size < 2)
		return ;
	temp = list->bottom->prev;
	top = list->top;
	bot = list->bottom;
	temp->next = NULL;
	bot->prev = NULL;
	bot->next = top;
	top->prev = bot;
	list->top = bot;
	list->bottom = temp;
}

void	rra(t_wrapper *wrapper)
{
	if (!wrapper->a || wrapper->a->size < 2)
		return ;
	rev_rot(wrapper->a);
	print_op(wrapper, "rra\n", 4, OP_RRA);
}

void	rrb(t_wrapper *wrapper)
{
	if (!wrapper->b || wrapper->b->size < 2)
		return ;
	rev_rot(wrapper->b);
	print_op(wrapper, "rrb\n", 4, OP_RRB);
}

void	rrr(t_wrapper *wrapper)
{
	if ((!wrapper->a || wrapper->a->size < 2)
		&& (!wrapper->b || wrapper->b->size < 2))
		return ;
	rev_rot(wrapper->a);
	rev_rot(wrapper->b);
	print_op(wrapper, "rrr\n", 4, OP_RRR);
}
