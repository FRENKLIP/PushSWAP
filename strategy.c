/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:15:00 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/05 11:15:00 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	adaptive(t_wrapper *wrapper)
{
	if (wrapper->a->size <= 20 && wrapper->disorder < 0.2)
		n2(wrapper);
	else if (wrapper->a->size <= 100 && wrapper->disorder < 0.5)
		medium(wrapper);
	else
		complex(wrapper);
}

void	flags(t_wrapper *wrapper)
{
	if (wrapper->strategy == STRAT_SIMPLE)
		n2(wrapper);
	else if (wrapper->strategy == STRAT_MEDIUM)
		medium(wrapper);
	else if (wrapper->strategy == STRAT_COMPLEX)
		complex(wrapper);
	else
		adaptive(wrapper);
}
