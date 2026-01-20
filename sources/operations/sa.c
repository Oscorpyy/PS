/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:36:52 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/20 13:06:29 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

void	swap_a(t_stack *stack)
{
	int	tmp;

	if (stack->stack_a == NULL || stack->len_a < 2)
		return ;
	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	stack->total++;
	stack->sa++;
	if (stack->print == 1)
		ft_printf("sa\n", 1);
}
