/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:15:18 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/03 20:44:44 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_list *list)
{
	int	temp;

	temp = list->top->data;
	list->top->data = list->top->next->data;
	list->top->next->data = temp;
}

void	sa(t_wrapper *wrapper)
{
	if (!wrapper->a || wrapper->a->size <= 1)
		return ;
	swap(wrapper->a);
	print_op(wrapper, "sa\n", 3, OP_SA);
}

void	sb(t_wrapper *wrapper)
{
	if (!wrapper->b || wrapper->b->size <= 1)
		return ;
	swap(wrapper->b);
	print_op(wrapper, "sb\n", 3, OP_SB);
}

void	ss(t_wrapper *wrapper)
{
	if (wrapper->a && wrapper->a->size > 1)
		swap(wrapper->a);
	if (wrapper->b && wrapper->b->size > 1)
		swap(wrapper->b);
	print_op(wrapper, "ss\n", 3, OP_SS);
}
