/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:15:00 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/05 11:15:00 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_a_to(t_wrapper *wrapper, int pos)
{
	int	i;

	if (pos <= wrapper->a->size / 2)
	{
		i = 0;
		while (i++ < pos)
			ra(wrapper);
	}
	else
	{
		i = wrapper->a->size;
		while (i-- > pos)
			rra(wrapper);
	}
}

void	rotate_b_to(t_wrapper *wrapper, int pos)
{
	int	i;

	if (pos <= wrapper->b->size / 2)
	{
		i = 0;
		while (i++ < pos)
			rb(wrapper);
	}
	else
	{
		i = wrapper->b->size;
		while (i-- > pos)
			rrb(wrapper);
	}
}
