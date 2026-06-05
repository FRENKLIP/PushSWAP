/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_counts.c                                     :+:      :+:    :+:   */
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

void	print_first_counts(t_wrapper *wrapper)
{
	write(2, "\n[bench] sa: ", 13);
	ft_putnbr_fd(wrapper->ops[OP_SA], 2);
	write(2, " sb: ", 5);
	ft_putnbr_fd(wrapper->ops[OP_SB], 2);
	write(2, " ss: ", 5);
	ft_putnbr_fd(wrapper->ops[OP_SS], 2);
	write(2, " pa: ", 5);
	ft_putnbr_fd(wrapper->ops[OP_PA], 2);
	write(2, " pb: ", 5);
	ft_putnbr_fd(wrapper->ops[OP_PB], 2);
}

void	print_second_counts(t_wrapper *wrapper)
{
	write(2, "\n[bench] ra: ", 13);
	ft_putnbr_fd(wrapper->ops[OP_RA], 2);
	write(2, " rb: ", 5);
	ft_putnbr_fd(wrapper->ops[OP_RB], 2);
	write(2, " rr: ", 5);
	ft_putnbr_fd(wrapper->ops[OP_RR], 2);
	write(2, " rra: ", 6);
	ft_putnbr_fd(wrapper->ops[OP_RRA], 2);
	write(2, " rrb: ", 6);
	ft_putnbr_fd(wrapper->ops[OP_RRB], 2);
	write(2, " rrr: ", 6);
	ft_putnbr_fd(wrapper->ops[OP_RRR], 2);
	write(2, "\n", 1);
}
