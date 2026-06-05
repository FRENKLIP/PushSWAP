/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:15:00 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/05 11:15:00 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_flag(char *arg)
{
	return (arg && arg[0] == '-' && arg[1] == '-');
}

static void	set_flag(t_options *opt, char *arg)
{
	if (ft_strcmp(arg, "--bench") == 0)
		opt->bench = 1;
	else if (ft_strcmp(arg, "--simple") == 0)
		opt->strategy = STRAT_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		opt->strategy = STRAT_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		opt->strategy = STRAT_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		opt->strategy = STRAT_ADAPTIVE;
	else
		opt->error = 1;
}

static void	count_args(t_options *opt)
{
	opt->count = 0;
	while (opt->args[opt->count])
		opt->count++;
}

static t_options	init_options(void)
{
	t_options	opt;

	opt.bench = 0;
	opt.strategy = STRAT_ADAPTIVE;
	opt.error = 0;
	opt.split = 0;
	opt.count = 0;
	opt.args = NULL;
	return (opt);
}

t_options	parse_args(int argc, char **argv)
{
	t_options	opt;
	int			i;

	opt = init_options();
	i = 1;
	while (i < argc && is_flag(argv[i]))
		set_flag(&opt, argv[i++]);
	if (opt.error || i >= argc)
		return (opt);
	if (argc - i == 1)
	{
		opt.args = ft_split(argv[i], ' ');
		opt.split = 1;
		count_args(&opt);
		return (opt);
	}
	opt.args = argv + i;
	opt.count = argc - i;
	return (opt);
}
