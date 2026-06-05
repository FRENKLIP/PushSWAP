/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 20:12:11 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/04 17:25:37 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_wrapper	*init_wrapper(t_options opt)
{
	t_wrapper	*wrapper;

	wrapper = stack(opt.args);
	wrapper->bench = opt.bench;
	wrapper->strategy = opt.strategy;
	put_index(wrapper);
	wrapper->disorder = mistakes(wrapper->a);
	return (wrapper);
}

static int	finish(t_wrapper *wrapper)
{
	if (wrapper->bench)
		print_bench(wrapper);
	free_wrapper(wrapper);
	return (0);
}

int	main(int argc, char **argv)
{
	t_options	opt;
	t_wrapper	*wrapper;

	if (argc == 1)
		return (0);
	opt = parse_args(argc, argv);
	if (opt.error || opt.count == 0 || !valid(opt.count, opt.args))
	{
		write(2, "Error\n", 6);
		free_args(opt);
		return (0);
	}
	wrapper = init_wrapper(opt);
	free_args(opt);
	if (is_sorted(wrapper->a))
		return (finish(wrapper));
	flags(wrapper);
	return (finish(wrapper));
}

void	put_index(t_wrapper *wrapper)
{
	int		index;
	t_node	*temp;
	t_node	*node;

	node = wrapper->a->top;
	while (node)
	{
		index = 0;
		temp = wrapper->a->top;
		while (temp)
		{
			if (node->data > temp->data)
				index++;
			temp = temp->next;
		}
		node->index = index;
		node = node->next;
	}
}
