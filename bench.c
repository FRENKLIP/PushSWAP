/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:15:00 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/05 11:15:00 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

static void	print_percent(double n)
{
	int	pct;

	pct = (int)(n * 10000 + 0.5);
	ft_putnbr_fd(pct / 100, 2);
	write(2, ".", 1);
	if (pct % 100 < 10)
		write(2, "0", 1);
	ft_putnbr_fd(pct % 100, 2);
	write(2, "%\n", 2);
}

static void	print_strategy(t_wrapper *wrapper)
{
	if (wrapper->strategy == STRAT_SIMPLE)
		write(2, "[bench] strategy: Simple / O(n^2)\n", 34);
	else if (wrapper->strategy == STRAT_MEDIUM)
		write(2, "[bench] strategy: Medium / O(n sqrt(n))\n", 40);
	else if (wrapper->strategy == STRAT_COMPLEX)
		write(2, "[bench] strategy: Complex / O(n log n)\n", 39);
	else
		write(2, "[bench] strategy: Adaptive / O(n log n)\n", 40);
}

void	print_bench(t_wrapper *wrapper)
{
	write(2, "[bench] disorder: ", 18);
	print_percent(wrapper->disorder);
	print_strategy(wrapper);
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr_fd(wrapper->total_ops, 2);
	print_first_counts(wrapper);
	print_second_counts(wrapper);
}
