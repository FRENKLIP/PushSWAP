/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:20:00 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/05 12:20:00 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	free_list(t_list *list)
{
	t_node	*node;
	t_node	*next;

	if (!list)
		return ;
	node = list->top;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(list);
}

void	free_wrapper(t_wrapper *wrapper)
{
	if (!wrapper)
		return ;
	free_list(wrapper->a);
	free_list(wrapper->b);
	free(wrapper);
}

void	free_args(t_options opt)
{
	int	i;

	if (!opt.split || !opt.args)
		return ;
	i = 0;
	while (opt.args[i])
		free(opt.args[i++]);
	free(opt.args);
}
