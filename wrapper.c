/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 20:43:29 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/02 11:52:54 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_node	*new_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	append(t_list *list, t_node *node)
{
	t_node	*temp;

	if (!list)
		return ;
	if (!list->top)
	{
		list->top = node;
		list->bottom = node;
		list->size += 1;
		return ;
	}
	temp = list->bottom;
	temp->next = node;
	list->bottom = node;
	list->bottom->prev = temp;
	list->size += 1;
}

static t_list	*new_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->top = NULL;
	list->bottom = NULL;
	list->size = 0;
	return (list);
}

void	add_bottom(t_list *list, int n)
{
	t_node	*node;

	node = new_node(n);
	append(list, node);
}

t_wrapper	*stack(char **str)
{
	t_wrapper	*wrapper;
	int			i;

	wrapper = malloc(sizeof(t_wrapper));
	if (!wrapper)
		return (NULL);
	wrapper->a = new_list();
	wrapper->b = new_list();
	wrapper->bench = 0;
	wrapper->strategy = STRAT_ADAPTIVE;
	wrapper->disorder = 0;
	wrapper->total_ops = 0;
	i = 0;
	while (i < 11)
		wrapper->ops[i++] = 0;
	i = 0;
	while (str[i])
	{
		add_bottom(wrapper->a, ft_atoi(str[i]));
		i++;
	}
	return (wrapper);
}
